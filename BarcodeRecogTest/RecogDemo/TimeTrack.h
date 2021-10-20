#pragma once

LARGE_INTEGER getLongTimer();
double getTickTime(const LARGE_INTEGER& t1, const LARGE_INTEGER& t2);
double getTickNow(const LARGE_INTEGER& t1);
void initTimer();

class CTimeMeasure 
{
public:
	CTimeMeasure(const char* lpszFuntion, const char* lpszFile, int line);
	~CTimeMeasure();
private:
	//	DWORD m_dwNow;
	LARGE_INTEGER m_liLast;

	char m_sFunc[256];
	char m_sFile[256];
	int		m_sLine;
};
//.EOF