
// Lesson_6Dlg.h : header file
//

#pragma once


// CLesson_6Dlg dialog
class CLesson_6Dlg : public CDialogEx
{
// Construction
public:
	CLesson_6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_6_DIALOG };

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
	CString mResultEdit;
	afx_msg void OnClickedOkcancelBtn();
	afx_msg void OnClickedYesnocancelBtn();
	afx_msg void OnClickedRetrycancelBtn();
	afx_msg void OnClickedYesnoBtn();
};
