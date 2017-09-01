// TextWnd.cpp : implementation file
//

#include "stdafx.h"
#include "LantCtrl.h"
#include "TextWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextWnd
#include "InfoDlg.h"
#define TEXTWND _T("__TEXTWND__")

#define ROUNDRECTDEGREE		20
#define TEXTDISTANCE		40				//ÿ���ַ���֮��ļ��

const COLORREF CTextWnd::m_clBack=RGB(180,180,180),
CTextWnd::m_clszText=RGB(0,0,0);
const CPen CTextWnd::m_pen(0,3,RGB(123,158,189));

CTextWnd::CTextWnd()
{
	m_startPos=0;
	m_endPos=0;
}

CTextWnd::~CTextWnd()
{
	if(m_font.GetSafeHandle())
		m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CTextWnd, CWnd)
	//{{AFX_MSG_MAP(CTextWnd)
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_SHOW_ADD, OnShowAdd)
	ON_COMMAND(ID_SHOW_DEL, OnShowDel)
	ON_COMMAND(ID_SHOW_MOD, OnShowMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTextWnd message handlers

/**********************************************
* void CTextWnd::Register()
* ���ܣ�ע�����ִ���
**********************************************/
void CTextWnd::Register()
{
	WNDCLASS wc={0};
	wc.hInstance=::AfxGetInstanceHandle();
	wc.lpfnWndProc=::DefWindowProc;
	wc.lpszClassName=TEXTWND;
	wc.hbrBackground=::GetSysColorBrush(COLOR_3DLIGHT);
	wc.hIcon=NULL;
	wc.hCursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.lpszMenuName=NULL;
	wc.style=CS_HREDRAW|CS_VREDRAW;
	AfxRegisterClass(&wc);
}



/**********************************************
* BOOL CTextWnd::CreateEx(DWORD dwExStyle,DWORD dwStyle,const RECT& rect,CWnd* pParentWnd,UINT nID)
* ���ܣ��������ִ���
* �����������MSDN
**********************************************/
BOOL CTextWnd::CreateEx(DWORD dwExStyle,DWORD dwStyle,const RECT& rect,CWnd* pParentWnd,UINT nID)
{
	static BOOL b=TRUE;
	if(b)
	{
		b=FALSE;
		Register();
	}

	if(CWnd::CreateEx(dwExStyle,TEXTWND,NULL,dwStyle,rect,pParentWnd,nID))
	{
		
		//���洰�ھ���
		GetClientRect(m_rcWnd);

		//���ô�����Բ�Ǿ���
		m_rgnWnd.CreateRoundRectRgn(m_rcWnd.left,m_rcWnd.top,m_rcWnd.right,
			m_rcWnd.bottom,ROUNDRECTDEGREE,ROUNDRECTDEGREE);
		SetWindowRgn((HRGN)m_rgnWnd.GetSafeHandle(),TRUE);

		//���ô�������
		CFont* pFont=pParentWnd->GetFont();
		if(!pFont)
		{
			HFONT hFont=(HFONT)::GetStockObject(DEFAULT_GUI_FONT);
			pFont=CFont::FromHandle(hFont);
		}
		LOGFONT lf;
		pFont->GetLogFont(&lf);
		m_font.CreateFontIndirect(&lf);

		//��ʼ���ַ����Ŀ�ʼλ��
		m_startPos=m_rcWnd.right;
		return TRUE;
		
	}
	else
		return FALSE;
}



/*********************************************************************
* int CTextWnd::GetTextWidth(CString szText)
* ���ܣ���ȡ�ַ����Ŀ��
* ������szText,��Ҫ��ȡ��ȵ��ַ���
********************************************************************/
int CTextWnd::GetTextWidth(CString szText)
{
	CClientDC dc(this);
	CFont* pFont=(CFont*)dc.SelectObject(&m_font);
	CSize size=dc.GetTextExtent(szText);
	dc.SelectObject(pFont);
//	m_font.DeleteObject();
	return size.cx;
}

/*********************************************************************
* int CTextWnd::GetItemCount() const
* ���ܣ���ȡ��ǰ��ʾ�����е��ַ����ĸ���
* ����ֵ���ַ����ĸ���
********************************************************************/
int CTextWnd::GetItemCount() const
{
	return m_arr.GetSize();
}

CString CTextWnd::GetItemText(int nItem)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	return m_arr[nItem].szText;
}

void CTextWnd::SetItemText(int nItem, LPCTSTR szText)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	m_arr[nItem].szText=szText;
}

