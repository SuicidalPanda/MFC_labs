// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lesson_7.h"
#include "SetDlg.h"
#include "afxdialogex.h"


// SetDlg dialog

IMPLEMENT_DYNAMIC(SetDlg, CDialogEx)

SetDlg::SetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SetDlg::IDD, pParent)
	, setRadio(0)
{

}

SetDlg::~SetDlg()
{
}

void SetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, Red_Radio, setRadio);
}


BEGIN_MESSAGE_MAP(SetDlg, CDialogEx)
	ON_BN_CLICKED(Red_Radio, &SetDlg::OnClickedRedRadio)
	ON_BN_CLICKED(Green_Radio, &SetDlg::OnBnClickedRadio)
	ON_BN_CLICKED(Blue_Radio, &SetDlg::BlueBnClicked)
	ON_BN_CLICKED(OK_Btn, &SetDlg::OnBnClickedBtn)
	ON_BN_CLICKED(Cancel_Btn, &SetDlg::OnClickedCancelBtn)
END_MESSAGE_MAP()


// SetDlg message handlers



void SetDlg::OnClickedRedRadio()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
}


void SetDlg::OnBnClickedRadio()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
}


void SetDlg::BlueBnClicked()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
}


void SetDlg::OnBnClickedBtn()
{
	// TODO: Add your control notification handler code here

	OnOK();

}


void SetDlg::OnClickedCancelBtn()
{
	// TODO: Add your control notification handler code here

	OnOK();

}
