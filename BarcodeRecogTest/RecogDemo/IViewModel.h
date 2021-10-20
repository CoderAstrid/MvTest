#pragma once

class IImageViewModel {
public:
	IImageViewModel();
	virtual ~IImageViewModel();

	virtual void DrawModel(CDC* pDC, const CRect& viewRect, int realW, int realH) = 0;
	void SetView(CWnd* pWnd);
protected:
	CWnd* m_pView;
};
