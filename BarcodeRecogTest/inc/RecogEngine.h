#ifndef __SVISION_BARRECENGINE_EXPORTJ_H__
#define __SVISION_BARRECENGINE_EXPORTJ_H__
#include "RecogEngineDefine.h"

#ifdef _USRDLL
#define SREXP	extern "C" __declspec(dllexport)
#else
#define SREXP	extern "C" __declspec(dllimport)
#endif//_USRDLL

SREXP int sv_engine_init();
SREXP int sv_engine_close();

SREXP int sv_engine_rec(unsigned char* _inBuf, int _inW, int _inH, int _inBpp, CodeRecogRes** _outRes);

SREXP int sv_engine_set_codedet_algorithm(CodeDetAlgo newAlgo);
SREXP int sv_get_param(SvBarRecParams* param);
SREXP int sv_set_param(const SvBarRecParams* param);

#endif//__SVISION_BARRECENGINE_EXPORTJ_H__
//.EOF