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

// BCGPFrameImpl.h: interface for the CBCGPFrameImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPFRAMEIMPL_H__829B77B5_FE0E_11D1_8BCB_00A0C9B05590__INCLUDED_)
#define AFX_BCGPFRAMEIMPL_H__829B77B5_FE0E_11D1_8BCB_00A0C9B05590__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CBCGPBaseControlBar;
class CBCGPToolBar;
class CBCGPMenuBar;
class CBCGPPopupMenu;
class CBCGPRibbonBar;
class CBCGPRibbonStatusBar;
class CBCGPFrameCaptionButton;
class CBCGPRibbonBackstageView;
struct CBCGPToolbarOptions;
class CBCGPRecentFilesListBox;

#include "BCGCBPro.h"
#include "BCGPDockManager.h"
#include "BCGPFullScreenImpl.h"
#include "BCGPVisualManager.h"
#include "BCGPShadowManager.h"

class BCGCBPRODLLEXPORT CBCGPFrameImpl
{
	friend class CBCGPToolBar;
	friend class CBCGPMDIFrameWnd;
	friend class CBCGPFrameWnd;
	friend class CBCGPOleIPFrameWnd;
	friend class CBCGPOleDocIPFrameWnd;
	friend class CBCGPMenuBar;
	friend class CBCGPToolbarsPage;
	friend class CBCGPWorkspace;
	friend class CBCGPPopupMenu;
	friend class CBCGPMiniFrameWnd;
	friend class CBCGPFullScreenImpl;
	friend class CBCGPRibbonBar;
	friend class CBCGPRibbonStatusBar;
	friend class CBCGPMDIChildWnd;
	friend class CBCGPWinApp;
	friend class CBCGPShadowManager;
	friend class CBCGPWindowsNavigator;

public:
	CBCGPFrameImpl(CFrameWnd* pFrame);
	virtual ~CBCGPFrameImpl();

	void SetDockManager (CBCGPDockManager* pManager) 
	{
		ASSERT_VALID (pManager); 
		m_pDockManager = pManager;
	}

	void GetFullScreenMinMaxInfo(MINMAXINFO FAR* lpMMI)
	{
		m_FullScreenMgr.OnGetMinMaxInfo(lpMMI);
	}

	static const CList<CFrameWnd*, CFrameWnd*>& GetFrameList ()
	{
		return m_lstFrames;
	}

	static void AddFrame (CFrameWnd* pFrame);
	static void RemoveFrame (CFrameWnd* pFrame);

// Attributes:
public:
	const CBCGPMenuBar* GetMenuBar () const
	{
		return m_pMenuBar;
	}

	CBCGPMenuBar* GetMenuBar ()
	{
		return m_pMenuBar;
	}

	CBCGPRibbonBar* GetRibbonBar ()
	{
		return m_pRibbonBar;
	}

	void SetNewUserToolBarRTC(CRuntimeClass* pCustomUserToolBarRTC);
	void SetControlbarsMenuId (UINT uiViewMenuEntryID, BOOL bViewMenuShowsToolbarsOnly)
	{
		m_uiControlbarsMenuEntryID = uiViewMenuEntryID;
		m_bViewMenuShowsToolbarsOnly = bViewMenuShowsToolbarsOnly;
	}

	static BOOL			m_bControlBarExtraPixel;

	CRect GetCaptionRect ();

	const CObList& GetCaptionSysButtons () const
	{
		return m_lstCaptionSysButtons;
	}

protected:
	UINT				m_uiUserToolbarFirst;
	UINT				m_uiUserToolbarLast;

	CObList				m_listUserDefinedToolbars;
	CObList				m_listTearOffToolbars;

	CString				m_strControlBarRegEntry;

