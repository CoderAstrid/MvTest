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
SREXP int sv_engine_init();
// shut down engine
SREXP int sv_engine_close();

// recognition of barcode
SREXP int						// [ret] error code(at errcode.h) or size of result array 
sv_engine_rec(					
	unsigned char*		_inBuf,	// [in]  buffer of input image
	int					_inW,	// [in]  width of input image
	int					_inH,	// [in]  height of input image
	int					_inBpp, // [in]  bpp of input image(8 or 24)
	CodeRecogRes** 		_outRes	// [out] array of result
);

SREXP int sv_engine_set_codedet_algorithm(CodeDetAlgo newAlgo);
SREXP int sv_get_param(SvBarRecParams* param);
SREXP int sv_set_param(const SvBarRecParams* param);

#endif//__SVISION_BARRECENGINE_EXPORTJ_H__
//.EOF