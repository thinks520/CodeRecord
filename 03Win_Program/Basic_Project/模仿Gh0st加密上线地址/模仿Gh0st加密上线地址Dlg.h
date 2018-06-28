
// 模仿Gh0st加密上线地址Dlg.h : 头文件
//

#pragma once


// C模仿Gh0st加密上线地址Dlg 对话框
class C模仿Gh0st加密上线地址Dlg : public CDialogEx
{
// 构造
public:
	C模仿Gh0st加密上线地址Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GH0ST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_remote_host;
	CString m_remote_port;

	CString m_encode;
	afx_msg void OnBnBuild();
	char * MyEncode(char *str); //加密函数
	int base64_encode(const void *data, int size, char **str); //base64_encode
	int pos(char c);
	int base64_decode(const char *str, char **data);
	char* MyDecode(char *str);
	afx_msg void OnBnGetLoginInfo();
	CString m_decode;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
