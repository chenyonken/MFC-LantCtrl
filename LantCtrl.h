// LantCtrl.h : main header file for the LANTCTRL application
//

#if !defined(AFX_LANTCTRL_H__5C3CED4F_9731_4C68_B99F_C08038279289__INCLUDED_)
#define AFX_LANTCTRL_H__5C3CED4F_9731_4C68_B99F_C08038279289__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLantCtrlApp:
// See LantCtrl.cpp for the implementation of this class
//

class CLantCtrlApp : public CWinApp
{
public:
	CLantCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLantCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLantCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANTCTRL_H__5C3CED4F_9731_4C68_B99F_C08038279289__INCLUDED_)
