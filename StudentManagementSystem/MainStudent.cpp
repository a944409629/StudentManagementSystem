// MainStudent.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentManagementSystem.h"
#include "MainStudent.h"
#include "afxdialogex.h"


// CMainStudent �Ի���

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


// CMainStudent ��Ϣ�������


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
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}


BOOL CMainStudent::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
