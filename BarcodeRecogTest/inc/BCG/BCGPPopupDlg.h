#if !defined(AFX_BCGPPOPUPDLG_H__9EC5BC9D_ED2B_4255_A14E_E130CF5E49CA__INCLUDED_)
#define AFX_BCGPPOPUPDLG_H__9EC5BC9D_ED2B_4255_A14E_E130CF5E49CA__INCLUDED_

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
// BCGPPopupDlg.h : header file
//
#include "BCGCBPro.h"

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
#include "BCGPPopupMenuBar.h"
#include "BCGPPopupMenu.h"
#include "BCGPURLLinkButton.h"
#include "BCGPRibbonButton.h"
#endif

#include "BCGPDialog.h"

#ifndef BCGP_EXCLUDE_POPUP_WINDOW

/////////////////////////////////////////////////////////////////////////////
// CBCGPPopupWndParams

class BCGCBPRODLLEXPORT CBCGPPopupWndParams
{
public:
	CBCGPPopupWndParams()
	{
		m_hIcon = NULL;
		m_nURLCmdID = 0;
		m_bOpenURLOnClick = FALSE;
		m_nXPadding = 10;
		m_nYPadding = 10;
	}

	HICON	m_hIcon;
	CString	m_strText;
	CString	m_strURL;
	UINT	m_nURLCmdID;
	BOOL	m_bOpenURLOnClick;
	int		m_nXPadding;
	int		m_nYPadding;

	const CBCGPPopupWndParams& operator= (const CBCGPPopupWndParams& src)
	{
		m_hIcon			  = src.m_hIcon;
		m_strText		  = src.m_strText;
		m_strURL		  = src.m_strURL;
		m_nURLCmdID		  = src.m_nURLCmdID;
		m_bOpenURLOnClick = src.m_bOpenURLOnClick;
		m_nXPadding		  = src.m_nXPadding;
		m_nYPadding		  = src.m_nYPadding;

		return *this;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPPopupDlg window

class CBCGPPopupWindow;

class BCGCBPRODLLEXPORT CBCGPPopupDlg : public CBCGPDialog
{
	DECLARE_DYNCREATE (CBCGPPopupDlg)

	friend class CBCGPPopupWindow;

// Construction
public:
	CBCGPPopupDlg();

	BOOL CreateFromParams (CBCGPPopupWndParams& params, CBCGPPopupWindow* pParent);

// Attributes
public:
	LPARAM GetCustomParam() const
	{
		return m_lCustomParam;
	}

protected:
	CBCGPPopupWindow*	m_pParentPopup;
	BOOL				m_bDefault;
	CBCGPPopupWndParams	m_Params;
	LPARAM				m_lCustomParam;

	CStatic				m_wndIcon;
	CStatic				m_wndText;
#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	CBCGPURLLinkButton	m_btnURL;
#else
	CMFCLinkCtrl		m_btnURL;
#endif

	CSize				m_sizeDlg;

	BOOL				m_bDontSetFocus;
	BOOL				m_bMenuIsActive;

// Operations
public:
	BOOL HasFocus () const;
	CSize GetDlgSize ();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPPopupDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBCGPPopupDlg();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPPopupDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

	virtual void OnDraw (CDC* pDC);
	virtual CSize GetExtraSize() { return CSize(0, 0); }
	virtual BOOL IsEmptyDlg() { return FALSE; }

	CSize GetOptimalTextSize (CString str);

	CSize UpdateContent(CString str);
	void UpdateLayout();
};

#endif // BCGP_EXCLUDE_POPUP_WINDOW

////////////////////////////////////////////////////////////////////////
// CBCGPDlgPopupMenuBar

class BCGCBPRODLLEXPORT CBCGPDlgPopupMenuBar : public CBCGPPopupMenuBar
{
	friend class CBCGPDlgPopupMenu;
	
	CBCGPDlgPopupMenuBar()
	{
		m_nDlgWidth = 0;
	}
	
	virtual CSize CalcSize(BOOL bVertDock)
	{
		CSize size = CBCGPPopupMenuBar::CalcSize(bVertDock);
		size.cx = max(size.cx, m_nDlgWidth);
		
		return size;
	}
	
	virtual CSize GetEmptyMenuSize() const
	{
		return CSize(0, 0);
	}
	
	int m_nDlgWidth;
};

////////////////////////////////////////////////////////////////////////
// CBCGPDlgPopupMenu

class CBCGPEdit;
class CBCGPGridPopupDlgItem;
class CBCGPMenuButton;

class BCGCBPRODLLEXPORT CBCGPDlgPopupMenu : public CBCGPPopupMenu
{
	friend class CBCGPEdit;
	friend class CBCGPGridPopupDlgItem;
	friend class CBCGPRibbonButton;
	friend class CBCGPMenuButton;
	
	DECLARE_DYNAMIC(CBCGPDlgPopupMenu)
		
public:
	CBCGPDlgPopupMenu(CBCGPEdit* pParentEdit, CRuntimeClass* pRTI, LPCTSTR lpszTemplateName);

#ifndef BCGP_EXCLUDE_GRID_CTRL
	CBCGPDlgPopupMenu(CBCGPGridPopupDlgItem* pParentItem, CRuntimeClass* pRTI, LPCTSTR lpszTemplateName);
#endif

	CBCGPDlgPopupMenu(CBCGPMenuButton* pParentButton, CRuntimeClass* pRTI, LPCTSTR lpszTemplateName);

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	CBCGPDlgPopupMenu(CBCGPRibbonButton* pParentRibbonButton, CRuntimeClass* pRTI, LPCTSTR lpszTemplateName);
#endif

	virtual ~CBCGPDlgPopupMenu();
	
	virtual BOOL HasDroppedDown() const;

protected:
	// Generated message map functions
	//{{AFX_MSG(CBCGPDlgPopupMenu)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
	virtual void RecalcLayout(BOOL bNotify = TRUE);
	virtual CBCGPPopupMenuBar* GetMenuBar() { return &m_wndMenuBar; }
	virtual CWnd* GetParentArea(CRect& rectParentBtn);

	void Initialize (CRuntimeClass* pRTI, LPCTSTR lpszTemplateName);
	
	CBCGPClosePopupDialogImpl*	m_pParentEdit;
	CBCGPDlgPopupMenuBar		m_wndMenuBar;
	CBCGPDialog*				m_pDlg;
	LPCTSTR						m_lpszTemplateName;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPPOPUPDLG_H__9EC5BC9D_ED2B_4255_A14E_E130CF5E49CA__INCLUDED_)
