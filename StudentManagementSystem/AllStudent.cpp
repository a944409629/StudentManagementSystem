// AllStudent.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManagementSystem.h"
#include "AllStudent.h"
#include "afxdialogex.h"
#include "Student.h"


// CAllStudent 对话框

IMPLEMENT_DYNAMIC(CAllStudent, CDialog)

CAllStudent::CAllStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CAllStudent::IDD, pParent)
{

}

CAllStudent::~CAllStudent()
{
}

void CAllStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CAllStudent, CDialog)
END_MESSAGE_MAP()


// CAllStudent 消息处理程序


BOOL CAllStudent::OnInitDialog()
{
	CDialog::OnInitDialog();
	UpdateData(true);
	// 将“关于...”菜单项添加到系统菜单中。
	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width() / 4, 0);
	//m_list.InsertColumn(1, _T("密码"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_list.InsertColumn(2, _T("年龄"), LVCFMT_CENTER, rect.Width() / 4, 2);
	m_list.InsertColumn(3, _T("性别"), LVCFMT_CENTER, rect.Width() / 4, 3);
	m_list.InsertColumn(4, _T("专业"), LVCFMT_CENTER, rect.Width() / 4, 4);
	m_list.InsertColumn(5, _T("学院"), LVCFMT_CENTER, rect.Width() / 4, 5);
	int i;
	CString temp, string, string1;
	CStudent stu;
	if (stu.IsOpen())
	{
		stu.Close();
	}
	else
	{
		stu.Open();
	}
	stu.MoveFirst();
	for (i = 0; i < 30; i++)
	{
		m_list.InsertItem(i, (stu.m_StuNum));
		//m_list.SetItemText(i, 1, (stu.m_StuPwd));
		m_list.SetItemText(i, 1, (stu.m_StuName));
		string1.Format(L"%d", stu.m_StuAge);
		m_list.SetItemText(i, 2, (string1));
		string.Format(L"%s", stu.m_StuSex);
		m_list.SetItemText(i, 3, (string));
		m_list.SetItemText(i, 4, (stu.m_StuMajor));
		m_list.SetItemText(i, 5, (stu.m_StuCollege));
		stu.MoveNext();
	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