	CBCGPMenuBar*		m_pMenuBar;
	BOOL				m_bAutoCreatedMenuBar;
	HMENU				m_hDefaultMenu;
	CFrameWnd*			m_pFrame;
	BOOL				m_bIsTearOffFrame;
	BOOL				m_bIsPersistantFrame;
	CBCGPDockManager*	m_pDockManager;
	UINT				m_nIDDefaultResource;
	CBCGPFullScreenImpl	m_FullScreenMgr;
	BOOL				m_bLoadDockState;
	BOOL				m_bIsLoadingFrame;

	CRuntimeClass*		m_pCustomUserToolBarRTC;

	UINT				m_uiControlbarsMenuEntryID;
	BOOL				m_bViewMenuShowsToolbarsOnly;

	CBCGPRibbonBar*			m_pRibbonBar;
	CBCGPRibbonStatusBar*	m_pRibbonStatusBar;

	CObList				m_lstCaptionSysButtons;
	BOOL				m_bCaptured;
	UINT				m_nHotSysButton;
	UINT				m_nHitSysButton;
	CRect				m_rectRedraw;
	BOOL				m_bIsWindowRgn;
	BOOL				m_bHasBorder;
	BOOL				m_bHasCaption;
	BOOL				m_bIsMDIChildFrame;
	BOOL				m_bIsOleInPlaceActive;
	BOOL				m_bHadCaption;
	BOOL				m_bWindowPosChanging;
	BOOL				m_bDisableThemeCaption;
	BOOL				m_bPrevVisualManagerOwnerDrawCaption;
	BOOL				m_bPrevVisualManagerSmallSystemBorders;

	CBCGPRibbonBackstageView*	m_pBackstageView;

	HWND				m_hwndWindowsNavigator;
	BOOL				m_bIsWindowsNavigatorEnabled;
	UINT				m_nWindowsNextNavigationCmdID;
	UINT				m_nWindowsPrevNavigationCmdID;
	BOOL				m_bIsPrevNavigation;

// Operations
protected:

	static UINT GetFreeCtrlBarID (UINT uiFirstID, UINT uiLastID,
							const CObList& lstCtrlBars);

	// User-defined toolbars:
	void InitUserToolbars (LPCTSTR lpszRegEntry, UINT uiUserToolbarFirst, UINT uiUserToolbarLast);
	void LoadUserToolbars ();
	void SaveUserToolbars (BOOL bFrameBarsOnly = FALSE);

	const CBCGPToolBar* CreateNewToolBar (LPCTSTR lpszName);
	BOOL DeleteToolBar (CBCGPToolBar* pToolBar);

	// Tear-off toolbars:
	void AddTearOffToolbar (CBCGPBaseControlBar* pToolBar);
	void RemoveTearOffToolbar (CBCGPBaseControlBar* pToolBar);

	void LoadTearOffMenus ();
	void SaveTearOffMenus (BOOL bFrameBarsOnly = FALSE);

	void OnCloseFrame();
	void OnLoadFrame();
	void RestorePosition(CREATESTRUCT& cs);

	void StoreWindowPlacement ();

	BOOL IsPersistantFrame();

	BOOL IsDockStateValid (const CDockState& state);
	BOOL IsUserDefinedToolbar (const CBCGPToolBar* pToolBar) const;

	void SetMenuBar (CBCGPMenuBar* pMenuBar);
	CBCGPToolBar* GetUserBarByIndex (int iIndex) const;

	void SetupToolbarMenu (	CMenu& menu, 
							const UINT uiViewUserToolbarCmdFirst,
							const UINT uiViewUserToolbarCmdLast);

	BOOL ProcessKeyboard (int nKey, BOOL* pbProcessAccel = NULL);
	BOOL ProcessMouseClick (UINT uiMsg, POINT pt, HWND hwnd);
	BOOL ProcessMouseMove (POINT pt);
	BOOL ProcessMouseWheel (WPARAM wParam, LPARAM lParam);
	BOOL ProcessSysKeyUp(WPARAM wParam, LPARAM lParam);

	void FrameEnableDocking(CFrameWnd * pFrame, DWORD dwDockStyle);

	BOOL OnShowPopupMenu (CBCGPPopupMenu* pMenuPopup, CFrameWnd* pWndFrame);

