
// RecogDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RecogDemo.h"
#include "RecogDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRecogDemoApp

BEGIN_MESSAGE_MAP(CRecogDemoApp, CBCGPWinApp)
	ON_COMMAND(ID_HELP, &CBCGPWinApp::OnHelp)
END_MESSAGE_MAP()


// CRecogDemoApp construction

CRecogDemoApp::CRecogDemoApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CRecogDemoApp object

CRecogDemoApp theApp;
CString			theAppPath;

// CRecogDemoApp initialization

BOOL CRecogDemoApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
//	CBCGPVisualManager::SetDefaultManager(RUNTIME_CLASS(CBCGPVisualManagerCarbon));

	CString sPath;
	AfxGetModuleFileName(NULL, sPath);
	int k = sPath.ReverseFind('\\');
	if (k >= 0)
	{
		theAppPath = sPath.Left(k + 1);
	}

	SetRegistryKey(_T("BarcodeRecDemo"));

	CRecogDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

