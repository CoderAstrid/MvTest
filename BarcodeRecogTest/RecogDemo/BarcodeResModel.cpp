#include "stdafx.h"
#include "BarcodeResModel.h"


CBarcodeResModel::CBarcodeResModel()
{
}


CBarcodeResModel::~CBarcodeResModel()
{
}

void CBarcodeResModel::DrawModel(CDC* pDC, const CRect& rc, int realW, int realH)
{
	int n = m_aRes.size();
	if (n > 0) {
		CPen penG(PS_SOLID, 2, RGB(0, 0, 255));
		CPen penR(PS_SOLID, 2, RGB(255, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&penG);
		CBrush* pOldBr = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		for (int i = 0; i < n; i++) {
			int x1, x2, y1, y2;
			CString s;
#if _DEV_ANAL_MODE
			x1 = m_aRes[i].ptFirst.x;
			y1 = m_aRes[i].ptFirst.y;
			x2 = m_aRes[i].ptLast.x;
			y2 = m_aRes[i].ptLast.y;

			memDC.GetDC().MoveTo(x1, y1);
			memDC.GetDC().LineTo(x2, y2);

			s.Format(_T("%d deg"), m_aRes[i].iOrientation);
			memDC.GetDC().TextOut((x1 + x2) / 2, (y1 + y2) / 2, s);
#endif//_DEV_ANAL_MODE
			x1 = m_aRes[i].rcRoi.left;
			x2 = m_aRes[i].rcRoi.right;
			y1 = m_aRes[i].rcRoi.top;
			y2 = m_aRes[i].rcRoi.bottom;

			x1 = x1 * rc.Width() / realW;
			x2 = x2 * rc.Width() / realW;
			y1 = y1 * rc.Height() / realH;
			y2 = y2 * rc.Height() / realH;

			pDC->Rectangle(x1, y1, x2, y2);
			CA2T ps(m_aRes[i].sText);
			s.Format(_T("%s"), ps.m_psz);
			pDC->TextOut((x1 + x2) / 2, (y1 + y2) / 2, s);

			if (m_aRes[i].countRegion > 0) {
				for (int j = 0; j < m_aRes[i].countRegion; j++)
				{
					POINT pts[4];
					for (int k = 0; k < 4; k++) {
						pts[k].x = m_aRes[i].corner_x[j * 4 + k] * rc.Width() / realW;
						pts[k].y = m_aRes[i].corner_y[j * 4 + k] * rc.Height() / realH;
					}
					pDC->Polygon(pts, 4);
				}
			}
		}
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBr);
	}
}

void CBarcodeResModel::SetBarcodeResult(int _cnt, CodeRecogRes* _pRes)
{
	m_aRes.clear();
	if (_pRes) {
		for (int i = 0; i < _cnt; i++) {
			m_aRes.push_back(_pRes[i]);
		}
	}
	if (m_pView)
		m_pView->Invalidate();
}