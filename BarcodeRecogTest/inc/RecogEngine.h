#ifndef __SVISION_BARRECENGINE_EXPORTJ_H__
#define __SVISION_BARRECENGINE_EXPORTJ_H__
#include "RecogEngineDefine.h"

#ifdef _USRDLL
#	define SREXP	extern "C" __declspec(dllexport)
#else
#	define SREXP	extern "C" __declspec(dllimport)
#endif//_USRDLL

// main flowchart
// sv_engine_init -> sv_engine_rec -> sv_engine_close

// init engine
SREXP int sv_engine_init_v2();
// shut down engine
SREXP int sv_engine_close_v2();

// recognition of barcode
SREXP int						// [ret] error code(at errcode.h) or size of result array 
sv_engine_rec_v2(					
	unsigned char*		_inBuf,		// [in]  buffer of input image
	int					_inW,		// [in]  width of input image
	int					_inH,		// [in]  height of input image
	int					_inBpp,		// [in]  bpp of input image(8 or 24)
	int					_codeType,	// [in]  code recognition type(0, 1, 2, 3)
	CodeRecogRes** 		_outRes		// [out] array of result
);

SREXP int sv_engine_set_codedet_algorithm_v2(CodeDetAlgo newAlgo);
SREXP int sv_get_param_v2(SvBarRecParams* param);
SREXP int sv_set_param_v2(SvBarRecParams param);

#endif//__SVISION_BARRECENGINE_EXPORTJ_H__
//.EOF