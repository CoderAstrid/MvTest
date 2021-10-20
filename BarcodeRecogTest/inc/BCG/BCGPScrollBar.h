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
// BCGPScrollBar.h : header file
//

#if !defined(AFX_BCGPSCROLLBAR_H__A96CA752_C9F3_4FEB_8D6F_9057D17337A0__INCLUDED_)
#define AFX_BCGPSCROLLBAR_H__A96CA752_C9F3_4FEB_8D6F_9057D17337A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"

BCGCBPRODLLEXPORT extern UINT BCGM_ON_DRAW_SCROLLBAR;	// wParam - scrollbar ID, lParam - pointer to BCGPSCROLLBAR_DRAW_INFO
BCGCBPRODLLEXPORT extern UINT BCGM_REDRAW_SCROLLBAR; // Redraw internal scrollbars, wParam - SB_HORZ, SB_VERT or -1;

/////////////////////////////////////////////////////////////////////////////
// BCGPSCROLLBAR_DRAW_INFO struct, used in BCGM_ON_DRAW_SCROLLBAR message

class CBCGPScrollBar;

enum BCGPSB_PART
{
	BCGP_SCROLLBAR_BACKGROUND	= 0,
	BCGP_SCROLLBAR_BUTTON		= 1,
	BCGP_SCROLLBAR_THUMB		= 2,
};

struct BCGCBPRODLLEXPORT BCGPSCROLLBAR_DRAW_INFO
{
	CDC*			m_pDC;
	CBCGPScrollBar*	m_pScrollBar;
	BCGPSB_PART		m_part;
	CRect			m_rect;
	BOOL			m_bFirst;
	BOOL			m_bHorz;
	BOOL			m_bHighlighted;
	BOOL			m_bPressed;
	BOOL			m_bDisabled;

	BCGPSCROLLBAR_DRAW_INFO (
		CDC* pDC, CBCGPScrollBar* pScrollBar, BCGPSB_PART part, 
		CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, 
		BOOL bFirst, BOOL bDisabled)
	{
		m_pDC = pDC;
		m_pScrollBar = pScrollBar;
		m_part = part;
		m_rect = rect;
		m_bHorz = bHorz;
		m_bHighlighted = bHighlighted;
		m_bPressed = bPressed;
		m_bFirst = bFirst;
		m_bDisabled = bDisabled;
	}
};

/////////////////////////////////////////////////////////////////////////////
// BCGPSCROLLBAR_COLOR_THEME

struct BCGCBPRODLLEXPORT BCGPSCROLLBAR_COLOR_THEME
{
	friend class CBCGPScrollBar;

public:
	BCGPSCROLLBAR_COLOR_THEME()
	{
		Reset();
	}

	void Reset()
	{
		m_clrFace = (COLORREF)-1;
		m_clrFacePressed = (COLORREF)-1;
		m_clrBorder = (COLORREF)-1;
		m_clrButton = (COLORREF)-1;
		m_clrButtonPressed = (COLORREF)-1;
		m_clrButtonBorder = (COLORREF)-1;
		m_clrButtonBorderPressed = (COLORREF)-1;
		m_clrButtonHighlighted = (COLORREF)-1;
		m_clrButtonGradient = (COLORREF)-1;
		m_clrButtonHighlightedGradient = (COLORREF)-1;
		m_clrButtonPressedGradient = (COLORREF)-1;

		m_bHighlightEffect = FALSE;
		m_b3DEffect = FALSE;
	}

	BOOL IsValid() const
	{
		return m_clrFace != (COLORREF)-1;
	}

	COLORREF	m_clrFace;
	COLORREF	m_clrFacePressed;
	COLORREF	m_clrBorder;
	COLORREF	m_clrButton;
	COLORREF	m_clrButtonPressed;
	COLORREF	m_clrButtonBorder;
	COLORREF	m_clrButtonBorderPressed;

