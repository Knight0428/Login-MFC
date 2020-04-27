
// LoginDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Login.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "CRegisterDlg.h"

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


// CLoginDlg 对话框



CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	, m_name(_T(""))
	, m_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, EDT_LOGIN_NAME, m_name);
	DDX_Text(pDX, EDT_LOGIN_PASSWORD, m_password);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_LOGIN, &CLoginDlg::OnBnClickedLogin)
	ON_BN_CLICKED(BTN_REGISTER, &CLoginDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CLoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLoginDlg::OnPaint()
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
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//登录存在bug，shift这类键也会被接受

//点击登录按钮
void CLoginDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取数据
	UpdateData(TRUE);
	if (m_name.IsEmpty() || m_password.IsEmpty())
	{
		AfxMessageBox("请输入完整");
		return;
	}

	CStdioFile file("user.dat", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);

	//CUserInfo* pUser = new CUserInfo;
	//pUser->ReadFile(file);

	//if (m_name==pUser->GetName()&&m_password==pUser->GetPassword())
	//{
	//	AfxMessageBox("登录成功");
	//	return;
	//}

	CString userRead;
	//读取每一行信息
	CString name;
	CString password;

	while (file.ReadString(userRead))
	{
		//字符串分割，用户名的位置
		int pos = userRead.Find("#");

		//从左开始提取名字，到分隔符截止
		name = userRead.Left(pos);
		//从右边开始提取密码，到分隔符截止
		password = userRead.Right(pos);

		//是否存在
		if (m_name==name&&m_password==password)
		{
			AfxMessageBox("登录成功");
			return;
		}

	}


	AfxMessageBox("输入错误或不存在");
}


//点击注册按钮
void CLoginDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	
	ShowWindow(SW_HIDE);

	//新建注册窗口类
	CRegisterDlg dlgRegister;
	//模态对话框，返回值传递给EndDialog的参数
	INT_PTR nRet = dlgRegister.DoModal();

	//逻辑处理尽量在同一个窗口类中

	//若是注册退出后窗口
	if (nRet == IDOK)
	{
		//保存新用户到文件
		CUserInfo* pUser = new CUserInfo;
		//从注册窗口类中获取信息，保存在缓冲区
		pUser->SetName(dlgRegister.m_RegisterName);
		pUser->SetPassword(dlgRegister.m_RegisterPassword);

		//创建文件
		CStdioFile file("user.dat", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		//写入文件
		pUser->WriteFile(file);
		//关闭文件
		file.Close();

		AfxMessageBox("注册成功!");
		delete pUser;

	}

	ShowWindow(SW_SHOWNORMAL);

}
