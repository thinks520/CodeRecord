
// 模仿Gh0st加密上线地址Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "模仿Gh0st加密上线地址.h"
#include "模仿Gh0st加密上线地址Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C模仿Gh0st加密上线地址Dlg 对话框



C模仿Gh0st加密上线地址Dlg::C模仿Gh0st加密上线地址Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GH0ST_DIALOG, pParent)
	, m_remote_host(_T(""))
	, m_remote_port(_T(""))
	, m_encode(_T(""))
	, m_decode(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C模仿Gh0st加密上线地址Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_remote_host);
	DDX_Text(pDX, IDC_EDIT3, m_remote_port);
	DDX_Text(pDX, IDC_EDIT7, m_encode);
	DDX_Text(pDX, IDC_EDIT8, m_decode);
}

BEGIN_MESSAGE_MAP(C模仿Gh0st加密上线地址Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C模仿Gh0st加密上线地址Dlg::OnBnBuild)
	ON_BN_CLICKED(IDC_BUTTON2, &C模仿Gh0st加密上线地址Dlg::OnBnGetLoginInfo)
END_MESSAGE_MAP()


// C模仿Gh0st加密上线地址Dlg 消息处理程序

BOOL C模仿Gh0st加密上线地址Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C模仿Gh0st加密上线地址Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C模仿Gh0st加密上线地址Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C模仿Gh0st加密上线地址Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C模仿Gh0st加密上线地址Dlg::OnBnBuild()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_remote_host.Replace(L" ", L"");
	m_remote_port.Replace(L" ", L"");

	CString str = m_remote_host + ":" + m_remote_port;
	str.MakeLower();
	TCHAR * pWStrKey;         // 合并后的内容

	// 开辟数组
	pWStrKey = new TCHAR[str.GetLength() + 1];
	pWStrKey = str.GetBuffer(0);

	// 第一次调用确认转换后单字节字符串的长度，用于开辟空间
	int pSize = WideCharToMultiByte(CP_OEMCP, 0, pWStrKey, wcslen(pWStrKey), NULL, 0, NULL, NULL);
	// 单字符
	char* pCStrKey = new char[pSize + 1];
	// 第二次调用将双字节字符串转换成单字节字符串
	WideCharToMultiByte(CP_OEMCP, 0, pWStrKey, wcslen(pWStrKey), pCStrKey, pSize, NULL, NULL);
	pCStrKey[pSize] = '\0';

	// 接收char*
	m_encode = MyEncode(pCStrKey);

	m_encode.Insert(0, L"AAAA");
	m_encode += "AAAA";

	UpdateData(FALSE);
}

void C模仿Gh0st加密上线地址Dlg::OnBnGetLoginInfo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);


	// 1 获取加密编辑控件里的字符串
	int pSize = m_encode.GetLength() + 1;
	wchar_t	* pStart, *pEnd;
	wchar_t strKey[] = L"AAAA";
	wchar_t strEncode[1024];

	// 拿到最开始的字符串,如果前面是AAAA就赋值到pStart
	pStart = wcsstr(m_encode.GetBuffer(0), strKey);
	// 前移动4个字节，也就是跳过AAAA
	pStart += 4;
	// 如果AAAA匹配不到把strKey，也就是AAAA赋值给pEnd
	pEnd = wcsstr(pStart, strKey);
	// 清空原先AAAA字符串
	wmemset(strEncode, 0, wcslen(pStart) + 1);
	// 取key值之间的内容，配置字符串 - 字符串长度，取前面的真实加密字符串
	wmemcpy(strEncode, pStart, pEnd - pStart);
	// 单字符
	char* pCStrKey = new char[wcslen(strEncode) + 1];
	// 调用将双字节字符串转换成单字节字符串
	WideCharToMultiByte(CP_OEMCP, 0, strEncode, wcslen(strEncode) + 1, pCStrKey, wcslen(strEncode) + 1, NULL, NULL);
	pCStrKey[pSize] = '\0';

	// 解密代码
	m_decode = MyDecode(pCStrKey);


	UpdateData(FALSE);
}

