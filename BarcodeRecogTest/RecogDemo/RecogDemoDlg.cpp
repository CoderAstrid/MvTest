
// RecogDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RecogDemo.h"
#include "RecogDemoDlg.h"
#include "afxdialogex.h"
#include "RecogEngine.h"
#include <io.h>							// for findfile
#include "TimeTrack.h"
#include <fstream>
#include "ximage/ximage.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _UNICODE
#	if _WIN64
typedef _wfinddata64_t FindData;
#	else
typedef _wfinddata_t FindData;
#	endif
#else
#	if _WIN64
typedef _finddatai64_t FindData;
#	else
typedef _finddata_t FindData;
#	endif
#endif
#if _WIN64
#	define FindFirst	_tfindfirst64
#	define FindNext	_tfindnext64
#else
#	define FindFirst	_tfindfirst
#	define FindNext	_tfindnext
#endif//_WIN64


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRecogDemoDlg dialog

enum ResultItemIndex {
	eResIdxNo,
	eResIdxDim,
	eResIdxCnt,
	eResIdxTime,
	eResIdxFile,
	eCntResIdx
};

CString ResultItemName[] = {
	_T("No"),
	_T("Dimension"),
	_T("Count"),
	_T("Time"),
	_T("File")
};

int ResIdxWidth[] = { 30, 100, 30, 60, 200 };

CRecogDemoDlg::CRecogDemoDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(IDD_RECOGDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_iCurFileIdx = -1;
	m_bParamDirty = FALSE;
	m_pViewModel = NULL;
	initTimer();
}

void CRecogDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LBL_RES, m_lblStat);
	DDX_Control(pDX, IDC_LIST_STAT, m_lstRes);
	DDX_Control(pDX, IDC_BTN_BROWSE, m_btnBroser);
	DDX_Control(pDX, IDC_EDIT_PATH, m_edtPath);
	DDX_Control(pDX, IDC_BTN_EXPORT, m_btnExport);
	DDX_Control(pDX, IDC_BTN_RESET, m_btnReset);
	DDX_Control(pDX, IDC_BTN_CONT, m_btnCont);
	DDX_Control(pDX, IDC_BTN_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BTN_PREV, m_btnPrev);
	DDX_Control(pDX, IDC_EDIT_NUM, m_edtFileNum);
	DDX_Control(pDX, IDC_LBL_TOTAL, m_lblTotal);
	DDX_Control(pDX, IDC_BTN_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BTN_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BTN_PROC, m_btnRecog);
	DDX_Control(pDX, IDC_CHK_ALL_SAME, m_chkAllSame);
	DDX_Control(pDX, IDC_SPIN_MIN_CODE_LEN, m_spinCodeLen);
	DDX_Control(pDX, IDC_EDIT_MIN_CODE_LEN, m_edtCodeLen);
}

BEGIN_MESSAGE_MAP(CRecogDemoDlg, CBCGPDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRecogDemoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CRecogDemoDlg::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_RESET, &CRecogDemoDlg::OnBnClickedBtnReset)
	ON_BN_CLICKED(IDC_BTN_EXPORT, &CRecogDemoDlg::OnBnClickedBtnExport)
	ON_BN_CLICKED(IDC_BTN_BROWSE, &CRecogDemoDlg::OnBnClickedBtnBrowse)
	ON_BN_CLICKED(IDC_BTN_FIRST, &CRecogDemoDlg::OnBnClickedBtnFirst)
	ON_BN_CLICKED(IDC_BTN_CONT, &CRecogDemoDlg::OnBnClickedBtnCont)
	ON_BN_CLICKED(IDC_BTN_PREV, &CRecogDemoDlg::OnBnClickedBtnPrev)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CRecogDemoDlg::OnEnChangeEditNum)
	ON_BN_CLICKED(IDC_BTN_NEXT, &CRecogDemoDlg::OnBnClickedBtnNext)
	ON_BN_CLICKED(IDC_BTN_LAST, &CRecogDemoDlg::OnBnClickedBtnLast)
	ON_BN_CLICKED(IDC_BTN_PROC, &CRecogDemoDlg::OnBnClickedBtnProc)
	ON_BN_CLICKED(IDC_CHK_ALL_SAME, &CRecogDemoDlg::OnBnClickedChkAllSame)
	ON_EN_CHANGE(IDC_EDIT_MIN_CODE_LEN, &CRecogDemoDlg::OnEnChangeEditMinCodeLen)
