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
// BCGPWindowsNavigator.h : header file
//

#if !defined(AFX_BCGPWINDOWSNAVIGATOR_H__8FE329B6_D0E9_4F33_B6D4_C3B2F94A3BCA__INCLUDED_)
#define AFX_BCGPWINDOWSNAVIGATOR_H__8FE329B6_D0E9_4F33_B6D4_C3B2F94A3BCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPPopupDlg.h"
#include "BCGPStatic.h"
#include "bcgprores.h"

class CBCGPWindowsNavigatorObject;

#ifndef BCGP_EXCLUDE_POPUP_WINDOW

/////////////////////////////////////////////////////////////////////////////
// CBCGPWindowsNavigator dialog

class CBCGPWindowsNavigator : public CBCGPPopupDlg
{
	DECLARE_DYNCREATE(CBCGPWindowsNavigator)

// Construction
public:
	CBCGPWindowsNavigator();
	virtual ~CBCGPWindowsNavigator();

// Dialog Data
	//{{AFX_DATA(CBCGPWindowsNavigator)
	enum { IDD = IDD_BCGBARRES_PANE_MANAGER_DLG };
	CBCGPStatic	m_wndPath;
	CStatic	m_wndViewListLocation;
	CStatic	m_wndPaneListLocation;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPWindowsNavigator)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	virtual void OnDraw (CDC* pDC);
	virtual CSize GetExtraSize() { return m_sizeExtra; }

	virtual BOOL IsEmptyDlg()
	{
		return m_arMDIChildren.GetSize() == 0 && m_arDockingPanes.GetSize() == 0;
	}

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBCGPWindowsNavigator)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void SetSel(CBCGPWindowsNavigatorObject* pSel);
	BOOL ReposItems(LPINT lpMDIColumns = NULL);

	CBCGPWindowsNavigatorObject* HitTest(CPoint pt, int* pIndex = NULL);
	void SetActive(CBCGPWindowsNavigatorObject* pPane);

	CArray<CBCGPWindowsNavigatorObject*, CBCGPWindowsNavigatorObject*>	m_arDockingPanes;
	CArray<CBCGPWindowsNavigatorObject*, CBCGPWindowsNavigatorObject*>	m_arMDIChildren;

	int								m_nMDIColumns;
	int								m_nScrollOffset1;
	int								m_nScrollOffset2;

	CBCGPWindowsNavigatorObject*	m_pSel;
	CSize							m_sizeExtra;
	BOOL							m_bIsActivePane;
	BYTE							m_nInitialVirtKeys;
	UINT							m_nNextChar;
	BYTE							m_nNextVirtKeys;
	UINT							m_nPrevChar;
	BYTE							m_nPrevVirtKeys;
};

#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPWINDOWSNAVIGATOR_H__8FE329B6_D0E9_4F33_B6D4_C3B2F94A3BCA__INCLUDED_)
