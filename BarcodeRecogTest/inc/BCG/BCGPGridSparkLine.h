#if !defined(AFX_BCGPGRIDSPARKLINE_H__573C359C_D1FB_446F_B60D_B5E331228237__INCLUDED_)
#define AFX_BCGPGRIDSPARKLINE_H__573C359C_D1FB_446F_B60D_B5E331228237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This is a part of the BCGControlBar Library
// Copyright (C) 1998-2016 BCGSoft Ltd.
// All rights reserved.
//
// This source code can be used, distributed or modified
// only under terms and conditions 
// of the accompanying license agreement.
//*******************************************************************************
//
// BCGPGridSparkLine.h : header file
//

#include "BCGCBPro.h"

#ifndef BCGP_EXCLUDE_GRID_CTRL

#include "BCGPGridCtrl.h"
#include "BCGPChartFormat.h"
#include "BCGPImageGaugeImpl.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPGridSparklineDataPoint object

struct BCGCBPRODLLEXPORT CBCGPGridSparklineDataPoint
{
	CBCGPGridSparklineDataPoint(double dblVal = 0.0, double dblSecondVal = 0.0)
	{
		m_dblValue = dblVal;
		m_dblValue1 = dblSecondVal;
	}

	double		m_dblValue;			// Data point value
	double		m_dblValue1;		// Data point second value (used un bubble charts)

	CBCGPBrush	m_brDataPointFill;	// Data point fill color
	CBCGPBrush	m_brDataPointBorder;// Data point border color (if empty, m_brDataPointFill will be used)

	BCGPChartMarkerOptions	m_MarkerOptions;	// Marker options: show marker or not, shape and size

	CBCGPBrush	m_brMarkerFill;		// Marker fill color
	CBCGPBrush	m_brMarkerBorder;	// Marker border color (if empty, m_brMarkerFill will be used)
};

typedef CArray<CBCGPGridSparklineDataPoint, const CBCGPGridSparklineDataPoint&> CBCGPGridSparklineDataArray;

/////////////////////////////////////////////////////////////////////////////
// CBCGPGridSparklineItem object

class BCGCBPRODLLEXPORT CBCGPGridSparklineItem : public CBCGPGridItem
{
	DECLARE_DYNCREATE(CBCGPGridSparklineItem)

public:
	enum SparklineType
	{ 
		SparklineTypeDefault = -1,
		SparklineTypeLine,
		SparklineTypeColumn,
		SparklineTypeArea,
		SparklineTypeBar,
		SparklineTypeBubble,
		SparklineTypePie,
		SparklineTypeDoughnut,
	};
		
// Construction
public:
	CBCGPGridSparklineItem(SparklineType type = SparklineTypeLine, DWORD_PTR dwData = 0);
	CBCGPGridSparklineItem(const CBCGPDoubleArray& arData, SparklineType type = SparklineTypeLine, DWORD_PTR dwData = 0);
	CBCGPGridSparklineItem(const CBCGPGridSparklineDataArray& arData, SparklineType type = SparklineTypeLine, DWORD_PTR dwData = 0);

	virtual ~CBCGPGridSparklineItem();
	
// Attributes:
public:
	void SetType(SparklineType type);
	SparklineType GetType();
	
	virtual CBCGPChartVisualObject* GetChart();
	
// Overrides
public:
	virtual void OnDrawValue (CDC* pDC, CRect rect);
	virtual void OnPrintValue (CDC* pDC, CRect rect);
	virtual BOOL OnEdit (LPPOINT lptClick);
	virtual void OnPosSizeChanged (CRect rectOld);
	virtual void OnAfterChangeGridColors();

	virtual BOOL IsChangeSelectedBackground() const
	{
		return m_bDefaultSelColor;
	}

// Operations
public:
	void AddData(const CBCGPDoubleArray& arData, int nSeries = 0, SparklineType type = SparklineTypeDefault);
	void AddData(const CBCGPGridSparklineDataArray& arData, int nSeries = 0, SparklineType type = SparklineTypeDefault);

	BOOL UpdateDataPoint(int nIndex, double dblValue, int nSeries = 0);

	BOOL ShowDataPointMarker(int nIndex, const BCGPChartMarkerOptions& markerOptions, 
		const CBCGPBrush& brFill = CBCGPBrush(), const CBCGPBrush& brBorder = CBCGPBrush(),
		int nSeries = 0);

	void RemoveData(int nSeries = -1);

protected:
	virtual void InitChart();
	virtual COLORREF GetFillColor();

	int SparklineTypeToChartType (SparklineType type);
	CBCGPChartSeries* GetSeries(int nSeries, SparklineType type);

protected:
	CBCGPChartVisualObject*	m_pChart;
	int						m_nMaxMarkerSize;
	BOOL					m_bDefaultSelColor;
};

#endif // BCGP_EXCLUDE_GRID_CTRL

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPGRIDSPARKLINE_H__573C359C_D1FB_446F_B60D_B5E331228237__INCLUDED_)
