
// Lesson_5Dlg.h : header file
//

#pragma once


// CLesson_5Dlg dialog
class CLesson_5Dlg : public CDialogEx
{
// Construction
public:
	CLesson_5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_5_DIALOG };

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
	int mSpeedEdit;
	afx_msg void OnEnChangeEdit();
	afx_msg void OnFileCurrentspeed();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpSayhello();
};
