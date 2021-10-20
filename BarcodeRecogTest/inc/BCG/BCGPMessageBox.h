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
// BCGPMessageBox.h : header file
//

#if !defined(AFX_BCGPMESSAGEBOX_H__74E5EE7A_9BED_4A34_B359_95A187BA50CF__INCLUDED_)
#define AFX_BCGPMESSAGEBOX_H__74E5EE7A_9BED_4A34_B359_95A187BA50CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPDialog.h"
#include "BCGPButton.h"

struct BCGCBPRODLLEXPORT BCGP_MSGBOXPARAMS : public MSGBOXPARAMS
{
	enum BCGP_MSGBOX_POSITION
	{
		BCGP_MSGBOX_POSITION_NO_CENTER     = 0,
		BCGP_MSGBOX_POSITION_CENTER_PARENT = 1,
		BCGP_MSGBOX_POSITION_CENTER_OWNER  = 2
	};

	BOOL	bUseNativeControls;
	BOOL	bUseNativeCaption;
	BOOL	bDrawButtonsBanner;

	BOOL    bShowCheckBox;
	BOOL    bIsChecked;
	BOOL    bShowSeparator;  // Draw separator line above check box (only if check box present).
	LPCTSTR lpszCheckBoxText; 
	UINT*   puiAutoRespond;  // [in/out] points to variable that receives selected button ID when user checks "Don't ask me..." checkbox.
	HFONT	hfontText;
	HFONT	hfontButtons;
	LPCTSTR	lpszHeader;		// "Main" text displayed on top

	BOOL    bIgnoreStandardButtons; // Show user-defined buttons only

	BCGP_MSGBOX_POSITION boxPosition;

	BOOL    bHeaderWordBreak; //
	BOOL    bMessageWordBreak; //

	enum
	{
		UserButtonsCount = 4
	};

	LPCTSTR lpszUserButtonText[UserButtonsCount];
	UINT    uiUserButtonID[UserButtonsCount];

	inline BCGP_MSGBOXPARAMS ()
	{
		ZeroMemory (this, sizeof (BCGP_MSGBOXPARAMS));
		cbSize = sizeof (MSGBOXPARAMS);

		bDrawButtonsBanner = TRUE;
		boxPosition = BCGP_MSGBOX_POSITION_CENTER_PARENT;

		bHeaderWordBreak = TRUE;
		bMessageWordBreak = TRUE;
	}
};

class BCGCBPRODLLEXPORT CBCGPMessageBox : public CBCGPDialog
{
public:
	CBCGPMessageBox(const MSGBOXPARAMS* pParams);
	CBCGPMessageBox(const BCGP_MSGBOXPARAMS* pParams);
	~CBCGPMessageBox();

	enum { IDD = IDD_BCGBARRES_MSG_BOX };

	// Implementation
protected:
	void DoInitDialog();
	void Initialize ();
	void AddButton (UINT id, HINSTANCE hInst, LPCTSTR lpszCaption = NULL);
	virtual BOOL CheckAutoCenter() {	return FALSE;	}

	CString GetString (LPCTSTR lpszText, LPCTSTR lpszDefault = NULL) const;
	// Generated message map functions
	//{{AFX_MSG(CBCGPMessageBox)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButton(UINT nID);
	afx_msg LRESULT OnHelp(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnGetDefID(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnSetDefID(WPARAM wp, LPARAM lp);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	// Overridables
protected:
	virtual BOOL PreTranslateMessage (MSG* pMsg);
	virtual void DrawHeader(CDC* pDC);
	virtual void DrawText(CDC* pDC);

#if _MSC_VER >= 1300
	//Accessibility
public:
	virtual HRESULT get_accChildCount(long *pcountChildren);
	virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
	virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
	virtual HRESULT get_accHelp(VARIANT varChild, BSTR* pszHelp);
	virtual HRESULT get_accHelpTopic(BSTR* pszHelpFile, VARIANT varChild, long* pidTopic);
	virtual HRESULT get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut);
	virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
#endif

	// Change these attributes to modify message box global appearance:
public:
	static BOOL	m_bUseNativeControls;
	static BOOL	m_bUseNativeCaption;
	static BOOL	m_bDontUseDefaultIcon;
	static BOOL	m_bShowImmediately;

protected:
	BCGP_MSGBOXPARAMS m_Params;
	HWND m_hwndOwner;

	CBCGPToolBarImages	m_Icon;
	CString m_strMessageCaption;
	CString	m_strMessageHeader;
	CString m_strMessageText;
	CString m_strCheckBox;
	CFont   m_fntHeader;
	CFont   m_fntText;
	CFont   m_fntButtons;
	int     m_nDefaultButtonIndex;
	int     m_nAccTextIndex;
	int		m_nAccHeaderIndex;

	CArray <CWnd*, CWnd*> m_arrButtons;
	CBCGPButton m_wndDontAskCheckBox;
	bool    m_bHasCancelButton;
	DWORD   m_dwDrawTextFlags;
	CRect   m_rectButtons;
	CRect   m_rectIcon;
	CRect   m_rectHeader;
	CRect   m_rectText;
	int     m_cySeparatorLine;
	CPoint  m_ptNextButtonPos;
	bool    m_bRightAlignment;

	// Initial sizes
	CRect   m_rectClientMargins;
	CRect   m_rectButtonsMargins;
	int     m_cxIconSpacing;  // spacing between an icon and message text
	CSize   m_szButton;
	int     m_cyCheckBoxHeight;
	int		m_cyCheckBoxSpacing;
	int     m_cxButtonSpacing;  // gap between buttons
};

int BCGCBPRODLLEXPORT BCGPMessageBox (HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, LPCTSTR lpszCheckBoxLabel = NULL, BOOL* pCheckBoxResult = NULL, LPCTSTR lpszHeader = NULL);
int BCGCBPRODLLEXPORT BCGPMessageBoxEx (HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, WORD wLanguageId, LPCTSTR lpszCheckBoxLabel = NULL, BOOL* pCheckBoxResult = NULL, LPCTSTR lpszHeader = NULL);
int BCGCBPRODLLEXPORT BCGPMessageBoxIndirect (const MSGBOXPARAMS* pMsgBoxParams);
int BCGCBPRODLLEXPORT BCGPMessageBoxIndirect (const BCGP_MSGBOXPARAMS* pMsgBoxParams);

int BCGCBPRODLLEXPORT BCGPMessageBox (LPCTSTR lpszText, UINT nType = MB_OK, LPCTSTR lpszCheckBoxLabel = NULL, BOOL* pCheckBoxResult = NULL, LPCTSTR lpszHeader = NULL);
int BCGCBPRODLLEXPORT BCGPMessageBox (UINT nIDPrompt, UINT nType = MB_OK, UINT nIDCheckBoxPrompt = 0, BOOL* pCheckBoxResult = NULL, LPCTSTR lpszHeader = NULL);

inline int BCGPShowMessageBox(BOOL bIsThemed, CWnd* pWnd, LPCTSTR lpszText, LPCTSTR lpCaption = NULL, UINT nType = MB_OK)
{
	return bIsThemed ? 
		BCGPMessageBox(pWnd->GetSafeHwnd(), lpszText, lpCaption, nType) :
		pWnd->MessageBox(lpszText, lpCaption, nType);
}

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPMESSAGEBOX_H__74E5EE7A_9BED_4A34_B359_95A187BA50CF__INCLUDED_)
