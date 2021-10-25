#ifndef __BARCODE_RECOGAPP_IMAGEPROVIDER_ABSTRACTJ_H__
#define __BARCODE_RECOGAPP_IMAGEPROVIDER_ABSTRACTJ_H__

#include "dev_macro.h"
#include <vector>

#if _DEV_CAM_MODE
#	include "cysuvclib.h"
#endif//_DEV_CAM_MODE

const int _MAX_IMG_W = 4000;
const int _MAX_IMG_H = 3000;
const UINT SHUM_STREAM = ::RegisterWindowMessage(_T("SHUM_STREAM"));
#if _DEV_CAM_MODE
class CCamDev 
{
public:
	CCamDev(const WCHAR* lpwName = NULL);

	CCamDev(const WCHAR* lpwName, PCYSDEV pCam);

	virtual ~CCamDev();
	const CString& GetName() const {
		return m_sName;
	}

	BOOL IsCheck(const PCYSDEV& dev) const {
		return (dev == m_pCamHandle);
	}

	void PushStream(BYTE* pBuffer, long size);
	BOOL Play();
	void Stop();
	void GetBuffer(BYTE* pBuffer, int* w, int* h);
private:
	void Init();
protected:
	CString m_sName;

	PCYSDEV m_pCamHandle;
	long	m_iWidth;
	long	m_iHeight;
	BOOL	m_bIsOpen;
	BOOL	m_bIsPreview;

	BYTE*	m_pBuffer;
private:
	CRITICAL_SECTION m_cs;
};
#endif//_DEV_CAM_MODE	

class CImageProvider
{
public:
	CImageProvider(CWnd* pParent = NULL);
	~CImageProvider();
	BOOL initProvider();
	int  GetNumberCam() const;
	
	int GetBarCamIdx() const {
		return 0;
	}
	int GetFaceCamIdx() const {
		return 1;
	}
#if _DEV_CAM_MODE
	int PushStreamData(const PCYSDEV& dev, LPBYTE pBuffer, long nSize);
	const CString& GetCamName(int idx) const;
#endif
	void StartPlay();
	void StopPlay();
	void GetBuffer(int idx, BYTE* pBuffer, int* w, int* h);
private:
#if _DEV_CAM_MODE
	std::vector<CCamDev> m_cams;
#endif//_DEV_CAM_MODE
	CWnd*					m_pParent;
};
#endif//__BARCODE_RECOGAPP_IMAGEPROVIDER_ABSTRACTJ_H__
//.EOF