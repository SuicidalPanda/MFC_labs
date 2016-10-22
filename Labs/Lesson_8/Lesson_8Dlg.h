
// Lesson_8Dlg.h : header file
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


// CLesson_8Dlg dialog
class CLesson_8Dlg : public CDialogEx
{
// Construction
public:
	CLesson_8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LESSON_8_DIALOG };

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
private:
	CRect Canvas;
public:
	afx_msg void OnBnClickedBtn();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
private:
	CPoint LineEnd;
public:
//	CPoint LineNd;
private:
	CPoint LineStart;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	COLORREF PenColor;
	CRect PenColorSwatch;
public:
//	afx_msg void OnStnClickedPencolorpic();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPen mPen;
public:
	afx_msg void OnClickedPencolorpic();
	int mPenWidth;
	int mPenStyle;
	CComboBox mComboShapes;
	bool isDrawing;
	CString mDebugText;
	CEdit mTextEdit;
private:
	void DrawShape(bool stretch);
public:
	CBrush mBrush;
	COLORREF mBrushColor;
	CRect mBrushColorSwatch;
	CRect mBrushPreviewSwatch;
	int mBrushStyle;
	CListBox mBrushStyleList;
	afx_msg void OnSelchangeListBrushstyle();
	void PaintBrushPreview();
	afx_msg void OnClickedPicBrushcolor();
	CMetaFileDC* mpMF;
	bool firstTime;
	afx_msg void OnDestroy();
};
