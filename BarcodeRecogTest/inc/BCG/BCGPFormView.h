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
// BCGPFormView.h : header file
//

#if !defined(AFX_BCGPFORMVIEW_H__F08F0347_F179_4EC1_AD1F_E42BC29856F7__INCLUDED_)
#define AFX_BCGPFORMVIEW_H__F08F0347_F179_4EC1_AD1F_E42BC29856F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBCGPFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "bcgcbpro.h"
#include "bcgpdlgimpl.h"
#include "BCGPScrollBar.h"

#pragma warning (push) 
#pragma warning (disable : 4355)

template<>
inline TBCGPInternalScrollBarWrapperWnd<CFormView>::TBCGPInternalScrollBarWrapperWnd()
    : CFormView((LPCTSTR)NULL)
    , CBCGPInternalScrollBarWrapper(this)
{
    ASSERT(FALSE);
}

template<>
inline TBCGPInternalScrollBarWrapperWnd<CFormView>::TBCGPInternalScrollBarWrapperWnd(LPCTSTR lpszParam)
    : CFormView(lpszParam)
    , CBCGPInternalScrollBarWrapper(this)
{
}

template<>
inline TBCGPInternalScrollBarWrapperWnd<CFormView>::TBCGPInternalScrollBarWrapperWnd(UINT nIDParam)
    : CFormView(nIDParam)
    , CBCGPInternalScrollBarWrapper(this)
{
}

#pragma warning (pop)

class BCGCBPRODLLEXPORT CBCGPFormView : public TBCGPInternalScrollBarWrapperWnd<CFormView>
{
protected:
	DECLARE_DYNAMIC(CBCGPFormView)

protected:      // must derive your own class
	CBCGPFormView(LPCTSTR lpszTemplateName);
	CBCGPFormView(UINT nIDTemplate);

// Form Data
public:

// Attributes
public:
	void EnableVisualManagerStyle (BOOL bEnable = TRUE, const CList<UINT,UINT>* plstNonSubclassedItems = NULL);
	BOOL IsVisualManagerStyle () const
	{
		return m_Impl.m_bVisualManagerStyle;
	}

	void SetWhiteBackground(BOOL bSet = TRUE);
	BOOL IsWhiteBackground() const
	{
		return m_Impl.m_bIsWhiteBackground;
	}

	// Layout:
	void EnableLayout(BOOL bEnable = TRUE, CRuntimeClass* pRTC = NULL)
	{
		m_Impl.EnableLayout(bEnable, pRTC, FALSE);
	}

	BOOL IsLayoutEnabled() const
	{
		return m_Impl.IsLayoutEnabled();
	}

	CBCGPControlsLayout* GetLayout()
	{
		return m_Impl.m_pLayout;
	}

	virtual void AdjustControlsLayout()
	{
		m_Impl.AdjustControlsLayout();
	}

	BOOL IsInitDlgCompleted() const
	{
		return m_bInitDlgCompleted;
	}

	void SetControlInfoTip(UINT nCtrlID, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));
	void SetControlInfoTip(CWnd* pWndCtrl, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));

	CWnd* GetInfoTipControl() const
	{
		return CWnd::FromHandle(m_Impl.m_hwndInfoTipCurr);
	}

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPFormView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

	virtual BOOL IsInternalScrollBarThemed() const;

// Implementation
protected:
	virtual ~CBCGPFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CBCGPFormView)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnChangeVisualManager (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGUpdateToolTips (WPARAM, LPARAM);
	afx_msg BOOL OnNeedTipText(UINT id, NMHDR* pNMH, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

	CBCGPDlgImpl	m_Impl;
	BOOL			m_bInitDlgCompleted;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPScrollView view

class BCGCBPRODLLEXPORT CBCGPScrollView : public TBCGPInternalScrollBarWrapperWnd<CScrollView>
{
	DECLARE_DYNAMIC(CBCGPScrollView)

// Constructors
protected:
	CBCGPScrollView()
	{
	}


// Overrides
public:
	virtual BOOL IsInternalScrollBarThemed() const;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPFORMVIEW_H__F08F0347_F179_4EC1_AD1F_E42BC29856F7__INCLUDED_)
