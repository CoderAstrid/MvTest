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
// BCGPListBox.h : header file
//

#if !defined(AFX_BCGPLISTBOX_H__7E778AEF_FFBB_486D_A7B3_D25D7868F5D9__INCLUDED_)
#define AFX_BCGPLISTBOX_H__7E778AEF_FFBB_486D_A7B3_D25D7868F5D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "bcgcbpro.h"
#include "BCGPScrollBar.h"

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
#include "BCGPToolBarImages.h"
#endif

struct BCGP_LB_ITEM_DATA;

extern BCGCBPRODLLEXPORT UINT BCGM_ON_CLICK_LISTBOX_PIN;

/////////////////////////////////////////////////////////////////////////////
// CBCGPListBox window

class BCGCBPRODLLEXPORT CBCGPListBox :	public TBCGPInternalScrollBarWrapperWnd<CListBox>
{
	friend class CBCGPPropertySheet;

	DECLARE_DYNAMIC(CBCGPListBox)

// Construction
public:
	CBCGPListBox();

// Attributes
public:
	BOOL	m_bOnGlass;
	BOOL	m_bVisualManagerStyle;

	BOOL IsBackstageMode() const
	{
		return m_bBackstageMode;
	}

	virtual BOOL IsBackstagePageSelector() const
	{
		return m_bBackstageMode && m_bPropertySheetNavigator;
	}

	void SetPropertySheetNavigator(BOOL bSet = TRUE);
	BOOL IsPropertySheetNavigator() const
	{
		return m_bPropertySheetNavigator;
	}

	void EnablePins(BOOL bEnable = TRUE);
	BOOL HasPins() const
	{
		return m_bPins;
	}

	void EnableItemDescription(BOOL bEnable = TRUE, int nRows = 2);
	BOOL HasItemDescriptions() const
	{
		return m_nDescrRows > 0;
	}

	void EnableItemHighlighting(BOOL bEnable = TRUE);
	BOOL IsItemHighlightingEnabled() const
	{
		return m_bItemHighlighting;
	}

	void SetItemExtraHeight(int nExtraHeight);
	int GetItemExtraHeight() const
	{
		return m_nItemExtraHeight;
	}

	virtual BOOL IsRecentFilesListBox()	{ return FALSE; }

// Operations
public:
	BOOL SetImageList (HIMAGELIST hImageList, int nVertMargin = 2);
	BOOL SetImageList (UINT nImageListResID, int cxIcon = 16, int nVertMargin = 2, BOOL bAutoScale = FALSE);

	void SetItemImage(int nIndex, int nImageIndex);
	int GetItemImage(int nIndex) const;

	void SetItemIcon(int nIndex, HICON hIcon);
	HICON GetItemIcon(int nIndex) const;

	CSize GetItemImageSize(int nIndex) const;

	void SetItemDescription(int nIndex, const CString& strDescription);
	LPCTSTR GetItemDescription(int nIndex) const;

	void SetItemToolTip(int nIndex, const CString& strToolTip, LPCTSTR lpszDescription = NULL);
	LPCTSTR GetItemToolTip(int nIndex) const;
	LPCTSTR GetItemToolTipDescription(int nIndex) const;

	void SetItemPinned(int nIndex, BOOL bSet = TRUE, BOOL bRedraw = FALSE);
	BOOL IsItemPinned(int nIndex);
	void ResetPins();

	void SetItemColorBar(int nIndex, COLORREF color);
	COLORREF GetItemBarColor(int nIndex) const;

	void AddCaption(LPCTSTR lpszCaption);
	void AddSeparator();

	BOOL IsCaptionItem(int nIndex) const;
	BOOL IsSeparatorItem(int nIndex) const;

	void Enable(int nIndex, BOOL bEnabled = TRUE, BOOL bRedraw = TRUE);
	BOOL IsEnabled(int nIndex) const;

	void CleanUp();

	virtual int GetCheck(int /*nIndex*/) const
	{
		return 0;
	}

	virtual BOOL IsCheckEnabled(int /*nIndex*/) const
	{
		return TRUE;
	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPListBox)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

	virtual void OnClickPin(int nClickedItem);
	virtual void OnClickItem(int /*nClickedItem*/)	{}
	virtual BOOL OnReturnKey() { return FALSE; }

	virtual int GetItemMinHeight();

	virtual void OnFillBackground(CDC* pDC, CRect rectClient, COLORREF& clrTextDefault);
	virtual COLORREF OnFillItem(CDC* pDC, int nIndex, CRect rect, BOOL bIsHighlihted, BOOL bIsSelected, BOOL& bFocusRectDrawn);

