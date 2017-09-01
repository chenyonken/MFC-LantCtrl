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
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW_ADD, OnShowAdd)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_SHOW_DEL, OnShowDel)
	ON_COMMAND(ID_SHOW_MOD, OnShowMod)
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
		CRect rc(rect);
		rc.DeflateRect(CXDEFLATE,CYDEFLATE);
		//必须有WS_CHILDWINDOW风格或者WS_CHILD，才能调用CWnd::CreateEx()函数，否则只能调用CreateEX创建主窗口
		if(m_TextWnd.CreateEx(0,WS_VISIBLE|WS_CHILD ,rc,GetParent(),IDC_TEXTWND))//文本窗口和背景窗口的父窗口都是主对话框

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

void CBackWnd::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pPopup=menu.GetSubMenu(0);
	ClientToScreen(&point);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,this);
	CWnd::OnRButtonUp(nFlags, point);	
}


void CBackWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	static b=TRUE;
	if(b)
	{
		b=FALSE;
		SetTimer(1,100,NULL);
	}
	else
	{
		b=TRUE;
		KillTimer(1);
	}
		
	CWnd::OnLButtonDown(nFlags, point);
}

void CBackWnd::OnTimer(UINT nIDEvent) 
{
	CDC* pDC=m_TextWnd.GetDC();
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int movedis=tm.tmAveCharWidth;
	int startPos,endPos;
	CRect rect;
	GetTextPos(&startPos,&endPos);
	GetWndRect(&rect);
	if(endPos>=rect.left)
		startPos-=movedis;
	else
		startPos=rect.right;
	SetTextStartPos(startPos);

	m_TextWnd.Invalidate(FALSE);
	CWnd::OnTimer(nIDEvent);
}

/*************************end*************************************/


/******************************************************
*以下三个函数是菜单的响应函数
*******************************************************/
void CBackWnd::OnShowAdd() 
{
	// TODO: Add your command handler code here
	CInfoDlg dlg;
	
	//获取已存在字符传输到弹出对话框的编辑框里
	int nCount=GetItemCount();
	CString str;
	for(int i=0;i<nCount;i++)
	{
		str=GetItemText(i)+_T(";");
	}
	dlg.m_szText=str;
	dlg.DoModal();
}

void CBackWnd::OnShowMod() 
{
	OnShowAdd();	
}
void CBackWnd::OnShowDel() 
{
	OnShowAdd();
}

/***********************end********************************/










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



void CBackWnd::GetTextPos(int *startPos, int *endPos)
{
	m_TextWnd.GetTextPos(startPos,endPos);
}

void CBackWnd::GetTextStartPos(int *startPos)
{
	m_TextWnd.GetTextStartPos(startPos);
}

void CBackWnd::GetTextEndPos(int *endPos)
{
	m_TextWnd.GetTextEndPos(endPos);

}

void CBackWnd::GetWndRect(CRect *rect)
{
	m_TextWnd.GetWndRect(rect);
}


void CBackWnd::SetTextStartPos(int startPos)
{
	m_TextWnd.SetTextStartPos(startPos);
}

/************************end**********************************/

