
// KonwerterDlg.h : header file
//

#pragma once

#include "pch.h"

// CKonwerterDlg dialog
class CKonwerterDlg : public CDialogEx
{
// Construction
public:
	CKonwerterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KONWERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	int m_nSelectedSystemCombo2;
	int m_nSelectedSystemCombo3;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString DecimalToBinary(int decimalValue);
};


