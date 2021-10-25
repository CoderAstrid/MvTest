#ifndef __BARCODEREC_EMGINE_CLS_HALCONJ_H__
#define __BARCODEREC_EMGINE_CLS_HALCONJ_H__

#include "RecogEngineDefine.h"
#include <vector>

// in order to link at halcon
#include "HalconCpp.h"
using namespace HalconCpp;
#pragma comment(lib, "halcon.lib")
#pragma comment(lib, "halconcpp.lib")

typedef struct tagCodeRegionInfo
{
	RECT roi;
	float fAngle;
	std::string res;
	std::string type;
	POINT center;

	float length;
	bool bFoundAngle;
	int scale;

	POINT corners[4];

	tagCodeRegionInfo()
	{
		fAngle = 0;
		scale = 1;
		length = 0;
		bFoundAngle = false;
		for (int i = 0; i < 4; i++) {
			corners[i].x = 0;
			corners[i].y = 0;
		}
	}
}CodeRegionInfo, *LPCodeRegionInfo;

class CRecogByHC
{
public:
	CRecogByHC();
	~CRecogByHC();

public:
	BOOL InitModel();
	int SetParam(const SvBarRecParams* param);
	int GetParam(SvBarRecParams* param);
	int RecognitionFromColor(BYTE* pBuf, int w, int h, CodeRecogRes** _outRes);
	int RecognitionFromGrayBuffer(BYTE* pBuf, int w, int h, CodeRecogRes** _outRes);
private:
	int FindAllCandiatesFromGrayBuf(BYTE* pBuf, int w, int h);
private:
	HTuple							m_tuModelHandel;
	HTuple							hv_CodeType;
	BOOL							m_bModelInited;
	std::vector<CodeRegionInfo>		m_aFounds;
	SvBarRecParams					m_params;
	BYTE*							m_pGLBuf;
};
#endif//__BARCODEREC_EMGINE_CLS_HALCONJ_H__
//.EOF