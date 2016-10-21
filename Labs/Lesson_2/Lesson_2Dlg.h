
// Lesson_2Dlg.h : header file
//

#pragma once


// CLesson_2Dlg dialog
class CLesson_2Dlg : public CDialogEx
{
// Construction
public:
	CLesson_2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_2_DIALOG };

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
//	CString m_;
	BOOL m_EnableCheck;
	BOOL m_VisibleCheck;
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedTestButton();
	CString m_TestEdit;
	afx_msg void OnBnClickedClearButton();
	afx_msg void OnBnClickedVisibleCheck();
	afx_msg void OnBnClickedEnabledCheck();
	afx_msg void OnEnChangeTestEdit();
};
