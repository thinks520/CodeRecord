// 20171102-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdafx.h"
#include "windows.h"
#include "locale.h"
#include <tlhelp32.h>


//��������ʾCreateToolhelp32Snapshot Process32First Process32Next


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "chs");//�ñ������Ի���
	PROCESSENTRY32 pe32;//���̽���Ϣ�ṹ��
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		wprintf_s(L"CreateToolhelp32Snapshot ����ʧ��.\n");
		return -1;
	}
	BOOL bMore = Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		wprintf_s(L"�������ƣ�%s\n", pe32.szExeFile);
		wprintf_s(L"����ID��%u\n\n", pe32.th32ProcessID);
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);
	getchar();
	return 0;
}


