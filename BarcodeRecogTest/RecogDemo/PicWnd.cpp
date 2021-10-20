/******************************************************************************
\author	Jewel
\date	10/17/2019
******************************************************************************/

#include "stdafx.h"
#include "RecogDemo.h"
#include "PicWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPicWnd

IMPLEMENT_DYNAMIC(CPicWnd, CWnd)

CPicWnd::CPicWnd()
	: m_iWidth(0)
	, m_iHeight(0)
	, m_pViewModel(NULL)
{
	m_nCntFps = 0;
	m_ullStartTime = 0U;
}

CPicWnd::~CPicWnd()
{
}

BEGIN_MESSAGE_MAP(CPicWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CPicWnd message handlers
BOOL CPicWnd::CreateWnd(CWnd* pParent, const RECT& rc, UINT nID, int id)
{
	m_id = id;
	return CWnd::Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, rc, pParent, nID);
}

void CPicWnd::SetModel(IImageViewModel* pModel)
{
	m_pViewModel = pModel;
}

void CPicWnd::SetImage(BYTE* pBuf, int w, int h)
{	
	if (m_iWidth == w && m_iHeight == h) {

	}
	else {
		
		if (m_image.IsValid()) {
			m_image.Destroy();
			m_iWidth = m_iHeight = 0;
		}
		m_iWidth = w;
		m_iHeight = h;
		m_image.Create(w, h, 24);		
	}
	BYTE* pLineSrc = pBuf;
	for (int i = h-1; i >= 0; i--) {
		int y = i; // h - 1 - i;
		BYTE* pLine = m_image.GetBits(y);
		memcpy(pLine, pLineSrc, w * 3);
		pLineSrc += w * 3;
	}

	if (m_nCntFps == 0)
		m_ullStartTime = GetTickCount64();
	m_nCntFps++;
#if 0
	if (m_nCntFps % 10 == 0) {
		CString sFile;
		sFile.Format(_T("e:\\TestImg\\ch0-%02d-%04d.jpg"), m_id, m_nCntFps);
		m_image.Save(sFile, CXIMAGE_FORMAT_JPG);
	}
#endif
	if (GetSafeHwnd() && IsWindow(GetSafeHwnd()))
		Invalidate();
}

void CPicWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages
	CRect rc;
	GetClientRect(&rc);

	CMemDC memDC(dc, this);	
	
	if (m_image.IsValid()) {
		m_image.Draw(memDC.GetDC().GetSafeHdc(), rc);
		auto iNow = GetTickCount64();
		LONGLONG iPos = (LONGLONG)(iNow - m_ullStartTime);
		if (m_nCntFps > 5) {
			int fps = m_nCntFps * 1000 / iPos;
			CString s;
			s.Format(_T("%d fps"), fps);
			memDC.GetDC().TextOut(10, 10, s);
		}
		if (m_pViewModel)
		{
			m_pViewModel->DrawModel(&memDC.GetDC(), rc, m_iWidth, m_iHeight);
		}
		
	}
	else {
		memDC.GetDC().FillSolidRect(&rc, RGB(49, 49, 49));
	}
}


BOOL CPicWnd::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN) {
		int iKey = -1;
		if (pMsg->wParam == VK_LEFT) {
			iKey = 0;
		}
		else if (pMsg->wParam == VK_RIGHT) {
			iKey = 1;
		}
		else if (pMsg->wParam == VK_HOME) {
			iKey = 2;
		}
		else if (pMsg->wParam == VK_END) {
			iKey = 3;
		}
		if (iKey >= 0) {

		}
	}

	return CWnd::PreTranslateMessage(pMsg);
}


void CPicWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetFocus();

	CWnd::OnLButtonDown(nFlags, point);
}
//.EOF