
// StudentManagementSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentManagementSystem.h"
#include "StudentManagementSystemDlg.h"
#include "afxdialogex.h"
#include "StuPwd.h"
#include "MainStudent.h"
#include "AllStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentManagementSystemDlg �Ի���



CStudentManagementSystemDlg::CStudentManagementSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStudentManagementSystemDlg::IDD, pParent)
	, m_user(_T(""))
	, m_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentManagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}

BEGIN_MESSAGE_MAP(CStudentManagementSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Login, &CStudentManagementSystemDlg::OnBnClickedLogin)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CStudentManagementSystemDlg ��Ϣ�������

BOOL CStudentManagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 1000, NULL);//���ö�ʱ��

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CStudentManagementSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStudentManagementSystemDlg::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC dc2;
	dc2.CreateCompatibleDC(&dc);
	CBitmap bmp2;
	bmp2.LoadBitmap(IDB_BITMAP2);//����λͼ��Դ
	BITMAP bitmap;
	bmp2.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dc2.SelectObject(&bmp2);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dc2, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CStudentManagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentManagementSystemDlg::OnBnClickedLogin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if ( m_user == "" && m_password == "" )
	{
		MessageBox(L"�������û��������룡");
	}
	else
	{
		CStuPwd pwd;
		if (!pwd.Open())
		{
			MessageBox(L"���ݿ�����ʧ�ܣ�");
			return;
		}
		pwd.MoveFirst();
		for (int i = 0; i <= 30; i++)
		{
			if (pwd.IsEOF())
			{
				MessageBox(L"�û������ڣ�");
				return;
			}
			else
			{
				if (m_user == pwd.m_StuNum&&m_password == pwd.m_StuPwd)
				{
					CAllStudent dlg1;
					dlg1.DoModal();
					return;
				}
				else if (pwd.IsEOF())
				{
					MessageBox(L"�˺��������");
						return;
				}
				else
				{
					pwd.MoveNext();
				}
			}
		}
	}
}


void CStudentManagementSystemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString strTime = CTime::GetCurrentTime().Format("%H:%M:%S");//����ʱ�䣬��ȡ��ǰʱ����ʱ�����ʽ���
	CEdit *showTime = (CEdit*)GetDlgItem(IDC_EDIT3);//�������ʱ����ʾ�ڱ༭����
	showTime->SetWindowText(strTime);
	CDialog::OnTimer(nIDEvent);
	CDialogEx::OnTimer(nIDEvent);
}


HBRUSH CStudentManagementSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC:
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(RGB(0, 0, 0));
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH);//����һ���յĻ�ˢ
		default:
				break;
	}
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}