	BOOL		m_bHighlightEffect;
	BOOL		m_b3DEffect;

protected:
	COLORREF	m_clrButtonHighlighted;
	COLORREF	m_clrButtonGradient;
	COLORREF	m_clrButtonHighlightedGradient;
	COLORREF	m_clrButtonPressedGradient;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPScrollBarImpl class

class BCGCBPRODLLEXPORT CBCGPScrollBarImpl
{
	friend class CBCGPInternalScrollBarWrapper;

public:
	enum BCGPSB_HITTEST
	{
		BCGP_HT_NOWHERE       = 0,
		BCGP_HT_BUTTON_LEFT   = 1,
		BCGP_HT_BUTTON_UP	  = BCGP_HT_BUTTON_LEFT,
		BCGP_HT_BUTTON_LTUP   = BCGP_HT_BUTTON_LEFT,
		BCGP_HT_BUTTON_RIGHT  = 2,
		BCGP_HT_BUTTON_DOWN   = BCGP_HT_BUTTON_RIGHT,
		BCGP_HT_BUTTON_RTDN   = BCGP_HT_BUTTON_RIGHT,
		BCGP_HT_THUMB         = 3,
		BCGP_HT_CLIENT_LEFT   = 4,
		BCGP_HT_CLIENT_UP	  = BCGP_HT_CLIENT_LEFT,
		BCGP_HT_CLIENT_LTUP   = BCGP_HT_CLIENT_LEFT,
		BCGP_HT_CLIENT_RIGHT  = 5,
		BCGP_HT_CLIENT_DOWN   = BCGP_HT_CLIENT_RIGHT,
		BCGP_HT_CLIENT_RTDN   = BCGP_HT_CLIENT_RIGHT,
		BCGP_HT_CLIENT        = 6
	};

	void SendPosBeforeEndThumb(BOOL bSendPosBeforeEndThumb)
	{
		m_bSendPosBeforeEndThumb = bSendPosBeforeEndThumb;
	}

protected:
	CBCGPScrollBarImpl();

	void SetRect(const CRect& rect)
	{
		m_rect = rect;
	}

	void SetHorz(BOOL bSet)
	{
		m_bHorz = bSet;
	}

	BOOL IsHorz() const
	{
		return m_bHorz;
	}

	const CRect& GetRect() const
	{
		return m_rect;
	}

	CRect GetThumbRect(BOOL bIsEnabled, const SCROLLINFO& si) const;

	void Render(CDC* pDC, BOOL bIsEnabled, const SCROLLINFO& si, const CPoint& ptOffset = CPoint(0, 0));

