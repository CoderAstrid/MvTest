#include "stdafx.h"
#include "RecogByHC.h"
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <combaseapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int inline area_of_rc(const RECT& r)
{
	return abs((r.right - r.left) * (r.bottom - r.left));
}
//////////////////////////////////////////////////////////////////////////
bool compareInterval(const CodeRegionInfo& i1, const CodeRegionInfo& i2)
{
	if (i1.res.size() > i2.res.size())
		return true;
	else if (i1.res.size() < i2.res.size())
		return false;
	else {
		return area_of_rc(i1.roi) > area_of_rc(i2.roi);
	}
}
//////////////////////////////////////////////////////////////////////////

CRecogByHC::CRecogByHC()
	: m_bModelInited(FALSE)
	, m_pGLBuf(NULL)
{
	
}


CRecogByHC::~CRecogByHC()
{
	if (m_pGLBuf)
		delete[] m_pGLBuf;
	m_pGLBuf = NULL;
}

BOOL CRecogByHC::InitModel()
{
	BOOL res = TRUE;
	Herror  error_num;
	try
	{
		CreateBarCodeModel(HTuple(), HTuple(), &m_tuModelHandel);
		m_bModelInited = TRUE;
		m_pGLBuf = new BYTE[MAX_WIDTH * MAX_HEIGHT * 3];

		hv_CodeType.Clear();
		hv_CodeType[0] = "EAN-13";
		hv_CodeType[1] = "Code 128";
		hv_CodeType[2] = "Code 39";
		hv_CodeType[3] = "Code 93";
		hv_CodeType[4] = "EAN-8";
		hv_CodeType[5] = "2/5 Industrial";
	}
	catch (HException &except)
	{
		error_num = except.ErrorCode();
		res = FALSE;
	}	
	
	return res;
}

int CRecogByHC::SetParam(const SvBarRecParams* param)
{
	if (param == NULL)
		return svec_invalid_param;
	memcpy(&m_params, param, sizeof(m_params));
	return svec_ok;
}

int CRecogByHC::GetParam(SvBarRecParams* param)
{
	if (param == NULL)
		return svec_invalid_param;
	memcpy(param, &m_params, sizeof(m_params));
	return svec_ok;
}

