#include "stdafx.h"
#include "ImageProvider.h"

#if _DEV_CAM_MODE
#ifdef _WIN64
#pragma comment(lib, "cysuvclib_x64.lib")
#else
#pragma comment(lib, "cysuvclib.lib")
#endif
#endif//_DEV_CAM_MODE

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CImageProvider* theProvider = NULL;

void INIReadString(TCHAR* wszPath, TCHAR* wszSection, TCHAR* wszKey, TCHAR* wszValue)
{
	GetPrivateProfileString(wszSection, wszKey, _T("-9999"), wszValue, 100, wszPath);
	int x = GetLastError();
}

void INIReadDWORD(TCHAR* wszPath, TCHAR* wszSection, TCHAR* wszKey, DWORD* value)
{
	TCHAR wszValue[100] = { 0 };
	INIReadString(wszPath, wszSection, wszKey, wszValue);

	*value = (DWORD)_ttoi64(wszValue);
}

#if _DEV_CAM_MODE
void CALLBACK StreamingDataCallback(PCYSDEV pCam, BYTE* pBuffer, long lBufferSize)
{
	if (!pBuffer || lBufferSize == 0) return;
	//这里返回的lbuffersize即为w*h*3大小
	theProvider->PushStreamData(pCam, pBuffer, lBufferSize);
#if 0
	CString s;
	s.Format(_T("..... StreamingDataCallback(%X): %d .....\n"), pCam, lBufferSize);
	OutputDebugString(s);
#endif
	Sleep(1);
	Sleep(0);
}
#endif//_DEV_CAM_MODE

//////////////////////////////////////////////////////////////////////////
#if _DEV_CAM_MODE
CCamDev::CCamDev(const WCHAR* lpwName)
{
	if (lpwName) {
		m_sName = CString(lpwName);
	}
	m_pCamHandle = NULL;
	Init();
}

CCamDev::CCamDev(const WCHAR* lpwName, PCYSDEV pCam)
{
	if (lpwName) {
		m_sName = CString(lpwName);
	}
	m_pCamHandle = pCam;
	Init();
}

void CCamDev::Init()
{
	m_iWidth = m_iHeight = 0;
	m_bIsOpen = m_bIsPreview = FALSE;
	m_pBuffer = NULL;

	InitializeCriticalSection(&m_cs);
}

CCamDev::~CCamDev()
{
	if (m_pBuffer) {
		delete[] m_pBuffer;
		m_pBuffer = NULL;
	}
	if (m_pCamHandle != NULL) {
		CysCloseDevice(m_pCamHandle);
		m_pCamHandle = NULL;
	}
	DeleteCriticalSection(&m_cs);
}

void CCamDev::PushStream(BYTE* pBuffer, long size)
{
	long oSize = m_iWidth * m_iHeight * 3;
	if (oSize != size) {
		ASSERT(FALSE);
	}
	ASSERT(m_pBuffer);

	EnterCriticalSection(&m_cs);
	memcpy(m_pBuffer, pBuffer, size);
	LeaveCriticalSection(&m_cs);
}

void CCamDev::GetBuffer(BYTE* pBuffer, int* w, int* h)
{
	if (pBuffer == NULL || w == NULL || h == NULL)
		return;
	*w = m_iWidth;
	*h = m_iHeight;
	EnterCriticalSection(&m_cs);
	memcpy(pBuffer, m_pBuffer, m_iWidth * m_iHeight * 3);
	LeaveCriticalSection(&m_cs);
}

void CCamDev::Stop()
{
	if (m_pCamHandle == NULL)
		return;
	CysStopStreaming(m_pCamHandle);
	CysCloseDevice(m_pCamHandle);
}