	virtual void DoPaintThumb (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bDisabled);
	virtual void DoPaintButton (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);
	virtual void DoPaintBackground (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	BOOL ProcessEvent(CWnd* pWnd);
	BOOL ProcessMouseDown(CWnd* pWnd, CPoint point);
	BOOL ProcessMouseUp(CWnd* pWnd, CPoint point);
    BOOL ProcessMouseDblClk(CWnd* pWnd, CPoint point);
	BOOL ProcessMouseMove(CWnd* pWnd, BOOL bIsMouseDown, CPoint point);
	void ProcessMouseLeave(CWnd* pWnd);
	BOOL ProcessCancelMode(CWnd* pWnd, CPoint point);
	BOOL ProcessTimer(CWnd* pWnd, UINT_PTR nIDEvent);
	int PosFromThumb (int thumb, const CSize& szClamp, const SCROLLINFO& si);

	virtual CBCGPScrollBar* GetScrollBarCtrl() { return NULL; }

	BCGPSB_HITTEST DoHitTest(CWnd* pWnd, const CPoint& point) const;

	BOOL _GetScrollInfo(CWnd* pWnd, SCROLLINFO& si) const;
	int _GetScrollPos(CWnd* pWnd) const;
	int _SetScrollPos(CWnd* pWnd, int nPos, BOOL bRedraw = TRUE) const;
	void _RedrawScrollBar(CWnd* pWnd) const;

	BOOL TimerStarted() const {	return m_TimerDown != 0 || m_Timer != 0;	}

	BOOL			m_bInternal;
	CRect			m_rect;
	BOOL			m_bHorz;
	BCGPSB_HITTEST	m_HitTest;
	BCGPSB_HITTEST	m_HitPressed;

	CRect			m_rectTrackThumb;
	CRect			m_rectTrackThumbStart;

	CPoint			m_ptTrackStart;
	int				m_TrackPos;

	BOOL			m_bTracked;
	DWORD			m_dwDisabledArrows;

	UINT_PTR		m_TimerDown;
	UINT_PTR		m_Timer;

	CWnd*			m_pLastCapture;

	BOOL			m_bSendPosBeforeEndThumb;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPScrollBar window

class BCGCBPRODLLEXPORT CBCGPScrollBar :	public CScrollBar,
											public CBCGPScrollBarImpl
{
	DECLARE_DYNAMIC(CBCGPScrollBar)

// Construction
public:
	CBCGPScrollBar();

	enum BCGPSB_STYLE
	{
		BCGP_SBSTYLE_FIRST				  = 0,
		BCGP_SBSTYLE_DEFAULT				= BCGP_SBSTYLE_FIRST,	// Windows default style,
		BCGP_SBSTYLE_VISUAL_MANAGER			= 1,	// Defined by currently activated Visual Manager
		BCGP_SBSTYLE_VISUAL_MANAGER_FRAME	= 2,	// Used in frame window,
		BCGP_SBSTYLE_OWNER_DRAW				= 3,	// Developer should handle BCGM_ON_DRAW_SCROLLBAR message,
		BCGP_SBSTYLE_CUSTOM					= 4,	// Developer should handle BCGM_ON_DRAW_SCROLLBAR message,
		BCGP_SBSTYLE_LAST				   = BCGP_SBSTYLE_CUSTOM
	};

// Attributes
public:
	void SetVisualStyle (BCGPSB_STYLE style, BOOL bIsRedraw = TRUE)
	{
		ASSERT (BCGP_SBSTYLE_FIRST <= style && style <= BCGP_SBSTYLE_LAST);
		ASSERT (style != BCGP_SBSTYLE_CUSTOM);

		m_Style = style;

		if (bIsRedraw && GetSafeHwnd () != NULL)
		{
			RedrawWindow ();
		}
	}

	BCGPSB_STYLE GetVisualStyle () const
	{
		return m_Style;
	}

	void SetColorTheme(const BCGPSCROLLBAR_COLOR_THEME& theme, BOOL bIsRedraw = TRUE)
	{
		if (!theme.IsValid())
		{
			// All members should be specified!
			ASSERT(FALSE);
			return;
		}

		m_Style = BCGP_SBSTYLE_CUSTOM;
		m_ColorTheme = theme;

		RebuildCustomColors();

		if (bIsRedraw && GetSafeHwnd () != NULL)
		{
			RedrawWindow ();
		}
	}

	const BCGPSCROLLBAR_COLOR_THEME& GetColorTheme() const
	{
		return m_ColorTheme;
	}

	BOOL IsActive () const
	{
		return m_HitTest != BCGP_HT_NOWHERE || m_HitPressed != BCGP_HT_NOWHERE;
	}

	BOOL	m_bAutoDestoyWindow;
	BOOL	m_bOnGlass;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPScrollBar)
	protected:
	virtual void PreSubclassWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage (MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBCGPScrollBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPScrollBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM,LPARAM);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcDestroy();
	//}}AFX_MSG
	afx_msg LRESULT OnBCGSetControlAero (WPARAM, LPARAM);
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

	virtual void DoPaint (CDC* pDC);
	virtual void Process ();

	virtual void DoPaintThumb (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bDisabled);
	virtual void DoPaintButton (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);
	virtual void DoPaintBackground (CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bFirst, BOOL bDisabled);

	virtual CBCGPScrollBar* GetScrollBarCtrl() { return this; }
	virtual BCGPSB_HITTEST HitTest (const CPoint& point) const;

	void RebuildCustomColors();

	COLORREF DrawCustomBox(CDC* pDC, CRect rect, BOOL bHorz, BOOL bHighlighted, BOOL bPressed, BOOL bDisabled);

protected:
	BCGPSB_STYLE				m_Style;
	BCGPSCROLLBAR_COLOR_THEME	m_ColorTheme;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPInternalScrollBarWrapper

class BCGCBPRODLLEXPORT CBCGPInternalScrollBarWrapper
{
protected:
	CBCGPInternalScrollBarWrapper(CWnd* pWndOwner)
	{
		m_pWndOwner = pWndOwner;
		m_dwScrool = 0;
		m_dwScroolEx = 0;
		m_bSuppressMessage = FALSE;

		m_ScrollHorz.SetHorz(TRUE);
		m_ScrollVert.SetHorz(FALSE);

		m_rectSizeBox.SetRectEmpty();

		for (int i = 0; i < 2; i++)
		{
			ZeroMemory(&m_ScrollInfo[i], sizeof(SCROLLINFO));
		}
	}

	LRESULT InternalSB_WrapperWindowProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL& bProcessed);

	virtual LRESULT InternalSB_ControlWindowProc(UINT message, WPARAM wParam, LPARAM lParam) = 0;

	virtual BOOL IsInternalScrollBarThemed() const
	{
		return TRUE;
	}

	virtual BOOL InternalSB_OnThumbTrack(int /*nBar*/, int /*nTrackPos*/)
	{
		return FALSE;
	}

	virtual BOOL InternalSB_OnMessageRedraw(UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
	{
		return message == WM_PAINT || message == WM_MOUSEWHEEL;
	}

	void _RedrawScrollBars(HRGN hRgn, int nBar = -1);

	CWnd*				m_pWndOwner;
	DWORD				m_dwScrool;
	DWORD				m_dwScroolEx;
	BOOL				m_bSuppressMessage;

	CBCGPScrollBarImpl	m_ScrollVert;
	CBCGPScrollBarImpl	m_ScrollHorz;

	CRect				m_rectSizeBox;

	SCROLLINFO			m_ScrollInfo[2];
};

#pragma warning (push) 
#pragma warning (disable : 4355)

template<class T> 
class TBCGPInternalScrollBarWrapperWnd :	public T,
											public CBCGPInternalScrollBarWrapper
{
public:
	virtual ~TBCGPInternalScrollBarWrapperWnd()
	{
	}

protected:
	TBCGPInternalScrollBarWrapperWnd();
	TBCGPInternalScrollBarWrapperWnd(LPCTSTR lpszParam);
	TBCGPInternalScrollBarWrapperWnd(UINT nIDParam);

	virtual void PreSubclassWindow()
	{
		T::PreSubclassWindow();

		m_dwScrool = GetStyle() & (WS_HSCROLL | WS_VSCROLL);
		m_dwScroolEx = GetExStyle() & WS_EX_LEFTSCROLLBAR;
	}
	
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		BOOL bProcessed = FALSE;
		LRESULT lResult = InternalSB_WrapperWindowProc(message, wParam, lParam, bProcessed);

		return bProcessed ? lResult : InternalSB_ControlWindowProc(message, wParam, lParam);
	}

	virtual LRESULT InternalSB_ControlWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		return T::WindowProc(message, wParam, lParam);
	}

