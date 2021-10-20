#include "stdafx.h"
#include "IViewModel.h"

IImageViewModel::IImageViewModel()
	: m_pView(NULL)
{

}

IImageViewModel::~IImageViewModel()
{

}

void IImageViewModel::SetView(CWnd* pWnd)
{
	m_pView = pWnd;
}