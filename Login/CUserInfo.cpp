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


//д���ļ�
void CUserInfo::WriteFile(CStdioFile& file)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	//�ϲ�ѧ����Ϣ
	CString userWrite = m_name + "#" + m_password + "\n";
	//�ȶ�ȡ���û���Ϣ��������
	CString userRead;
	//��ȡÿһ����Ϣ
	while (file.ReadString(userRead))
	{
		//�ַ����ָ�û�����λ��
		int pos = userRead.Find("#");

		//�ж��û����Ƿ��Ѵ���
		//����ʼ��ȡ���֣����ָ�����ֹ
		if (m_name==userRead.Left(pos))
		{
			AfxMessageBox("�û����Ѵ���");
			return;
		}
	}

	//д���ļ�

	file.WriteString(userWrite);

}


//��ȡ�ļ�
void CUserInfo::ReadFile(CStdioFile& file)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	//�ȶ�ȡ���û���Ϣ��������
	//CString userRead;
	////��ȡÿһ����Ϣ
	//while (file.ReadString(userRead))
	//{
	//	//�ַ����ָ�û�����λ��
	//	int pos = userRead.Find("#");

	//	//����ʼ��ȡ���֣����ָ�����ֹ
	//	m_name = userRead.Left(pos);
	//	//���ұ߿�ʼ��ȡ���룬���ָ�����ֹ
	//	m_password = userRead.Right(pos);
	//}
}
