
// Lesson_7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_7.h"
#include "Lesson_7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLesson_7Dlg dialog



CLesson_7Dlg::CLesson_7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLesson_7Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson_7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson_7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Exit_Btn, &CLesson_7Dlg::OnBnClickedBtn)
//	ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_TIMER()
//ON_BN_CLICKED(Draw_Btn, &CLesson_7Dlg::OnClickedDrawBtn)
ON_BN_CLICKED(Draw_Btn, &CLesson_7Dlg::OnClickedDrawBtn)
END_MESSAGE_MAP()


// CLesson_7Dlg message handlers

BOOL CLesson_7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	int iInstallResult;
	iInstallResult = SetTimer(1, 50, NULL);
	if (iInstallResult == FALSE)
	{
		MessageBox(L"Cannot install timer",
			L"Error message",
			MB_OK + MB_ICONERROR);
	}

	colorDlg.setRadio = 0;
	mRadius = 50;
	mDirection = 1;

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLesson_7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLesson_7Dlg::OnPaint()
{
	if (IsIconic())
	{
	}
	else
	{
		CPaintDC dc(this);
		CPen MyNewPen;

		switch (colorDlg.setRadio)
		{
		case 0:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
			break;
		case 1:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 255, 0));
			break;
		case 2:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
			break;
		}

		CPen* pOriginalPen;
		CRect MyRectangle(20, 10, 20 + mRadius * 2, 10 + mRadius * 2);

		pOriginalPen = dc.SelectObject(&MyNewPen);
		dc.Ellipse(&MyRectangle);
		dc.SelectObject(pOriginalPen);
	}

	UpdateData(TRUE);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLesson_7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLesson_7Dlg::OnBnClickedBtn()
{
	// TODO: Add your control notification handler code here

	OnOK();
}


void CLesson_7Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	KillTimer(1);
	// TODO: Add your message handler code here
}


void CLesson_7Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	//MessageBeep((WORD)-2);

	mRadius = mRadius + mDirection;

	if (mRadius >= 100)
	{
		mDirection = -1;
	}
	if (mRadius <= 10)
	{
		mDirection = 1;
	}

	OnPaint();
	Invalidate();
	CDialogEx::OnTimer(nIDEvent);
}

void CLesson_7Dlg::OnClickedDrawBtn()
{
	// TODO: Add your control notification handler code here

	colorDlg.DoModal();
}
