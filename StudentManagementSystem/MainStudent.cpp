// MainStudent.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManagementSystem.h"
#include "MainStudent.h"
#include "afxdialogex.h"


// CMainStudent 对话框

IMPLEMENT_DYNAMIC(CMainStudent, CDialog)

CMainStudent::CMainStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CMainStudent::IDD, pParent)
{

}

CMainStudent::~CMainStudent()
{
}

void CMainStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainStudent, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMainStudent 消息处理程序


void CMainStudent::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);
	CDC dc1;
	dc1.CreateCompatibleDC(&dc);
	CBitmap bmp1;
	bmp1.LoadBitmap(IDB_BITMAP1);
	BITMAP bitmap;
	bmp1.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dc1.SelectObject(&bmp1);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dc1, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}


BOOL CMainStudent::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
