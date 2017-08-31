#if !defined(AFX_TEXTWND_H__9479FD51_7176_45F1_A3D4_0C4C39C3935C__INCLUDED_)
#define AFX_TEXTWND_H__9479FD51_7176_45F1_A3D4_0C4C39C3935C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextWnd window

class CTextWnd : public CWnd
{
// Construction
public:
	struct SItem
	{
		CString szText;
		int nWidth;
	};
	CArray<SItem,SItem>m_arr;	//标签项的数据集合
	CFont m_font;				//文字字体
	static const COLORREF m_clszText;	//文字颜色
	static const CPen m_pen;			//边框画笔
	int m_startPos,m_endPos;	//文字显示的起点位置

	CRgn m_rgnWnd;				//窗口区域
	CRect m_rcWnd;				//窗口变成圆角矩形前的矩形
	static const COLORREF m_clBack;	//窗口背景颜色
public:
	CTextWnd();

// Attributes
public:
	BOOL CreateEx(DWORD dwExStyle,DWORD dwStyle,const RECT& rect,CWnd* pParentWnd,UINT nID);
	void Register();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTextWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTWND_H__9479FD51_7176_45F1_A3D4_0C4C39C3935C__INCLUDED_)
