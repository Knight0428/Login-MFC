
// LoginDlg.h: 头文件
//

#pragma once


// CLoginDlg 对话框
class CLoginDlg : public CDialogEx
{
// 构造
public:
	CLoginDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DLG_LOGIN };
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
	CString m_name;
	CString m_password;
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedRegister();
};
