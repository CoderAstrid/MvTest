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
// BCGPColorComboBox.h : header file
//

#if !defined(AFX_BCGPCOLORCOMBOBOX_H__CE32E477_B93F_4001_A2A1_470A350B67BE__INCLUDED_)
#define AFX_BCGPCOLORCOMBOBOX_H__CE32E477_B93F_4001_A2A1_470A350B67BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"
#include "BCGPComboBox.h"

/////////////////////////////////////////////////////////////////////////////
// CBCGPColorComboBox window

class BCGCBPRODLLEXPORT CBCGPColorComboBox : public CBCGPComboBox
{
// Construction
public:
	CBCGPColorComboBox();

// Attributes
public:
	void EnableNoneColor(BOOL bEnable = TRUE, const CString& strName = _T("No color"));
	BOOL IsNoneColorEnabled() const
	{
		return m_bIsNoneColor;
	}

// Operations
public:
	int AddColor(COLORREF color, const CString& strColorName);
	int SetStandardColors();
	int SetSystemColors();
	
	COLORREF GetItemColor(int nIndex) const;
	int FindIndexByColor(COLORREF color) const;

	static void SetSystemColorName(int nIndex, const CString strName);
	static const CString& GetSystemColorName(int nIndex);

	static BOOL DoDrawItem(CDC* pDC, CRect rect, CFont* pFont, COLORREF color, const CString& strText, BOOL bDisabled);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPColorComboBox)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBCGPColorComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGPColorComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	static CMap<UINT, UINT, CString, const CString&>	m_mapSystemColorNames;
	BOOL												m_bIsNoneColor;
	CString												m_strNoneColor;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPCOLORCOMBOBOX_H__CE32E477_B93F_4001_A2A1_470A350B67BE__INCLUDED_)
