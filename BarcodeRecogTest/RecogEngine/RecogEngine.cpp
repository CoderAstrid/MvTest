// RecogEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "RecogEngine.h"
#include "RecogByHC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRecogByHC* g_engine = NULL;

int sv_engine_init_v2()
{	
	g_engine = new CRecogByHC;
	g_engine->InitModel();
	return svec_ok;
}

int sv_engine_close_v2()
{	
	if (g_engine)
		delete g_engine;
	g_engine = NULL;

	return svec_ok;
}

int sv_engine_rec_v2(unsigned char* _inBuf, int _inW, int _inH, int _inBpp, int _codeType, CodeRecogRes** _outRes) 
{
	if (_inBuf == NULL || _inW < 1 || _inH < 1)
		return svec_invalid_param;
	if (_inW > MAX_WIDTH || _inH > MAX_HEIGHT)
		return svec_too_large_image;
	if(_inBpp != 8 && _inBpp != 24)
		return svec_not_implement;
	if (_codeType <= e_codeNone || _codeType > e_codeAllType)
		return svec_not_implement;

	if (_inBpp == 8)
	{	
		return g_engine->RecognitionFromGrayBuffer(_inBuf, _inW, _inH, (CodeRecType)_codeType, _outRes);
	}
	else if (_inBpp == 24)
	{
		return g_engine->RecognitionFromColor(_inBuf, _inW, _inH, (CodeRecType)_codeType, _outRes);
	}
	return svec_ok;
}

int sv_engine_set_codedet_algorithm_v2(CodeDetAlgo newAlgo)
{
	return svec_ok;
}

int sv_get_param_v2(SvBarRecParams* param)
{
	if (g_engine == NULL)
		return svec_modelfail;
	return g_engine->GetParam(param);
}

int sv_set_param_v2(SvBarRecParams param)
{
	if (g_engine == NULL)
		return svec_modelfail;
	return g_engine->SetParam(&param);
}
//.EOF