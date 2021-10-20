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
// BCGPDlgImpl.h: interface for the CBCGPDlgImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPDLGIMPL_H__18772215_4E74_4900_82E4_288CA46AB7E0__INCLUDED_)
#define AFX_BCGPDLGIMPL_H__18772215_4E74_4900_82E4_288CA46AB7E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGGlobals.h"
#include "BCGPVisualManager.h"
#include "BCGPLayout.h"

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
#include "BCGPShadowManager.h"
#endif

class CBCGPPopupMenu;
class CBCGPFrameCaptionButton;

struct BCGCBPRODLLEXPORT CBCGPControlInfoTip
{
	enum BCGPControlInfoTipStyle
	{
		BCGPINFOTIP_Info = 0,
		BCGPINFOTIP_Error,
		BCGPINFOTIP_Shield,
		BCGPINFOTIP_Ok,
		BCGPINFOTIP_Custom = 999,
	};

	CBCGPControlInfoTip(CWnd* pWnd = NULL, LPCTSTR lpszText = NULL, DWORD dwVertAlign = DT_TOP, BCGPControlInfoTipStyle style = BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0))
	{
		m_hWnd = pWnd->GetSafeHwnd();
		m_dwVertAlign = dwVertAlign;
		m_rect.SetRectEmpty();
		m_style = style;
		m_bIsClickable = bIsClickable;
		m_ptOffset = ptOffset;

		m_strText = (lpszText == NULL) ? _T("") : lpszText;

		int nIndex = m_strText.Find (_T('\n'));
		if (nIndex >= 0)
		{
			m_strDescription = m_strText.Mid (nIndex + 1);
			m_strText = m_strText.Left(nIndex);
		}
	}

	HWND					m_hWnd;
	CString					m_strText;
	CString					m_strDescription;
	DWORD					m_dwVertAlign;
	CRect					m_rect;
	BCGPControlInfoTipStyle	m_style;
	BOOL					m_bIsClickable;
	CPoint					m_ptOffset;
};

class BCGCBPRODLLEXPORT CBCGPDlgImpl  
{
	friend class CBCGPDialog;
    friend class CBCGPMessageBox;
	friend class CBCGPPropertyPage;
	friend class CBCGPPropertySheet;
	friend class CBCGPDialogBar;
	friend class CBCGPFormView;
	friend class CBCGPShadowManager;
	friend class CBCGPProgressDlg;
	friend class CBCGPVisualManager2007;
	friend class CBCGPVisualManagerCarbon;
	friend class CBCGPGlobalUtils;

public:
	enum BCGPControlClass
	{
		BCGPCONTROLSCLASS_First = 0,		
		BCGPCONTROLSCLASS_Button = 0,		// CBCGPButton
		BCGPCONTROLSCLASS_GroupBox = 1,		// CBCGPGroup
		BCGPCONTROLSCLASS_Progress = 2,		// CBCGPProgressCtrl
		BCGPCONTROLSCLASS_TrackBar = 3,		// CBCGPSliderCtrl
		BCGPCONTROLSCLASS_Edit = 4,			// CBCGPEdit
		BCGPCONTROLSCLASS_ComboBox = 5,		// CBCGPComboBox
		BCGPCONTROLSCLASS_ScrollBar = 6,	// CBCGPScrollBar
		BCGPCONTROLSCLASS_UpDown = 7,		// CBCGPSpinButtonCtrl
		BCGPCONTROLSCLASS_Static = 8,		// CBCGPStatic
		BCGPCONTROLSCLASS_Last = BCGPCONTROLSCLASS_Static,
	};

	static void SetSubclassControlRTI(BCGPControlClass idClass, CRuntimeClass* pRTI);

protected:
	CBCGPDlgImpl(CWnd& dlg);
	virtual ~CBCGPDlgImpl();

	static LRESULT CALLBACK BCGDlgMouseProc (int nCode, WPARAM wParam, LPARAM lParam);

	void SetActiveMenu (CBCGPPopupMenu* pMenu);

	BOOL ProcessMouseClick (POINT pt);
	BOOL ProcessMouseMove (POINT pt);

	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL OnCommand (WPARAM wParam, LPARAM lParam);
	void OnNcActivate (BOOL& bActive);
	void OnActivate(UINT nState, CWnd* pWndOther);

	CWnd* CreateSubclassedCtrl(BCGPControlClass idClass);
	void EnableVisualManagerStyle (BOOL bEnable, BOOL bNCArea = FALSE, const CList<UINT,UINT>* plstNonSubclassedItems = NULL);

	void OnDestroy ();
	void OnDWMCompositionChanged ();

	BOOL EnableAero (BCGPMARGINS& margins);
	void GetAeroMargins (BCGPMARGINS& margins) const;
	BOOL HasAeroMargins () const;
	void ClearAeroAreas (CDC* pDC);

	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	BOOL OnNcPaint();
	BOOL OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	void UpdateCaption ();
	void UpdateCaptionButtons ();
	UINT OnNcHitTest (CPoint point);
	void OnNcMouseMove(UINT nHitTest, CPoint point);
	void OnLButtonDown(CPoint point);
	void OnLButtonUp(CPoint point);
	void OnMouseMove(CPoint point);
	CBCGPFrameCaptionButton* GetSysButton (UINT nHit);