	virtual BOOL InternalSB_OnThumbTrack(int nBar, int nTrackPos);
	virtual BOOL InternalSB_OnMessageRedraw(UINT message, WPARAM wParam, LPARAM lParam);
};

template<class T>
inline TBCGPInternalScrollBarWrapperWnd<T>::TBCGPInternalScrollBarWrapperWnd()
    : T()
    , CBCGPInternalScrollBarWrapper(this)
{
}

template<class T>
inline TBCGPInternalScrollBarWrapperWnd<T>::TBCGPInternalScrollBarWrapperWnd(LPCTSTR /*lpszParam*/)
    : T()
    , CBCGPInternalScrollBarWrapper(this)
{
}

template<class T>
inline TBCGPInternalScrollBarWrapperWnd<T>::TBCGPInternalScrollBarWrapperWnd(UINT /*nIDParam*/)
	: T()
	, CBCGPInternalScrollBarWrapper(this)
{
}

template<class T>
inline BOOL TBCGPInternalScrollBarWrapperWnd<T>::InternalSB_OnThumbTrack(int nBar, int nTrackPos)
{
	return CBCGPInternalScrollBarWrapper::InternalSB_OnThumbTrack(nBar, nTrackPos);
}

template<class T>
inline BOOL TBCGPInternalScrollBarWrapperWnd<T>::InternalSB_OnMessageRedraw(UINT message, WPARAM wParam, LPARAM lParam)
{
	return CBCGPInternalScrollBarWrapper::InternalSB_OnMessageRedraw(message, wParam, lParam);
}

template<>
inline BOOL TBCGPInternalScrollBarWrapperWnd<CListCtrl>::InternalSB_OnThumbTrack(int nBar, int nTrackPos)
{
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(SCROLLINFO);

	GetScrollInfo(nBar, &si, SIF_TRACKPOS);

	nTrackPos -= si.nTrackPos;

	if ((GetStyle() & LVS_REPORT) && nBar == SB_VERT)
	{
		CRect rect;
		GetItemRect(0, rect, LVIR_BOUNDS);
		nTrackPos *= rect.Height();
	}

	ListView_Scroll(GetSafeHwnd(), nBar == SB_HORZ ? nTrackPos : 0, nBar == SB_HORZ ? 0 : nTrackPos);

	return FALSE;
}

template<>
inline BOOL TBCGPInternalScrollBarWrapperWnd<CListCtrl>::InternalSB_OnMessageRedraw(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == LVM_GETEXTENDEDLISTVIEWSTYLE)
	{
		return FALSE;
	}

