#pragma once
#include "afxcmn.h"


// CAllStudent �Ի���

class CAllStudent : public CDialog
{
	DECLARE_DYNAMIC(CAllStudent)

public:
	CAllStudent(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAllStudent();

// �Ի�������
	enum { IDD = IDD_ALLSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
