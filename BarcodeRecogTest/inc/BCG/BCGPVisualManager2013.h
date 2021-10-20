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
// BCGPVisualManager2013.h: interface for the CBCGPVisualManager2013 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPVISUALMANAGER2013_H__E0C4C3FF_13B6_4956_9E0C_4692963F5E15__INCLUDED_)
#define AFX_BCGPVISUALMANAGER2013_H__E0C4C3FF_13B6_4956_9E0C_4692963F5E15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGPVisualManagerVS2012.h"

//////////////////////////////////////////////////////////////////////////////
// CBCGPVisualManager2013

class BCGCBPRODLLEXPORT CBCGPVisualManager2013 : public CBCGPVisualManagerVS2012
{
	DECLARE_DYNCREATE(CBCGPVisualManager2013)

public:
	enum Style
	{
		Office2013_White,
		Office2013_Gray,
		Office2013_DarkGray,
	};
	
	static void SetStyle(Style style);
	static Style GetStyle() { return m_Style; }
	
	CBCGPVisualManager2013();
	virtual ~CBCGPVisualManager2013();

	virtual void OnUpdateSystemColors ();
	virtual void ModifyGlobalColors ();
	virtual void SetupColors();

	virtual COLORREF GetNCBorderColor(BOOL bActive);

	virtual BOOL IsDarkTheme () const { return FALSE; }
	virtual BOOL IsAutoGrayscaleImages() { return FALSE; }

	virtual COLORREF OnDrawMenuLabel (CDC* pDC, CRect rect);
	virtual void OnDrawMenuImageRectBorder (CDC* pDC, CBCGPToolbarButton* pButton, CRect rect, CBCGPVisualManager::BCGBUTTON_STATE state);
	virtual void OnFillMenuImageRect (CDC* pDC, CBCGPToolbarButton* pButton, CRect rect, CBCGPVisualManager::BCGBUTTON_STATE state);

	virtual void OnScrollBarDrawThumb (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bDisabled);
	