	return CBCGPInternalScrollBarWrapper::InternalSB_OnMessageRedraw(message, wParam, lParam) || 
		(WM_KEYFIRST <= message && message <= WM_KEYLAST && (ListView_GetExtendedListViewStyle(GetSafeHwnd()) & 0x00010000/*LVS_EX_DOUBLEBUFFER*/) != 0);
}

template<>
inline BOOL TBCGPInternalScrollBarWrapperWnd<CTreeCtrl>::InternalSB_OnThumbTrack(int nBar, int nTrackPos)
{
	if (nBar != SB_HORZ)
	{
		SetScrollPos(nBar, nTrackPos, TRUE);
	}

	return FALSE;
}

template<>
inline BOOL TBCGPInternalScrollBarWrapperWnd<CTreeCtrl>::InternalSB_OnMessageRedraw(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == (TV_FIRST + 45)/*TVM_GETEXTENDEDSTYLE*/)
	{
		return FALSE;
	}

	return CBCGPInternalScrollBarWrapper::InternalSB_OnMessageRedraw(message, wParam, lParam) || 
		(WM_KEYFIRST <= message && message <= WM_KEYLAST) && ((DWORD)SNDMSG(GetSafeHwnd(), (TV_FIRST + 45)/*TVM_GETEXTENDEDSTYLE*/, 0, 0) & 0x0004/*TVS_EX_DOUBLEBUFFER*/) != 0;
}

#pragma warning (pop)

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPSCROLLBAR_H__A96CA752_C9F3_4FEB_8D6F_9057D17337A0__INCLUDED_)
