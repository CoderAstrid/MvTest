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

#if !defined(AFX_BCGPMENUPAGE_H__385604B4_DDC0_11D1_A64F_00A0C93A70EC__INCLUDED_)
#define AFX_BCGPMENUPAGE_H__385604B4_DDC0_11D1_A64F_00A0C93A70EC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MenuPage.h : header file
//

#ifndef __AFXTEMPL_H__
	#include "afxtempl.h"
#endif

#include "bcgprores.h"
#include "BCGPButton.h"
#include "BCGPStatic.h"
#include "BCGPComboBox.h"
#include "BCGPGroup.h"
#include "BCGPPropertyPage.h"

class CBCGPMenuBar;
class CBCGPPopupMenu;

/////////////////////////////////////////////////////////////////////////////
// CBCGPMenuPage dialog

class CBCGPMenuPage : public CBCGPPropertyPage
{
	DECLARE_DYNCREATE(CBCGPMenuPage)

// Construction
public:
	CBCGPMenuPage (CFrameWnd* pParentFrame = NULL, BOOL bAutoSet = FALSE);
	~CBCGPMenuPage();

// Operations
public:
	void CloseContextMenu (CBCGPPopupMenu* pMenu);
	BOOL SelectMenu (CDocTemplate* pTemplate, BOOL bSaveCurr = TRUE);

// Dialog Data
	//{{AFX_DATA(CBCGPMenuPage)
	enum { IDD = IDD_BCGBARRES_PROPPAGE3 };
	CBCGPStatic	m_wndMenuAnimationsLabel;
	CBCGPComboBox	m_wndMenuAnimations;
	CBCGPButton	m_wndMenuShadows;
	CBCGPGroup	m_wndContextFrame;
	CBCGPStatic	m_wndContextHint;
	CBCGPButton	m_wndResetMenuButton;
	CBCGPStatic	m_wndContextMenuCaption;
	CBCGPComboBox	m_wndContextMenus;
	CBCGPStatic	m_wndIcon;
	CBCGPComboBox	m_wndMenuesList;
	CString	m_strMenuDescr;
	CString	m_strContextMenuName;
	CString	m_strMenuName;
	int		m_iMenuAnimationType;
	BOOL	m_bMenuShadows;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBCGPMenuPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBCGPMenuPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMenuList();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeContextMenuList();
	afx_msg void OnResetMenu();
	afx_msg void OnBcgbarresResetFrameMenu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	void SaveMenu ();

// Attributes:
protected:
	CBCGPMenuBar*	m_pMenuBar;
	HMENU			m_hmenuCurr;
	HMENU			m_hmenuSelected;
	CBCGPPopupMenu*	m_pContextMenu;
	UINT			m_uiContextMenuResId;

	BOOL			m_bIsDefaultMDIMenu;
	static CPoint	m_ptMenuLastPos;
	BOOL			m_bAutoSet;

	CFrameWnd*		m_pParentFrame;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPMENUPAGE_H__385604B4_DDC0_11D1_A64F_00A0C93A70EC__INCLUDED_)