	virtual void OnScrollBarDrawButton (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	virtual void OnScrollBarFillBackground (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	virtual COLORREF OnDrawControlBarCaption (CDC* pDC, CBCGPDockingControlBar* pBar, 
		BOOL bActive, CRect rectCaption, CRect rectButtons);

	virtual void OnDrawBarGripper (CDC* pDC, CRect rectGripper, BOOL bHorz, CBCGPBaseControlBar* pBar);
	virtual void OnDrawControlBarCaptionText (CDC* pDC, CBCGPDockingControlBar* pBar, BOOL bActive, const CString& strTitle, CRect& rectCaption);

	virtual void OnDrawCaptionButton (CDC* pDC, CBCGPCaptionButton* pButton, BOOL bActive, BOOL bHorz,
		BOOL bMaximized, BOOL bDisabled, int nImageID = -1);
	
	virtual void OnDrawCaptionButtonIcon (CDC* pDC, 
		CBCGPCaptionButton* pButton,
		CBCGPMenuImages::IMAGES_IDS id,
		BOOL bActive, BOOL bDisabled,
		CPoint ptImage);

	virtual void OnHighlightRarelyUsedMenuItems (CDC* pDC, CRect rectRarelyUsed);
	virtual COLORREF GetHighlightedMenuItemTextColor (CBCGPToolbarMenuButton* pButton);	
	virtual COLORREF GetToolbarButtonTextColor (CBCGPToolbarButton* pButton, CBCGPVisualManager::BCGBUTTON_STATE state);
	virtual int GetMenuDownArrowState (CBCGPToolbarMenuButton* pButton, BOOL bHightlight, BOOL bPressed, BOOL bDisabled);

	virtual COLORREF OnFillMiniFrameCaption (CDC* pDC, CRect rectCaption, 
		CBCGPMiniFrameWnd* pFrameWnd,
		BOOL bActive);
	virtual void OnDrawMiniFrameBorder (CDC* pDC, CBCGPMiniFrameWnd* pFrameWnd,
		CRect rectBorder, CRect rectBorderSize);

	virtual BOOL UseLargeCaptionFontInDockingCaptions();
	virtual BOOL IsRibbonBackstageWhiteBackground()		{	return TRUE;	}

	virtual COLORREF OnFillListBox(CDC* pDC, CBCGPListBox* pListBox, CRect rectClient);
	virtual COLORREF OnFillListBoxItem (CDC* pDC, CBCGPListBox* pListBox, int nItem, CRect rect, BOOL bIsHighlihted, BOOL bIsSelected);
	virtual int GetListBoxItemExtraHeight(CBCGPListBox* pListBox);
	virtual BOOL IsUnderlineListBoxCaption(CBCGPListBox* pListBox);
	virtual COLORREF GetListBoxCaptionTextColor(CBCGPListBox* pListBox, int nIndex);
	
	virtual COLORREF OnFillComboBoxItem(CDC* pDC, CBCGPComboBox* pComboBox, int nIndex, CRect rect, BOOL bIsHighlihted, BOOL bIsSelected);

	virtual void OnDrawComboBorder (CDC* pDC, CRect rect,
		BOOL bDisabled,
		BOOL bIsDropped,
		BOOL bIsHighlighted,
		CBCGPToolbarComboBoxButton* pButton);

	virtual void OnDrawComboDropButton (CDC* pDC, CRect rect,
		BOOL bDisabled,
		BOOL bIsDropped,
		BOOL bIsHighlighted,
		CBCGPToolbarComboBoxButton* pButton);

	virtual void OnDrawEditBorder (CDC* pDC, CRect rect,
		BOOL bDisabled,
		BOOL bIsHighlighted,
		CBCGPToolbarEditBoxButton* pButton);

	virtual void OnFillHighlightedArea (CDC* pDC, CRect rect, CBrush* pBrush, CBCGPToolbarButton* pButton);
	
	virtual void OnDrawButtonBorder (CDC* pDC,
		CBCGPToolbarButton* pButton, CRect rect, CBCGPVisualManager::BCGBUTTON_STATE state);

	virtual void OnDrawSeparator (CDC* pDC, CBCGPBaseControlBar* pBar, CRect rect, BOOL bIsHoriz);

	// Tabs support:
	virtual void OnDrawTab (CDC* pDC, CRect rectTab, int iTab, BOOL bIsActive, const CBCGPBaseTabWnd* pTabWnd);

	virtual void OnDrawTabContent (CDC* pDC, CRect rectTab,
		int iTab, BOOL bIsActive, const CBCGPBaseTabWnd* pTabWnd,
		COLORREF clrText);

	virtual void OnDrawTabBorder(CDC* pDC, CBCGPTabWnd* pTabWnd, CRect rectBorder, COLORREF clrBorder, CPen& penLine);

	virtual BOOL OnEraseTabsFrame (CDC* pDC, CRect rect, const CBCGPBaseTabWnd* pTabWnd);
	virtual int GetTabButtonState (CBCGPTabWnd* pTab, CBCGTabButton* pButton);

	virtual void OnDrawTabButton (CDC* pDC, CRect rect, 
		const CBCGPBaseTabWnd* pTabWnd, 
		int nID,
		BOOL bIsHighlighted,
		BOOL bIsPressed,
		BOOL bIsDisabled);

	virtual void GetTabFrameColors (const CBCGPBaseTabWnd* pTabWnd,
		COLORREF& clrDark,
		COLORREF& clrBlack,
		COLORREF& clrHighlight,
		COLORREF& clrFace,
		COLORREF& clrDarkShadow,
		COLORREF& clrLight,
		CBrush*& pbrFace,
		CBrush*& pbrBlack);

	virtual COLORREF GetActiveTabBackColor(const CBCGPBaseTabWnd* pTabWnd) const;

	virtual COLORREF GetStatusBarPaneTextColor (CBCGPStatusBar* pStatusBar, CBCGStatusBarPaneInfo* pPane);

	// Grid control:
#ifndef BCGP_EXCLUDE_GRID_CTRL
	virtual void OnFillGridHeaderBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual BOOL OnDrawGridHeaderItemBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);
	virtual COLORREF GetGridHeaderItemTextColor (CBCGPGridCtrl* pCtrl, BOOL bSelected, BOOL bGroupByBox);
	virtual void OnFillGridRowHeaderBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual void OnFillGridSelectAllAreaBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);
	virtual COLORREF OnFillGridGroupByBoxBackground (CDC* pDC, CRect rect);
	virtual COLORREF OnFillGridGroupByBoxTitleBackground (CDC* pDC, CRect rect);
	virtual COLORREF GetGridGroupByBoxLineColor () const;
	virtual void OnDrawGridGroupByBoxItemBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual COLORREF GetGridLeftOffsetColor (CBCGPGridCtrl* pCtrl);
	virtual void OnFillGridGroupBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill);
	virtual COLORREF GetGridGroupTextColor(const CBCGPGridCtrl* pCtrl, BOOL bSelected);
	virtual BOOL IsGridGroupUnderline () const;
	virtual void OnDrawGridGroupUnderline (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill);
	virtual COLORREF OnFillGridRowBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill, BOOL bSelected);
	virtual COLORREF OnFillGridItem (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill,
		BOOL bSelected, BOOL bActiveItem, BOOL bSortedColumn);
	virtual CBrush& GetGridCaptionBrush(CBCGPGridCtrl* pCtrl);
	virtual COLORREF GetGridTreeLineColor (CBCGPGridCtrl* pCtrl);
	virtual BOOL OnSetGridColorTheme (CBCGPGridCtrl* pCtrl, BCGP_GRID_COLOR_DATA& theme);

	virtual BOOL IsGridSparklineDefaultSelColor() const
	{
		return TRUE;
	}

	// Report control:
	virtual COLORREF GetReportCtrlGroupBackgoundColor ();
	virtual COLORREF OnFillReportCtrlRowBackground (CBCGPGridCtrl* pCtrl, CDC* pDC,
		CRect rectFill, BOOL bSelected, BOOL bGroup);
