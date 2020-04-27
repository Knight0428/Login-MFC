#pragma once


//用户信息类
class CUserInfo
{
public:
	CUserInfo();
	~CUserInfo();

	CString GetName() const { return m_name; }
	void SetName(CString val) { m_name = val; }
	CString GetPassword() const { return m_password; }
	void SetPassword(CString val) { m_password = val; }

private:
	CString m_name;
	CString m_password;

public:
	void WriteFile(CStdioFile& file);
	void ReadFile(CStdioFile& file);
};