BOOL CTextWnd::InsertItem(int nItem, LPCTSTR szItem)
{
	SItem item;
	int nWidth=GetTextWidth(szItem)+TEXTDISTANCE;
	item.szText=szItem;
	item.nWidth=nWidth;
	m_arr.InsertAt(nItem,item);
	return TRUE;
}


BOOL CTextWnd::DeleteItem(int nItem)
{
	ASSERT(nItem<m_arr.GetSize()&&nItem>=0);
	m_arr.RemoveAt(nItem);
	return TRUE;
}
BOOL CTextWnd::DeleteAllItem()
{
	if(m_arr.GetSize())
		m_arr.RemoveAll();
	return TRUE;
}




/********************************************************************
* void CTextWnd::OnLButtonDown(UINT nFlags, CPoint point) 
* ���ܣ��������ֵ���ͣ������
* �����������MSDN
*********************************************************************/
void CTextWnd::OnLButtonDown(UINT nFlags, CPoint point) 
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



/**************************************************
* void CTextWnd::OnPaint() 
* ���ܣ������ִ������ƶ���������
*************************************************/
void CTextWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	//�������ݻ���	
	CDC mdc;
	mdc.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,m_rcWnd.Width(),m_rcWnd.Height());
	CBitmap* pOldBmp=(CBitmap*)mdc.SelectObject(&bmp);
	mdc.FillSolidRect(m_rcWnd,m_clBack);

	CFont* pOldFont=(CFont*)mdc.SelectObject(m_font);
	mdc.SetBkMode(TRANSPARENT);
	CPen* pOldPen=(CPen*)mdc.SelectObject(m_pen);
	mdc.SetTextColor(m_clszText);

	CString szText;
	CRect rect,rc;
	GetClientRect(rc);
	rect=rc;
	rect.right=m_startPos;
	int i=-1,nCount=GetItemCount();
	while(++i<nCount)
	{
		rect.left=rect.right;
		rect.right+=m_arr[i].nWidth;
		szText=GetItemText(i);

		mdc.DrawText(szText,szText.GetLength(),rect,
			DT_SINGLELINE|DT_VCENTER|DT_CENTER);
		
	}
	m_endPos=rect.right;
	dc.BitBlt(rc.left,rc.top,rc.Width(),rc.Height(),&mdc,0,0,SRCCOPY);	

	mdc.SelectObject(pOldBmp);
//	mdc.SelectObject(pOldPen);
//	mdc.SelectObject(pOldFont);//�������䣬����ᵱ��
	bmp.DeleteObject();
	mdc.DeleteDC();

}



void CTextWnd::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);	
	int movedis=tm.tmAveCharWidth;
	if(m_endPos>=m_rcWnd.left)
		m_startPos-=movedis;
	else
		m_startPos=m_rcWnd.right;
	Invalidate(FALSE);
	CWnd::OnTimer(nIDEvent);		

}


/************************************************************
* void CTextWnd::OnRButtonUp(UINT nFlags, CPoint point) 
* ���ܣ��Ҽ������˵�
*************************************************************/
void CTextWnd::OnRButtonUp(UINT nFlags, CPoint point) 
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





/*************************************************************************
*���º����ǻ�ȡ˽�г�Ա������˽�г�Ա�ĺ�����ͬʱ���뱳�����ڽ������ݵĺ���
*********************************************************************/
void CTextWnd::GetTextPos(int *startPos, int *endPos)
{
	*startPos=m_startPos;
	*endPos=m_endPos;
}

void CTextWnd::GetTextStartPos(int *startPos)
{
	*startPos=m_startPos;
}

void CTextWnd::GetTextEndPos(int *endPos)
{
	*endPos=m_endPos;
}

void CTextWnd::GetWndRect(CRect *rect)
{
	*rect=m_rcWnd;
}

void CTextWnd::SetTextStartPos(int startPos)
{
	m_startPos=startPos;
}

/***************************End*********************************************/




/***********************************************************************
*�����ǲ˵�����Ӧ����
***********************************************************************/
void CTextWnd::OnShowAdd() 
{
	// TODO: Add your command handler code here
	CInfoDlg dlg;
	
	//��ȡ�Ѵ����ַ����䵽�����Ի���ı༭����
	int nCount=GetItemCount();
	CString str;
	for(int i=0;i<nCount;i++)
	{
		str=GetItemText(i)+_T(";");
	}
	dlg.m_szText=str;
	dlg.DoModal();
	
}

void CTextWnd::OnShowDel() 
{
	OnShowAdd(); 	
}

void CTextWnd::OnShowMod() 
{
	OnShowAdd(); 
}