int CRecogByHC::FindAllCandiatesFromGrayBuf(BYTE* pBuf, int w, int h)
{
	Herror  error_num;
	HImage* img = NULL;
	HTuple  hv_DecodedDataStrings;
	HTuple  hv_res, hv_Area, hv_Row, hv_Column;
	HObject ho_SymbolRegions;

	// for alignment memory
	BYTE* pLine = m_pGLBuf;
	BYTE* pSrc = pBuf;
	for (int i = 0; i < h; i++, pLine += w, pSrc += w)
		memcpy(pLine, pSrc, w);

	
	m_aFounds.clear();

	try {
		img = new HImage("byte", w, h, pBuf);
	}
	catch (HException &except)
	{
		error_num = except.ErrorCode();
		return svec_cannot_alloc_image;
	}
	try {
		FindBarCode(*img, &ho_SymbolRegions, m_tuModelHandel, hv_CodeType, &hv_DecodedDataStrings);
	}
	catch (HException &except)
	{
		error_num = except.ErrorCode();
		delete img;
		return svec_raised_find_code;
	}
	try
	{
		auto kind = hv_DecodedDataStrings.Type();
		int count = hv_DecodedDataStrings.Length();
		std::vector<std::string> sn_string;
		std::vector<std::string> type_string;
		for (int i = 0; i < count; i++)
		{
			std::string s = hv_DecodedDataStrings[i].S().Text();
			sn_string.push_back(s);
			GetBarCodeResult(m_tuModelHandel, i, "decoded_types", &hv_res);
			std::string p = hv_res.S().Text();
			type_string.push_back(p);
		}

		int rgnCount = ho_SymbolRegions.CountObj();
		std::vector<std::vector<POINT>> coors;
		for (int i = 0; i < rgnCount; i++)
		{
			HTuple row, col, phi, len1, len2;
			double y = 0, x = 0;

			SmallestRectangle2(ho_SymbolRegions.SelectObj(i + 1), &row, &col, &phi, &len1, &len2);

			int nr = row.Length(), nc = col.Length();
			if (nr == nc && nc > 0)
			{
				y = row.D();
				x = col.D();
				double al = phi.D();
				double r1 = len1.D();
				double r2 = len2.D();

				POINT p1{ x + cos(-al) * (r1)-sin(-al) * (r2), y + sin(-al) * (r1)+cos(-al) * (r2) };
				POINT p2{ x + cos(-al) * (-r1) - sin(-al) * (r2), y + sin(-al) * (-r1) + cos(-al) * (r2) };
				POINT p3{ x + cos(-al) * (-r1) - sin(-al) * (-r2), y + sin(-al) * (-r1) + cos(-al) * (-r2) };
				POINT p4{ x + cos(-al) * (r1)-sin(-al) * (-r2), y + sin(-al) * (r1)+cos(-al) * (-r2) };
				std::vector<POINT> p;
				p.push_back(p1); p.push_back(p2); p.push_back(p3); p.push_back(p4);
				coors.push_back(p);
			}
		}

		if (sn_string.size() == type_string.size() && sn_string.size() == coors.size())
		{
			int n = sn_string.size();
			for (int i = 0; i < n; i++)
			{
				CodeRegionInfo aInfo;
				aInfo.res = sn_string[i];
				aInfo.type = type_string[i];
				aInfo.center.x = aInfo.center.y = 0;
				int minx = 10000, miny = 10000, maxx = 0, maxy = 0;
				for (int j = 0; j < 4; j++) {
					aInfo.corners[j] = coors[i][j];
					aInfo.center.x += coors[i][j].x;
					aInfo.center.y += coors[i][j].y;
					if (minx > aInfo.corners[j].x) minx = aInfo.corners[j].x;
					if (miny > aInfo.corners[j].y) miny = aInfo.corners[j].y;
					if (maxx < aInfo.corners[j].x) maxx = aInfo.corners[j].x;
					if (maxy < aInfo.corners[j].y) maxy = aInfo.corners[j].y;
				}
				aInfo.center.x /= 4;
				aInfo.center.y /= 4;
				aInfo.roi.left = minx, aInfo.roi.right = maxx;
				aInfo.roi.top = miny, aInfo.roi.bottom = maxy;
				m_aFounds.push_back(aInfo);
			}
		}
		else
		{
			delete img;
			return svec_mismatched_vectors;
		}
	}
	catch (HException &except)
	{
		error_num = except.ErrorCode();
		delete img;
		return svec_get_attributes;
	}

	delete img;

	return svec_ok;
}

int CRecogByHC::RecognitionFromColor(BYTE* pBuf, int w, int h, CodeRecogRes** _outRes)
{
	int wex = 4 * ((w * 24 + 31) / 32);
	BYTE* pGray = m_pGLBuf;
	BYTE* pLine = pBuf;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++)
		{
			pGray[x] = (((int)pLine[x * 3] * 215) + ((int)pLine[x * 3 + 1]*737) + ((int)pLine[x * 3 + 2]*22)) >> 10;
		}
		pLine += wex;
		pGray += w;
	}
	int res = RecognitionFromGrayBuffer(m_pGLBuf, w, h, _outRes);
	return res;
}

