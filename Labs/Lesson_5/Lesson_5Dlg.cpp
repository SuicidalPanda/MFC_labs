
// Lesson_5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_5.h"
#include "Lesson_5Dlg.h"
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
public:
	afx_msg void OnFileCurrentspeed();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_FILE_CURRENTSPEED, &CAboutDlg::OnFileCurrentspeed)
END_MESSAGE_MAP()


// CLesson_5Dlg dialog



CLesson_5Dlg::CLesson_5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLesson_5Dlg::IDD, pParent)
	, mSpeedEdit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson_5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Speed_Edit, mSpeedEdit);
	DDV_MinMaxInt(pDX, mSpeedEdit, 0, 100);
}

BEGIN_MESSAGE_MAP(CLesson_5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(Speed_Edit, &CLesson_5Dlg::OnEnChangeEdit)
	ON_COMMAND(ID_FILE_CURRENTSPEED, &CLesson_5Dlg::OnFileCurrentspeed)
	ON_COMMAND(ID_FILE_EXIT, &CLesson_5Dlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &CLesson_5Dlg::OnHelpAbout)
	ON_COMMAND(ID_HELP_SAYHELLO, &CLesson_5Dlg::OnHelpSayhello)
END_MESSAGE_MAP()


// CLesson_5Dlg message handlers

BOOL CLesson_5Dlg::OnInitDialog()
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

void CLesson_5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson_5Dlg::OnPaint()
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
HCURSOR CLesson_5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLesson_5Dlg::OnEnChangeEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
}


void CAboutDlg::OnFileCurrentspeed()
{
	// TODO: Add your command handler code here
}


void CLesson_5Dlg::OnFileCurrentspeed()
{
	// TODO: Add your command handler code here

	wchar_t strSpeed[100];
	_itow_s(mSpeedEdit, strSpeed, 10);
	MessageBox(strSpeed);
}


void CLesson_5Dlg::OnFileExit()
{
	// TODO: Add your command handler code here

	OnOK();
}


void CLesson_5Dlg::OnHelpAbout()
{
	// TODO: Add your command handler code here

	CAboutDlg dlg;
	dlg.DoModal();
}


void CLesson_5Dlg::OnHelpSayhello()
{
	// TODO: Add your command handler code here

	MessageBox(L"Hello!");
}
