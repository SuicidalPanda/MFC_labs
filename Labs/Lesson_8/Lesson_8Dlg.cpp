
// Lesson_8Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_8.h"
#include "Lesson_8Dlg.h"
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


// CLesson_8Dlg dialog



CLesson_8Dlg::CLesson_8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLesson_8Dlg::IDD, pParent)
	, mPenWidth(0)
	, mPenStyle(0)
	, mDebugText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	PenColor = RGB(0, 0, 0);
	//mBrushStyleList = 0;
}

void CLesson_8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Edit_PenWidth, mPenWidth);
	DDV_MinMaxInt(pDX, mPenWidth, 1, 32);
	DDX_Radio(pDX, Radio_SolidPen, mPenStyle);
	DDV_MinMaxInt(pDX, mPenStyle, 0, 6);
	DDX_Control(pDX, ComboShapes, mComboShapes);
	DDX_Text(pDX, DebugEdit, mDebugText);
	DDX_Control(pDX, DebugEdit, mTextEdit);
	DDX_Control(pDX, List_BrushStyle, mBrushStyleList);
}

BEGIN_MESSAGE_MAP(CLesson_8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Clear_Btn, &CLesson_8Dlg::OnBnClickedBtn)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
//	ON_STN_CLICKED(PenColorPic, &CLesson_8Dlg::OnStnClickedPencolorpic)
	ON_WM_LBUTTONDOWN()
	ON_STN_CLICKED(PenColorPic, &CLesson_8Dlg::OnClickedPencolorpic)
	ON_LBN_SELCHANGE(List_BrushStyle, &CLesson_8Dlg::OnSelchangeListBrushstyle)
	ON_STN_CLICKED(Pic_BrushColor, &CLesson_8Dlg::OnClickedPicBrushcolor)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CLesson_8Dlg message handlers

BOOL CLesson_8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	CWnd* pCanvas = GetDlgItem(IDC_CANVAS);
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(Spin_PenWidth);
	CWnd* pBrushColor = GetDlgItem(Pic_BrushColor);
	CWnd* pPreviewColor = GetDlgItem(Pic_BrushPrev);

	pCanvas->GetWindowRect(&Canvas);
	ScreenToClient(&Canvas);
	Canvas.DeflateRect(2, 2, 1, 1);
	mPenWidth = 1;
	pSpin->SetRange(1, 32);
	pSpin->SetPos(1);
	mComboShapes.AddString(L"FreeHand");
	mComboShapes.AddString(L"Lines");
	mComboShapes.AddString(L"Ovals");
	mComboShapes.AddString(L"Rectangle");
	mComboShapes.SetCurSel(0);
	pBrushColor->GetWindowRect(&mBrushColorSwatch);
	ScreenToClient(&mBrushColorSwatch);
	mBrushColorSwatch.DeflateRect(2, 2, 1, 1);
	pPreviewColor->GetWindowRect(&mBrushPreviewSwatch);
	ScreenToClient(&mBrushPreviewSwatch);
	mBrushPreviewSwatch.DeflateRect(2, 2, 1, 1);
	mBrushColor = RGB(0, 0, 0);
	mBrush.CreateStockObject(WHITE_BRUSH);

	mBrushStyleList.AddString(L"(none)");
	mBrushStyleList.AddString(L"Solid");
	mBrushStyleList.AddString(L"LL-UR Diagonal");
	mBrushStyleList.AddString(L"UL-LR Diagonal");
	mBrushStyleList.AddString(L"Grid");
	mBrushStyleList.AddString(L"Grid Diagonal");
	mBrushStyleList.AddString(L"Horizontal");
	mBrushStyleList.AddString(L"Vertical");
	mBrushStyleList.AddString(L"White");
	mBrushStyleList.AddString(L"Light Gray");
	mBrushStyleList.AddString(L"Medium Gray");
	mBrushStyleList.AddString(L"Dark Gray");
	mBrushStyleList.AddString(L"Black");

	mBrushStyleList.SetCurSel(8);

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

	CWnd* pPenColor = GetDlgItem(PenColorPic);

	pPenColor->GetWindowRect(&PenColorSwatch);
	ScreenToClient(&PenColorSwatch);
	PenColorSwatch.DeflateRect(2, 2, 1, 1);

	mpMF = new CMetaFileDC;
	mpMF->Create();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLesson_8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson_8Dlg::OnPaint()
{
	CPaintDC dc(this);

	HMETAFILE hmf = mpMF->Close();
	dc.PlayMetaFile(hmf);

	CMetaFileDC* temp = new CMetaFileDC;

	temp->Create();
	temp->PlayMetaFile(hmf);
	DeleteMetaFile(hmf);

	//delete hmf;

	mpMF = temp;

	firstTime = TRUE;

	if (firstTime)
	{
		OnBnClickedBtn();
		firstTime = FALSE;
	}

	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLesson_8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLesson_8Dlg::OnBnClickedBtn()
{
	// TODO: Add your control notification handler code here

	CClientDC dc(this);
	HMETAFILE hmf = mpMF->Close();
	::DeleteMetaFile(hmf);
	//delete hmf;

	mpMF = new CMetaFileDC;
	mpMF->Create();
	mpMF->SetAttribDC(dc);

	dc.SelectStockObject(NULL_PEN);
	dc.Rectangle(Canvas);

	mpMF->SelectStockObject(NULL_PEN);
	mpMF->Rectangle(Canvas.left, Canvas.top, Canvas.right + 1, Canvas.bottom + 1);
}


void CLesson_8Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonDblClk(nFlags, point);

	if (Canvas.PtInRect(point))
	{
		LineStart = point;
		LineEnd = point;
		SetCapture();
	}
}


