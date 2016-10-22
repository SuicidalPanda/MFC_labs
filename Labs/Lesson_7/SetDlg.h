#pragma once


// SetDlg dialog

class SetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetDlg)

public:
	SetDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SetDlg();

// Dialog Data
	enum { IDD = SetColorDiag };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int setRadio;
//	virtual BOOL OnInitDialog();
	afx_msg void OnClickedRedRadio();
	afx_msg void OnBnClickedRadio();
	afx_msg void BlueBnClicked();
	afx_msg void OnBnClickedBtn();
	afx_msg void OnClickedCancelBtn();
};
