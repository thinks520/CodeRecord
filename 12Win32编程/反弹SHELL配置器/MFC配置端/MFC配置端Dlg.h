
// MFC���ö�Dlg.h : ͷ�ļ�
//

#pragma once


// CMFC���ö�Dlg �Ի���
class CMFC���ö�Dlg : public CDialogEx
{
// ����
public:
	CMFC���ö�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_szIpStr;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnChangePE();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_szPortStr;
	CString m_szOtherStr;
	afx_msg void OnBnChangeResource();

	// �޸�PE���ļ�
	CString strPath, strEXE, strResult;
	// ����״̬ʶ��
    // 1 exe
	// 2 dll
	int BuildFlag;

	afx_msg void OnBuild_DLL();
	CString m_usage_method;
	afx_msg void Builx64EXE();
	afx_msg void Builx64DLL();
};