	void SetHighlightedSysButton (UINT nHitTest);
	void OnTrackCaptionButtons (CPoint point);
	void StopCaptionButtonsTracking ();
	void RedrawCaptionButton (CBCGPFrameCaptionButton* pBtn);

	void DrawBackgroundImage(CDC* pDC, CRect rectClient);

	void SetControlInfoTip(UINT nCtrlID, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));
	void SetControlInfoTip(CWnd* pWndCtrl, LPCTSTR lpszInfoTip, DWORD dwVertAlign = DT_TOP, BOOL bRedrawInfoTip = FALSE, CBCGPControlInfoTip::BCGPControlInfoTipStyle style = CBCGPControlInfoTip::BCGPINFOTIP_Info, BOOL bIsClickable = FALSE, const CPoint& ptOffset = CPoint(0, 0));

	void GetControlInfoTipRect(CWnd* pWndCtrl, CRect& rect, DWORD dwVertAlign, const CPoint& ptOffset);
	void DrawControlInfoTips(CDC* pDC);
	BOOL ProcessInfoTipClick(CPoint point);

	BOOL OnSetCursor();

	void CreateTooltipInfo();
	void UpdateToolTipsRect();

	HWND GetControlInfoTipFromPoint(CPoint point, CString& strInfo, CString& strDescription, BOOL& bIsClickable);
	BOOL OnNeedTipText(UINT id, NMHDR* pNMH, LRESULT* pResult);

	BOOL IsOwnerDrawCaption ()
	{
		if (m_Dlg.GetSafeHwnd() != NULL && m_Dlg.GetMenu() != NULL)
		{
			return FALSE;
		}

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
		return m_bVisualManagerStyle && m_bVisualManagerNCArea && CBCGPVisualManager::GetInstance ()->IsOwnerDrawCaption ();
#else
		return m_bVisualManagerStyle && m_bVisualManagerNCArea && CMFCVisualManager::GetInstance ()->IsOwnerDrawCaption ();
#endif
	}

	CRect GetCaptionRect ();
	void OnChangeVisualManager ();
	void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	void OnGetMinMaxInfo (MINMAXINFO FAR* lpMMI);

	int GetCaptionHeight ();

	void EnableLayout(BOOL bEnable = TRUE, CRuntimeClass* pRTC = NULL, BOOL bResizeBox = TRUE);
	BOOL IsLayoutEnabled() const
	{
		return m_pLayout != NULL;
	}

	void EnableDragClientArea(BOOL bEnable = TRUE);
	BOOL IsDragClientAreaEnabled() const
	{
		return m_bDragClientArea;
	}

	int OnCreate();

	void DrawResizeBox(CDC* pDC);
	void AdjustControlsLayout();

	void EnableBackstageMode();

	BOOL LoadPlacement(LPCTSTR lpszProfileName = NULL);
	BOOL SavePlacement(LPCTSTR lpszProfileName = NULL);
	BOOL SetPlacement(WINDOWPLACEMENT& wp);

	BOOL GetPlacementSection(LPCTSTR lpszProfileName, CString& strSection);

	CWnd&					m_Dlg;
	BOOL					m_bDisableShadows;
	static HHOOK			m_hookMouse;
	static CBCGPDlgImpl*	m_pMenuDlgImpl;
	BOOL					m_bVisualManagerStyle;
	BOOL					m_bVisualManagerNCArea;
	CArray<CWnd*, CWnd*>	m_arSubclassedCtrls;
	BCGPMARGINS				m_AeroMargins;
	BOOL					m_bTransparentStaticCtrls;
	CObList					m_lstCaptionSysButtons;
	UINT					m_nHotSysButton;
	UINT					m_nHitSysButton;
	CRect					m_rectRedraw;
	BOOL					m_bWindowPosChanging;
	BOOL					m_bIsWindowRgn;
	BOOL					m_bHasBorder;
	BOOL					m_bHasCaption;
	BOOL					m_bIsWhiteBackground;
	BOOL					m_bDragClientArea;
	CToolTipCtrl*			m_pToolTipInfo;

	static CMap<BCGPControlClass,BCGPControlClass,CRuntimeClass*,CRuntimeClass*>	m_mapSubclassedCtrlsRTI;
	CList<UINT,UINT>		m_lstNonSubclassedItems;
	CStringList				m_lstNonSubclassedWndClasses;

	CMap<UINT,UINT,CBCGPControlInfoTip, const CBCGPControlInfoTip&>	m_mapCtrlInfoTipDelayed;
	CMap<HWND,HWND,CBCGPControlInfoTip, const CBCGPControlInfoTip&>	m_mapCtrlInfoTip;
	HWND					m_hwndInfoTipCurr;
	CBCGPToolBarImages		m_InfotipIcons;

	CBCGPControlsLayout*	m_pLayout;
	MINMAXINFO				m_LayoutMMI;
	CRect					m_rectResizeBox;
	BOOL					m_bResizeBox;
	BOOL					m_bBackstageMode;
	BOOL					m_bLoadWindowPlacement;
	BOOL					m_bWindowPlacementIsSet;
	CString					m_strWindowPlacementProfile;

	CBCGPToolBarImages		m_Background;
	int						m_BkgrLocation;

	void AdjustShadow(BOOL bActive);
	CBCGPShadowManager*	m_pShadow;

	void OnSysCommand(UINT nID, LPARAM lParam);
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPClosePopupDialogImpl

