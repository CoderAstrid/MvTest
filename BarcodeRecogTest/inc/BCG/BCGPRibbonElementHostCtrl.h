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

#if !defined(AFX_BCGPRIBBONELEMENTHOSTCTRL_H__0927987A_158F_4281_8BBF_5E9608360A06__INCLUDED_)
#define AFX_BCGPRIBBONELEMENTHOSTCTRL_H__0927987A_158F_4281_8BBF_5E9608360A06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BCGPRibbonElementHostCtrl.h : header file
//

#include "BCGCBPro.h"

#ifndef BCGP_EXCLUDE_RIBBON

#include "BCGPRibbonPanelMenu.h"
#include "BCGPRibbonPaletteButton.h"
#include "BCGPMultiDocTemplate.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPRibbonGalleryCtrl window

class BCGCBPRODLLEXPORT CBCGPRibbonGalleryCtrl : public CBCGPRibbonPanelMenuBar
{
	DECLARE_DYNAMIC(CBCGPRibbonGalleryCtrl)

// Construction
public:
	CBCGPRibbonGalleryCtrl();

// Attributes
public:
	void SelectItem (int nItemIndex)
	{
		m_PaletteButton.SelectItem(nItemIndex);
	}

	int GetSelectedItem () const
	{
		return m_PaletteButton.GetSelectedItem();
	}

	BOOL IsMouseClicked() const
	{
		return m_bIsMouseClicked;
	}

	void SetNotifyBySingleClick(BOOL bSet = TRUE)
	{
		m_bNotifyBySingleClick = bSet;
	}

	BOOL IsNotifyBySingleClick() const
	{
		return m_bNotifyBySingleClick;
	}

	void SetDrawSelectionAlways(BOOL bSet = TRUE)
	{
		m_PaletteButton.m_bDrawSelectionAlways = bSet;
	}

	BOOL IsDrawSelectionAlways() const
	{
		return m_PaletteButton.m_bDrawSelectionAlways;
	}

// Operations
public:
	void AddGroup (
		LPCTSTR lpszGroupName,
		UINT	uiImagesPaletteResID,
		int		cxPaletteImage,
		BOOL	bRecalcLayout = TRUE)
	{
		m_PaletteButton.AddGroup(lpszGroupName, uiImagesPaletteResID, cxPaletteImage);

		if (bRecalcLayout)
		{
			RecalcLayout();
		}
	}

	void AddGroup (				// Add owner-draw group
		LPCTSTR lpszGroupName,
		CSize	sizeIcon,
		int		nIconsNum,
		BOOL	bRecalcLayout = TRUE)
	{
		m_PaletteButton.m_bIsOwnerDraw = TRUE;
		m_PaletteButton.m_imagesPalette.SetImageSize (sizeIcon);

		m_PaletteButton.AddGroup(lpszGroupName, nIconsNum);

		if (bRecalcLayout)
		{
			RecalcLayout();
		}
	}

	int GetCount() const
	{
		return m_PaletteButton.m_nIcons;
	}

	void SetItemToolTip(int nIndex, LPCTSTR lpszToolTip)
	{
		m_PaletteButton.SetItemToolTip(nIndex, lpszToolTip);
	}

	void RemoveAll(BOOL bRecalcLayout = TRUE);
	void RecalcLayout();

	void EnsureVisible(int nItemIndex);

// Overrides
	virtual void OnDrawGalleryItem(CDC* pDC, CRect rect, int nIndex, CBCGPRibbonPaletteIcon* pIcon, COLORREF clr)
	{
		UNREFERENCED_PARAMETER(pDC);
		UNREFERENCED_PARAMETER(rect);
		UNREFERENCED_PARAMETER(nIndex);
		UNREFERENCED_PARAMETER(pIcon);
		UNREFERENCED_PARAMETER(clr);

		// Should be implemented in derived class!
		ASSERT(FALSE);
	}

	virtual BOOL OnKey (UINT nChar);
	virtual void NotifyCommand(BOOL bByMouseClick);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPRibbonGalleryCtrl)
	public:
	virtual BOOL Create(const RECT& rect, CWnd* pParentWnd, UINT nID, DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER);
	protected:
	virtual void PreSubclassWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

	void InitCtrl();

// Implementation
public:
	virtual ~CBCGPRibbonGalleryCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPRibbonGalleryCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnEnable(BOOL bEnable);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CBCGPRibbonPaletteButton	m_PaletteButton;
	BOOL						m_bIsMouseClicked;
	BOOL						m_bNotifyBySingleClick;
	CBCGPBaseRibbonElement*		m_pClicked;
};

/////////////////////////////////////////////////////////////////////////////
// CNewDocumentGallery control

class BCGCBPRODLLEXPORT CBCGPNewDocumentGalleryCtrl : public CBCGPRibbonGalleryCtrl
{
	DECLARE_DYNAMIC(CBCGPNewDocumentGalleryCtrl)

public:
	CBCGPNewDocumentGalleryCtrl();

	int AddApplicationDocTemplates(const CString strGroupName, CSize sizeItem = CSize(96, 96), CSize sizePadding = CSize(10, 10));
	BOOL CloseBackstageView();

protected:
	virtual void NotifyCommand(BOOL bByMouseClick);
	virtual void OnDrawGalleryItem (CDC* pDC, CRect rectIcon, int nIconIndex, CBCGPRibbonPaletteIcon* pIcon, COLORREF clrText);

	CArray<CBCGPMultiDocTemplate*, CBCGPMultiDocTemplate*>	m_arTemplates;
	int														m_nTemplatesGroupStartIndex;
	CSize													m_sizeTemplatePadding;
};

#endif // BCGP_EXCLUDE_RIBBON

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPRIBBONELEMENTHOSTCTRL_H__0927987A_158F_4281_8BBF_5E9608360A06__INCLUDED_)
