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
//
// BCGPPageTransitionManager.h: interface for the CBCGPPageTransitionManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPPAGETRANSITIONMANAGER_H__43473BD8_A527_4EAE_B561_19A398B49681__INCLUDED_)
#define AFX_BCGPPAGETRANSITIONMANAGER_H__43473BD8_A527_4EAE_B561_19A398B49681__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGCBPro.h"

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	#include "BCGPToolBarImages.h"
#endif

#include "BCGPAnimationManager.h"

class BCGCBPRODLLEXPORT CBCGPPageTransitionManager : public CBCGPAnimationManager
{
public:
	enum BCGPPageTransitionEffect
	{
		BCGPPageTransitionNone,
		BCGPPageTransitionSlide,
		BCGPPageTransitionSimpleSlide,
		BCGPPageTransitionPop,
		BCGPPageTransitionFade,
		BCGPPageTransitionSlideVertical,
		BCGPPageTransitionSimpleSlideVertical,
		BCGPPageTransitionAppear,
	};
	
	CBCGPPageTransitionManager();
	virtual ~CBCGPPageTransitionManager();

	void SetPageTransitionEffect(BCGPPageTransitionEffect effect, int nAnimationTime = 300 /* ms */,
		BCGPAnimationType animationType = BCGPANIMATION_SmoothStop,
		CBCGPAnimationManagerOptions* pAnimationOptions = NULL)
	{
		m_PageTransitionEffect = effect;
		m_nPageTransitionTime = nAnimationTime;
		m_animationType = animationType;

		if (pAnimationOptions != NULL)
		{
			m_animationOptions = *pAnimationOptions;
		}
	}

	BCGPPageTransitionEffect GetPageTransitionEffect() const 
	{
		return m_PageTransitionEffect;
	}

	BCGPAnimationType GetAnimationType() const
	{
		return m_animationType;
	}

	const CBCGPAnimationManagerOptions& GetAnimationOptions() const
	{
		return m_animationOptions;
	}

	BOOL StartPageTransition(HWND hwdHost, const CArray<HWND, HWND>& arPages, BOOL bReverseOrder = FALSE, const CSize& szPageOffset = CSize(0, 0), const CSize& szPageMax = CSize(0, 0));
	BOOL StartPageTransition(HWND hwdHost, HWND hwndPageFrom, HWND hwndPageTo, BOOL bReverseOrder = FALSE, const CSize& szPageOffset = CSize(0, 0), const CSize& szPageMax = CSize(0, 0));

	BOOL StartBitmapTransition(HWND hwdHost, const CArray<HBITMAP, HBITMAP>& arPages, const CRect& rectPageTransition, BOOL bReverseOrder = FALSE);
	BOOL StartBitmapTransition(HWND hwdHost, HBITMAP hbmpFrom, HBITMAP hbmpTo, const CRect& rectPageTransition, BOOL bReverseOrder = FALSE);

	void StopPageTransition(BOOL bNotify = TRUE);

	virtual void OnPageTransitionFinished() {}

protected:
	virtual void OnAnimationValueChanged(double dblOldValue, double dblNewValue);
	virtual void OnAnimationFinished();

	void DoDrawTransition(CDC* pDC, BOOL bIsMemDC);
	BOOL StartInternal(BOOL bReverseOrder);

protected:
	BCGPPageTransitionEffect	m_PageTransitionEffect;
	int							m_nPageTransitionTime;
	BCGPAnimationType			m_animationType;
	CBCGPAnimationManagerOptions	m_animationOptions;

#if (!defined _BCGSUITE_) && (!defined _BCGSUITE_INC_)
	CBCGPToolBarImages			m_Panorama;
#else
	CBCGPToolBarImagesSuite		m_Panorama;
#endif
	CRect						m_rectPageTransition;
	int							m_nPageTransitionOffset;
	int							m_nPageTransitionStep;	// Obsolete
	int							m_nPageTransitionTotal;
	int							m_nPageScreenshot1;
	int							m_nPageScreenshot2;
	HWND						m_hwndHost;
	COLORREF					m_clrFillFrame;
};

#endif // !defined(AFX_BCGPPAGETRANSITIONMANAGER_H__43473BD8_A527_4EAE_B561_19A398B49681__INCLUDED_)
