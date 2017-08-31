// LantCtrlDlg.h : header file
//

#if !defined(AFX_LANTCTRLDLG_H__7D156B77_D918_4A2C_A4C9_541FA26BA64E__INCLUDED_)
#define AFX_LANTCTRLDLG_H__7D156B77_D918_4A2C_A4C9_541FA26BA64E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLantCtrlDlg dialog
#include "BackWnd.h"
class CLantCtrlDlg : public CDialog
{
// Construction
public:
	enum{IDC_BACKWND=1234};
	CBackWnd m_BackWnd;
public:
public:
	CLantCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLantCtrlDlg)
	enum { IDD = IDD_LANTCTRL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLantCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLantCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANTCTRLDLG_H__7D156B77_D918_4A2C_A4C9_541FA26BA64E__INCLUDED_)
