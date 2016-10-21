
// Lesson_3Dlg.h : header file
//

#pragma once


// CLesson_3Dlg dialog
class CLesson_3Dlg : public CDialogEx
{
// Construction
public:
	CLesson_3Dlg(CWnd* pParent = NULL);	// standard constructor

	int m_PrevX;
	int m_PrevY;
// Dialog Data
	enum { IDD = IDD_LESSON_3_DIALOG };

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
	afx_msg void OnBnClickedbtn();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