	BOOL OnShowCustomizePane(CBCGPPopupMenu* /*pMenuPane*/, UINT uiToolbarID);

	BOOL OnMenuChar (UINT nChar);

	void DeactivateMenu ();

	void SetDockState (const CDockState& state);
	void SaveDockState (LPCTSTR lpszSectionName = NULL);
	void LoadDockState (LPCTSTR lpszSectionName = NULL);

	BOOL LoadLargeIconsState ();

	static BOOL IsHelpKey (LPMSG lpMsg);

	void ShowQuickCustomizePane(CBCGPPopupMenu* pMenuPopup);
	void AddDefaultButtonsToCustomizePane(CBCGPPopupMenu* pMenuPane, UINT uiToolbarID);
	BOOL IsCustomizePane(const CBCGPPopupMenu* pMenuPopup) const;

	CRect GetFullScreeen()
	{
		return m_FullScreenMgr.GetFullScreenRect();
	}

	BOOL IsFullScreeen() const
	{
		return m_FullScreenMgr.IsFullScreen();
	}

	void EnableFullScreenMainMenu(BOOL bShow = TRUE)
	{
		m_FullScreenMgr.EnableMainMenu(bShow);
	}

	void EnableFullScreenAutoHideTaskbar(BOOL bEnable = TRUE)
	{
		m_FullScreenMgr.EnableAutoHideTaskbar (bEnable);
	}

	void InvokeFullScreenCommand();

	BOOL IsPrintPreview ();

	BOOL IsOwnerDrawCaption ()
	{
		return CBCGPVisualManager::GetInstance ()->IsOwnerDrawCaption () && !m_bIsOleInPlaceActive && !m_bDisableThemeCaption;
	}

	void OnSetText (LPCTSTR lpszText);
	void OnActivateApp (BOOL bActive);
	void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	BOOL OnNcPaint();
	void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	BOOL OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	BOOL OnNcActivate (BOOL bActive);
	void UpdateCaption ();
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
	void OnChangeVisualManager ();
	void OnDWMCompositionChanged ();

	void SetRibbonBackstageView (CBCGPRibbonBackstageView* pView);
	void AdjustRibbonBackstageViewRect();
	void ActivateRibbonBackstageView();

	void CancelToolbarMode();

	BOOL SetupAutoMenuBar();
	void SetupToolbars(const CBCGPToolbarOptions& toolbarOptions);

	BOOL ProcessRibbonContextHelp();

	static CList<CFrameWnd*, CFrameWnd*>	m_lstFrames;

	void SetInputMode(BCGP_INPUT_MODE mode);
	BCGP_INPUT_MODE	m_InputMode;

	void AdjustShadow(BOOL bActive);
	CBCGPShadowManager*	m_pShadow;

	void AdjustMaximizedSize(int& cx, int& cy);
	void GetMonitorRect(CRect& rect);

	void OnSysCommand(UINT nID, LPARAM lParam);

	BOOL ActivateNextPane(BOOL bPrev, CFrameWnd* pActiveFrame);

	void EnableWindowsNavigator(BOOL bEnable);
	void EnableWindowsNavigator(UINT nNextCmdID, UINT nPrevCmdID);

	BOOL ShowWindowsNavigator(BOOL bPrev);

	BOOL IsMenuActive();

	HICON OnGetRecentFileIcon(CBCGPRecentFilesListBox* pWndListBox, const CString& strPath, int nIndex) const;
	
	void SendMessageToViews(UINT msg, WPARAM wp = 0, LPARAM lp = 0);
};

#define UserToobars	UserToolbars

extern UINT BCGM_POSTSETPREVIEWFRAME;
extern UINT BCGCBPRODLLEXPORT BCGM_ONAFTERUPDATECAPTION;
extern UINT BCGM_PRECLOSEFRAME;


#endif // !defined(AFX_BCGPFRAMEIMPL_H__829B77B5_FE0E_11D1_8BCB_00A0C9B05590__INCLUDED_)