class BCGCBPRODLLEXPORT CBCGPClosePopupDialogImpl
{
public:
	virtual void ClosePopupDlg(LPCTSTR lpszEditValue, BOOL bOK, DWORD_PTR dwUserData = 0) = 0;
	
	virtual void OnDestroyPopupDlg() = 0;
	virtual CWnd* GetParentArea(CRect& rectParentBtn) = 0;
	virtual void GetParentText(CString& strEditValue) = 0;
	virtual void SetParentText(const CString& strEditValue) = 0;
};

class CBCGPEdit;
class CBCGPGridPopupDlgItem;

class BCGCBPRODLLEXPORT CBCGPParentEditPtr : public CBCGPClosePopupDialogImpl
{
	friend class CBCGPEdit;
	
public:
	CBCGPParentEditPtr (CBCGPEdit* pParentEdit) : m_pParentEdit (pParentEdit) {}
	
	virtual void ClosePopupDlg(LPCTSTR lpszEditValue, BOOL bOK, DWORD_PTR dwUserData = 0);
	virtual void OnDestroyPopupDlg();
	virtual CWnd* GetParentArea(CRect& rectParentBtn);
	virtual void GetParentText(CString& strEditValue);
	virtual void SetParentText(const CString& strEditValue);
	
protected:
	CBCGPEdit* m_pParentEdit;
};

#ifndef BCGP_EXCLUDE_GRID_CTRL

class CBCGPParentGridItemPtr : public CBCGPClosePopupDialogImpl
{
	friend class CBCGPGridPopupDlgItem;
	
public:
	CBCGPParentGridItemPtr (CBCGPGridPopupDlgItem* pParentItem) : m_pParentGridItem (pParentItem) {}
	
	virtual void ClosePopupDlg(LPCTSTR lpszEditValue, BOOL bOK, DWORD_PTR dwUserData = 0);
	virtual void OnDestroyPopupDlg();
	virtual CWnd* GetParentArea(CRect& rectParentBtn);
	virtual void GetParentText(CString& strEditValue);
	virtual void SetParentText(const CString& strEditValue);
	
protected:
	CBCGPGridPopupDlgItem* m_pParentGridItem;
};

#endif

class CBCGPParentMenuButtonPtr : public CBCGPClosePopupDialogImpl
{
	friend class CBCGPMenuButton;
	
public:
	CBCGPParentMenuButtonPtr(CBCGPMenuButton* pParentButton) : m_pParentMenuButton(pParentButton) {}
	
	virtual void ClosePopupDlg(LPCTSTR lpszEditValue, BOOL bOK, DWORD_PTR dwUserData = 0);
	virtual void OnDestroyPopupDlg();
	virtual CWnd* GetParentArea(CRect& rectParentBtn);
	virtual void GetParentText(CString& strEditValue);
	virtual void SetParentText(const CString& strEditValue);
	
protected:
	CBCGPMenuButton* m_pParentMenuButton;
};

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_) && (!defined BCGP_EXCLUDE_RIBBON)

class BCGCBPRODLLEXPORT CBCGPParentRibbonButtonPtr : public CBCGPClosePopupDialogImpl
{
	friend class CBCGPRibbonButton;
	
public:
	CBCGPParentRibbonButtonPtr(CBCGPRibbonButton* pParentRibbonButton) : m_pParentRibbonButton (pParentRibbonButton) {}
	
	virtual void ClosePopupDlg(LPCTSTR lpszEditValue, BOOL bOK, DWORD_PTR dwUserData = 0);
	virtual void OnDestroyPopupDlg();
	virtual CWnd* GetParentArea(CRect& rectParentBtn);
	virtual void GetParentText(CString& strEditValue);
	virtual void SetParentText(const CString& strEditValue);
	
protected:
	CBCGPRibbonButton* m_pParentRibbonButton;
};

#endif

extern BCGCBPRODLLEXPORT UINT BCGM_ONSETCONTROLAERO;
extern BCGCBPRODLLEXPORT UINT BCGM_ONSETCONTROLVMMODE;
extern BCGCBPRODLLEXPORT UINT BCGM_ONSETCONTROLBACKSTAGEMODE;
extern BCGCBPRODLLEXPORT UINT BCGM_ONCLICKINFOTIP;
extern BCGCBPRODLLEXPORT UINT BCGM_ONDRAWCUSTOMINFOTIP;

#endif // !defined(AFX_BCGPDLGIMPL_H__18772215_4E74_4900_82E4_288CA46AB7E0__INCLUDED_)