END_MESSAGE_MAP()


// CRecogDemoDlg message handlers
BYTE theBuf[3][_MAX_IMG_W * _MAX_IMG_H * 3];
BOOL theUpdating[2] = { FALSE, FALSE };

BOOL CRecogDemoDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect rc1;
	GetDlgItem(IDC_PIC1)->GetWindowRect(&rc1);
	ScreenToClient(&rc1);
	m_wndBar.CreateWnd(this, rc1, IDC_PIC1, 0);
	
	m_pViewModel = new CBarcodeResModel;
	m_pViewModel->SetView(&m_wndBar);
	m_wndBar.SetModel(m_pViewModel);

	sv_engine_init_v2();

	CMFCDynamicLayout* dynamicLayout = GetDynamicLayout();
	dynamicLayout->AddItem(m_wndBar.GetSafeHwnd(), CMFCDynamicLayout::MoveNone(), CMFCDynamicLayout::SizeHorizontalAndVertical(100, 100));

	for (int i = 0; i < eCntResIdx; i++) {
		m_lstRes.InsertColumn(i, ResultItemName[i], 0, ResIdxWidth[i]);
	}
	m_lstRes.SetExtendedStyle(m_lstRes.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	sv_get_param_v2(&m_param);
	CString s;
	m_spinCodeLen.SetRange32(0, 20);
	s.Format(_T("%d"), m_param.minStringLength);
	m_edtCodeLen.SetWindowText(s);
	m_chkAllSame.SetCheck(m_param.isAllSame ? BST_CHECKED : BST_UNCHECKED);

	m_bParamDirty = FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

UINT CRecogDemoDlg::detect_thread(LPVOID pVoid)
{
	UINT res = 0;
	CRecogDemoDlg* pThis = (CRecogDemoDlg*)pVoid;
	if (pThis == NULL) {
		ExitThread(1);
		return 1;
	}
	MSG			msg;
	while (1) {
		::GetMessage(&msg, NULL, 0, 0);
		if (msg.message == TH_END_THREAD)
		{
			DWORD dwExitCode = 0;
			ExitThread(dwExitCode);
			break;
		}
		else if (msg.message == TH_PROC_THREAD) {
			ULONGLONG ull = GetTickCount64();
			int idx = (int)msg.wParam;
			char sRes[256];			
			int w = 0, h = 0;

			ull = GetTickCount64() - ull;
			CString s1(sRes);
			CString s;
			s.Format(_T("Result(%u ms): %s"), ull, s1.GetString());
		}

		Sleep(0);
		Sleep(1);
	}
	return res;
}

void CRecogDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CBCGPDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRecogDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CBCGPDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRecogDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRecogDemoDlg::OnBnClickedOk()
{
	CBCGPDialog::OnOK();
}


void CRecogDemoDlg::OnBnClickedCancel()
{
	CBCGPDialog::OnCancel();
}


void CRecogDemoDlg::OnDestroy()
{
	CBCGPDialog::OnDestroy();

	sv_engine_close_v2();
	if (m_uThreadID != 0)
	{
		PostThreadMessage(m_uThreadID, TH_END_THREAD, 0, (LPARAM)this);
		::WaitForSingleObject(m_hThread, 8000);	// 10 s delay		
		CloseHandle(m_hThread);
		m_hThread = NULL;
		m_uThreadID = 0;
	}

	if (m_pViewModel) {
		delete m_pViewModel;
		m_pViewModel = NULL;
	}
}

void CRecogDemoDlg::OnBnClickedBtnReset()
{
	m_lstRes.DeleteAllItems();
}


void CRecogDemoDlg::OnBnClickedBtnExport()
{
	CString sFile;
	sFile.Format(_T("%s\\log.log"), theAppPath.GetString());
	
	CT2A ps(sFile);
	std::ofstream file;
	file.open(ps.m_psz);
	int n = m_lstRes.GetHeaderCtrl().GetItemCount();
	for (int i = 0; i < m_lstRes.GetItemCount(); i++) {
		for (int j = 0; j < n; j++) {
			CString s = m_lstRes.GetItemText(i, j);
			CT2A psItem(s);
			file << psItem.m_psz << "\t";
		}
		file << "\n";
	}
	file.close();
}


void CRecogDemoDlg::OnBnClickedBtnBrowse()
{
	TCHAR szFilters[] = _T("Image Files (*.jpg; *.png;*.bmp;)|*.jpg; *.png; *.bmp;|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, 6, szFilters);
	if (dlg.DoModal() != IDOK)
		return;
	CString szSelFile = dlg.GetPathName();		// selected file path name
	CString szSelFolder = szSelFile;			// selected folder path
	int k = szSelFolder.ReverseFind('\\');
	if (k < 0)
		return;
	szSelFolder = szSelFolder.Left(k + 1);
	szSelFile = szSelFile.Mid(k + 1);

	const int EXT_CNT = 3;
	CString sExtensions[EXT_CNT] = { _T("*.bmp"), _T("*.png"), _T("*.jpg") };
	intptr_t h_File = 0L;
	CString b;

	FindData c_files;

	m_aFilePath.clear();

	for (int i = 0; i < EXT_CNT; i++)
	{
		h_File = 0L;
		CString sFindPattern = szSelFolder + sExtensions[i];
		if (((h_File = FindFirst(sFindPattern, &c_files)) != -1))
		{
			do
			{
				b = c_files.name;
				b.MakeUpper();
				m_aFilePath.push_back(b);
			} while (FindNext(h_File, &c_files) == 0);
			_findclose(h_File);
		}
	}

	// next, sorted order by file names.
	int leng = m_aFilePath.size();
	for (int i = 0; i < leng; i++) {
		for (int j = i + 1; j < leng; j++) {
			int i1 = _ttoi(m_aFilePath[i]);
			int i2 = _ttoi(m_aFilePath[j]);

			if (i1 > i2) {
				CString it = m_aFilePath[i];
				m_aFilePath[i] = m_aFilePath[j];
				m_aFilePath[j] = it;
			}
		}
	}

	int index = -1;
	for (int i = 0; i < m_aFilePath.size(); i++) {
		if (szSelFile.CompareNoCase(m_aFilePath[i]) == 0)
		{
			index = i;
			break;
		}
	}
	m_iCurFileIdx = index;
	m_sFolderPath = szSelFolder;
	m_edtPath.SetWindowText(m_sFolderPath);
	CString s;
	s.Format(_T("/ %d"), m_aFilePath.size());
	m_lblTotal.SetWindowText(s);

	UpdateCtrlBar();
}

void CRecogDemoDlg::UpdateCtrlBar()
{
	int n = m_aFilePath.size();
	CString s;
	if (m_iCurFileIdx >= 0 && m_iCurFileIdx < n) {
		s.Format(_T("%d"), m_iCurFileIdx + 1);
	}
	m_edtFileNum.SetWindowText(s);
	m_btnFirst.EnableWindow(m_iCurFileIdx > 0);
	m_btnPrev.EnableWindow(m_iCurFileIdx > 0);
	m_btnNext.EnableWindow(m_iCurFileIdx < n - 1);
	m_btnLast.EnableWindow(m_iCurFileIdx < n - 1);

	ProcessingFile();
}

void CRecogDemoDlg::ProcessingFile()
{
	if (m_iCurFileIdx < 0 || m_iCurFileIdx >= m_aFilePath.size())
		return;
	m_lstRes.SetFocus();
	CString filename;
	filename.Format(_T("%s%s"), m_sFolderPath, m_aFilePath[m_iCurFileIdx]);

	CxImage img;
	CString sExt;
	int k = filename.ReverseFind('.');
	if (k < 0)
		return;
	sExt = filename.Mid(k + 1);
	UINT typeID = CxImage::GetTypeIdFromName(sExt);
	if (!img.Load(filename, typeID))
		return;

	BOOL isGray = img.IsGrayScale();
	BOOL isIndex = img.IsIndexed();
	int bpp = img.GetBpp();
	
	if (bpp == 8 && isIndex && !isGray)
		isGray = img.GrayScale();

	m_wndBar.SetImage(img.GetBits(), img.GetWidth(), img.GetHeight(), bpp);
	int n = m_lstRes.GetItemCount();
	CString s;
	s.Format(_T("%d"), n + 1);
	k = m_lstRes.InsertItem(n, s);
	m_lstRes.SetItemText(k, eResIdxFile, filename);
	s.Format(_T("%d X %d"), img.GetWidth(), img.GetHeight());
	m_lstRes.SetItemText(k, eResIdxDim, s);

	UpdateParam();	

	auto tm = getLongTimer();
	CodeRecogRes* pRes = NULL;

	int res = sv_engine_rec_v2(img.GetBits(), img.GetWidth(), img.GetHeight(), bpp, 2, &pRes);
	if (res < 0)
		res = 0;
	double ms = getTickNow(tm);

	s.Format(_T("%g ms"), ms);
	m_lstRes.SetItemText(k, eResIdxTime, s);

	s.Format(_T("%d"), res);
	m_lstRes.SetItemText(k, eResIdxCnt, s);

	m_pViewModel->SetBarcodeResult(res, pRes);

	if (pRes) {
		CoTaskMemFree(pRes);
	}

	m_lstRes.SetItemState(k, LVIS_SELECTED, LVIS_SELECTED);
	m_lstRes.EnsureVisible(k, FALSE);
}

void CRecogDemoDlg::UpdateParam()
{
	if (!m_bParamDirty)
		return;
	CString s;
	m_param.isAllSame = (m_chkAllSame.GetCheck() == BST_CHECKED);

	m_edtCodeLen.GetWindowText(s);
	m_param.minStringLength = _ttoi(s);

	sv_set_param_v2(m_param);
}

void CRecogDemoDlg::OnBnClickedBtnFirst()
{
	int idx = 0;
	if (idx < m_aFilePath.size())
		m_iCurFileIdx = idx;
	UpdateCtrlBar();
}


void CRecogDemoDlg::OnBnClickedBtnCont()
{
}

void CRecogDemoDlg::OnBnClickedBtnPrev()
{
	int idx = m_iCurFileIdx - 1;
	if (idx >= 0)
		m_iCurFileIdx = idx;
	UpdateCtrlBar();
}


void CRecogDemoDlg::OnEnChangeEditNum()
{
	
}


void CRecogDemoDlg::OnBnClickedBtnNext()
{
	int idx = m_iCurFileIdx + 1;
	if (idx < m_aFilePath.size())
		m_iCurFileIdx = idx;
	UpdateCtrlBar();
}


void CRecogDemoDlg::OnBnClickedBtnLast()
{
	int idx = m_aFilePath.size() - 1;
	if (idx >= 0)
		m_iCurFileIdx = idx;
	UpdateCtrlBar();
}

void CRecogDemoDlg::OnBnClickedBtnProc()
{
	ProcessingFile();
}
void CRecogDemoDlg::OnBnClickedChkAllSame()
{
	m_bParamDirty = TRUE;
}

void CRecogDemoDlg::OnEnChangeEditMinCodeLen()
{
	m_bParamDirty = TRUE;
}
