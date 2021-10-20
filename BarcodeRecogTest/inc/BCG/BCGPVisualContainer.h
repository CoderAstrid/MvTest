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
// BCGPVisualContainer.h: interface for the CBCGPVisualContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPVISUALCONTAINER_H__F3037CD5_27F5_47A1_9D7E_189F956D2CB9__INCLUDED_)
#define AFX_BCGPVISUALCONTAINER_H__F3037CD5_27F5_47A1_9D7E_189F956D2CB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXMT_H__
	#include <afxmt.h>
#endif

#include "bcgcbpro.h"
#include "BCGPWnd.h"
#include "BCGPGraphicsManager.h"
#include "BCGPGestureManager.h"
#include "BCGPAnimationManager.h"

#ifndef _BCGPCHART_STANDALONE
#include "BCGPLayout.h"
#include "BCGPEdit.h"
#endif

// Object Drawing flags
#define BCGP_DRAW_STATIC						0x0001
#define BCGP_DRAW_DYNAMIC						0x0002

// Object Editing flags
#define BCGP_EDIT_NOMOVE						0x0001
#define BCGP_EDIT_NOSIZE						0x0002
#define BCGP_EDIT_SIZE_LOCK_ASPECT_RATIO		0x0004
#define BCGP_EDIT_NO_NORMALIZE_RECT				0x0008
#define BCGP_EDIT_NO_KEYBOARD					0x0010
#define BCGP_EDIT_SIZE_NO_LEFT					0x0020
#define BCGP_EDIT_SIZE_NO_RIGHT					0x0040
#define BCGP_EDIT_SIZE_NO_TOP					0x0080
#define BCGP_EDIT_SIZE_NO_BOTTOM				0x0100

// Container Editing flags
#define BCGP_CONTAINER_SINGLE_SEL				0x0001
#define	BCGP_CONTAINER_GRID						0x0002
#define BCGP_CONTAINER_ENABLE_KEYBOARD			0x0004
#define BCGP_CONTAINER_DISABLE_KEYBOARD_OBJECT	0x0008
#define BCGP_CONTAINER_ENABLE_COPY				0x0010
#define	BCGP_CONTAINER_SNAP_TO_GRID				0x0020

// InfoTip custom colors
#define BCGP_INFOTIP_FILL_COLOR					1
#define BCGP_INFOTIP_TEXT_COLOR					2
#define BCGP_INFOTIP_BORDER_COLOR				3

// Object size markers

////////////////////////////////////////////////////////////////
// CBCGPVisualDataObject

class CBCGPBaseVisualObject;
class CBCGPVisualScrollBar;

