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

#if !defined(AFX_BCGPEDIT_H__A7B40464_1C05_4981_A5F2_E21D74058A09__INCLUDED_)
#define AFX_BCGPEDIT_H__A7B40464_1C05_4981_A5F2_E21D74058A09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BCGPEdit.h : header file
//

#include "BCGCBPro.h"
#include "BCGPScrollBar.h"

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
#include "BCGPToolBarImages.h"
#include "BCGPDropDownList.h"

extern BCGCBPRODLLEXPORT UINT BCGM_EDIT_ON_FILL_AUTOCOMPLETE_LIST;

class CBCGPEdit;
class CBCGPComboBox;

/////////////////////////////////////////////////////////////////////////////
// CBCGPEditDropDownList

class BCGCBPRODLLEXPORT CBCGPEditDropDownList : public CBCGPDropDownList
{
	DECLARE_DYNAMIC(CBCGPEditDropDownList)

	friend class CBCGPEdit;

public:
// Construction
	CBCGPEditDropDownList(CBCGPEdit* pEdit);

// Overrides
public:
	virtual void OnChooseItem (UINT uidCmdID);
	virtual BOOL Compare(const CStringList& lstStrings) const;

// Attributes
protected:
	CBCGPEdit* m_pEdit;
};

#endif

class CBCGPCalculatorPopup;
class CBCGPCalculator;
class CBCGPDialog;

/////////////////////////////////////////////////////////////////////////////
// CBCGPEditColors

struct BCGCBPRODLLEXPORT CBCGPEditColors
{
	CBCGPEditColors()
	{
		m_clrBackground = (COLORREF)-1;
		m_clrText = (COLORREF)-1;
		m_clrPrompt = (COLORREF)-1;
		m_clrBorder = (COLORREF)-1;
		m_clrBorderFocused = (COLORREF)-1;
	}
	
	CBCGPEditColors(const CBCGPEditColors& src)
	{
		CopyFrom(src);
	}
	
	void CopyFrom(const CBCGPEditColors& src)
	{
		m_clrBackground = src.m_clrBackground;
		m_clrText = src.m_clrText;
		m_clrPrompt = src.m_clrPrompt;
		m_clrBorder = src.m_clrBorder;
		m_clrBorderFocused = src.m_clrBorderFocused;
	}
	
	COLORREF	m_clrBackground;
	COLORREF	m_clrText;
	COLORREF	m_clrPrompt;
	COLORREF	m_clrBorder;
	COLORREF	m_clrBorderFocused;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPEdit window

class BCGCBPRODLLEXPORT CBCGPEdit : public TBCGPInternalScrollBarWrapperWnd<CEdit>
{
	DECLARE_DYNAMIC(CBCGPEdit)

	friend class CBCGPCalculator;
	friend class CBCGPEditDropDownList;
	friend class CBCGPParentEditPtr;
	friend class CBCGPComboBox;
	friend class CBCGPSpinButtonCtrl;

// Construction
public:
	CBCGPEdit();

// Attributes
public:
	enum BrowseMode
	{
		BrowseMode_None,
		BrowseMode_Default,
		BrowseMode_Calculator,
		BrowseMode_File,
		BrowseMode_Folder,
		BrowseMode_PopupDialog,
		BrowseMode_PasswordPreview,
	};

	CBCGPEdit::BrowseMode GetMode () const
	{
		return m_Mode;
	}

	BOOL				m_bVisualManagerStyle;
	BOOL				m_bOnGlass;

	void SetPrompt(LPCTSTR lpszPrompt, COLORREF clrText = (COLORREF)-1, BOOL bRedraw = TRUE);
	void EnableSearchMode(BOOL bEnable, LPCTSTR lpszPrompt, COLORREF clrText = (COLORREF)-1, BOOL bRedraw = TRUE);
	
	BOOL IsSearchMode() const
	{
		return m_bSearchMode;
	}

	CString GetSearchPrompt () const
	{
		return GetPrompt();
	};

	CString GetPrompt() const
	{
		return m_strSearchPrompt;
	};

	void SetErrorMessage(LPCTSTR lpszMessage, COLORREF clrText = (COLORREF)-1, BOOL bRedraw = TRUE);
	CString GetErrorMessage() const
	{
		return m_strErrorMessage;
	}

	void SetColorTheme(const CBCGPEditColors& colors, BOOL bRedraw = TRUE);
	const CBCGPEditColors& GetColorTheme() const
	{
		return m_ColorTheme;
	}

	void SetDisableBrowseButtonInReadOnlyMode(BOOL bDisable = TRUE);
	BOOL IsDisableBrowseButtonInReadOnlyMode() const
	{
		return m_bDisableBrowseButtonInReadOnlyMode;
	}

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	BOOL IsDroppedDown() const
	{
		return ::IsWindow(m_pDropDownPopup->GetSafeHwnd());
	}
#endif

protected:
	CBCGPEditColors		m_ColorTheme;
	CBrush				m_brBackground;
	CRect				m_rectBtn;
	BOOL				m_bIsButtonPressed;
	BOOL				m_bIsButtonHighlighted;
	BOOL				m_bIsButtonCaptured;
	BrowseMode			m_Mode;
	CBCGPToolBarImages	m_ImageBrowse;
	BOOL				m_bDefaultImage;
	CSize				m_sizeImage;
	CString				m_strLabel;
	CString				m_strDefFileExt;
	CString				m_strFileFilter;
	CString				m_strInitialFolder;
	DWORD				m_dwFileDialogFlags;
	CString				m_strFolderBrowseTitle;
	UINT				m_nFolderBrowseFlags;
	int					m_nBrowseButtonWidth;
	BOOL				m_bSearchMode;
	BOOL				m_bHasPrompt;
	CString				m_strSearchPrompt;
	COLORREF			m_clrPrompt;
	CString				m_strErrorMessage;
	COLORREF			m_clrErrorText;
	CBCGPToolBarImages	m_ImageSearch;
	CBCGPToolBarImages	m_ImageClear;
	BOOL				m_bTextIsEmpty;
	CToolTipCtrl*		m_pToolTip;
	BOOL				m_bShowToolTip;
	BOOL				m_bDefaultPrintClient;
	BOOL				m_bDisableBrowseButtonInReadOnlyMode;
	BOOL				m_bIsLastPrintableCharacter;
	BOOL				m_bIsDelayedLayout;

