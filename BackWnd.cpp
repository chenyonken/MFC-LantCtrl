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
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
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
