#pragma once
#include "afxcmn.h"


// CMainStudent 对话框

class CMainStudent : public CDialog
{
	DECLARE_DYNAMIC(CMainStudent)

public:
	CMainStudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainStudent();

// 对话框数据
	enum { IDD = IDD_MAINSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab;
};
