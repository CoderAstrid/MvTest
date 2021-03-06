
// RecogDemoDlg.h : header file
//

#pragma once
#include "ImageProvider.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "PicWnd.h"
#include "BCG/BCGPVisualManager.h"
#include <vector>
#include "BarcodeResModel.h"

#define TH_CONTINUE_THREAD	415
#define TH_PROC_THREAD		416
#define TH_END_THREAD		417

// CRecogDemoDlg dialog
class CRecogDemoDlg : public CBCGPDialog
{
// Construction
public:
	CRecogDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECOGDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	static UINT __stdcall detect_thread(LPVOID pVoid);

	void UpdateCtrlBar();
	void ProcessingFile();
	void UpdateParam();

	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
protected:
	std::vector<CString>	m_aFilePath;
	int						m_iCurFileIdx;
	CString					m_sFolderPath;
	BOOL					m_bParamDirty;

	SvBarRecParams			m_param;

	HANDLE			m_hThread;
	UINT			m_uThreadID;

	CBCGPStatic		m_lblStat;
	CPicWnd			m_wndBar;
	CBarcodeResModel* m_pViewModel;

	CBCGPListCtrl	m_lstRes;
	CBCGPButton m_btnBroser;
	CBCGPEdit	m_edtPath;
	CBCGPButton m_btnExport;
	CBCGPButton m_btnReset;
	CBCGPButton m_btnCont;
	CBCGPButton m_btnFirst;
	CBCGPButton m_btnPrev;
	CBCGPButton m_btnNext;
	CBCGPButton m_btnLast;
	CBCGPEdit m_edtFileNum;
	CBCGPStatic m_lblTotal;
	CBCGPButton m_btnRecog;
	CBCGPButton m_chkAllSame;
	CBCGPSpinButtonCtrl m_spinCodeLen;
	CBCGPEdit m_edtCodeLen;
public:
	afx_msg void OnDestroy();	
	
	afx_msg void OnBnClickedBtnReset();
	afx_msg void OnBnClickedBtnExport();	
	afx_msg void OnBnClickedBtnBrowse();	
	afx_msg void OnBnClickedBtnFirst();
	afx_msg void OnBnClickedBtnCont();
	afx_msg void OnBnClickedBtnPrev();	
	afx_msg void OnEnChangeEditNum();	
	afx_msg void OnBnClickedBtnNext();
	afx_msg void OnBnClickedBtnLast();	
	afx_msg void OnBnClickedBtnProc();
	afx_msg void OnBnClickedChkAllSame();
	afx_msg void OnEnChangeEditMinCodeLen();	
};
//.EOF