#pragma once
#include "afxcmn.h"


// CAllStudent 对话框

class CAllStudent : public CDialog
{
	DECLARE_DYNAMIC(CAllStudent)

public:
	CAllStudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAllStudent();

// 对话框数据
	enum { IDD = IDD_ALLSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
