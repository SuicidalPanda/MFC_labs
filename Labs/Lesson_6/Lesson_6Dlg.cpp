
// Lesson_6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_6.h"
#include "Lesson_6Dlg.h"
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


// CLesson_6Dlg dialog



CLesson_6Dlg::CLesson_6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLesson_6Dlg::IDD, pParent)
	, mResultEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson_6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ResultEdit, mResultEdit);
}

BEGIN_MESSAGE_MAP(CLesson_6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Exit_Btn, &CLesson_6Dlg::OnBnClickedBtn)
	ON_BN_CLICKED(Exit_Btn, &CLesson_6Dlg::OnBnClickedBtn)
	ON_BN_CLICKED(OkCancel_Btn, &CLesson_6Dlg::OnClickedOkcancelBtn)
	ON_BN_CLICKED(YesNoCancel_Btn, &CLesson_6Dlg::OnClickedYesnocancelBtn)
	ON_BN_CLICKED(RetryCancel_Btn, &CLesson_6Dlg::OnClickedRetrycancelBtn)
	ON_BN_CLICKED(YesNo_Btn, &CLesson_6Dlg::OnClickedYesnoBtn)
END_MESSAGE_MAP()


// CLesson_6Dlg message handlers

BOOL CLesson_6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

void CLesson_6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson_6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLesson_6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLesson_6Dlg::OnBnClickedBtn()
{
	// TODO: Add your control notification handler code here

	int iResults;
	iResults = MessageBox(L"Exit?",
		L"Are you sure want to Exit?",
		MB_YESNO + MB_ICONQUESTION);

	if (iResults == IDYES)
		OnOK();
}


void CLesson_6Dlg::OnClickedOkcancelBtn()
{
	// TODO: Add your control notification handler code here

	int iResults;

	iResults = MessageBox(L"You want Ok and Cancel buttons.",
		L"I am the second parametr of the MessageBox function",
		MB_OKCANCEL + MB_ICONSTOP);

	if (iResults == IDOK)
	{
		mResultEdit = "You Clicked the Ok button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		mResultEdit = "You clicked on the Cancel button";
		UpdateData(FALSE);
	}

}


void CLesson_6Dlg::OnClickedYesnocancelBtn()
{
	// TODO: Add your control notification handler code here

	int iResults;

	iResults = MessageBox(L"You want Yes, No and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNOCANCEL + MB_ICONINFORMATION);

	if (iResults == IDYES)
	{
		mResultEdit = "You clicked on the Yes button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		mResultEdit = "You clicked on the No button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		mResultEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}
}


void CLesson_6Dlg::OnClickedRetrycancelBtn()
{
	// TODO: Add your control notification handler code here

	int iResults;

	iResults = MessageBox(L"You want Retry and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_RETRYCANCEL + MB_ICONQUESTION);

	if (iResults == IDRETRY)
	{
		mResultEdit = "You clicked on the Retry button.";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		mResultEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}

}


void CLesson_6Dlg::OnClickedYesnoBtn()
{
	// TODO: Add your control notification handler code here

	int iResults;
	iResults = MessageBox(L"You want Yes and No buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNO + MB_ICONEXCLAMATION);

	if (iResults == IDOK)
	{
		mResultEdit = "You clicked on the OK button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		mResultEdit = "You clicked on the NO button.";
		UpdateData(FALSE);
	}

}