#endif // BCGP_EXCLUDE_GRID_CTRL

#ifndef BCGP_EXCLUDE_TOOLBOX
	virtual BOOL OnEraseToolBoxButton (CDC* pDC, CRect rect, CBCGPToolBoxButton* pButton);
	virtual BOOL OnDrawToolBoxButtonBorder (CDC* pDC, CRect& rect, CBCGPToolBoxButton* pButton, UINT uiState);
	virtual COLORREF GetToolBoxButtonTextColor (CBCGPToolBoxButton* pButton);
#endif

	// Planner
#ifndef BCGP_EXCLUDE_PLANNER
	virtual BOOL CanDrawCaptionDayWithHeader() const;
	virtual DWORD GetPlannerDrawFlags () const;
	virtual UINT GetPlannerWeekBarType() const;

	virtual void GetPlannerAppointmentColors (CBCGPPlannerView* pView,
		BOOL bSelected, BOOL bSimple, DWORD dwDrawFlags, 
		COLORREF& clrBack1, COLORREF& clrBack2,
		COLORREF& clrFrame1, COLORREF& clrFrame2, COLORREF& clrText);

	virtual COLORREF GetPlannerAppointmentDurationColor (CBCGPPlannerView* pView, const CBCGPAppointment* pApp) const;

	virtual void OnFillPlanner (CDC* pDC, CBCGPPlannerView* pView, 
		CRect rect, BOOL bWorkingArea);

	virtual COLORREF OnFillPlannerCaption (CDC* pDC, CBCGPPlannerView* pView,
		CRect rect, BOOL bIsToday, BOOL bIsSelected, BOOL bNoBorder = FALSE,
		BOOL bHorz = TRUE);

	virtual COLORREF GetPlannerViewWorkingColor (CBCGPPlannerView* pView);
	virtual COLORREF GetPlannerViewNonWorkingColor (CBCGPPlannerView* pView);

	virtual COLORREF OnFillPlannerTimeBar (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect, COLORREF& clrLine);

	virtual void OnFillPlannerWeekBar (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect);

	virtual void OnDrawPlannerHeader (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect);

	virtual void OnDrawPlannerHeaderPane (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect);

	virtual void OnFillPlannerHeaderAllDay (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect);

	virtual void OnDrawPlannerHeaderAllDayItem (CDC* pDC, 
		CBCGPPlannerView* pView, CRect rect, BOOL bIsToday, BOOL bIsSelected);

	COLORREF m_clrPlannerHeader;
