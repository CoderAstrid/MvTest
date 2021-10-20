#if !defined(AFX_BCGPPROPERTYPAGE_H__A3843CA0_4B87_4A2D_8B53_FDD20BB95C10__INCLUDED_)
#define AFX_BCGPPROPERTYPAGE_H__A3843CA0_4B87_4A2D_8B53_FDD20BB95C10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

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
// BCGPPropertyPage.h : header file
//

#include "BCGCBPro.h"
#include "bcgpdlgimpl.h"

class CBCGPPropSheetCategory;
class CBCGPToolBarImages;

/////////////////////////////////////////////////////////////////////////////
// CBCGPPropertyPage window

class BCGCBPRODLLEXPORT CBCGPPropertyPage : public CPropertyPage
{
	friend class CBCGPPopupMenu;
	friend class CBCGPContextMenuManager;
	friend class CBCGPDropDownList;
	friend class CBCGPPropertySheet;
	friend class CBCGPRibbonBackstageViewItemForm;
	friend class CBCGPRibbonBackstageViewItemPropertySheet;

	DECLARE_DYNCREATE(CBCGPPropertyPage)

// Construction
public:
	CBCGPPropertyPage();
	CBCGPPropertyPage(UINT nIDTemplate, UINT nIDCaption = 0);
	CBCGPPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption = 0);
	~CBCGPPropertyPage();

// Attributes
public:
	void EnableVisualManagerStyle (BOOL bEnable = TRUE, const CList<UINT,UINT>* plstNonSubclassedItems = NULL);
	virtual BOOL IsVisualManagerStyle () const
	{
		return m_Impl.m_bVisualManagerStyle;
	}

	// Layout:
	void EnableLayout(BOOL bEnable = TRUE, CRuntimeClass* pRTC = NULL);
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

	BOOL IsBackstageMode() const
	{
		return m_Impl.m_bBackstageMode;
	}

	void SetPageIcon(HICON hIcon);

	HICON GetPageIcon() const
	{
		return m_hIcon;
	}

	void SetControlInfoTip(UINT nCtrlID, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));
	void SetControlInfoTip(CWnd* pWndCtrl, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));

	CWnd* GetInfoTipControl() const
	{
		return CWnd::FromHandle(m_Impl.m_hwndInfoTipCurr);
	}

	enum BackgroundLocation
	{
		BACKGR_TILE,
		BACKGR_TOPLEFT,
		BACKGR_TOPRIGHT,
		BACKGR_BOTTOMLEFT,
		BACKGR_BOTTOMRIGHT,
	};

	void SetBackgroundImage (HBITMAP hBitmap, BackgroundLocation location = BACKGR_TILE, BOOL bAutoDestroy = TRUE, BOOL bRepaint = TRUE);
	BOOL SetBackgroundImage (UINT uiBmpResId, BackgroundLocation location = BACKGR_TILE, BOOL bRepaint = TRUE);

// Dialog Data
	//{{AFX_DATA(CBCGPPropertyPage)
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBCGPPropertyPage)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnSetActive();
	virtual BOOL OnApply();
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBCGPPropertyPage)
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnNcPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnRedrawHeader(WPARAM, LPARAM);
	afx_msg LRESULT OnChangeVisualManager (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGUpdateToolTips (WPARAM, LPARAM);
	afx_msg BOOL OnNeedTipText(UINT id, NMHDR* pNMH, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

	void SetActiveMenu (CBCGPPopupMenu* pMenu);
	void CommonInit ();

	void SetHeaderRect();

	void EnableBackstageMode()
	{
		m_Impl.EnableBackstageMode();
	}

	CBCGPDlgImpl			m_Impl;
	CBCGPPropSheetCategory*	m_pCategory;
	int						m_nIcon;
	HICON					m_hIcon;
	int						m_nSelIconNum;
	HTREEITEM				m_hTreeNode;
	BOOL					m_bIsAeroWizardPage;
	CRect					m_rectHeader;
	CRect					m_rectBackstageWatermark;
	CBCGPToolBarImages*		m_pBackstageWatermark;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPPROPERTYPAGE_H__A3843CA0_4B87_4A2D_8B53_FDD20BB95C10__INCLUDED_)
