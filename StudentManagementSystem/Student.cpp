// Student.h : CStudent 类的实现



// CStudent 实现

// 代码生成在 2015年12月8日, 9:53

#include "stdafx.h"
#include "Student.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_StuNum = L"";
	m_StuName = L"";
	m_StuAge = 0;
	m_StuSex = L"";
	m_StuMajor = L"";
	m_StuCollege = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=XJGL;Description=\x5b66\x7c4d\x7ba1\x7406;UID=sa;PWD=yzq123;APP=Microsoft\x00ae Visual Studio\x00ae 2013;WSID=USER-20151012UB;DATABASE=XJGL");
}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[StuNum]"), m_StuNum);
	RFX_Text(pFX, _T("[StuName]"), m_StuName);
	RFX_Long(pFX, _T("[StuAge]"), m_StuAge);
	RFX_Text(pFX, _T("[StuSex]"), m_StuSex);
	RFX_Text(pFX, _T("[StuMajor]"), m_StuMajor);
	RFX_Text(pFX, _T("[StuCollege]"), m_StuCollege);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent 诊断

#ifdef _DEBUG
void CStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


