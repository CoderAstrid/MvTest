/******************************************************************************
\author	Jewel
\date	10/17/2019
******************************************************************************/

#pragma once
#include "RecogEngineDefine.h"
#include <vector>
#include "IViewModel.h"
//#include <afxwin.h>

//#define _MSC_STDINT_H_		//  [9/26/2019 Jewel]

#include "ximage/ximage.h"
#pragma comment(lib, "cximagecrt.lib")


// CPicWnd
class CPicWnd : public CWnd
{
	DECLARE_DYNAMIC(CPicWnd)

public:
	CPicWnd();
	virtual ~CPicWnd();

	BOOL CreateWnd(CWnd* pParent, const RECT& rc, UINT nID, int id);
	void SetImage(BYTE* pBuf, int w, int h, int bpp);

	int GetRealWidth() const { return m_iWidth; }
	int GetRealHeight() const { return m_iHeight; }
	void SetModel(IImageViewModel* pModel);
private:
	CxImage m_image;
	int		m_iWidth;
	int		m_iHeight;
	int		m_iBpp;
	int		m_id;
	ULONGLONG  m_ullStartTime;
	int			m_nCntFps;

	IImageViewModel*	m_pViewModel;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
//.EOF