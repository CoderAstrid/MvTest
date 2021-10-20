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
// BCGPSliderCtrl.h : header file
//

#if !defined(AFX_BCGPSLIDERCTRL_H__D54F6105_98FA_4CD8_B021_C6862EEE5968__INCLUDED_)
#define AFX_BCGPSLIDERCTRL_H__D54F6105_98FA_4CD8_B021_C6862EEE5968__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPSliderCtrl window

class BCGCBPRODLLEXPORT CBCGPSliderCtrl : public CSliderCtrl
{
	DECLARE_DYNAMIC(CBCGPSliderCtrl)

// Construction
public:
	CBCGPSliderCtrl();

// Attributes
public:
	BOOL		m_bOnGlass;
	BOOL		m_bVisualManagerStyle;
	BOOL		m_bDrawFocus;

protected:
	BOOL		m_bIsThumbHighligted;
	BOOL		m_bIsThumPressed;
	BOOL		m_bTracked;
	int			m_nTicFreq;
	COLORREF	m_clrSelection;
	BOOL		m_bZoomButtons;
	CRect		m_rectZoomInBtn;
	CRect		m_rectZoomOutBtn;
	int			m_nZoomStepValue;
	int			m_nZoomButtonSize;
	UINT		m_nAutoRepeatDelay;
	BOOL		m_bAutoCommandSent;

	int			m_nPressedZoomButton;
	int			m_nHighlightedZoomButton;
	int			m_nCapturedZoomButton;

	BOOL		m_bIsDelayedLayout;

// Operations
public:
	CRect GetSelectionRect();
	
	COLORREF GetSelectionColor() const
	{
		return m_clrSelection;
	}

	void SetSelectionColor(COLORREF clrSelection, BOOL bRedraw = TRUE)
	{
		m_clrSelection = clrSelection;

		if (bRedraw && GetSafeHwnd() != NULL)
		{
			RedrawWindow();
		}
	}
	
	BOOL HasZoomButtons() const
	{
		return m_bZoomButtons;
	}

	void EnableZoomButtons(BOOL bEnable = TRUE, UINT nAutoRepeatDelay = 200, int nZoomStepValue = 0 /* Page size by default */);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPSliderCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

	virtual void OnDraw(CDC* pDC);
	virtual void DoNcPaint(CDC* pDC);

protected:
	virtual void OnDrawChannel(CDC* pDC, BOOL bVert, CRect rect, BOOL bDrawOnGlass);
	virtual void OnDrawThumb(CDC* pDC, 
		CRect rect, BOOL bIsHighlighted, BOOL bIsPressed, BOOL bIsDisabled,
		BOOL bVert, BOOL bLeftTop, BOOL bRightBottom,
		BOOL bDrawOnGlass);

	virtual void OnDrawZoomButton(CDC* pDC, CRect rect, BOOL bIsZoomOut, BOOL bIsPressed, BOOL bIsHighlighted);
	virtual void OnClickZoomButton(BOOL bIsZoomOut);

	int HitTestZoomButton(CPoint point);

// Implementation
public:
	virtual ~CBCGPSliderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPSliderCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCancelMode();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg BCGNcHitTestType OnNcHitTest(CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg LRESULT OnBCGSetControlVMMode (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGSetControlAero (WPARAM, LPARAM);
	afx_msg LRESULT OnMouseLeave(WPARAM,LPARAM);
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnPrint(WPARAM wp, LPARAM lp);
	afx_msg	LRESULT OnSetTicFreq(WPARAM wp, LPARAM);
	afx_msg LRESULT OnRedrawFrame(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPSLIDERCTRL_H__D54F6105_98FA_4CD8_B021_C6862EEE5968__INCLUDED_)
