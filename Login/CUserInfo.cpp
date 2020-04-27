#include "stdafx.h"
#include "CUserInfo.h"


CUserInfo::CUserInfo()
{
	SetName(_T(""));
	SetPassword(_T(""));
}


CUserInfo::~CUserInfo()
{
}


//写入文件
void CUserInfo::WriteFile(CStdioFile& file)
{
	// TODO: 在此处添加实现代码.

	//合并学生信息
	CString userWrite = m_name + "#" + m_password + "\n";
	//先读取的用户信息到缓冲区
	CString userRead;
	//读取每一行信息
	while (file.ReadString(userRead))
	{
		//字符串分割，用户名的位置
		int pos = userRead.Find("#");

		//判断用户名是否已存在
		//从左开始提取名字，到分隔符截止
		if (m_name==userRead.Left(pos))
		{
			AfxMessageBox("用户名已存在");
			return;
		}
	}

	//写入文件

	file.WriteString(userWrite);

}


//读取文件
void CUserInfo::ReadFile(CStdioFile& file)
{
	// TODO: 在此处添加实现代码.

	//先读取的用户信息到缓冲区
	//CString userRead;
	////读取每一行信息
	//while (file.ReadString(userRead))
	//{
	//	//字符串分割，用户名的位置
	//	int pos = userRead.Find("#");

	//	//从左开始提取名字，到分隔符截止
	//	m_name = userRead.Left(pos);
	//	//从右边开始提取密码，到分隔符截止
	//	m_password = userRead.Right(pos);
	//}
}
