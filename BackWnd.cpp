// BackWnd.cpp : implementation file
//

#include "stdafx.h"
#include "LantCtrl.h"
#include "BackWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackWnd
#include "InfoDlg.h"
#define BACKWND _T("__BACKWND__")
#define CXDEFLATE	20				//圆角矩形的x坐标缩进
#define CYDEFLATE	10				//圆角矩形的y坐标缩进



CBackWnd::CBackWnd()
{
}

CBackWnd::~CBackWnd()
{
}


BEGIN_MESSAGE_MAP(CBackWnd, CWnd)
	//{{AFX_MSG_MAP(CBackWnd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBackWnd message handlers


/******************************************************
*以下函数是窗口注册和创建函数
******************************************************/
void CBackWnd::Register()
{
	WNDCLASS wc={0};
	wc.hInstance=::AfxGetInstanceHandle();
	wc.lpfnWndProc=::DefWindowProc;
	wc.lpszClassName=BACKWND;
	wc.hbrBackground=::GetSysColorBrush(COLOR_BTNSHADOW);
	wc.hIcon=NULL;
	wc.hCursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.lpszMenuName=NULL;
	wc.style=CS_HREDRAW|CS_VREDRAW;
	AfxRegisterClass(&wc);
	
}

BOOL CBackWnd::Create( DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID)
{
	static BOOL b1=TRUE;
	if(b1)
	{
		b1=FALSE;
		Register();
	}
	if(CWnd::Create(BACKWND,NULL,dwStyle,rect,pParentWnd,nID))
	{
		CRect rc;
		GetClientRect(rc);
		rc.DeflateRect(CXDEFLATE,CYDEFLATE);
		//必须有WS_CHILDWINDOW风格或者WS_CHILD，才能调用CWnd::CreateEx()函数，否则只能调用CreateEX创建主窗口
//		if(m_TextWnd.CreateEx(0,WS_VISIBLE|WS_CHILD ,rc,GetParent(),IDC_TEXTWND))//文本窗口和背景窗口的父窗口都是主对话框
		if(m_TextWnd.CreateEx(0,WS_VISIBLE|WS_CHILD ,rc,this,IDC_TEXTWND))//文本窗口和背景窗口的父窗口都是主对话框

			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
}

/*************************End************************************************/



/*****************************************************************
* 以下四个函数是消息响应函数
*******************************************************************/

void CBackWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CDC mdc;
	CRect rect;
	mdc.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BACK);
	BITMAP LOGBMP;
	bmp.GetBitmap(&LOGBMP);
	int cx=LOGBMP.bmWidth;
	int cy=LOGBMP.bmHeight;
	mdc.SelectObject(&bmp);
	GetClientRect(&rect);
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&mdc,0,0,SRCCOPY);	
}





/****************************************************
*以下函数用于背景窗口和文字窗口的数据互传
*****************************************************/


BOOL CBackWnd::InsertItem(int nItem, LPCTSTR szItem)
{
	return m_TextWnd.InsertItem(nItem,szItem);
}

BOOL CBackWnd::DeleteAllItem()
{
	return m_TextWnd.DeleteAllItem();
}

int CBackWnd::GetItemCount()
{
	return m_TextWnd.GetItemCount();
}

CString CBackWnd::GetItemText(int nItem)
{
	return m_TextWnd.GetItemText(nItem);
}


