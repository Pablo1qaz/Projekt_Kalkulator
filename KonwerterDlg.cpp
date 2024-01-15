
// KonwerterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Konwerter.h"
#include "KonwerterDlg.h"
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
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKonwerterDlg dialog



CKonwerterDlg::CKonwerterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KONWERTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKonwerterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO2, m_nSelectedSystemCombo2);
	DDX_CBIndex(pDX, IDC_COMBO3, m_nSelectedSystemCombo3);
}

BEGIN_MESSAGE_MAP(CKonwerterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CKonwerterDlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CKonwerterDlg::OnCbnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT1, &CKonwerterDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CKonwerterDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CKonwerterDlg message handlers

BOOL CKonwerterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pComboBox->AddString(_T("Binary"));
	pComboBox->AddString(_T("Octal"));
	pComboBox->AddString(_T("Decimal"));
	pComboBox->AddString(_T("Hexadecimal"));

	m_nSelectedSystemCombo2 = 2; 
	pComboBox->SetCurSel(m_nSelectedSystemCombo2);

	CComboBox* pComboBox3 = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pComboBox3->AddString(_T("Binary"));
	pComboBox3->AddString(_T("Octal"));
	pComboBox3->AddString(_T("Decimal"));
	pComboBox3->AddString(_T("Hexadecimal"));

	m_nSelectedSystemCombo3 = 2; 
	pComboBox3->SetCurSel(m_nSelectedSystemCombo3);

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CKonwerterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKonwerterDlg::OnPaint()
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
HCURSOR CKonwerterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKonwerterDlg::OnCbnSelchangeCombo2()
{
	CComboBox* pComboBox2 = (CComboBox*)GetDlgItem(IDC_COMBO2);
	m_nSelectedSystemCombo2 = pComboBox2->GetCurSel();
}


void CKonwerterDlg::OnCbnSelchangeCombo3()
{
	CComboBox* pComboBox3 = (CComboBox*)GetDlgItem(IDC_COMBO3);
	m_nSelectedSystemCombo3 = pComboBox3->GetCurSel();
}


void CKonwerterDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CKonwerterDlg::OnBnClickedButton1()
{

	int inputValue;

	CString strInput;
	GetDlgItemText(IDC_EDIT1, strInput);

	if (strInput.IsEmpty())
	{
		MessageBox(_T("WprowadŸ liczbê do konwersji."), _T("B³¹d"), MB_OK | MB_ICONERROR);
		return;
	}



	switch (m_nSelectedSystemCombo2)
	{
	case 0:
		// Binary to Decimal
		inputValue = _tcstol(strInput, nullptr, 2);
		break;
	case 1:
		// Decimal
		inputValue = _ttoi(strInput);
		break;
	case 2:
		// Hex
		inputValue = _tcstol(strInput, nullptr, 16);
		break;
	case 3:
		// Octal
		inputValue = _tcstol(strInput, nullptr, 8);
		break;
	default:
		return;

	}

	if (m_nSelectedSystemCombo2 == 0) // Binary
	{
		// SprawdŸ, czy ci¹g zawiera tylko zera i jedynki
		if (strInput.SpanIncluding(_T("01")) != strInput)
		{
			MessageBox(_T("WprowadŸ poprawn¹ liczbê binarn¹."), _T("B³¹d"), MB_OK | MB_ICONERROR);
			return;
		}
	}

	else if (m_nSelectedSystemCombo2 == 1) // Decimal
	{
		// SprawdŸ, czy ci¹g zawiera tylko cyfry od 0 do 9
		if (strInput.SpanIncluding(_T("0123456789")) != strInput)
		{
			MessageBox(_T("WprowadŸ poprawn¹ liczbê dziesiêtn¹."), _T("B³¹d"), MB_OK | MB_ICONERROR);
			return;
		}
	}

	else if (m_nSelectedSystemCombo2 == 2) // Hexadecimal
	{
		// SprawdŸ, czy ci¹g zawiera tylko cyfry od 0 do 9 oraz litery od A do F (lub a do f)
		if (strInput.SpanIncluding(_T("0123456789ABCDEFabcdef")) != strInput)
		{
			MessageBox(_T("WprowadŸ poprawn¹ liczbê heksadecymaln¹."), _T("B³¹d"), MB_OK | MB_ICONERROR);
			return;
		}
	}

	else if (m_nSelectedSystemCombo2 == 3) // Octal
	{
		// SprawdŸ, czy ci¹g zawiera tylko cyfry od 0 do 7
		if (strInput.SpanIncluding(_T("01234567")) != strInput)
		{
			MessageBox(_T("WprowadŸ poprawn¹ liczbê ósemkow¹."), _T("B³¹d"), MB_OK | MB_ICONERROR);
			return;
		}
	}

	CString strResult;
	switch (m_nSelectedSystemCombo3)
	{
	case 0:
		// Convert to Binary
		strResult.Format(_T("%s"), DecimalToBinary(inputValue));
		break;
	case 1:
		// Convert to Decimal
		strResult.Format(_T("%d"), inputValue);
		break;
	case 2:
		// Convert to Hex
		strResult.Format(_T("%X"), inputValue);
		break;
	case 3:
		// Convert to Octal
		strResult.Format(_T("%o"), inputValue);
		break;
	}


	SetDlgItemText(IDC_EDIT4, strResult);
}





CString CKonwerterDlg::DecimalToBinary(int decimalValue)
{
    CString binaryString;
    while (decimalValue > 0)
    {
        // Dodaj cyfrê binarn¹ z reszty
        binaryString.Insert(0, (decimalValue % 2) + '0');
        // Podziel przez 2
        decimalValue /= 2;
    }

    if (binaryString.IsEmpty())
    {
        // Je¿eli liczba wynosi 0
        binaryString = '0';
    }

    return binaryString;
}