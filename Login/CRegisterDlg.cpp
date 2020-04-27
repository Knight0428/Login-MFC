// CRegisterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Login.h"
#include "CRegisterDlg.h"
#include "afxdialogex.h"


// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialog)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(DLG_REGISTER, pParent)
	, m_RegisterName(_T(""))
	, m_RegisterPassword(_T(""))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, EDT_REGISTER_NAME, m_RegisterName);
	DDX_Text(pDX, EDT_REGISTER_PASSWORD, m_RegisterPassword);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
	ON_BN_CLICKED(BTN_REGISTER_DLG, &CRegisterDlg::OnBnClickedRegisterDlg)
	ON_BN_CLICKED(BTN_CANCEL, &CRegisterDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


void CRegisterDlg::OnBnClickedRegisterDlg()
{
	// TODO: 在此添加控件通知处理程序代码

	//检查输入是否为空
	UpdateData(TRUE);
	if (m_RegisterName.IsEmpty()||m_RegisterPassword.IsEmpty())
	{
		AfxMessageBox("请输入完整信息");
		return;
	}

	//注册后正常退出窗口
	EndDialog(IDOK);
}


void CRegisterDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	//取消退出窗口
	EndDialog(IDCANCEL);
}
