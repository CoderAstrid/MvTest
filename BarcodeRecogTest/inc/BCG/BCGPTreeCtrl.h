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
// BCGPTreeCtrl.h : header file
//

#if !defined(AFX_BCGPTREECTRL_H__2341CBB2_8676_40E1_BAD8_F4D8F893656F__INCLUDED_)
#define AFX_BCGPTREECTRL_H__2341CBB2_8676_40E1_BAD8_F4D8F893656F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPScrollBar.h"

#ifndef BCGP_EXCLUDE_GRID_CTRL
#include "BCGPGridCtrl.h"
#endif // BCGP_EXCLUDE_GRID_CTRL

/////////////////////////////////////////////////////////////////////////////
// CBCGPTreeCtrl window

#define _NEW_MEMBERS

#ifndef TVM_SETLINECOLOR
#define TVM_SETLINECOLOR            (TV_FIRST + 40)
#endif
#ifndef TreeView_SetLineColor
#define TreeView_SetLineColor(hwnd, clr) \
    (COLORREF)SNDMSG((hwnd), TVM_SETLINECOLOR, 0, (LPARAM)(clr))
#endif

#ifndef TVM_GETLINECOLOR
#define TVM_GETLINECOLOR            (TV_FIRST + 41)
#endif

#ifndef TreeView_GetLineColor
#define TreeView_GetLineColor(hwnd) \
    (COLORREF)SNDMSG((hwnd), TVM_GETLINECOLOR, 0, 0)
#endif

class BCGCBPRODLLEXPORT CBCGPTreeCtrl : public TBCGPInternalScrollBarWrapperWnd<CTreeCtrl>
{
	DECLARE_DYNAMIC(CBCGPTreeCtrl)

// Construction
public:
	CBCGPTreeCtrl();

// Attributes
public:
	BOOL m_bVisualManagerStyle;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPTreeCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

	virtual BOOL IsInternalScrollBarThemed() const;

// Implementation
public:
	virtual ~CBCGPTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPTreeCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnBCGSetControlVMMode (WPARAM, LPARAM);
	afx_msg LRESULT OnChangeVisualManager (WPARAM, LPARAM);
	afx_msg LRESULT OnPrint(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPTreeCtrlEx

#ifndef BCGP_EXCLUDE_GRID_CTRL

class BCGCBPRODLLEXPORT CBCGPTreeCtrlEx : public CBCGPGridCtrl
{
	DECLARE_DYNAMIC(CBCGPTreeCtrlEx)

// Construction
public:
	CBCGPTreeCtrlEx();

// Attributes
public:
	CImageList* GetImageList(UINT nImageList) const;
	CImageList* SetImageList(CImageList* pImageList, int nImageListType);
	HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode) const;
	HTREEITEM GetChildItem(HTREEITEM hItem) const;
	HTREEITEM GetNextSiblingItem(HTREEITEM hItem) const;
	HTREEITEM GetPrevSiblingItem(HTREEITEM hItem) const;
	HTREEITEM GetParentItem(HTREEITEM hItem) const;
	HTREEITEM GetFirstVisibleItem() const;
	HTREEITEM GetNextVisibleItem(HTREEITEM hItem) const;
	HTREEITEM GetPrevVisibleItem(HTREEITEM hItem) const;
	HTREEITEM GetSelectedItem() const;
	HTREEITEM GetRootItem() const;
	BOOL GetItem(TVITEM* pItem) const;
	CString GetItemText(HTREEITEM hItem) const;
	BOOL GetItemImage(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;
	UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const;
	DWORD GetItemData(HTREEITEM hItem) const;
	BOOL SetItem(TVITEM* pItem);
	BOOL SetItem(HTREEITEM hItem, UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam);
	BOOL SetItemText(HTREEITEM hItem, LPCTSTR lpszItem);
	BOOL SetItemImage(HTREEITEM hItem, int nImage, int nSelectedImage);
	BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask);
	BOOL SetItemData(HTREEITEM hItem, DWORD dwData);
	BOOL ItemHasChildren(HTREEITEM hItem) const;
	CEdit* GetEditControl() const;
	UINT GetVisibleCount() const;
	BOOL GetCheck(HTREEITEM hItem) const;
	BOOL SetCheck(HTREEITEM hItem, BOOL fCheck = TRUE);

// Operations
public:
	HTREEITEM InsertItem(LPTVINSERTSTRUCT lpInsertStruct);
	HTREEITEM InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage, int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam, HTREEITEM hParent, HTREEITEM hInsertAfter);
	HTREEITEM InsertItem(LPCTSTR lpszItem, HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);
	HTREEITEM InsertItem( LPCTSTR lpszItem, int nImage, int nSelectedImage, HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);

	BOOL SetColumnValue(HTREEITEM hItem, int nSubItem, const _variant_t& varValue);
	BOOL SetColumnValue(HTREEITEM hItem, int nSubItem, const _variant_t& varValue, int nImage);
	BOOL ReplaceColumnValue(HTREEITEM hItem, int nSubItem, CBCGPGridItem* pNewItem);

	BOOL DeleteItem(HTREEITEM hItem);
	BOOL DeleteAllItems();
	BOOL Expand(HTREEITEM hItem, UINT nCode);
	BOOL Select(HTREEITEM hItem, UINT nCode);
	BOOL SelectItem(HTREEITEM hItem);
	BOOL SelectSetFirstVisible(HTREEITEM hItem);
	CEdit* EditLabel(HTREEITEM hItem);
	HTREEITEM HitTest(CPoint pt, UINT* pFlags = NULL) const;
	HTREEITEM HitTest(TVHITTESTINFO* pHitTestInfo) const;
	BOOL EnsureVisible(HTREEITEM hItem);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPTreeCtrlEx)
protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBCGPTreeCtrlEx();
	virtual BOOL IsTreeControl() const { return TRUE; }

protected:
	virtual void Init ();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPTreeCtrlEx)
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void InitStyle(DWORD style);

	HTREEITEM     TreeItem(CBCGPGridRow* pRow) const { return (HTREEITEM)pRow; }
	CBCGPGridRow* TreeItem(HTREEITEM hItem) const    { return (CBCGPGridRow*)hItem; }

	CBCGPGridRow* NextRow(CBCGPGridRow* pRow, UINT nCode) const;

	void GetPositionInsertAfter(CBCGPGridRow* pParent, CBCGPGridRow* pInsertAfter, UINT nFlags, POSITION& pos, POSITION& posParent, POSITION& posSub) const;
	POSITION GetPositionOfLastSubItem(POSITION posParent, BOOL bRecursive) const;
	POSITION InsertAfterInternal(CBCGPGridRow* pNew, POSITION pos, POSITION posParent, POSITION posSub);
};

#endif // BCGP_EXCLUDE_GRID_CTRL

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPTREECTRL_H__2341CBB2_8676_40E1_BAD8_F4D8F893656F__INCLUDED_)
