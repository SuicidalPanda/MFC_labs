
// Lesson_1Dlg.h : header file
//

#pragma once


// CLesson_1Dlg dialog
class CLesson_1Dlg : public CDialogEx
{
// Construction
public:
	CLesson_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_1_DIALOG };

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
	afx_msg void OnBnClickedSayhelloButton();
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedBeepButton();
};