void CLesson_8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnMouseMove(nFlags, point);

	if (isDrawing && (nFlags & MK_LBUTTON) && Canvas.PtInRect(point))
	{
		DrawShape(true);
		LineEnd = point;
		DrawShape(true);

		//mTextEdit.ReplaceSel(L"Mouse MOVE\r\n");
	}
}

void CLesson_8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	isDrawing = FALSE;

	if (Canvas.PtInRect(point))
	{
		LineEnd = point;
		DrawShape(false);
	}
	else
		DrawShape(true);

	LineStart = point;
	ReleaseCapture();
	mTextEdit.SetWindowTextW(L"");
	mTextEdit.ReplaceSel(L"Mouse UP\r\n");
}

void CLesson_8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialogEx::OnLButtonDown(nFlags, point);

	if (Canvas.PtInRect(point))
	{
		LineStart = point;
		LineEnd = point;
		isDrawing = TRUE;
		mPen.DeleteObject();
		UpdateData(TRUE);
		mPen.CreatePen(mPenStyle, mPenWidth, PenColor);
		SetCapture();
		mTextEdit.ReplaceSel(L"Mouse DOWN\r\n");
	}
}


void CLesson_8Dlg::OnClickedPencolorpic()
{
	// TODO: Add your control notification handler code here

	CColorDialog dlg(PenColor);

	if (dlg.DoModal() == IDOK)
	{
		CBrush swatch;
		CClientDC dc(this);

		PenColor = dlg.GetColor();
		swatch.CreateSolidBrush(PenColor);
		dc.FillRect(&PenColorSwatch, &swatch);
	}
}

void CLesson_8Dlg::DrawShape(bool stretch)
{

	CClientDC dc(this);

	dc.SetAttribDC(dc);
	dc.SelectObject(&mBrush);
	mpMF->SetAttribDC(dc);
	dc.IntersectClipRect(Canvas);
	mpMF->IntersectClipRect(Canvas);

	int drawmode = mComboShapes.GetCurSel();

	dc.SelectObject(&mPen);
	dc.SelectObject(&mBrush);
	mpMF->SelectObject(&mPen);
	mpMF->SelectObject(&mBrush);

	if (stretch && drawmode != 0)
		dc.SetROP2(R2_NOT);

	switch (drawmode)
	{
	case 0:
		dc.MoveTo(LineStart);
		dc.LineTo(LineEnd);
		mpMF->MoveTo(LineStart);
		mpMF->LineTo(LineEnd);
		LineStart = LineEnd;
		mTextEdit.ReplaceSel(L"Draw Free\r\n");
		break;

	case 1:
		dc.MoveTo(LineStart);
		dc.LineTo(LineEnd);

		if (!stretch)
		{
			mpMF->MoveTo(LineStart);
			mpMF->LineTo(LineEnd);
		}

		mTextEdit.ReplaceSel(L"Draw Line\r\n");
		break;

	case 2:
		dc.Ellipse(CRect(LineStart, LineEnd));

		if (!stretch)
		{
			mpMF->Ellipse(CRect(LineStart, LineEnd));
		}

		mTextEdit.ReplaceSel(L"Draw Ellipse\r\n");
		break;

	case 3:
		dc.Rectangle(CRect(LineStart, LineEnd));

		if (!stretch)
			mpMF->Rectangle(CRect(LineStart, LineEnd));

		mTextEdit.ReplaceSel(L"Draw Rectangle\r\n");
		break;
	}
}

void CLesson_8Dlg::OnSelchangeListBrushstyle()
{
	int style = mBrushStyleList.GetCurSel();

	mBrush.DeleteObject();

	switch (style)
	{
	case 0:
		mBrush.CreateStockObject(NULL_BRUSH);
		break;

	case 1:
		mBrush.CreateSolidBrush(mBrushColor);
		break;

	case 2:
		mBrush.CreateHatchBrush(HS_BDIAGONAL, mBrushColor);
		break;

	case 3:
		mBrush.CreateHatchBrush(HS_FDIAGONAL, mBrushColor);
		break;

	case 4:
		mBrush.CreateHatchBrush(HS_CROSS, mBrushColor);
		break;

	case 5:
		mBrush.CreateHatchBrush(HS_DIAGCROSS, mBrushColor);
		break;

	case 6:
		mBrush.CreateHatchBrush(HS_HORIZONTAL, mBrushColor);
		break;

	case 7:
		mBrush.CreateHatchBrush(HS_VERTICAL, mBrushColor);
		break;

	case 9:
		mBrush.CreateStockObject(LTGRAY_BRUSH);
		break;

	case 10:
		mBrush.CreateStockObject(GRAY_BRUSH);
		break;

	case 11:
		mBrush.CreateStockObject(DKGRAY_BRUSH);
		break;

	case 12:
		mBrush.CreateStockObject(BLACK_BRUSH);
		break;

	default:
		mBrush.CreateStockObject(WHITE_BRUSH);
		break;
	}

	PaintBrushPreview();
}


void CLesson_8Dlg::PaintBrushPreview()
{
	CClientDC dc(this);
	dc.FillRect(&mBrushPreviewSwatch, &mBrush);
}


void CLesson_8Dlg::OnClickedPicBrushcolor()
{
	CColorDialog dlg(mBrushColor);

	if (dlg.DoModal() == IDOK)
	{
		mBrushColor = dlg.GetColor();

		CClientDC dc(this);
		CBrush b(mBrushColor);

		dc.FillRect(&mBrushColorSwatch, &b);
	}

	OnSelchangeListBrushstyle();
}


void CLesson_8Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	mpMF->Close();
	delete mpMF;
}
