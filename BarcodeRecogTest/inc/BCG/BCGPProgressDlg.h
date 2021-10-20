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
// BCGPProgressDlg.h : header file
//

#if !defined(AFX_BCGPPROGRESSDLG_H__38133669_1DE1_42D5_98C8_380D6F27C875__INCLUDED_)
#define AFX_BCGPPROGRESSDLG_H__38133669_1DE1_42D5_98C8_380D6F27C875__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPDialog.h"
#include "BCGPButton.h"
#include "BCGPStatic.h"
#include "BCGPProgressCtrl.h"
#include "bcgprores.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPProgressDlgParams

class BCGCBPRODLLEXPORT CBCGPProgressDlgParams
{
public:
	CBCGPProgressDlgParams()
	{
		m_nRangeMin = 0;
		m_nRangeMax = 100;
		m_nStep = 10;
		m_bShowCancel = TRUE;
		m_bShowProgress = TRUE;
		m_bShowInfiniteProgress = FALSE;
		m_bShowPercentage = TRUE;
		m_bDisableParentWnd = TRUE;
		m_bDialogLook = FALSE;
		m_nHeaderHeight = 0;
		m_nAnimationResID = 0;
		m_nAnimationHeight = 60;
		m_bWaitForMessages = TRUE;
		m_MarqueeStyle = CBCGPProgressCtrl::BCGP_MARQUEE_DEFAULT;
		m_clrMarquee = (COLORREF)-1;
		m_clrMarqueeGradient = (COLORREF)-1;
	}

	CString	m_strCaption;
	CString	m_strMessage;
	CString	m_strMessage2;

	long	m_nRangeMin;
	long	m_nRangeMax;
	long	m_nStep;

	BOOL	m_bShowCancel;
	BOOL	m_bShowProgress;
	BOOL	m_bShowInfiniteProgress;
	BOOL	m_bShowPercentage;
	BOOL	m_bDialogLook;
	int		m_nHeaderHeight;

	CBCGPProgressCtrl::BCGP_MARQUEE_STYLE m_MarqueeStyle;
	COLORREF	m_clrMarquee;
	COLORREF	m_clrMarqueeGradient;

	UINT	m_nAnimationResID;
	CString	m_strAnimationPath;
	int		m_nAnimationHeight;

	BOOL	m_bDisableParentWnd;
	BOOL	m_bWaitForMessages;

	CBCGPProgressDlgParams& operator= (const CBCGPProgressDlgParams& src)
	{
		m_strCaption		= src.m_strCaption;
		m_strMessage		= src.m_strMessage;    
		m_strMessage2		= src.m_strMessage2;   
		                 	                  
		m_nRangeMin			= src.m_nRangeMin;     
		m_nRangeMax     	= src.m_nRangeMax;     
		m_nStep				= src.m_nStep;
		                 	                  
		m_bShowCancel   	= src.m_bShowCancel;   
		m_bShowProgress		= src.m_bShowProgress;
		m_bShowInfiniteProgress = src.m_bShowInfiniteProgress;
		m_bShowPercentage	= src.m_bShowPercentage;

		m_bDisableParentWnd	= src.m_bDisableParentWnd;

		m_bDialogLook		= src.m_bDialogLook;
		m_nHeaderHeight		= src.m_nHeaderHeight;

		m_nAnimationResID	= src.m_nAnimationResID;
		m_strAnimationPath	= src.m_strAnimationPath;
		m_nAnimationHeight	= src.m_nAnimationHeight;

		m_bWaitForMessages	= src.m_bWaitForMessages;

		m_MarqueeStyle		= src.m_MarqueeStyle;
		m_clrMarquee		= src.m_clrMarquee;
		m_clrMarqueeGradient= src.m_clrMarqueeGradient;

		return *this;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPProgressDlgCtrl

class CBCGPProgressDlgCtrl : public CBCGPProgressCtrl
{
	friend class CBCGPProgressDlg;

	CBCGPProgressDlgCtrl(CBCGPProgressDlg& dlg) :
		m_dlg(dlg)
	{
	}

	virtual void OnAnimationIdle();
	
	CBCGPProgressDlg& m_dlg;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPProgressDlg dialog

class BCGCBPRODLLEXPORT CBCGPProgressDlg : public CBCGPDialog
{
	friend class CBCGPProgressDlgCtrl;

// Construction
public:
	CBCGPProgressDlg();
	virtual ~CBCGPProgressDlg();

// Operations:

    virtual BOOL Create (const CBCGPProgressDlgParams& params, CWnd* pParent = NULL);

	void SetMessage (const CString& strMessage);
	void SetMessage2 (const CString& strMessage);

    long StepIt (BOOL bWaitForMessages = TRUE);

    long SetPos(long nCurPos);

    long SetPos(long nCurPos, BOOL bWaitForMessages);

	long GetPos () const
	{
		return m_nCurPos; 
	}

	long OffsetPos (long nPos);

    BOOL IsCancelled ()
	{
		BOOL bCancelled = m_bCancelled;
		m_bCancelled = FALSE;

		return bCancelled;
	}

	void RedrawHeader ();

	virtual BOOL PumpMessages ();

	const CBCGPProgressDlgParams& GetParameters() const { return m_Params; }

// Dialog Data
	//{{AFX_DATA(CBCGPProgressDlg)
	enum { IDD = IDD_BCGBARRES_PROGRESS_DLG };
	CBCGPProgressDlgCtrl	m_wndProgress;
	CBCGPStatic	m_wndLine;
	CBCGPButton	m_wndCancel;
	CBCGPStatic	m_wndProgressPerc;
	CBCGPStatic	m_wndMessage2;
	CBCGPStatic	m_wndMessage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPProgressDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	virtual void OnDrawHeader (CDC* pDC, CRect rect)
	{
		UNREFERENCED_PARAMETER(pDC);
		UNREFERENCED_PARAMETER(rect);
	}

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBCGPProgressDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	afx_msg LRESULT OnUMPumpMessages(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

	virtual void UpdatePercent (long nNewPos);
	virtual void ReEnableParent ();

	void OffsetWnd (CWnd* pWnd, int cy);

	BOOL IsWindowBackground () const
	{
		return !IsVisualManagerStyle () && !HasAeroMargins () && !m_Params.m_bDialogLook;
	}

protected:
	BOOL					m_bCancelled;
	BOOL					m_bParentDisabled;
	BOOL					m_bWaitForMessages;
	BOOL					m_bAnimation;
	long					m_nCurPos;
	CBCGPProgressDlgParams	m_Params;
	int						m_yLine;
	CAnimateCtrl			m_wndAnimation;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPPROGRESSDLG_H__38133669_1DE1_42D5_98C8_380D6F27C875__INCLUDED_)
