
// Lesson_9Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CLesson_9Dlg dialog
class CLesson_9Dlg : public CDialogEx
{
// Construction
public:
	CLesson_9Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_9_DIALOG };

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
	HICON mHeart;
	HICON mTref;
	HICON mBoob;
	HICON mPik;
	CStatic mCard1;
	CStatic mCard2;
	CStatic mCard3;
	CStatic mCard4;
	CStatic mAmountLeft;
	double mAmtRemaining;
	afx_msg void OnBnClickedDeal();
	int mCards[4];
	void DealCards();
	HICON& PickRandomCard();
	void CalculateWinnings();
	afx_msg void OnBnClickedCashout();
};
