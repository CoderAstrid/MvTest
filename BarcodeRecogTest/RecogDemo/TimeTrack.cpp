#include "stdafx.h"
#include "TimeTrack.h"
LARGE_INTEGER frequency;        // ticks per second
bool init_timer = false;
void initTimer()
{
	QueryPerformanceFrequency(&frequency);
}

LARGE_INTEGER getLongTimer()
{
	LARGE_INTEGER t1;
	QueryPerformanceCounter(&t1);
	return t1;
}

double getTickTime(const LARGE_INTEGER& t1, const LARGE_INTEGER& t2)
{
	double elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	return elapsedTime;
}

double getTickNow(const LARGE_INTEGER& t1)
{
	LARGE_INTEGER t2;
	QueryPerformanceCounter(&t2);
	double elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	return elapsedTime;
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

CTimeMeasure::CTimeMeasure(const char* lpszFuntion, const char* lpszFile, int line)
//	: m_dwNow(GetTickCount())	
	: m_sLine(line)
{
	m_liLast = getLongTimer();

	strcpy_s(m_sFunc, lpszFuntion);
	strcpy_s(m_sFile, lpszFile);
}

CTimeMeasure::~CTimeMeasure()
{
	double dTime = getTickNow(m_liLast);
	//	m_dwNow = GetTickCount() - m_dwNow;
	CStringA sOut;
	sOut.Format("%s(%d): %s --> %.3f ms\n", m_sFile, m_sLine, m_sFunc, dTime);
	OutputDebugStringA(sOut);
}