
// MFC���ö�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC���ö�App: 
// �йش����ʵ�֣������ MFC���ö�.cpp
//

class CMFC���ö�App : public CWinApp
{
public:
	CMFC���ö�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC���ö�App theApp;