#endif

	// ToolTip
	virtual BOOL GetToolTipParams (CBCGPToolTipParams& params, UINT nType = (UINT)(-1));

	// Auto-hide buttons:
	virtual void OnDrawAutohideBar(CDC* pDC, CRect rectBar, CBCGPAutoHideButton* pButton);

	// Outlook bar:
	virtual void OnFillOutlookPageButton (	CDC* pDC, const CRect& rect,
		BOOL bIsHighlighted, BOOL bIsPressed,
		COLORREF& clrText);
	virtual void OnDrawOutlookPageButtonBorder (CDC* pDC, CRect& rectBtn, 
		BOOL bIsHighlighted, BOOL bIsPressed);
	
	virtual void OnFillOutlookBarCaption (CDC* pDC, CRect rectCaption, COLORREF& clrText);
	virtual COLORREF OnDrawOutlookPopupButton(CDC* pDC, CRect& rectBtn, BOOL bIsHighlighted, BOOL bIsPressed, BOOL bIsOnCaption);
	
	// Tree control:
	virtual COLORREF GetTreeControlFillColor(CBCGPTreeCtrl* pTreeCtrl, BOOL bIsSelected = FALSE, BOOL bIsFocused = FALSE, BOOL bIsDisabled = FALSE);
	virtual COLORREF GetTreeControlTextColor(CBCGPTreeCtrl* pTreeCtrl, BOOL bIsSelected = FALSE, BOOL bIsFocused = FALSE, BOOL bIsDisabled = FALSE);

	// Caption bar:
	virtual BOOL IsCaptionBarCloseButtonOutsideMessageBar()	{	return FALSE; }

	virtual BOOL IsLargePropertySheetListFont(CBCGPPropertySheet* pPropSheet)
	{
		UNREFERENCED_PARAMETER(pPropSheet);
		return TRUE;
	}

	// Breadcrumb control:
	virtual void BreadcrumbDrawItem (CDC& dc, CBCGPBreadcrumb* pControl, BREADCRUMBITEMINFO* pItemInfo, CRect rectItem, UINT uState, COLORREF color);
	virtual void BreadcrumbDrawArrow (CDC& dc, CBCGPBreadcrumb* pControl, BREADCRUMBITEMINFO* pItemInfo, CRect rect, UINT uState, COLORREF color);

#ifndef BCGP_EXCLUDE_RIBBON
	// Ribbon control:
	virtual void OnDrawRibbonPaletteButton (
		CDC* pDC,
		CBCGPRibbonPaletteIcon* pButton);
	
	virtual void OnDrawRibbonPaletteButtonIcon(
		CDC* pDC,
		CBCGPRibbonPaletteIcon* pButton,
		int nID,
		CRect rect);

	virtual void OnDrawRibbonKeyTip (CDC* pDC, CBCGPBaseRibbonElement* pElement, CRect rect, CString str);
	virtual BOOL IsLayeredRibbonKeyTip () const;

	virtual void OnDrawRibbonPaletteBorder (
		CDC* pDC, 
		CBCGPRibbonPaletteButton* pButton, 
		CRect rectBorder);

	virtual CSize GetRibbonTabMargin();

	virtual void OnDrawRibbonMainButton(CDC* pDC, CBCGPRibbonButton* pButton);
	virtual COLORREF OnDrawRibbonStatusBarPane(CDC* pDC, CBCGPRibbonStatusBar* pBar, CBCGPRibbonStatusBarPane* pPane);
	virtual COLORREF OnFillRibbonStatusBarButton(CDC* pDC, CBCGPRibbonButton* pButton);
	virtual COLORREF OnFillRibbonBackstageLeftPane(CDC* pDC, CRect rectPanel);

#endif

	static Style	m_Style;
	COLORREF		m_clrRibbonGalleryBorder;
	COLORREF		m_clrRibbonGalleryBorderActive;
	BOOL			m_bUseVS2012AccentColors;
	
#ifndef BCGP_EXCLUDE_PLANNER
	COLORREF		m_clrPlannerTextHeader;
	COLORREF		m_clrPlannerTextHeaderHilite;
	COLORREF		m_clrPlannerTextHeaderPrep;
	COLORREF		m_clrPlannerTextHeaderPrepHilite;
	BOOL			m_clrPlannerTextApp;
#endif
};

//////////////////////////////////////////////////////////////////////////////
// CBCGPVisualManager2016

