#if !defined(AFX_BCGPSPLITTERWND_H__20AD33F0_E3A3_4D62_8D7E_65E6E11C69DC__INCLUDED_)
#define AFX_BCGPSPLITTERWND_H__20AD33F0_E3A3_4D62_8D7E_65E6E11C69DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BCGPSplitterWnd.h : header file
//

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
// CBCGPSplitterWnd window

#include "BCGCBPro.h"

class BCGCBPRODLLEXPORT CBCGPSplitterWnd : public CSplitterWnd
{
	friend class CBCGPFrameImpl;

	DECLARE_DYNAMIC(CBCGPSplitterWnd)

// Construction
public:
	CBCGPSplitterWnd();

// Attributes
protected:
	BOOL m_bCyclicPaneActivation;

// Operations
public:
	BOOL ActivateFirstPane();
	BOOL ActivateLastPane();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPSplitterWnd)
	//}}AFX_VIRTUAL

	virtual void OnDrawSplitter (CDC* pDC, ESplitType nType, const CRect& rect);
	virtual void RecalcLayout();    // call after changing sizes
	virtual BOOL CanActivateNext(BOOL bPrev = FALSE);

// Implementation
public:
	virtual ~CBCGPSplitterWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPSplitterWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPSPLITTERWND_H__20AD33F0_E3A3_4D62_8D7E_65E6E11C69DC__INCLUDED_)
