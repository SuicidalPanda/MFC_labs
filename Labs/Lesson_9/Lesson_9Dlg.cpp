
// Lesson_9Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_9.h"
#include "Lesson_9Dlg.h"
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


// CLesson_9Dlg dialog



CLesson_9Dlg::CLesson_9Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLesson_9Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mTref = AfxGetApp()->LoadIcon(ico_tref);
	mBoob = AfxGetApp()->LoadIcon(ico_boob);
	mHeart = AfxGetApp()->LoadIcon(ico_heart);
	mPik = AfxGetApp()->LoadIcon(ico_pik);
	mAmtRemaining = 100.0;
}

void CLesson_9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, picCard1, mCard1);
	DDX_Control(pDX, picCard2, mCard2);
	DDX_Control(pDX, picCard3, mCard3);
	DDX_Control(pDX, picCard4, mCard4);
	DDX_Control(pDX, group_AmountLeft, mAmountLeft);
}

BEGIN_MESSAGE_MAP(CLesson_9Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_Deal, &CLesson_9Dlg::OnBnClickedDeal)
	ON_BN_CLICKED(btn_CashOut, &CLesson_9Dlg::OnBnClickedCashout)
END_MESSAGE_MAP()


// CLesson_9Dlg message handlers

BOOL CLesson_9Dlg::OnInitDialog()
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

void CLesson_9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson_9Dlg::OnPaint()
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
HCURSOR CLesson_9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLesson_9Dlg::OnBnClickedDeal()
{
	CString s;

	mAmtRemaining -= 2.00;
	DealCards();
	CalculateWinnings();

	s.Format(L"Amount Remaining $ %.2f", mAmtRemaining);
	mAmountLeft.SetWindowText(s);
}


void CLesson_9Dlg::DealCards()
{
	for (int i = 0; i < 4; i++)
		mCards[i] = 0;

	mCard1.SetIcon(PickRandomCard());
	mCard2.SetIcon(PickRandomCard());
	mCard3.SetIcon(PickRandomCard());
	mCard4.SetIcon(PickRandomCard());
}


HICON& CLesson_9Dlg::PickRandomCard()
{
	int num = (rand() % 4);

	mCards[num]++;

	switch (num)
	{
	case 0: return mTref;
	case 1: return mBoob;
	case 2: return mHeart;
	}
	return mPik;
}


void CLesson_9Dlg::CalculateWinnings()
{
	int pairs = 0;
	for (int i = 0; i<4; i++)
	{
		if (mCards[i] == 2)
		{
			if (pairs>0)
			{
				mAmtRemaining += 3.00;
				break;
			}
			else
			{
				pairs++;
			}
		}
		else if (mCards[i] == 3)
		{
			mAmtRemaining += 6.00;
			break;

		}
		else if (mCards[i] == 4)
		{
			mAmtRemaining += 9.00;
			break;
		}
	}

}


void CLesson_9Dlg::OnBnClickedCashout()
{
	CString s;

	s.Format(L"Good game! I have $ %.2f.", mAmtRemaining);
	MessageBox(s, L"Thank you for game in FourUp!");

	CDialog::OnCancel();
}
