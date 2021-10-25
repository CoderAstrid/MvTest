//////////////////////////////////////////////////////////////////////////
/*
* definition of types used in engine
*/
//////////////////////////////////////////////////////////////////////////
#ifndef __SVISION_BARRECENGINE_DEFINEJ_H__
#define __SVISION_BARRECENGINE_DEFINEJ_H__
#include "dev_macro.h"
#include "errcode.h"

#define MAX_WIDTH		4000
#define MAX_HEIGHT		3000

#define SMALL_WIDTH		2000
#define SMALL_HEIGHT	1600
#define MAX_REGION		4

// Barcode Area Identification Algorithm
typedef enum E_CodeDetAlgo {
	e_codeDetDeformableTemplates,			// by Deformable Template
	e_codeDetScaleRotationInvariant,		// by Scale-Rotation Invariant
	e_codeDetBlurResistantJoint,			// by Blur Resistant Joint
	e_codeDetClassicIP,						// by Classical Image Processing	
	e_codeDetDnn,							// by YOLO
	eCntCodeDetAlgo
}CodeDetAlgo;

// Parameters for barcode recognition
typedef struct tagSvBarRecParams
{
	int thrMag;				// edge magnitude threshold, def: 30
	int smoothWinSz;		// size of smoothing window
	int minEdgeT;			// minimum edge threshold
	int localBlockSz;		// size of local block
	double minDensityEdgeT;	// minimum of edge density
	int maxDistLines;		// maximum of distance between lines

	bool isSmallProc;		// at 1st try with small image, default: true
	bool isFisrtFound;		// if found the 1st result, stop
	bool isFastMode;		// fast mode(no try for failed regions)

	bool isAllSame;			// if all codes are same	

	bool isShowMidRes;		// if true, show middle results
	int  marginROI;			
	int  minStringLength;	// minimum length of code string
	tagSvBarRecParams()
	{
		thrMag = 30;
		smoothWinSz = 25;
		minEdgeT = 20;
		localBlockSz = 19;
		minDensityEdgeT = 0.2;
		maxDistLines = 15;
		isSmallProc = true;
		isAllSame = true;
		isFisrtFound = false;
		isFastMode = false;
		isShowMidRes = false;
		marginROI = 280;
		minStringLength = 10;
	}
} SvBarRecParams, *LPSvBarRecParams;


// Result of barcode recognition
typedef struct tagCodeRecogRes {
#if _DEV_ANAL_MODE
	POINT	ptFirst;
	POINT	ptLast;
	BOOL	isBarcode;
#endif//_DEV_ANAL_MODE
	RECT	rcRoi;						// rectangle of code region
	int		iOrientation;				// angle of degree
	char	sText[128];					// code string
	char	sType[64];					// code type(e.g. Code128, Code 39...)

	// if all same mode, have several regions.  [8/18/2021 Astrid]
	int		countRegion;				// code-rectangle count
	int		corner_x[MAX_REGION * 4];	// code-rectangle x corner
	int		corner_y[MAX_REGION * 4];	// code-rectangle y corner
	tagCodeRecogRes() {
#if _DEV_ANAL_MODE
		memset(&ptFirst, 0, sizeof(ptFirst));
		memset(&ptLast, 0, sizeof(ptLast));
		isBarcode = FALSE;
#endif//_DEV_ANAL_MODE
		memset(&rcRoi, 0, sizeof(rcRoi));
		memset(&sText, 0, sizeof(sText));
		memset(&sType, 0, sizeof(sType));
		iOrientation = 0;

		countRegion = 0;
		memset(corner_x, 0, sizeof(corner_x));
		memset(corner_y, 0, sizeof(corner_y));
	}
}CodeRecogRes, *LPCodeRecogRes;

#endif//__SVISION_BARRECENGINE_DEFINEJ_H__
//.EOF