int CRecogByHC::RecognitionFromGrayBuffer(BYTE* pBuf, int w, int h, CodeRecogRes** _outRes)
{
	if (!m_bModelInited)
		return svec_modelfail;


	int res = FindAllCandiatesFromGrayBuf(pBuf, w, h);
	if (res < svec_ok)
		return res;

	int nCandiates = m_aFounds.size();
	if (nCandiates < 1)
		return nCandiates;

	int k = 0;
	if (m_params.minStringLength > 0) {
		for (int i = 0; i < nCandiates; i++) {
			int nres = m_aFounds[i].res.size();
			if (nres > 0 && nres < m_params.minStringLength)
				m_aFounds[i].res = "";
		}
	}

	std::sort(m_aFounds.begin(), m_aFounds.end(), compareInterval);
	std::string aFirstRes = "";
	std::string aFirstType = "";
	RECT merged;

	std::vector<CodeRecogRes> resList;
	for (int i = 0; i < nCandiates; i++) {
		if (m_aFounds[i].res.empty())
			continue;

		if (m_params.isAllSame) {
			if (aFirstRes.empty()) {
				merged = m_aFounds[i].roi;
				merged.left *= m_aFounds[i].scale;
				merged.top *= m_aFounds[i].scale;
				merged.right *= m_aFounds[i].scale;
				merged.bottom *= m_aFounds[i].scale;

				aFirstRes = m_aFounds[i].res;

				CodeRecogRes a;

				a.iOrientation = m_aFounds[i].fAngle * 180 / M_PI;
				a.rcRoi = merged;
				strcpy_s(a.sText, m_aFounds[i].res.c_str());
				strcpy_s(a.sType, m_aFounds[i].type.c_str());

				a.countRegion = 1;
				for (int j = 0; j < 4; j++) {
					a.corner_x[j] = m_aFounds[i].corners[j].x * m_aFounds[i].scale;
					a.corner_y[j] = m_aFounds[i].corners[j].y * m_aFounds[i].scale;
				}

				resList.push_back(a);
			}
			else if (m_aFounds[i].res == aFirstRes) {
				RECT curRc = m_aFounds[i].roi;
				curRc.left *= m_aFounds[i].scale;
				curRc.top *= m_aFounds[i].scale;
				curRc.right *= m_aFounds[i].scale;
				curRc.bottom *= m_aFounds[i].scale;

				merged.left = MIN(merged.left, curRc.left);
				merged.top = MIN(merged.top, curRc.top);
				merged.right = MAX(merged.right, curRc.right);
				merged.bottom = MAX(merged.bottom, curRc.bottom);

				resList[0].rcRoi = merged;
				if (MAX_REGION > resList[0].countRegion) {
					for (int j = 0; j < 4; j++) {
						resList[0].corner_x[resList[0].countRegion * 4 + j] = m_aFounds[i].corners[j].x * m_aFounds[i].scale;
						resList[0].corner_y[resList[0].countRegion * 4 + j] = m_aFounds[i].corners[j].y * m_aFounds[i].scale;
					}
					resList[0].countRegion++;
				}
			}
		} // if (m_params.isAllSame)
		else {
			CodeRecogRes a;
			a.iOrientation = m_aFounds[i].fAngle * 180 / M_PI;
			a.rcRoi = m_aFounds[i].roi;
			a.rcRoi.left *= m_aFounds[i].scale;
			a.rcRoi.top *= m_aFounds[i].scale;
			a.rcRoi.right *= m_aFounds[i].scale;
			a.rcRoi.bottom *= m_aFounds[i].scale;
			strcpy_s(a.sText, m_aFounds[i].res.c_str());
			strcpy_s(a.sType, m_aFounds[i].type.c_str());
			a.countRegion = 1;
			for (int j = 0; j < 4; j++) {
				a.corner_x[j] = m_aFounds[i].corners[j].x * m_aFounds[i].scale;
				a.corner_y[j] = m_aFounds[i].corners[j].y * m_aFounds[i].scale;
			}

			resList.push_back(a);
		} // else (m_params.isAllSame)
	}
	res = resList.size();

	*_outRes = (CodeRecogRes*)CoTaskMemAlloc(sizeof(CodeRecogRes) * res);
	for (int i = 0; i < res; i++) {
		(*_outRes)[i] = resList[i];
	}
	return res;
}
//.EOF