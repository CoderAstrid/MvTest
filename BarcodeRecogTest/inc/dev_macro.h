#ifndef __SVISION_PRJDEVE_MACROJ_H__
#define __SVISION_PRJDEVE_MACROJ_H__

#define _DEV_CAM_MODE		0		// Camera mode [7/8/2021 Jewel]
#define _DEV_USE_BARID		1		// must 1 : using bar code identify
#define _DEV_USE_CV			1


// for localization of Bar-code region
#	define	_DEV_USE_CUDA	0			// must 0
#	define  _DEV_USE_DET_BRJ		0	// Blur-resistant joint 1D and 2D bar code localization, 250
#	define  _DEV_USE_DET_DT			0	// Reading 1D barcodes with mobile phones using deformable templates, 32
#	define  _DEV_USE_DET_SRI		1	// Vision-Based 1D Barcode Localization Method for Scale and Rotation Invariant, 125

#if _DEV_USE_CV
#	define _DEV_WRIMG			0		// must 0 : write result images
#endif//_DEV_USE_CV
#	define _DEV_IMGENHANCE		1		// must 1 : using image enhancement
#	define _DEV_OMP				0		// must 1 : using OpenMP(disable)
#	define _DEV_FASTLINE		0		// must 0 : fast line detector

#define		_DEV_ANG			1
#define		_DEV_ANAL_MODE		0
#define		_DEV_PPL			1
#define		_DEV_GAUSSIAN		0

#if _DEV_USE_BARID
//#	define _BARENGINE_ZXING		// using zxing library
#	define _BARENGINE_ZXING12	// using zxing v12 library
//#	define _BARENGINE_ZBAR			// using zbar library
#endif

#endif//__SVISION_PRJDEVE_MACROJ_H__
//.EOF