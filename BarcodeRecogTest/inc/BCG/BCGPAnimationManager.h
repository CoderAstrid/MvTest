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

#pragma once

#ifndef __AFXMT_H__
	#include <afxmt.h>
#endif

#include "BCGCBPro.h"

interface IUIAnimationManager;
interface IUIAnimationTimer;
interface IUIAnimationTransitionLibrary;
interface IUIAnimationVariable;
class IBCGPAnimationTimerEventHandler;

/////////////////////////////////////////////////////////////////////////////
// CBCGPAnimationManagerOptions

struct BCGCBPRODLLEXPORT CBCGPAnimationManagerOptions
{
	CBCGPAnimationManagerOptions()
	{
		m_dblAccelerationRatio = 0.3;
		m_dblDecelerationRatio = 0.7;
		m_dblFinalVelocity = 0.0;
		m_dblParabolicAccelerationRatio = 0.0;
	}

	// BCGPANIMATION_AccelerateDecelerate options. The acceleration ratio and the 
	// deceleration ratio should sum to a maximum of 1.0.
	double	m_dblAccelerationRatio;
	double	m_dblDecelerationRatio;

	// BCGPANIMATION_Cubic and BCGPANIMATION_ParabolicFromAcceleration:
	double	m_dblFinalVelocity;

	// BCGPANIMATION_ParabolicFromAcceleration:
	double	m_dblParabolicAccelerationRatio;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPAnimationManager

class BCGCBPRODLLEXPORT CBCGPAnimationManager
{
	friend class IBCGPAnimationTimerEventHandler;

// Construction
public:
	CBCGPAnimationManager();
	virtual ~CBCGPAnimationManager();

	static BOOL IsAnimationSupportedByOS();

// Attributes
public:
	enum BCGPAnimationType
	{
		BCGPANIMATION_Legacy = 0,	// Timer-based linear animation
		BCGPANIMATION_AccelerateDecelerate,
		BCGPANIMATION_Cubic,
		BCGPANIMATION_Linear,
		BCGPANIMATION_SmoothStop,
		BCGPANIMATION_ParabolicFromAcceleration,
	};

	BOOL IsAnimated() const
	{
		return m_bIsAnimated;
	}

	double GetAnimatedValue() const
	{
		return m_dblAnimatedValue;
	}

	double GetAnimationDuration() const
	{
		return m_dblAnimationDuration;
	}

// Operations:
public:
	BOOL StartAnimation(
		double dblStartValue, double dblFinalValue, double dblDurationInSeconds,
		BCGPAnimationType type, CBCGPAnimationManagerOptions* pOptions = NULL,
		double dblDelayInSeconds = 0.0);

	BOOL StartFlashAnimation(double dblPeriodInSeconds);

	void StopAnimation(BOOL bNotify = TRUE);

	HRESULT GetLastAnimationError() const
	{
		return m_hrLastError;
	}

// Overrides:
protected:
	virtual void OnAnimationValueChanged(double dblOldValue, double dblNewValue) 
	{
		UNREFERENCED_PARAMETER(dblOldValue);
		UNREFERENCED_PARAMETER(dblNewValue);
	}

	virtual void OnAnimationFinished() {}
	virtual void OnAnimationIdle() {}

protected:
	static VOID CALLBACK AnimationTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	void OnWinAnimationTimerEvent();
	void OnTimerEvent();

	BOOL InitWinAnimation();
	void CleanUp();

	BOOL								m_bIsAnimated;
	double								m_dblFinalValue;
	double								m_dblAnimatedValue;
	double								m_dblAnimationDuration;
	BCGPAnimationType					m_AnimationType;
	BOOL								m_bIsFlashAnimation;
	BOOL								m_bInIdle;
	BOOL								m_bIsDelay;
	HRESULT								m_hrLastError;

	// Windows Animation API (not used in case of BCGPANIMATION_Legacy):
	int									m_nWinAnimationStatus;
	IUIAnimationManager*				m_animationManager;
	IUIAnimationTransitionLibrary*		m_transitionLibrary;
	IBCGPAnimationTimerEventHandler*	m_pTimerEventHandler;
	IUIAnimationVariable*				m_variable;
	IUIAnimationTimer*					m_animationTimer;

	// Timer-based animation:
	UINT								m_nTimerID;
	double								m_dblAnimationStep;

	static int g_AnimationSupportedByOS;
	static CMap<UINT,UINT,CBCGPAnimationManager*,CBCGPAnimationManager*> m_mapManagers;
	static CCriticalSection g_cs;			// For multi-thread applications
};
