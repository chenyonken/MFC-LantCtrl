#if !defined(AFX_BACKWND_H__331ADF16_2C80_476D_92AE_0550EEE2BDA7__INCLUDED_)
#define AFX_BACKWND_H__331ADF16_2C80_476D_92AE_0550EEE2BDA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackWnd window
#include "TextWnd.h"
class CBackWnd : public CWnd
{
// Construction
public:
	enum{IDC_TEXTWND=2000};
	CTextWnd m_TextWnd;
public:
	CBackWnd();

// Attributes
public:
	void Register();
	BOOL Create(DWORD dwStyle,const RECT& rect,CWnd* pParentWnd,UINT nID);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBackWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBackWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKWND_H__331ADF16_2C80_476D_92AE_0550EEE2BDA7__INCLUDED_)
