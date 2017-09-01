// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lantctrl.h"
#include "InfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog
#include "BackWnd.h"
#include "LantCtrlDlg.h"

#define NMAX	1024			//显示字符串的最大字节数

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{
	m_szText=_T("");
	//{{AFX_DATA_INIT(CInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

BOOL CInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_EDIT);
	CLantCtrlDlg* pParent=(CLantCtrlDlg*)GetParent();
	int nCount=pParent->m_BackWnd.GetItemCount();
	CString szText=_T("");
	for(int i=0;i<nCount;i++)
	{
		szText=szText+pParent->m_BackWnd.GetItemText(i)+_T(";");
	}

	pEdit->SetWindowText(szText);
	return TRUE;  
}

void CInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_EDIT);

	LPTSTR szText=new char[NMAX];
	pEdit->GetWindowText(szText,NMAX-1);
	//获取到的是主对话框窗口指针，虽然这个对话框是在背景窗口里被弹出的
	CLantCtrlDlg* pParent=(CLantCtrlDlg*)GetParent();
	pParent->m_BackWnd.DeleteAllItem();//情况原存放显示文字的字符串数组
	LPCTSTR sep=_T(";");
	LPTSTR p;
	p=strtok(szText,sep);
	int nItem=0;
	while(p)
	{
		pParent->m_BackWnd.InsertItem(nItem++,p);
		p=strtok(NULL,sep);

	}

	if(szText)
	{
		delete[] szText;
	}
	CDialog::OnOK();
}