class BCGCBPRODLLEXPORT CBCGPVisualManager2016 : public CBCGPVisualManager2013
{
	DECLARE_DYNCREATE(CBCGPVisualManager2016)

public:
	enum Style
	{
		Office2016_Colorful,
		Office2016_DarkGray,
		Office2016_White,
		Office2016_Black,
	};
	
	static void SetStyle(Style style);
	static Style GetStyle() { return m_Style; }
	
	CBCGPVisualManager2016();
	virtual ~CBCGPVisualManager2016();

	virtual void OnUpdateSystemColors ();
	virtual void ModifyGlobalColors ();
	virtual void SetupColors();

	virtual COLORREF GetNCBorderColor(BOOL bActive);

	virtual BOOL IsDarkTheme () const { return m_Style == Office2016_DarkGray || m_Style == Office2016_Black; }
	virtual BOOL IsTopLevelMenuItemUpperCase()	{ return FALSE; }

	virtual void OnFillStatusBarFrame(CDC* pDC, CRect rectStatus, BOOL bActive);
	virtual COLORREF GetStatusBarPaneTextColor (CBCGPStatusBar* pStatusBar, CBCGStatusBarPaneInfo* pPane);

	virtual CBrush* GetNcCaptionBrush(BOOL bActive, BOOL bSmallDlgCaption);

	virtual void DrawNcBtn (CDC* pDC, const CRect& rect, UINT nButton, 
		BCGBUTTON_STATE state, BOOL bSmall, 
		BOOL bActive, BOOL bMDI = FALSE, BOOL bEnabled = TRUE);

	virtual CBCGPMenuImages::IMAGE_STATE GetNcBtnState(BCGBUTTON_STATE state, BOOL bActive, BOOL bEnabled);

	virtual void OnScrollBarDrawThumb (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bDisabled);
	
