// StuPwd.h : CStuPwd ���ʵ��



// CStuPwd ʵ��

// ���������� 2015��12��8��, 9:00

#include "stdafx.h"
#include "StuPwd.h"
IMPLEMENT_DYNAMIC(CStuPwd, CRecordset)

CStuPwd::CStuPwd(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_StuNum = L"";
	m_StuPwd = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CStuPwd::GetDefaultConnect()
{
	return _T("DSN=XJGL;Description=\x5b66\x7c4d\x7ba1\x7406;UID=sa;PWD=yzq123;APP=Microsoft\x00ae Visual Studio\x00ae 2013;WSID=USER-20151012UB;DATABASE=XJGL");
}

CString CStuPwd::GetDefaultSQL()
{
	return _T("[dbo].[StuPwd]");
}

void CStuPwd::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[StuNum]"), m_StuNum);
	RFX_Text(pFX, _T("[StuPwd]"), m_StuPwd);

}
/////////////////////////////////////////////////////////////////////////////
// CStuPwd ���

#ifdef _DEBUG
void CStuPwd::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStuPwd::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