// Base64编码
static char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int C模仿Gh0st加密上线地址Dlg::base64_encode(const void *data, int size, char **str)
{
	char *s, *p;
	int i;
	int c;
	const unsigned char *q;

	p = s = (char*)malloc(size * 4 / 3 + 4);
	if (p == NULL)
		return -1;
	q = (const unsigned char*)data;
	i = 0;
	for (i = 0; i < size;) {
		c = q[i++];
		c *= 256;
		if (i < size)
			c += q[i];
		i++;
		c *= 256;
		if (i < size)
			c += q[i];
		i++;
		p[0] = base64[(c & 0x00fc0000) >> 18];  //base64
		p[1] = base64[(c & 0x0003f000) >> 12];
		p[2] = base64[(c & 0x00000fc0) >> 6];
		p[3] = base64[(c & 0x0000003f) >> 0];
		if (i > size)
			p[3] = '=';
		if (i > size + 1)
			p[2] = '=';
		p += 4;
	}
	*p = 0;
	*str = s;
	return strlen(s);
}

// 加密编码
char * C模仿Gh0st加密上线地址Dlg::MyEncode(char *str)
{
	int		i, len;
	char	*s, *data;
	// 字符串长度
	len = strlen(str) + 1;
	// 开辟字符串相对应的内存空间
	s = (char *)malloc(len);
	// 将字符串拷贝到开辟出来的指针中
	memcpy(s, str, len);
	// 异或操作
	for (i = 0; i < len; i++)
	{
		s[i] ^= 0x19;
		s[i] += 0x86;
	}
	// Base64编码
	base64_encode(s, len, &data);
	free(s);

	return data;
}

// 解码密钥
int C模仿Gh0st加密上线地址Dlg::pos(char c)
{
	char *p;
	for (p = base64; *p; p++)
		if (*p == c)
			return p - base64;
	return -1;
}

// Base64解码
int C模仿Gh0st加密上线地址Dlg::base64_decode(const char *str, char **data)
{
	const char *s, *p;
	unsigned char *q;
	int c;
	int x;
	int done = 0;
	int len;
	s = (const char *)malloc(strlen(str));
	q = (unsigned char *)s;
	for (p = str; *p && !done; p += 4) {
		x = pos(p[0]);
		if (x >= 0)
			c = x;
		else {
			done = 3;
			break;
		}
		c *= 64;

		x = pos(p[1]);
		if (x >= 0)
			c += x;
		else
			return -1;
		c *= 64;

		if (p[2] == '=')
			done++;
		else {
			x = pos(p[2]);
			if (x >= 0)
				c += x;
			else
				return -1;
		}
		c *= 64;

		if (p[3] == '=')
			done++;
		else {
			if (done)
				return -1;
			x = pos(p[3]);
			if (x >= 0)
				c += x;
			else
				return -1;
		}
		if (done < 3)
			*q++ = (c & 0x00ff0000) >> 16;

		if (done < 2)
			*q++ = (c & 0x0000ff00) >> 8;
		if (done < 1)
			*q++ = (c & 0x000000ff) >> 0;
	}

	len = q - (unsigned char*)(s);

	*data = (char*)realloc((void *)s, len);

	return len;
}

// 解密函数
char* C模仿Gh0st加密上线地址Dlg::MyDecode(char *str)
{
	int		i, len;
	char	*data = NULL;
	len = base64_decode(str, &data);

	for (i = 0; i < len; i++)
	{
		data[i] -= 0x86;
		data[i] ^= 0x19;

		//data[i] -= 0x6;
		//data[i] ^= 0x12;
	}
	return data;
}



BOOL C模仿Gh0st加密上线地址Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_BUTTON1)//按下回车，如果当前焦点是在自己期望的控件上
		{
			// 你想做的事，如果按下回车时焦点在你想要的控件上
			OnBnBuild();
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}