class BCGCBPRODLLEXPORT CBCGPVisualDataObject : public CObject,
												public CBCGPAnimationManager
{
	DECLARE_DYNAMIC(CBCGPVisualDataObject)
	friend class CBCGPBaseVisualObject;

// Construction
public:
	CBCGPVisualDataObject()
	{
		m_dblValue = 0.;
		m_pParentVisual = NULL;
	}

	CBCGPVisualDataObject(const CBCGPVisualDataObject & src)
	{
		CopyFrom(src);
	}

	const CBCGPBaseVisualObject* GetParentVisual() const
	{
		return m_pParentVisual;
	}

	CBCGPVisualDataObject & operator = (const CBCGPVisualDataObject & src)
	{
		CopyFrom(src);
		return *this;
	}

	virtual CBCGPVisualDataObject* CreateCopy () const
	{
		return new CBCGPVisualDataObject (*this);
	}

	virtual void CopyFrom(const CBCGPVisualDataObject & src)
	{
		m_dblValue = src.m_dblValue;
		m_pParentVisual = src.m_pParentVisual;
	}

	virtual ~CBCGPVisualDataObject()
	{
	}

// Attributes
public:
	double GetValue() const
	{
		return m_dblValue;
	}

	void SetValue(double dblValue)
	{
		m_dblValue = dblValue;
	}

protected:
	void SetParentVisual(CBCGPBaseVisualObject* pParentVisual)
	{
		m_pParentVisual = pParentVisual;
	}

	virtual void OnAnimationValueChanged(double dblOldValue, double dblNewValue);
	virtual void OnAnimationFinished();
	
protected:
	double					m_dblValue;
	CBCGPBaseVisualObject*	m_pParentVisual;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CBCGPBaseVisualObject

class BCGCBPRODLLEXPORT CBCGPBaseVisualObject : public CBCGPBaseAccessibleObject
{
	DECLARE_DYNAMIC(CBCGPBaseVisualObject)

	friend class CBCGPVisualContainer;
	friend class CBCGPBaseVisualCtrl;
	friend class CBCGPVisualDataObject;

public:
	CBCGPBaseVisualObject(CBCGPVisualContainer* pContainer = NULL);
 	CBCGPBaseVisualObject(const CBCGPBaseVisualObject& src);
	virtual ~CBCGPBaseVisualObject();

// Attributes:
public:
	// General attributes:
	UINT GetID() const
	{
		return m_nID;
	}

	void SetID(UINT nID)
	{
		m_nID = nID;
	}

	CString	GetName() const
	{
		return m_strName;
	}

	void SetName(const CString& strName)
	{
		m_strName = strName;
	}

	DWORD_PTR GetUserData() const
	{
		return m_dwUserData;
	}

	void SetUserData(DWORD_PTR dwUserData)
	{
		m_dwUserData = dwUserData;
	}

	CWnd* GetOwner() const
	{
		return m_pWndOwner;
	}

	virtual CWnd* GetParentWnd() const 
	{ 
		return m_pWndOwner; 
	}

	virtual CWnd* SetOwner(CWnd* pWndOwner, BOOL bRedraw = FALSE);

	const CBCGPVisualContainer* GetParentContainer () const
	{
		return m_pParentContainer;
	}

	virtual void SetRect(const CBCGPRect& rect, BOOL bRedraw = FALSE);
	const CBCGPRect& GetRect() const
	{
		return m_rect;
	}

	BOOL ResetRect();
	BOOL ResetOriginalRect();

	BOOL IsEditMode() const;

	BOOL IsVisible() const
	{
		return m_bIsVisible;
	}

	void SetVisible(BOOL bIsVisible = TRUE, BOOL bRedraw = FALSE)
	{
		m_bIsVisible = bIsVisible;

		if (bRedraw)
		{
			Redraw();
		}
	}

	BOOL IsEnabled() const
	{
		return m_bIsEnabled;
	}

	// Data attributes:
	int GetDataCount() const
	{
		return (int)m_arData.GetSize();
	}

	const CBCGPVisualDataObject* GetData(int nIndex) const
	{
		if (0 <= nIndex && nIndex < GetDataCount ())
		{
			return m_arData[nIndex];
		}

		return NULL;
	}

	virtual BOOL SetValue(double dblVal, int nIndex = 0, UINT uiAnimationTime = 100 /* Ms, 0 - no animation */, BOOL bRedraw = FALSE);
	double GetValue(int nIndex = 0) const;

	void EnableRedraw(BOOL enable = TRUE)
	{
		m_bIsRedrawEnabled = enable;
	}

	BOOL IsRedrawEnabled() const
	{
		return m_bIsRedrawEnabled;
	}

	virtual void SetDirty(BOOL bSet = TRUE, BOOL bRedraw = FALSE)
	{
		m_bIsDirty = bSet;

		if (m_bIsDirty && bRedraw)
		{
			Redraw();
		}
	}

	BOOL IsDirty() const
	{
		return m_bIsDirty;
	}

	void EnableImageCache(BOOL bEnable = TRUE);
	BOOL IsImageCache() const
	{
		return m_bCacheImage;
	}

	void SetAutoDestroy(BOOL bAutoDestroy = TRUE)
	{
		m_bIsAutoDestroy = bAutoDestroy;
	}

	BOOL IsAutoDestroy() const
	{
		return m_bIsAutoDestroy;
	}

	// Selection attributes:
	BOOL IsSelected() const
	{
		return m_bIsSelected;
	}

	virtual void SetSelected(BOOL bSet = TRUE);

	UINT GetEditFlags() const
	{
		return m_uiEditFlags;
	}

	void SetEditFlags(UINT nFlags)
	{
		m_uiEditFlags = nFlags;
	}

	const CBCGPSize& GetScaleRatio() const
	{
		return m_sizeScaleRatio;
	}
	
	const double GetScaleRatioMid() const
	{
		if (m_sizeScaleRatio.cx == m_sizeScaleRatio.cy)
		{
			return m_sizeScaleRatio.cx;
		}

		return (m_sizeScaleRatio.cx + m_sizeScaleRatio.cy) / 2.0;
	}

	void SetScaleRatio(const CBCGPSize& sizeScaleRatio)
	{
		if (m_sizeScaleRatio == sizeScaleRatio)
		{
			return;
		}

		CBCGPSize sizeScaleRatioOld = m_sizeScaleRatio;
		m_sizeScaleRatio = sizeScaleRatio;
		
		OnScaleRatioChanged(sizeScaleRatioOld);
	}

	UINT GetClickAndHoldID() const
	{
		return m_nClickAndHoldID;
	}

	const CBCGPRect& GetClickAndHoldRect() const
	{
		return m_rectClickAndHold;
	}

	const CBCGPPoint& GetDrawOffset () const
	{
		return m_ptDrawOffset;
	}

// Operations:
public:
	virtual void OnDraw(CBCGPGraphicsManager* pGM, const CBCGPRect& rectClip, DWORD dwFlags = BCGP_DRAW_STATIC | BCGP_DRAW_DYNAMIC) = 0;
	virtual void Redraw();
	virtual void RedrawRect(const CBCGPRect& rect);
	virtual void PostRedraw(BOOL bSetDirty = FALSE);

	virtual void Invalidate();
	virtual void InvalidateRect(const CBCGPRect& rect);
	virtual void UpdateWindow();

	void StopAllAnimations(BOOL bRedraw = FALSE);

	BOOL ExportToImage(CBCGPGraphicsManager* pGM, CBCGPImage& image, const CBCGPBrush& brFill = CBCGPBrush(CBCGPColor::White));
	HBITMAP ExportToBitmap(CBCGPGraphicsManager* pGM);

	BOOL CopyToClipboard(CBCGPGraphicsManager* pGM);
	BOOL ExportToFile(const CString& strFilePath, CBCGPGraphicsManager* pGM);

	virtual CBCGPSize GetMinSize() const
	{
		return CBCGPSize(0, 0);
	}

 	virtual CBCGPBaseVisualObject* CreateCopy () const;
	virtual void CopyFrom(const CBCGPBaseVisualObject& src);

	void SetClickAndHoldEvent(const CBCGPRect& rectBounds, UINT nEventID = 1001);	// Should be called inside OnMouseDown event
	void ResetGestureOptions();

// Overrides:
	virtual BOOL OnMouseDown(int /*nButton*/, const CBCGPPoint& /*pt*/)	{	return FALSE;	}
	virtual void OnMouseUp(int /*nButton*/, const CBCGPPoint& /*pt*/)	{}
	virtual BOOL OnMouseDblClick(int /*nButton*/, const CBCGPPoint& )	{	return FALSE;	}
	virtual void OnMouseMove(const CBCGPPoint& /*pt*/)					{}
	virtual void OnMouseLeave()											{}
	virtual BOOL OnMouseWheel(const CBCGPPoint& /*pt*/, short /*zDelta*/){	return FALSE;	}
	virtual BOOL OnSetMouseCursor(const CBCGPPoint& pt);
	virtual void OnCancelMode()											{}
	virtual BOOL OnGetToolTip(const CBCGPPoint& /*pt*/, CString& /*strToolTip*/, CString& /*strDescr*/)	{	return FALSE;	}
	virtual COLORREF GetInfoTipColor(const CBCGPPoint& /*pt*/, int /*nColor*/) { return (COLORREF)-1; }

	virtual BOOL GetGestureConfig(CBCGPGestureConfig& /*gestureConfig*/)					{	return FALSE;	}

	virtual BOOL OnGestureEventZoom(const CBCGPPoint& /*ptCenter*/, double /*dblZoomFactor*/)		{	return FALSE;	}
	virtual BOOL OnGestureEventPan(const CBCGPPoint& /*ptFrom*/, const CBCGPPoint& /*ptTo*/, CBCGPSize& /*sizeOverPan*/)		{	return FALSE;	}
	virtual BOOL OnGestureEventRotate(const CBCGPPoint& /*ptCenter*/, double /*dblAngle*/)	{	return FALSE;	}
	virtual BOOL OnGestureEventTwoFingerTap(const CBCGPPoint& /*ptCenter*/)					{	return FALSE;	}
	virtual BOOL OnGestureEventPressAndTap(const CBCGPPoint& /*ptPress*/, long /*lDelta*/)	{	return FALSE;	}

	virtual int HitTest(const CBCGPPoint& pt) const;

	virtual BOOL OnKeyboardDown(UINT /*nChar*/, UINT /*nRepCnt*/, UINT /*nFlags*/)	{	return FALSE;	}
	virtual BOOL OnKeyboardUp(UINT /*nChar*/, UINT /*nRepCnt*/, UINT /*nFlags*/)	{	return FALSE;	}

	virtual void DrawTrackingRect(CBCGPGraphicsManager* pGM,
		const CBCGPBrush& brOutline, const CBCGPBrush& brFill);

	virtual void OnScaleRatioChanged(const CBCGPSize& /*sizeScaleRatioOld*/)	{}

	virtual BOOL IsCaptured() const	{	return FALSE;	}

	virtual void OnClickAndHoldEvent(UINT /*nID*/, const CBCGPPoint& /*point*/) {}

	virtual void OnScroll(CBCGPVisualScrollBar* /*pScrollBar*/, double /*dblDelta*/) {}

	virtual void OnBeforeDrawScrolled (const CBCGPPoint& ptDrawOffset);
	virtual void OnAfterDrawScrolled ();
 
	virtual void SetScrollOffset(const CBCGPPoint& ptScrollOffset)
	{
		m_ptScrollOffset = ptScrollOffset;
	}

	const CBCGPPoint& GetScrollOffset() const
	{
		return m_ptScrollOffset;
	}

	virtual void OnAfterCreateWnd() {}
	virtual void OnBeforeDestroyWnd() {}

	virtual void OnChangeVisualManager() {}

	virtual void OnWndEnabled(BOOL bEnable);

	virtual BOOL IsSnapTpGridAvailable() const
	{
		return TRUE;
	}

protected:
	int AddData(CBCGPVisualDataObject* pObject);
	void RemoveAllData();

	virtual void OnAnimation(CBCGPVisualDataObject* /*pDataObject*/) {}
	virtual void OnAnimationFinished(CBCGPVisualDataObject* /*pDataObject*/) {}

	virtual double GetAnimationRange(int /*nIndex*/)
	{
		return 0.;
	}

	virtual void SetTrackingRect(const CBCGPRect& rect);

	CBCGPRect MakeTrackMarker(double x, double y) const;
	CBCGPRect MakeTrackMarker(const CBCGPPoint& pt) const;

	virtual void OnRectChanged(const CBCGPRect& /*rectOld*/) {}
	virtual void OnAddToContainer(CBCGPVisualContainer* /*pContainer*/) {}

// MSAA support:
public:
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
	virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT accHitTest(long  xLeft, long yTop, VARIANT *pvarChild);
	virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
	virtual HRESULT get_accParent(IDispatch **ppdispParent);

	virtual BOOL IsAccessibilityCompatible () { return TRUE; }

#if _MSC_VER < 1300
	DECLARE_OLECREATE(CBCGPBaseVisualObject)
#endif

protected:
	UINT					m_nID;
	DWORD_PTR				m_dwUserData;
	CString					m_strName;
	BOOL					m_bIsVisible;

	CBCGPRect				m_rect;
	CBCGPRect				m_rectOriginal;
	BOOL					m_bDontResetRect;
	CBCGPRect				m_rectTrack;
	CWnd*					m_pWndOwner;
	BOOL					m_bIsInteractiveMode;
	BOOL					m_bIsEnabled;

	CBCGPVisualContainer*	m_pParentContainer;
	BOOL					m_bIsAutoDestroy;

	BOOL					m_bIsDirty;
	BOOL					m_bIsRedrawEnabled;
	BOOL					m_bCacheImage;
	BOOL					m_bIsSelected;
	UINT					m_uiEditFlags;

	BOOL					m_bIsTracked;

	CBCGPSize				m_sizeScaleRatio;

	UINT					m_nClickAndHoldID;
	CBCGPRect				m_rectClickAndHold;
	CBCGPPoint				m_ptScrollOffset;
	CBCGPPoint				m_ptDrawOffset;

	CArray<CBCGPVisualDataObject*, CBCGPVisualDataObject*>	m_arData;
	CMap<UINT, UINT, CBCGPRect, const CBCGPRect&>			m_mapTrackRects;

#if _MSC_VER < 1300
	IAccessible*			m_pStdObject;
	virtual void OnSetIAccessible(IAccessible* pIAccessible) { m_pStdObject = pIAccessible; }
#endif
};

#ifndef _BCGPCHART_STANDALONE

////////////////////////////////////////////////////////////////////////////////////////////////////
// CBCGPVisualLayout

class BCGCBPRODLLEXPORT CBCGPVisualLayout : public CBCGPStaticLayout
{
	friend class CBCGPVisualContainer;

public:
	CBCGPVisualLayout(CBCGPVisualContainer& container) :
		m_container(container)
	{
	}

	BOOL AddAnchor (CBCGPBaseVisualObject* pObject, XMoveType typeMove, XSizeType typeSize, 
					const CPoint& percMove = CPoint (100, 100), const CPoint& percSize = CPoint (100, 100));

protected:
	virtual void AdjustLayout ();
	virtual CRect GetItemRect(XWndItem& item) const;
	virtual void GetHostWndRect (CRect& rect) const;

	CBCGPVisualContainer& m_container;
};

#endif // _BCGPCHART_STANDALONE


/////////////////////////////////////////////////////////////////////////////
// CBCGPVisualScrollBarColorTheme

class BCGCBPRODLLEXPORT CBCGPVisualScrollBarColorTheme
{
	friend class CBCGPVisualScrollBar;

public:
	CBCGPVisualScrollBarColorTheme(const CBCGPColor& color = CBCGPColor());

	CBCGPVisualScrollBarColorTheme & operator = (const CBCGPVisualScrollBarColorTheme & src)
	{
		CopyFrom(src);
		return *this;
	}

	virtual ~CBCGPVisualScrollBarColorTheme()
	{
	}
	
	virtual void CopyFrom(const CBCGPVisualScrollBarColorTheme & src)
	{
		m_brFace = src.m_brFace;
		m_brBorder = src.m_brBorder;
		m_brButton = src.m_brButton;
		m_brButtonPressed = src.m_brButtonPressed;

		if (m_brButtonPressed.IsEmpty() && !m_brButton.IsEmpty())
		{
			m_brButtonPressed = m_brButton;

			if (m_brButton.GetColor().IsDark())
			{
				m_brButtonPressed.MakeLighter();
			}
			else
			{
				m_brButtonPressed.MakeDarker();
			}
		}

		CleanUp3dColors();
	}

	CBCGPBrush	m_brFace;
	CBCGPBrush	m_brBorder;
	CBCGPBrush	m_brButton;
	CBCGPBrush	m_brButtonPressed;

protected:
	void CleanUp3dColors()
	{
		m_brFace3D.Empty();
		m_brButton3D.Empty();
		m_brButtonPressed3D.Empty();
	}

	CBCGPBrush	m_brFace3D;
	CBCGPBrush	m_brButton3D;
	CBCGPBrush	m_brButtonPressed3D;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPVisualScrollBar

class BCGCBPRODLLEXPORT CBCGPVisualScrollBar : public CObject
{
// Construction
public:
	CBCGPVisualScrollBar();
	virtual ~CBCGPVisualScrollBar();

// Attributes
public:
	enum BCGP_VISUAL_SCROLLBAR_STYLE
	{
		BCGP_VISUAL_SCROLLBAR_STYLE_FIRST		= 0,
		BCGP_VISUAL_SCROLLBAR_FLAT				= BCGP_VISUAL_SCROLLBAR_STYLE_FIRST,
		BCGP_VISUAL_SCROLLBAR_FLAT_ROUNDED		= 1,
		BCGP_VISUAL_SCROLLBAR_3D				= 2,
		BCGP_VISUAL_SCROLLBAR_3D_ROUNDED		= 3,
		BCGP_VISUAL_SCROLLBAR_VISUAL_MANAGER	= 4,
		BCGP_VISUAL_SCROLLBAR_STYLE_LAST		= BCGP_VISUAL_SCROLLBAR_VISUAL_MANAGER
	};

	void SetParentVisualObject(CBCGPBaseVisualObject* pOwner);
	void SetParentVisualContainer(CBCGPVisualContainer* pOwnerContainer);

	BOOL IsHorizontal() const { return m_bIsHorizontal; }
	void SetHorizontal(BOOL bSet = TRUE);

	const CBCGPRect& GetRect() { return m_rect; }
	void SetRect(const CBCGPRect& rect);

	double GetTotal() const { return m_dblTotal; }
	void SetTotal(double dblTotal) { m_dblTotal = dblTotal; }

	double GetStep() const { return m_dblStep; }
	void SetStep(double dblStep) { m_dblStep = dblStep; }

	double GetOffset() const { return m_dblOffset; }
	void SetOffset(double dblOffset) { m_dblOffset = dblOffset; }

	const CBCGPRect& GetPrevButton() const { return m_rectPrev; }
	const CBCGPRect& GetNextButton() const { return m_rectNext; }
	const CBCGPRect& GetThumb() const { return m_rectThumb; }

	double GetScrollSize() const { return m_bIsHorizontal ? m_rectScroll.Width() : m_rectScroll.Height(); }

	void SetColorTheme(CBCGPVisualScrollBarColorTheme& theme) { m_ColorTheme = theme; }
	const CBCGPVisualScrollBarColorTheme& GetColorTheme() const { return m_ColorTheme; }

	void SetStyle(BCGP_VISUAL_SCROLLBAR_STYLE style);
	BCGP_VISUAL_SCROLLBAR_STYLE GetStyle() const { return m_Style; }

// Overrides
public:
	virtual void DoDraw(CBCGPGraphicsManager* pGM);
	virtual BOOL OnMouseDown(const CBCGPPoint& pt);
	virtual BOOL OnDragThumb(const CBCGPPoint& pt);
	virtual void OnScrollStep(BOOL bNext);
	virtual void OnCancelMode();

// Operations:
public:
	void Redraw();
	void Reset();
	void ReposThumb();

	BOOL IsInAction() const
	{
		return m_bIsDraggingThumb || m_bPrevIsClicked || m_bNextIsClicked;
	}

protected:
	BOOL					m_bIsHorizontal;
	CBCGPBaseVisualObject*	m_pOwner;
	CBCGPVisualContainer*	m_pOwnerContainer;
	CBCGPRect				m_rect;
	CBCGPRect				m_rectScroll;
	CBCGPRect				m_rectThumb;
	CBCGPRect				m_rectPrev;
	CBCGPRect				m_rectNext;
	CBCGPPoint				m_ptDragThumbLast;
	BOOL					m_bIsDraggingThumb;
	BOOL					m_bPrevIsClicked;
	BOOL					m_bNextIsClicked;
	double					m_dblTotal;
	double					m_dblOffset;
	double					m_dblStep;
	HBITMAP					m_hBitmap;
	
	BCGP_VISUAL_SCROLLBAR_STYLE		m_Style;
	CBCGPVisualScrollBarColorTheme	m_ColorTheme;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// CBCGPVisualContainer

class CBCGPVisualDataObject;

class BCGCBPRODLLEXPORT CBCGPVisualContainer : public CBCGPBaseAccessibleObject  
{
	friend class CBCGPBaseVisualCtrl;
	friend class CBCGPWndHostVisualObject;
	friend class CBCGPVisualContainerCtrl;
	friend class CBCGPVisualCollector;

	DECLARE_DYNCREATE(CBCGPVisualContainer)

public:
	enum BCGP_VISUAL_CONTAINER_GRID_STYLE
	{
		BCGP_VISUAL_CONTAINER_GRID_STYLE_FIRST		= -1,
		BCGP_VISUAL_CONTAINER_GRID_STYLE_CURRENT	= BCGP_VISUAL_CONTAINER_GRID_STYLE_FIRST,
		BCGP_VISUAL_CONTAINER_GRID_LINES			= 0,
		BCGP_VISUAL_CONTAINER_GRID_DOTS				= 1,
		BCGP_VISUAL_CONTAINER_GRID_STYLE_LAST		= BCGP_VISUAL_CONTAINER_GRID_DOTS
	};

	
// Construction
	CBCGPVisualContainer(CWnd* pWndOwner = NULL);
	virtual ~CBCGPVisualContainer();

// Attributes:
public:
	CWnd* GetOwner() const
	{
		return m_pWndOwner;
	}

	virtual CWnd* GetParentWnd() const 
	{ 
		return m_pWndOwner; 
	}

	virtual CWnd* SetOwner(CWnd* pWndOwner, BOOL bRedraw = FALSE);

	const CBCGPRect& GetRect() const
	{
		return m_rect;
	}

	void SetRect(const CBCGPRect& rect, BOOL bReposObjects = TRUE, BOOL bRedraw = FALSE);
	CBCGPRect GetBoundsRect(BOOL bOnlyVisible = FALSE) const;

	void EnableEditMode(BOOL bEnable = TRUE, DWORD dwEditFlags = 0);
	BOOL IsEditMode() const
	{
		return m_bIsEditMode;
	}

	void SetDirty(BOOL bSet = TRUE) const;
	BOOL IsDirty() const;

	void EnableImageCache(BOOL bEnable = TRUE);
	BOOL IsImageCache() const
	{
		return m_bCacheImage;
	}

	void EnableScrollBars(BOOL bEnable = TRUE, CBCGPVisualScrollBarColorTheme* pColorTheme = NULL, CBCGPVisualScrollBar::BCGP_VISUAL_SCROLLBAR_STYLE style = CBCGPVisualScrollBar::BCGP_VISUAL_SCROLLBAR_FLAT);
	BOOL HasScrollBars() const { return m_bScrollBars; }
	const CBCGPPoint& GetScrollOffset() const
	{
		return m_ptScrollOffset;
	}

	void SetOutlineBrush(const CBCGPBrush& br);
	void SetFillBrush(const CBCGPBrush& br);
	
	void SetGridBrush(const CBCGPBrush& br, BCGP_VISUAL_CONTAINER_GRID_STYLE style = BCGP_VISUAL_CONTAINER_GRID_STYLE_CURRENT);

	void SetGridSize(const CBCGPSize& size);
	void SetGridStyle(BCGP_VISUAL_CONTAINER_GRID_STYLE style);

	const CBCGPSize& GetGridSize() const
	{
		return m_sizeGrid;
	}

	BCGP_VISUAL_CONTAINER_GRID_STYLE GetGridStyle() const
	{
		return m_styleGrid;
	}

	const CBCGPBrush& GetOutlineBrush() const
	{
		return m_brOutline;
	}

	const CBCGPBrush& GetFillBrush() const
	{
		return m_brFill;
	}

	const CBCGPBrush& GetGridBrush(BCGP_VISUAL_CONTAINER_GRID_STYLE style = BCGP_VISUAL_CONTAINER_GRID_STYLE_CURRENT) const
	{
		if (style == BCGP_VISUAL_CONTAINER_GRID_STYLE_CURRENT)
		{
			style = m_styleGrid;
		}

		return (style == BCGP_VISUAL_CONTAINER_GRID_LINES) ? m_brGrid : m_brGridDots;
	}

	void SetDrawDynamicObjectsOnTop(BOOL bSet = TRUE);

	BOOL IsDrawDynamicObjectsOnTop() const
	{
		return m_bDrawDynamicObjectsOnTop;
	}

	const CBCGPSize& GetScaleRatio() const
	{
		return m_sizeScaleRatio;
	}

	double GetScaleRatioMid() const
	{
		if (m_sizeScaleRatio.cx == m_sizeScaleRatio.cy)
		{
			return m_sizeScaleRatio.cx;
		}

		return (m_sizeScaleRatio.cx + m_sizeScaleRatio.cy) / 2.0;
	}

	void SetScaleRatio(const CBCGPSize& sizeScaleRatio);
	void EnableScalingByMouseWheel(BOOL bEnable = TRUE, double dblMinScaleRatio = 0.1, double dblMaxScaleRatio = 4.0);

	UINT GetClickAndHoldID() const;
	CBCGPRect GetClickAndHoldRect();

	void SetClickAndHoldEvent(const CBCGPRect& rectBounds, UINT nEventID = 1001);	// Should be called inside OnMouseDown event
	void ResetGestureOptions();

// Overrides:
public:
	virtual void OnDraw(CBCGPGraphicsManager* pGM, const CBCGPRect& rectClip);
	virtual void Redraw();
	virtual void RedrawRect(const CBCGPRect& rect);
	
	virtual void OnChangeVisualManager();

	virtual void OnFillBackground(CBCGPGraphicsManager* pGM);
	virtual void OnDrawBorder(CBCGPGraphicsManager* pGM);
	virtual void OnDrawGrid(CBCGPGraphicsManager* pGM);

	virtual BOOL OnMouseDown(int nButton, const CBCGPPoint& pt);
	virtual void OnMouseUp(int nButton, const CBCGPPoint& pt);
	virtual BOOL OnMouseDblClick(int /*nButton*/, const CBCGPPoint& /*pt*/) { return FALSE; }
	virtual void OnMouseMove(const CBCGPPoint& pt);
	virtual void OnMouseLeave();
	virtual BOOL OnSetMouseCursor(const CBCGPPoint& pt);
	virtual BOOL OnMouseWheel(const CBCGPPoint& pt, short zDelta);
	virtual void OnCancelMode();
	virtual BOOL OnGetToolTip(const CBCGPPoint& pt, CString& strToolTip, CString& strDescr);
	virtual COLORREF GetInfoTipColor(const CBCGPPoint& pt, int nColor);
	virtual BOOL OnKeyboardDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL OnKeyboardUp(UINT nChar, UINT nRepCnt, UINT nFlags);

	virtual BOOL GetGestureConfig(CBCGPGestureConfig& /*gestureConfig*/) { return FALSE; }

	virtual BOOL OnGestureEventZoom(const CBCGPPoint& ptCenter, double dblZoomFactor);
	virtual BOOL OnGestureEventPan(const CBCGPPoint& ptFrom, const CBCGPPoint& ptTo, CBCGPSize& sizeOverPan);
	virtual BOOL OnGestureEventRotate(const CBCGPPoint& ptCenter, double dblAngle);
	virtual BOOL OnGestureEventTwoFingerTap(const CBCGPPoint& ptCenter);
	virtual BOOL OnGestureEventPressAndTap(const CBCGPPoint& ptPress, long lDelta);

	virtual void OnScaleRatioChanged(const CBCGPSize& sizeScaleRatioOld);

	virtual void OnClickAndHoldEvent(UINT nID, const CBCGPPoint& point);
	virtual void OnScroll(CBCGPVisualScrollBar* pScrollBar, double dblDelta);

	virtual void OnCalcBorderSize(CBCGPRect& rectNCArea);
	virtual void OnNcDraw(CBCGPGraphicsManager* pGM, const CBCGPRect& rect);
	virtual BOOL OnNcMouseDown(int nButton, const CBCGPPoint& pt);
	virtual void OnNcMouseUp(int nButton, const CBCGPPoint& pt);

	virtual void OnAfterCreateWnd() {}
	virtual void OnBeforeDestroyWnd() {}
	virtual void OnWndEnabled(BOOL bEnable);
	virtual void OnGridSelChanged(UINT /*nID*/) {}

	virtual BOOL OnCreateCustomControl(CBCGPWndHostVisualObject* pVisualObject, CWnd* pWnd, const CRect& rect, int nID, CWnd* pParent)
	{
		UNUSED_ALWAYS(pVisualObject);
		UNUSED_ALWAYS(pWnd);
		UNUSED_ALWAYS(rect);
		UNUSED_ALWAYS(nID);
		UNUSED_ALWAYS(pParent);

		// This method should be implemented in CBCGPVisualContainer-derived class.
		ASSERT(FALSE);
		return FALSE;
	}

// MSAA support:	
public:
	CBCGPBaseVisualObject* GetAccChild(int nIndex);
	long GetAccChildIndex(CBCGPBaseVisualObject* pObject);
	
	virtual HRESULT get_accChildCount(long *pcountChildren);
	virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
	virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	
	virtual HRESULT accSelect(long flagsSelect, VARIANT varChild);
	virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
	virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual HRESULT get_accParent(IDispatch **ppdispParent);

	virtual BOOL IsAccessibilityCompatible () { return TRUE; }

// Operations:
public:
	// Visual objects:
	BOOL Add(CBCGPBaseVisualObject* pObject, BOOL bAutoDestroy = TRUE);
	BOOL InsertAt(CBCGPBaseVisualObject* pObject, int nIndex, BOOL bAutoDestroy = TRUE);

	BOOL Remove(int nIndex);
	BOOL Remove(CBCGPBaseVisualObject* pObject);
	virtual void RemoveAll();
	void RemoveSelected();

	int GetCount() const;
	CBCGPBaseVisualObject* GetAt(int nIndex);

	CBCGPBaseVisualObject* GetByID(UINT nID);

	int FindIndex(const CBCGPBaseVisualObject* pObject) const;

	const CBCGPBaseVisualObject* operator[](int nIndex) const;
	CBCGPBaseVisualObject* GetFromPoint(const CPoint& point);

	// Selection:
	void Select(CBCGPBaseVisualObject* pObject, BOOL bAddToSel = FALSE);
	void SelectAll();
	virtual void ClearSelection(BOOL bRedraw = TRUE);

	BOOL IsSingleSel() const
	{
		return (m_dwEditFlags & BCGP_CONTAINER_SINGLE_SEL) == BCGP_CONTAINER_SINGLE_SEL;
	}

	int GetSelCount() const
	{
		return (int)m_lstSel.GetCount();
	}

	CBCGPBaseVisualObject* GetSel(int nIndex = 0) const;

	void SetHitTestSelected(BOOL bSet = TRUE);
	BOOL IsHitTestSelected() const { return m_bHitTestSelected; }

	// New objects:
	void SetAddObjectMode(BOOL bSet = TRUE)
	{
		m_bAddNewObjectMode = (m_bIsEditMode && bSet);
	}

	BOOL IsAddObjectModeEnabled () const
	{
		return m_bAddNewObjectMode;
	}

	virtual CBCGPBaseVisualObject* OnStartAddNewObject(const CBCGPPoint& /*pt*/)
	{
		return NULL;
	}

	virtual BOOL OnFinishAddNewObject(CBCGPBaseVisualObject* /*pObj*/, const CBCGPRect& /*rect*/)
	{
		return TRUE;
	}

	// Z-order:
	BOOL MoveForward(CBCGPBaseVisualObject* pObject);
	BOOL MoveBackward(CBCGPBaseVisualObject* pObject);
	BOOL MoveToFront(CBCGPBaseVisualObject* pObject);
	BOOL MoveToBack(CBCGPBaseVisualObject* pObject);

#ifndef _BCGPCHART_STANDALONE
	// Layout:
	void EnableLayout(BOOL bEnable = TRUE);
	BOOL IsLayoutEnabled() const
	{
		return m_pLayout != NULL;
	}

	CBCGPVisualLayout* GetLayout()
	{
		return m_pLayout;
	}
#endif

	virtual void DrawObjects(CBCGPGraphicsManager* pGM, CBCGPRect rectClip, DWORD dwFlags, const CBCGPPoint& ptOffset = CBCGPPoint(0, 0));
	virtual void DrawTrackingRects(CBCGPGraphicsManager* pGM);
	virtual void DrawSelectedArea(CBCGPGraphicsManager* pGM, const CBCGPRect& rectSel);

	virtual void FireSelectionChangedEvent();
	virtual void FireObjectMoveEvent(BOOL bAfter, BOOL bHasMoved);

	virtual void AdjustLayout();
	virtual void AdjustScrollBars(BOOL bRedraw = TRUE);

	// Serialization:
#ifndef _BCGPCHART_STANDALONE
	virtual BOOL LoadFromXML (UINT uiXMLResID);
	virtual BOOL LoadFromXML (LPCTSTR lpszXMLResID);
	virtual BOOL LoadFromFile (LPCTSTR lpszFileName);
	virtual BOOL LoadFromBuffer (LPCTSTR lpszXMLBuffer);

	virtual BOOL SaveToXML (const CString& strFileName);
#endif

	// Image export:
	BOOL ExportToImage(CBCGPGraphicsManager* pGM, CBCGPImage& image, BOOL bFullImage = FALSE);
	HBITMAP ExportToBitmap(CBCGPGraphicsManager* pGM, BOOL bFullImage = FALSE);

	BOOL CopyToClipboard(CBCGPGraphicsManager* pGM, BOOL bFullImage = FALSE);
	BOOL ExportToFile(const CString& strFilePath, CBCGPGraphicsManager* pGM, BOOL bFullImage = FALSE);

	BOOL SnapToGrid(CBCGPRect& rect);

// Implementation:
protected:
	virtual void MoveTrackingRects(CBCGPPoint pt);
	virtual void OnRemove (CBCGPBaseVisualObject* pObject);
	virtual void OnAdd (CBCGPBaseVisualObject* pObject);
	virtual BOOL OnCopyObject(CBCGPBaseVisualObject* pObject, const CBCGPRect& rectNew);

#if _MSC_VER < 1300
	DECLARE_OLECREATE(CBCGPVisualContainer)
#endif

// Attributes:
protected:
	CWnd*					m_pWndOwner;
	CBCGPRect				m_rect;
	BOOL					m_bScrollBars;
	BOOL					m_bIsEditMode;
	BOOL					m_bDrawDynamicObjectsOnTop;
	DWORD					m_dwEditFlags;
	BOOL					m_bCacheImage;
	CBCGPImage				m_ImageCache;
	CBCGPSize				m_sizeScaleRatio;

#ifndef _BCGPCHART_STANDALONE
	CBCGPVisualLayout*		m_pLayout;
#endif

	CBCGPBrush				m_brOutline;
	CBCGPBrush				m_brFill;

	CArray<CBCGPBaseVisualObject*, CBCGPBaseVisualObject*>	m_arObjects;
	CList<CBCGPBaseVisualObject*, CBCGPBaseVisualObject*>	m_lstSel;
	BOOL					m_bHitTestSelected;

	CBCGPPoint				m_ptDragStart;
	CBCGPPoint				m_ptDragFinish;
	CBCGPPoint				m_ptClick;
	CBCGPSize				m_szDrag;

	CBCGPBaseVisualObject*	m_pNewObject;
	BOOL					m_bAddNewObjectMode;

	CBCGPBrush				m_brSelFill;
	CBCGPBrush				m_brSelOutline;
	CBCGPBrush				m_brGrid;
	CBCGPBrush				m_brGridDots;

	CBCGPSize				m_sizeGrid;
	BCGP_VISUAL_CONTAINER_GRID_STYLE
							m_styleGrid;

	UINT					m_nDragMode;

	CBCGPGraphicsManager::BCGP_GRAPHICS_MANAGER	m_GMType;

	CBCGPVisualScrollBar	m_ScrollBarVert;
	CBCGPVisualScrollBar	m_ScrollBarHorz;
	CBCGPRect				m_rectBottomRight;
	BOOL					m_bDrawScrollBars;
	BOOL					m_bNCScrollBars;

	CBCGPPoint				m_ptScrollOffset;
	CBCGPSize				m_sizeScrollTotal;

	UINT					m_nClickAndHoldID;
	CBCGPRect				m_rectClickAndHold;

	BOOL					m_bScaleByMouseWheel;
	double					m_dblMinScaleRatio;
	double					m_dblMaxScaleRatio;

#if _MSC_VER < 1300
	IAccessible*			m_pStdObject;
	virtual void OnSetIAccessible(IAccessible* pIAccessible) { m_pStdObject = pIAccessible; }
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPWndHostColors

struct BCGCBPRODLLEXPORT CBCGPWndHostColors
{
	CBCGPWndHostColors()
	{
		m_clrBackground = (COLORREF)-1;
		m_clrText = (COLORREF)-1;
		m_clrBorder = (COLORREF)-1;
		m_clrHighlighted = (COLORREF)-1;
		m_clrHighlightedText = (COLORREF)-1;
	}
	
	CBCGPWndHostColors(const CBCGPWndHostColors& src)
	{
		CopyFrom(src);
	}
	
	void CopyFrom(const CBCGPWndHostColors& src)
	{
		m_clrBackground = src.m_clrBackground;
		m_clrText = src.m_clrText;
		m_clrBorder = src.m_clrBorder;
		m_clrHighlighted = src.m_clrHighlighted;
		m_clrHighlightedText = src.m_clrHighlighted;
	}
	
	COLORREF	m_clrBackground;
	COLORREF	m_clrText;
	COLORREF	m_clrBorder;
	COLORREF	m_clrHighlighted;
	COLORREF	m_clrHighlightedText;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPWndHostVisualObject

class BCGCBPRODLLEXPORT CBCGPWndHostVisualObject  : public CBCGPBaseVisualObject
{
	DECLARE_DYNAMIC(CBCGPWndHostVisualObject)
		
// Construction
public:
	CBCGPWndHostVisualObject(CBCGPVisualContainer* pContainer = NULL, CRuntimeClass* pRTI = NULL);
	virtual ~CBCGPWndHostVisualObject();

// Attributes:
public:
	CWnd* GetWnd();
	
	const CBCGPTextFormat& GetTextFormat() const
	{
		return m_textFormat;
	}
	
	void SetTextFormat(const CBCGPTextFormat& textFormat, BOOL bRedraw = TRUE);

	void SetColorTheme(const CBCGPWndHostColors& colors);
	const CBCGPWndHostColors& GetColorTheme() const { return m_Colors; }

// Overrides:
public:
	virtual CWnd* CreateWnd(const CRect& rect, UINT nID, CWnd* pParent);

	virtual void SetDirty(BOOL bSet = TRUE, BOOL bRedraw = FALSE)
	{
		BOOL bChanged = m_bIsDirty != bSet;

		if (bChanged)
		{
			m_ImageCache.Destroy();
		}

		CBCGPBaseVisualObject::SetDirty(bSet, bRedraw);

		if (bChanged)
		{
			ReposWnd();
		}
	}
	
	virtual void OnRectChanged(const CBCGPRect& rectOld) 
	{
		CBCGPBaseVisualObject::OnRectChanged(rectOld);
		ReposWnd();
	}

	virtual void OnAddToContainer(CBCGPVisualContainer* pContainer)
	{
		CBCGPBaseVisualObject::OnAddToContainer(pContainer);
		ReposWnd();
	}

	virtual void SetScrollOffset(const CBCGPPoint& ptScrollOffset)
	{
		CBCGPBaseVisualObject::SetScrollOffset(ptScrollOffset);
		ReposWnd();
	}

	virtual void ReposWnd();
	virtual void OnDraw(CBCGPGraphicsManager* pGM, const CBCGPRect& rectClip, DWORD dwFlags = BCGP_DRAW_STATIC | BCGP_DRAW_DYNAMIC);
	
protected:
	CBCGPImage			m_ImageCache;
	CBCGPTextFormat		m_textFormat;
	CWnd*				m_pWnd;
	CFont				m_Font;
	CRuntimeClass*		m_pRTI;
	CBCGPWndHostColors	m_Colors;
};

#ifndef BCGP_EXCLUDE_GRID_CTRL

/////////////////////////////////////////////////////////////////////////////
// CBCGPGridVisualObject

class CBCGPGridColors;
class CBCGPGridCtrl;

class BCGCBPRODLLEXPORT CBCGPGridVisualObject  : public CBCGPWndHostVisualObject
{
	DECLARE_DYNCREATE(CBCGPGridVisualObject)

// Construction
public:
	CBCGPGridVisualObject(CBCGPVisualContainer* pContainer = NULL, CRuntimeClass* pRTI = NULL);
	virtual ~CBCGPGridVisualObject();

// Attributes:
public:
	CBCGPGridCtrl* GetGridCtrl();
	
	void SetColorTheme(const CBCGPGridColors& colors);
	const CBCGPGridColors& GetColorTheme() const { return *m_pColorTheme; }

// Overrides:
protected:
	virtual CWnd* CreateWnd(const CRect& rect, UINT nID, CWnd* pParent);
	virtual void OnScaleRatioChanged(const CBCGPSize& sizeScaleRatioOld);

protected:
	CBCGPGridColors* m_pColorTheme;
};

#endif

/////////////////////////////////////////////////////////////////////////////
// CBCGPEditVisualObject

class BCGCBPRODLLEXPORT CBCGPEditVisualObject  : public CBCGPWndHostVisualObject
{
	DECLARE_DYNCREATE(CBCGPEditVisualObject)

// Construction
public:
	CBCGPEditVisualObject(CBCGPVisualContainer* pContainer = NULL, CRuntimeClass* pRTI = NULL);
	virtual ~CBCGPEditVisualObject();

// Attributes:
public:
	CBCGPEdit* GetEditCtrl();

	void SetInitialValue(const CString& strVal);
	const CString& GetInitialValue() const { return m_strInitialValue; }

	void SetColorTheme(const CBCGPEditColors& colors);
	const CBCGPEditColors& GetColorTheme() const { return m_ColorTheme; }

// Overrides:
protected:
	virtual CWnd* CreateWnd(const CRect& rect, UINT nID, CWnd* pParent);
	virtual void ReposWnd();

protected:
	CString			m_strInitialValue;
	CBCGPEditColors	m_ColorTheme;
};

BCGCBPRODLLEXPORT extern UINT BCGM_POSTREDRAW;
BCGCBPRODLLEXPORT extern UINT BCGM_CONTAINER_SELCHANGED;
BCGCBPRODLLEXPORT extern UINT BCGM_CONTAINER_SCALE_CHANGED;
BCGCBPRODLLEXPORT extern UINT BCGM_CONTAINER_OBJECT_MOVED;
BCGCBPRODLLEXPORT extern UINT BCGM_CONTAINER_BEFORE_OBJECT_MOVE;

#endif // !defined(AFX_BCGPVISUALCONTAINER_H__F3037CD5_27F5_47A1_9D7E_189F956D2CB9__INCLUDED_)