	virtual void OnDrawItemContent(CDC* pDC, CRect rect, int nIndex);

	virtual int OnDrawItemName(CDC* pDC, int xStart, CRect rect, int nIndex, const CString& strName, UINT nDrawFlags);
	virtual void OnDrawItemDescription(CDC* pDC, CRect rect, int nIndex, const CString& strDescr, UINT uiDTFlags);
	virtual void OnDrawItemColorBar(CDC* pDC, CRect rect, int nIndex, COLORREF color);

	virtual COLORREF GetCaptionTextColor(int nIndex);

	virtual BOOL IsInternalScrollBarThemed() const;

// Implementation
public:
	virtual ~CBCGPListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPListBox)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNcPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnLBAddString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBGetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBInsertString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg BOOL OnSelchange();
	afx_msg LRESULT OnBCGSetControlVMMode (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGSetControlAero (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGUpdateToolTips (WPARAM, LPARAM);
	afx_msg LRESULT OnMouseLeave(WPARAM,LPARAM);
	afx_msg LRESULT OnBCGSetControlBackStageMode (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGChangeVisualManager(WPARAM, LPARAM);
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnSetFont(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnLBSetTabstops(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnLBSetCurSel(WPARAM wp, LPARAM lp);
	afx_msg BOOL OnTTNeedTipText(UINT id, NMHDR* pNMH, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

	void OnDraw(CDC* pDC);
	int HitTest(CPoint pt, BOOL* pbPin = NULL, BOOL* pbCheck = NULL);
	void RebuildToolTips();

	const BCGP_LB_ITEM_DATA* _GetItemData(int nItem) const;
	BCGP_LB_ITEM_DATA* _GetAllocItemData(int nItem);

	int DU2DP(int nDU);
	
	CRect GetCheckBoxRect(const CRect& rectItem) const;
	int GetColorBarWidth() const;

	int					m_nHighlightedItem;
	BOOL				m_bHighlightedWasChanged;
	BOOL				m_bItemHighlighting;
	int					m_nItemExtraHeight;
	int					m_nClickedItem;
	BOOL				m_bTracked;
	HIMAGELIST			m_hImageList;		// External images
	CBCGPToolBarImages	m_ImageList;
	CSize				m_sizeImage;		// Image size
	int					m_nIconCount;
	BOOL				m_bBackstageMode;
	BOOL				m_bPropertySheetNavigator;
	BOOL				m_bIsPinHighlighted;
	BOOL				m_bPins;
	BOOL				m_bIsCheckHighlighted;
	BOOL				m_bHasCheckBoxes;
	BOOL				m_bHasDescriptions;
	BOOL				m_bHasColorBars;
	int					m_nDescrRows;
	HFONT				m_hFont;
	int					m_nTextHeight;
	int					m_nVMExtraHeight;
	BOOL				m_bInAddingCaption;
	CToolTipCtrl*		m_pToolTip;
	BOOL				m_bRebuildTooltips;
	int					m_nLastScrollPos;

	CList<int, int>		m_lstCaptionIndexes;

	CArray<int, int>	m_arTabStops;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPCheckListBox window

class BCGCBPRODLLEXPORT CBCGPCheckListBox : public CBCGPListBox
{
	DECLARE_DYNAMIC(CBCGPCheckListBox)

// Construction
public:
	CBCGPCheckListBox();

// Attributes
public:
	void SetCheckStyle(UINT nCheckStyle = BS_AUTOCHECKBOX);
	UINT GetCheckStyle() const
	{
		return m_nCheckStyle;
	}

	int GetCheckCount() const;

// Operations
public:
	virtual void SetCheck(int nIndex, int nCheck, BOOL bRedraw = TRUE);
	virtual int GetCheck(int nIndex) const;

	void EnableCheck(int nIndex, BOOL bEnabled = TRUE, BOOL bRedraw = TRUE);
	virtual BOOL IsCheckEnabled(int nIndex) const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPCheckListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBCGPCheckListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPCheckListBox)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void SetSelectionCheck(int nCheck);

	UINT m_nCheckStyle;
};

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)

/////////////////////////////////////////////////////////////////////////////
//CBCGPMDITemplatesListBox window

class BCGCBPRODLLEXPORT CBCGPMDITemplatesListBox : public CBCGPListBox
{
public:
	CBCGPMDITemplatesListBox();
	
	void FillList();

	CDocTemplate* GetSelectedTemplate() const;
};

#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPLISTBOX_H__7E778AEF_FFBB_486D_A7B3_D25D7868F5D9__INCLUDED_)