BOOL CCamDev::Play()
{
	if (m_pCamHandle == NULL){
		return FALSE;
	}

	auto status = CysGetOpenStatus(m_pCamHandle);
	if (status == OpenStatus_Opened) 
		return FALSE;

	if (!CysOpenDevice(m_pCamHandle))
		return FALSE;

	if (!CysRegisterStreamingCallback(m_pCamHandle, StreamingDataCallback))
		return FALSE; 

	if (!CysGetCurrentMediaType(m_pCamHandle, PIN_CATEGORY_CAPTURE, NULL, &m_iWidth, &m_iHeight))
		return FALSE;

	EnterCriticalSection(&m_cs);
	if (m_pBuffer != NULL)
	{
		delete[] m_pBuffer;
		m_pBuffer = NULL;
	}
	m_pBuffer = new BYTE[m_iWidth*m_iHeight * 3];
	LeaveCriticalSection(&m_cs);

	if (!CysConfigDevice(m_pCamHandle))
		return FALSE;

	status = CysGetVideoStatus(m_pCamHandle);
	if (status == VideoStatus_Streaming || status == VideoStatus_StreamingCapture) 
		return FALSE;

	if (!CysStartStreaming(m_pCamHandle))
		return FALSE;
	return TRUE;
}
#endif//_DEV_CAM_MODE

//////////////////////////////////////////////////////////////////////////
CImageProvider::CImageProvider(CWnd* pParent)
	: m_pParent(pParent)
{	
}


CImageProvider::~CImageProvider()
{
	StopPlay();

#if _DEV_CAM_MODE
	m_cams.clear();
	CysLibRelease();
#endif
}


BOOL CImageProvider::initProvider()
{
#if _DEV_CAM_MODE
	DWORD sn = 0;
	TCHAR wszPath[MAX_PATH];
	GetModuleFileName(NULL, wszPath, MAX_PATH);
	PathRemoveFileSpec(wszPath);
	_tcscat_s(wszPath, _T("\\sn.ini"));
	INIReadDWORD(wszPath, _T("sn"), _T("sn"), &sn);

	if (CysLibInit(sn)) {
		int count = CysEnumVideoDevices();
// 		CString s;
// 		s.Format(_T("%d Cameras"), count);
// 		AfxMessageBox(s);
		if (count < 1)
			return FALSE;
		for (int i = count-1; i >= 0; i--) {
			PCYSDEV pDev = CysGetDeviceFromIndex(i);
			if (pDev != NULL) {
				WCHAR wszName[260] = { 0 };
				CysGetFriendlyName(pDev, wszName);
				
				// to remove laptop cameras
				CString s = wszName;
				if(s.Left(3) == _T("USB"))
					continue;
				if (s.Left(3) == _T("Eas"))
					continue;

				CCamDev dev(wszName, pDev);
				m_cams.push_back(dev);
			}
		}
		theProvider = this;
		return TRUE;
	}
	else
		return FALSE;
#else
	return TRUE;
#endif
}


int CImageProvider::GetNumberCam() const
{
#if _DEV_CAM_MODE
	return m_cams.size();
#else
	return 0;
#endif//
}
#if _DEV_CAM_MODE
const CString& CImageProvider::GetCamName(int idx) const
{

	if (idx >= 0 && idx < m_cams.size()) {
		return m_cams[idx].GetName();
	}
	return _T("");
}
int CImageProvider::PushStreamData(const PCYSDEV& dev, LPBYTE pBuffer, long nSize)
{
	int idx = -1;
	for (int i = 0; i < m_cams.size(); i++) {
		if (m_cams[i].IsCheck(dev)) {
			m_cams[i].PushStream(pBuffer, nSize);
			idx = i;
			break;
		}
	}
	if (idx >= 0) {
		m_pParent->PostMessage(SHUM_STREAM, 0, idx);
		Sleep(1);
		Sleep(0);
	}
	return idx;
}
#endif//_DEV_CAM_MODE

void CImageProvider::StartPlay()
{
#if _DEV_CAM_MODE
	for (int i = 0; i < m_cams.size(); i++) {
		m_cams[i].Play();
	}
#endif//_DEV_CAM_MODE
}

void CImageProvider::StopPlay()
{
#if _DEV_CAM_MODE
	for (int i = 0; i < m_cams.size(); i++) {
		m_cams[i].Stop();
	}
#endif//_DEV_CAM_MODE
}

void CImageProvider::GetBuffer(int idx, BYTE* pBuffer, int* w, int* h)
{
#if _DEV_CAM_MODE
	if (idx < 0 || idx >= m_cams.size())
		return;
	m_cams[idx].GetBuffer(pBuffer, w, h);
#endif//_DEV_CAM_MODE
}
//.EOF