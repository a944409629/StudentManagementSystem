#pragma once
#include "afxcmn.h"


// CMainStudent �Ի���

class CMainStudent : public CDialog
{
	DECLARE_DYNAMIC(CMainStudent)

public:
	CMainStudent(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainStudent();

// �Ի�������
	enum { IDD = IDD_MAINSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab;
};
