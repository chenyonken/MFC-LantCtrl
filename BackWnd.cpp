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
#define CXDEFLATE	20				//Բ�Ǿ��ε�x��������
#define CYDEFLATE	10				//Բ�Ǿ��ε�y��������
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBackWnd message handlers






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
		//������WS_CHILDWINDOW������WS_CHILD�����ܵ���CWnd::CreateEx()����������ֻ�ܵ���CreateEX����������
		if(m_TextWnd.CreateEx(0,WS_VISIBLE|WS_CHILD ,rc,GetParent(),IDC_TEXTWND))//�ı����ںͱ������ڵĸ����ڶ������Ի���
//		if(m_TextWnd.CreateEx(0,WS_VISIBLE|WS_CHILD ,rc,this,IDC_TEXTWND))
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
}


BOOL CBackWnd::InsertItem(int nItem, LPCTSTR szItem)
{
	m_TextWnd.InsertItem(nItem,szItem);
	return TRUE;
}




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

void CBackWnd::OnShowAdd() 
{
	// TODO: Add your command handler code here
	CInfoDlg dlg;

	//��ȡ�Ѵ����ַ����䵽�����Ի���ı༭����
	int nCount=m_TextWnd.GetItemCount();
	CString str;
	for(int i=0;i<nCount;i++)
	{
		str=m_TextWnd.m_arr[i].szText+_T(";");
	}
	dlg.m_szText=str;
	dlg.DoModal();

	//��������ı������²�����ʾ���ı�
//	m_TextWnd.DeleteAllItem();
	this->DeleteAllItem();
	nCount=this->m_arr.GetSize();
	for(int j=0;j<nCount;j++)
	{
		this->InsertItem(j,m_arr[j]);
	}
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
	// TODO: Add your message handler code here and/or call default

	CDC* pDC=m_TextWnd.GetDC();
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int movedis=tm.tmAveCharWidth;
	if(m_TextWnd.m_endPos>=m_TextWnd.m_rcWnd.left)
	{
		m_TextWnd.m_startPos-=movedis;
	}
	else
	{
		m_TextWnd.m_startPos=m_TextWnd.m_rcWnd.right;
	}
	m_TextWnd.Invalidate(FALSE);
	
	CWnd::OnTimer(nIDEvent);
}

BOOL CBackWnd::DeleteAllItem()
{
	return m_TextWnd.DeleteAllItem();

}

int CBackWnd::GetItemCount()
{
	return m_TextWnd.GetItemCount();
}