	CBCGPCalculatorPopup*	m_pCalcPopup;
	CStringList				m_lstCalcAdditionalCommands;
	CList<UINT, UINT>		m_lstCalcExtCommands;
	CString					m_strCalcDisplayFormat;

	CRuntimeClass*		m_pRTIPopupDlg;
	LPCTSTR				m_lpszPopupDlgTemplateName;
	CBCGPDialog*		m_pPopupDlg;
	BOOL				m_bIsResizablePopup;
	BOOL				m_bIsRightAlignedPopup;
	BOOL				m_bComboBoxMode;
	CRect				m_rectClick;

	BOOL				m_bHasSpinButton;

	BOOL				m_bAllowEditingInPasswordPreview;
	TCHAR				m_cPassword;

	CBCGPComboBox*		m_pAutoCompleteCombo;

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	CBCGPEditDropDownList*	m_pDropDownPopup;
	BOOL					m_bInAutoComplete;
#endif

// Operations
public:
	void EnableBrowseButton (BOOL bEnable = TRUE, LPCTSTR szLabel = _T("..."));
	void EnableFileBrowseButton (LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFilter = NULL, LPCTSTR lpszInitialFolder = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT);
	void EnableFolderBrowseButton (LPCTSTR lpszTitle = NULL, UINT ulFlags = BIF_RETURNONLYFSDIRS);
	void EnableCalculatorButton (const CStringList* plstAdditionalCommands = NULL,
		const CList<UINT, UINT>* plstExtCommands = NULL,
		LPCTSTR lpszDisplayFormat = NULL);
	
	void EnablePopupDialog(CRuntimeClass* pRTI, UINT nIDTemplate, BOOL bIsResizable = FALSE, BOOL bComboBoxMode = FALSE, BOOL bIsRightAligned = FALSE);
	void EnablePopupDialog(CRuntimeClass* pRTI, LPCTSTR lpszTemplateName, BOOL bIsResizable = FALSE, BOOL bComboBoxMode = FALSE, BOOL bIsRightAligned = FALSE);

	void EnablePasswordPreview(BOOL bEnable = TRUE, BOOL bAllowEditingInPreview = FALSE);

	void SetBrowseButtonImage (HICON hIcon, BOOL bAutoDestroy = TRUE, BOOL bAlphaBlend = FALSE);
	void SetBrowseButtonImage (HBITMAP hBitmap, BOOL bAutoDestroy = TRUE);
	void SetBrowseButtonImage (UINT uiBmpResId);

	virtual void OnBeforeShowPopupDlg(CBCGPDialog* pDlg) 
	{
		UNREFERENCED_PARAMETER(pDlg);
	}

	virtual void ClosePopupDlg(BOOL bOK, DWORD_PTR dwUserData = 0);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

	virtual void OnBrowse ();
	virtual void OnDrawBrowseButton (CDC* pDC, CRect rect, BOOL bIsButtonPressed, BOOL bIsButtonHot);
	virtual void OnChangeLayout ();
	virtual void OnAfterUpdate ();
	virtual BOOL FilterCalcKey (int nChar);

	virtual void OnCalculatorUserCommand (CBCGPCalculator* pCalculator, UINT uiCmd);
	virtual BOOL OnIllegalFileName (CString& strFileName);

	virtual BOOL IsDrawPrompt();

	virtual void DoPaint(CDC* pDC, BOOL bDrawPrompt, BOOL bIsPrint);
	virtual void DoNcPaint(CDC* pDC, BOOL bIsPrint);
	virtual void DoEraseBrowseButton(CDC* pDC, CRect rect);


#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	virtual BOOL OnGetAutoCompleteList(const CString& strEditText, CStringList& lstAutocomplete);
#endif

	virtual BOOL IsInternalScrollBarThemed() const;
	virtual BOOL IsBrowseButtonEnabled() const;

// Implementation
public:
	virtual ~CBCGPEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPEdit)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg void OnNcPaint();
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg BOOL OnChange();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg BCGNcHitTestType OnNcHitTest(CPoint point);
	afx_msg LRESULT OnBCGSetControlVMMode (WPARAM, LPARAM);
	afx_msg LRESULT OnBCGSetControlAero (WPARAM, LPARAM);
	afx_msg BOOL OnNeedTipText(UINT id, NMHDR* pNMH, LRESULT* pResult);
	afx_msg LRESULT OnPrintClient(WPARAM wParam, LPARAM lp);
	afx_msg LRESULT OnPrint(WPARAM wParam, LPARAM lp);
	afx_msg LRESULT OnRedrawFrame(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

	void CreateAutocompleteList(const CStringList& lstAutocomplete);
	void CloseAutocompleteList();
	void SetIntenalImage ();
	void SetupPasswordChar();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPEDIT_H__A7B40464_1C05_4981_A5F2_E21D74058A09__INCLUDED_)
