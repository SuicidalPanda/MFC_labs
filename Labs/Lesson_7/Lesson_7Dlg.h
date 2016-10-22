#include "SetDlg.h"
// Lesson_7Dlg.h : header file
//

#pragma once


// CLesson_7Dlg dialog
class CLesson_7Dlg : public CDialogEx
{
// Construction
public:
	CLesson_7Dlg(CWnd* pParent = NULL);	// standard constructor

	SetDlg colorDlg;
	int mRadius;
	int mDirection;

// Dialog Data
	enum { IDD = IDD_LESSON_7_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnClickedDrawBtn();
	afx_msg void OnClickedDrawBtn();
};