	virtual void OnScrollBarDrawButton (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	virtual void OnScrollBarFillBackground (CDC* pDC, CBCGPScrollBar* pScrollBar, CRect rect, 
		BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	virtual void OnDrawMenuResizeBar (CDC* pDC, CRect rect, int nResizeFlags);
	virtual COLORREF OnDrawMenuLabel (CDC* pDC, CRect rect);

	virtual COLORREF GetPrintPreviewFrameColor(BOOL bIsActive);

	// ToolTip
	virtual BOOL GetToolTipParams (CBCGPToolTipParams& params, UINT nType = (UINT)(-1));

	virtual void OnDrawSeparator (CDC* pDC, CBCGPBaseControlBar* pBar, CRect rect, BOOL bIsHoriz);

	virtual COLORREF OnDrawControlBarCaption (CDC* pDC, CBCGPDockingControlBar* pBar, 
		BOOL bActive, CRect rectCaption, CRect rectButtons);

	virtual COLORREF OnFillMiniFrameCaption (CDC* pDC, CRect rectCaption, 
		CBCGPMiniFrameWnd* pFrameWnd,
		BOOL bActive);

	virtual void OnDrawMiniFrameBorder (CDC* pDC, CBCGPMiniFrameWnd* pFrameWnd,
		CRect rectBorder, CRect rectBorderSize);

	virtual void OnDrawCaptionButton (CDC* pDC, CBCGPCaptionButton* pButton, BOOL bActive, BOOL bHorz,
		BOOL bMaximized, BOOL bDisabled, int nImageID = -1);

	virtual void OnDrawCaptionButtonIcon (CDC* pDC, 
		CBCGPCaptionButton* pButton,
		CBCGPMenuImages::IMAGES_IDS id,
		BOOL bActive, BOOL bDisabled,
		CPoint ptImage);

	virtual COLORREF GetDlgTextColor(CWnd* pDlg);
	virtual COLORREF GetURLLinkColor (CBCGPURLLinkButton* pButton, BOOL bHover);
	virtual COLORREF GetDlgHeaderTextColor(CWnd* pDlg);

	virtual void OnDrawHeaderCtrlBorder (CBCGPHeaderCtrl* pCtrl, CDC* pDC, CRect& rect, BOOL bIsPressed, BOOL bIsHighlighted);

	virtual COLORREF OnFillListBox(CDC* pDC, CBCGPListBox* pListBox, CRect rectClient);
	virtual COLORREF OnFillListBoxItem (CDC* pDC, CBCGPListBox* pListBox, int nItem, CRect rect, BOOL bIsHighlihted, BOOL bIsSelected);

	virtual BOOL IsDrawLineOnTopOfMenuBar() { return m_Style == Office2016_White; }

#ifndef BCGP_EXCLUDE_RIBBON
	virtual BOOL IsMainRibbonButtonColored() { return m_Style == Office2016_White; }
	virtual void OnDrawRibbonMainButton(CDC* pDC, CBCGPRibbonButton* pButton);

	virtual COLORREF GetRibbonCaptionTextColor(CBCGPRibbonBar* pBar, BOOL bActive);
	virtual void OnFillBarBackground(CDC* pDC, CBCGPBaseControlBar* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea = FALSE);
	virtual COLORREF OnDrawRibbonCategoryTab(CDC* pDC, CBCGPRibbonTab* pTab, BOOL bIsActive);

	virtual COLORREF GetRibbonQATTextColor(BOOL bDisabled = FALSE);
	virtual BOOL IsSimplifiedRibbonQATIcon(CBCGPRibbonButton* pButton);
	virtual BOOL IsSimplifiedRibbonTabControlIcon(CBCGPRibbonButton* pButton);

	virtual COLORREF OnFillRibbonButton(CDC* pDC, CBCGPRibbonButton* pButton);
	virtual void OnDrawRibbonMinimizeButtonImage(CDC* pDC, CBCGPRibbonMinimizeButton* pButton, BOOL bRibbonIsMinimized);
	virtual COLORREF OnDrawRibbonStatusBarPane(CDC* pDC, CBCGPRibbonStatusBar* pBar, CBCGPRibbonStatusBarPane* pPane);

	virtual void OnDrawRibbonButtonBorder (
		CDC* pDC, 
		CBCGPRibbonButton* pButton);

	virtual COLORREF GetRibbonEditBackgroundColor (
		CBCGPRibbonEditCtrl* pEdit,
		BOOL bIsHighlighted,
		BOOL bIsPaneHighlighted,
		BOOL bIsDisabled);

	virtual COLORREF GetRibbonEditTextColor (
		CBCGPRibbonEditCtrl* pEdit,
		BOOL bIsHighlighted,
		BOOL bIsDisabled);

	virtual COLORREF GetRibbonEditPromptColor(
		CBCGPRibbonEditCtrl* pEdit,
		BOOL bIsHighlighted,
		BOOL bIsDisabled);

	virtual BOOL IsRibbonStatusBarDark();
	virtual COLORREF OnFillRibbonStatusBarButton(CDC* pDC, CBCGPRibbonButton* pButton);

	virtual COLORREF GetRibbonStatusBarTextColor (CBCGPRibbonStatusBar* pStatusBar);
	virtual COLORREF GetRibbonHyperlinkTextColor (CBCGPRibbonHyperlink* pHyperLink);

	virtual COLORREF GetRibbonFrameColor(CBCGPRibbonBar* pWndRibbonBar);

	virtual BOOL IsRibbonBackstageWhiteBackground()		{	return FALSE;	}
	virtual BOOL IsDrawRibbonSystemIcon()				{	return FALSE;	}

	virtual void OnFillRibbonBackstageForm(CDC* pDC, CWnd* pDlg, CRect rect);
	virtual void PrepareRibbonBackgroundDark(CBCGPToolBarImages& src, CBCGPToolBarImages& dst);

	virtual void GetRibbonSliderColors (CBCGPRibbonSlider* pSlider, 
		BOOL bIsHighlighted, 
		BOOL bIsPressed,
		BOOL bIsDisabled,
		COLORREF& clrLine,
		COLORREF& clrFill);

	virtual void OnDrawRibbonSliderChannel (
		CDC* pDC, CBCGPRibbonSlider* pSlider, 
		CRect rect);

	virtual void OnDrawRibbonDefaultPaneButton (
		CDC* pDC, 
		CBCGPRibbonButton* pButton);

	virtual COLORREF OnFillRibbonPanelCaption (
		CDC* pDC,
		CBCGPRibbonPanel* pPanel, 
		CRect rectCaption);

	virtual COLORREF OnFillRibbonBackstageLeftPane(CDC* pDC, CRect rectPanel);

	virtual COLORREF GetRibbonBackstageTextColor();
	virtual COLORREF GetRibbonBackstageInfoTextColor();

	virtual void OnDrawRibbonMenuArrow(CDC* pDC, CBCGPRibbonButton* pButton, UINT id, const CRect& rectMenuArrow);
	virtual void OnDrawRibbonPaletteBorder(CDC* pDC, CBCGPRibbonPaletteButton* pButton, CRect rectBorder);

	virtual COLORREF OnDrawRibbonCategoryCaption(CDC* pDC, CBCGPRibbonContextCaption* pContextCaption);

	virtual void OnFillRibbonQAT(CDC* pDC, CRect rect);
	virtual void OnFillRibbonQATPopup(CDC* pDC, CBCGPRibbonPanelMenuBar* pMenuBar, CRect rect);

	virtual void OnDrawRibbonDropDownPanel(CDC* pDC, CBCGPRibbonPanel* pPanel, CRect rectFill);

	virtual CSize GetRibbonQATButtonHorzMargin(){	return CSize(2, 4);	}

#endif

#ifndef BCGP_EXCLUDE_PROP_LIST
	virtual void OnFillPropListToolbarArea(CDC* pDC, CBCGPPropList* pList, const CRect& rectToolBar);
	virtual COLORREF OnFillPropertyListSelectedItem(CDC* pDC, CBCGPProp* pProp, CBCGPPropList* pWndList, const CRect& rectFill, BOOL bFocused);
	virtual COLORREF GetPropListGroupTextColor(CBCGPPropList* pPropList);
	virtual COLORREF OnFillPropListDescriptionArea(CDC* pDC, CBCGPPropList* pList, const CRect& rect);
	virtual COLORREF OnFillPropListCommandsArea(CDC* pDC, CBCGPPropList* pList, const CRect& rect);
	virtual COLORREF GetPropListCommandTextColor (CBCGPPropList* pPropList);
	virtual COLORREF GetPropListGroupColor (CBCGPPropList* pPropList);
	virtual COLORREF GetPropListDisabledTextColor(CBCGPPropList* pPropList);
#endif

	// Editor colors:
	virtual COLORREF GetEditCtrlSelectionBkColor(CBCGPEditCtrl* pEdit, BOOL bIsFocused);
	virtual COLORREF GetEditCtrlSelectionTextColor(CBCGPEditCtrl* pEdit, BOOL bIsFocused);

	virtual HBRUSH GetEditBackgroundBrush(CBCGPEditCtrl* pEdit);
	virtual COLORREF GetEditTextColor(CBCGPEditCtrl* pEdit);

	virtual COLORREF GetEditLineNumbersBarTextColor(CBCGPEditCtrl* pEdit);

	virtual CBrush& GetEditCtrlBackgroundBrush(CBCGPEdit* pEdit);

#ifndef BCGP_EXCLUDE_GRID_CTRL
	// Report control:
	virtual COLORREF OnFillReportCtrlRowBackground (CBCGPGridCtrl* pCtrl, CDC* pDC,
		CRect rectFill, BOOL bSelected, BOOL bGroup);
	virtual BOOL IsGridGroupUnderline () const { return FALSE; }

	// Grid control:
	virtual void OnFillGridGroupBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill);
	virtual CBrush& GetGridCaptionBrush(CBCGPGridCtrl* pCtrl);

	virtual void OnFillGridHeaderBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual BOOL OnDrawGridHeaderItemBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);
	virtual void OnFillGridRowHeaderBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual BOOL OnDrawGridRowHeaderItemBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);
	virtual void OnFillGridSelectAllAreaBackground (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);
	virtual void OnDrawGridSelectAllMarker(CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, int nPadding, BOOL bPressed);
	virtual BOOL OnDrawGridSelectAllAreaBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect, BOOL bPressed);

	virtual COLORREF OnFillGridGroupByBoxBackground (CDC* pDC, CRect rect);
	virtual COLORREF GetGridGroupByBoxLineColor () const;
	virtual void OnDrawGridGroupByBoxItemBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);
	virtual COLORREF OnFillGridItem (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill,
		BOOL bSelected, BOOL bActiveItem, BOOL bSortedColumn);
	virtual void OnDrawGridSelectionBorder (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rect);

	virtual COLORREF GetGridTreeLineColor (CBCGPGridCtrl* pCtrl);
	virtual BOOL OnSetGridColorTheme (CBCGPGridCtrl* pCtrl, BCGP_GRID_COLOR_DATA& theme);
	virtual COLORREF OnFillGridCaptionRow (CBCGPGridCtrl* pCtrl, CDC* pDC, CRect rectFill);
