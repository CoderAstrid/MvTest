//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This is a part of BCGControlBar Library Professional Edition
// Copyright (C) 1998-2016 BCGSoft Ltd.
// All rights reserved.
//
// This source code can be used, distributed or modified
// only under terms and conditions 
// of the accompanying license agreement.
//*******************************************************************************
//
// BCGPProgressCtrl.h : header file
//

#if !defined(AFX_BCGPPROGRESSCTRL_H__23E0C43A_6498_403C_AB8F_7A395D9C2FA4__INCLUDED_)
#define AFX_BCGPPROGRESSCTRL_H__23E0C43A_6498_403C_AB8F_7A395D9C2FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPAnimationManager.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPProgressMarqueeObject object

class CBCGPProgressMarqueeObject : public CBCGPAnimationManager
{
	friend class CBCGPProgressCtrl;
	
	CBCGPProgressMarqueeObject();
	
	void Start(CBCGPProgressCtrl* pParent, int nIndex, int nOffset, int nMiddle, int nFinish);
	
	virtual void OnAnimationValueChanged(double dblOldValue, double dblNewValue);
	virtual void OnAnimationFinished();
	virtual void OnAnimationIdle();
	
	CBCGPProgressCtrl*	m_pParent;
	int					m_nIndex;
	int					m_nOffset;
	int					m_nFinish;
	BOOL				m_bIsFirstStep;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPProgressCtrl window

#define BCGP_PROGRESS_MARQUEE_OBJECTS	5

class BCGCBPRODLLEXPORT CBCGPProgressCtrl : public CProgressCtrl
{
	friend class CBCGPProgressMarqueeObject;

	DECLARE_DYNAMIC(CBCGPProgressCtrl)

public:
	enum BCGP_MARQUEE_STYLE
	{
		BCGP_MARQUEE_DEFAULT,	// Progress bar
		BCGP_MARQUEE_DOTS,
		BCGP_MARQUEE_GRADIENT
	};

// Construction
public:
	CBCGPProgressCtrl();

// Attributes
public:
	BOOL				m_bOnGlass;
	BOOL				m_bVisualManagerStyle;
	BCGP_MARQUEE_STYLE	m_MarqueeStyle;
	BOOL				m_bIsMarqueeStarted;

	COLORREF			m_clrMarquee;
	COLORREF			m_clrMarqueeGradient;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPProgressCtrl)
	//}}AFX_VIRTUAL

	virtual void OnAnimationIdle() {}

// Implementation
public:
	virtual ~CBCGPProgressCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPProgressCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg void OnNcPaint();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	afx_msg LRESULT OnBCGSetControlVMMode (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGSetControlAero (WPARAM, LPARAM);
	afx_msg LRESULT OnSetMarquee(WPARAM, LPARAM);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnPrintClient(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

	void DoPaint(CDC* pDC);

	int	m_nMarqueeStep;
	CBCGPProgressMarqueeObject m_MarqueeObjects[BCGP_PROGRESS_MARQUEE_OBJECTS];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPPROGRESSCTRL_H__23E0C43A_6498_403C_AB8F_7A395D9C2FA4__INCLUDED_)
