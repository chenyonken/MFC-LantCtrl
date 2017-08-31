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
#define TEXTWND _T("__TEXTWND__")

#define ROUNDRECTDEGREE		20
#define TEXTDISTANCE		40				//每项字符串之间的间隔

const COLORREF CTextWnd::m_clBack=RGB(180,180,180),
CTextWnd::m_clszText=RGB(0,0,0);
const CPen CTextWnd::m_pen(0,3,RGB(123,158,189));

CTextWnd::CTextWnd()
{
}

CTextWnd::~CTextWnd()
{
}


BEGIN_MESSAGE_MAP(CTextWnd, CWnd)
	//{{AFX_MSG_MAP(CTextWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTextWnd message handlers

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


BOOL CTextWnd::CreateEx(DWORD dwExStyle,DWORD dwStyle,const RECT& rect,CWnd* pParentWnd,UINT nID)
{
	static BOOL b=TRUE;
	if(b)
	{
		b=FALSE;
		Register();
	}

	//创建文字窗口
	if(CWnd::CreateEx(dwExStyle,TEXTWND,NULL,dwStyle,rect,pParentWnd,nID))
	{
		
		//保存窗口矩形
		GetClientRect(m_rcWnd);

		//设置窗口字体
		CFont* pFont=pParentWnd->GetFont();
		if(!pFont)
		{
			HFONT hFont=(HFONT)::GetStockObject(DEFAULT_GUI_FONT);
			pFont=CFont::FromHandle(hFont);
		}
		LOGFONT lf;
		pFont->GetLogFont(&lf);
		m_font.CreateFontIndirect(&lf);

		return TRUE;
		
	}
	else
		return FALSE;
}