#endif // BCGP_EXCLUDE_GRID_CTRL
	
	// Popup window:
#ifndef BCGP_EXCLUDE_POPUP_WINDOW
	virtual COLORREF GetPopupWindowLinkTextColor(CBCGPPopupWindow* pPopupWnd, BOOL bIsHover);
	virtual COLORREF GetPopupWindowTextColor(CBCGPPopupWindow* pPopupWnd);
	virtual COLORREF OnDrawPopupWindowCaption (CDC* pDC, CRect rectCaption, CBCGPPopupWindow* pPopupWnd);
	virtual COLORREF GetPopupWindowCaptionTextColor(CBCGPPopupWindow* pPopupWnd, BOOL bButton);
#endif

#if !defined (BCGP_EXCLUDE_GRID_CTRL) && !defined (BCGP_EXCLUDE_GANTT)
	virtual void GetGanttColors (const CBCGPGanttChart* pChart, BCGP_GANTT_CHART_COLORS& colors, COLORREF clrBack = CLR_DEFAULT) const;
#endif // !defined (BCGP_EXCLUDE_GRID_CTRL) && !defined (BCGP_EXCLUDE_GANTT)

	virtual CBrush& GetDlgButtonsAreaBrush(CWnd* pDlg, COLORREF* pclrLine = NULL);
	virtual void OnDrawSpinButtons (CDC* pDC, CRect rectSpin, int nState, BOOL bOrientation, CBCGPSpinButtonCtrl* pSpinCtrl);

	virtual void OnDrawComboDropButton (CDC* pDC, CRect rect,
		BOOL bDisabled,
		BOOL bIsDropped,
		BOOL bIsHighlighted,
		CBCGPToolbarComboBoxButton* pButton);

	virtual COLORREF GetToolbarButtonTextColor (CBCGPToolbarButton* pButton, CBCGPVisualManager::BCGBUTTON_STATE state);

	// Push button:
	virtual BOOL OnDrawPushButton (CDC* pDC, CRect rect, CBCGPButton* pButton, COLORREF& clrText);

	// Tree control:
	virtual COLORREF GetTreeControlFillColor(CBCGPTreeCtrl* pTreeCtrl, BOOL bIsSelected = FALSE, BOOL bIsFocused = FALSE, BOOL bIsDisabled = FALSE);
	virtual COLORREF GetTreeControlTextColor(CBCGPTreeCtrl* pTreeCtrl, BOOL bIsSelected = FALSE, BOOL bIsFocused = FALSE, BOOL bIsDisabled = FALSE);

	// IntelliSense window:
	virtual COLORREF GetIntelliSenseFillColor(CBCGPBaseIntelliSenseLB* pCtrl, BOOL bIsSelected = FALSE);
	virtual COLORREF GetIntelliSenseTextColor(CBCGPBaseIntelliSenseLB* pTreeCtrl, BOOL bIsSelected = FALSE);

	// Tab control:
	virtual void OnDrawTabContent (CDC* pDC, CRect rectTab,
		int iTab, BOOL bIsActive, const CBCGPBaseTabWnd* pTabWnd,
		COLORREF clrText);

	// Date/time controls:
	virtual void GetCalendarColors (const CBCGPCalendar* pCalendar, CBCGPCalendarColors& colors);
	virtual void OnDrawDateTimeDropButton (CDC* pDC, CRect rect, BOOL bDisabled, BOOL bPressed, BOOL bHighlighted, CBCGPDateTimeCtrl* pCtrl);

protected:
	static Style	m_Style;
	COLORREF		m_clrScrollButtonHot;
	COLORREF		m_clrScrollButton;
	COLORREF		m_clrCaption;
	CBrush			m_brCaption;
	CBrush			m_brCloseButtonHighlighted;
	CBrush			m_brCloseButtonPressed;
};

#endif // !defined(AFX_BCGPVISUALMANAGER2013_H__E0C4C3FF_13B6_4956_9E0C_4692963F5E15__INCLUDED_)
