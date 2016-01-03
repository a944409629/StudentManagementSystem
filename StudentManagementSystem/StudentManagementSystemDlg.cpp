
// StudentManagementSystemDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CStudentManagementSystemDlg 对话框



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


// CStudentManagementSystemDlg 消息处理程序

BOOL CStudentManagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 1000, NULL);//设置定时器

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentManagementSystemDlg::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC dc2;
	dc2.CreateCompatibleDC(&dc);
	CBitmap bmp2;
	bmp2.LoadBitmap(IDB_BITMAP2);//加载位图资源
	BITMAP bitmap;
	bmp2.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dc2.SelectObject(&bmp2);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dc2, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentManagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentManagementSystemDlg::OnBnClickedLogin()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if ( m_user == "" && m_password == "" )
	{
		MessageBox(L"请输入用户名或密码！");
	}
	else
	{
		CStuPwd pwd;
		if (!pwd.Open())
		{
			MessageBox(L"数据库连接失败！");
			return;
		}
		pwd.MoveFirst();
		for (int i = 0; i <= 30; i++)
		{
			if (pwd.IsEOF())
			{
				MessageBox(L"用户不存在！");
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
					MessageBox(L"账号密码错误！");
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString strTime = CTime::GetCurrentTime().Format("%H:%M:%S");//定义时间，获取当前时间用时分秒格式输出
	CEdit *showTime = (CEdit*)GetDlgItem(IDC_EDIT3);//把输出的时间显示在编辑框里
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
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH);//定义一个空的画刷
		default:
				break;
	}
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}