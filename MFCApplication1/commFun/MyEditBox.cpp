// MyEditBox.cpp : implementation file
//

#include "stdafx.h"
#include "MyEditBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyEditBox

MyEditBox::MyEditBox()
{
	m_ForeColor = RGB(0,0,0);          //black
    m_BackColor = RGB(255,255,255);    //white
    m_BkBrush.CreateSolidBrush(m_BackColor);   
    p_Font = NULL;   
}

MyEditBox::~MyEditBox()
{
	if( p_Font )
        delete p_Font;
}


BEGIN_MESSAGE_MAP(MyEditBox, CEdit)
	//{{AFX_MSG_MAP(MyEditBox)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyEditBox message handlers

void MyEditBox::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetLimitText( -1 );    //set limit is max -1
	
	m_FontSize = 100;
    m_FontName = _T("FangSong_GB2312");
    p_Font = new CFont;    //
    p_Font->CreatePointFont( m_FontSize, m_FontName );  //create font
    SetFont( p_Font );     //set default font for handles
	
	CEdit::PreSubclassWindow();
}

HBRUSH MyEditBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	pDC->SetTextColor( m_ForeColor );    //
    pDC->SetBkColor( m_BackColor );      //
    return (HBRUSH)m_BkBrush.GetSafeHandle();  //
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}


//
void MyEditBox::SetForeColor(COLORREF color)
{
    m_ForeColor = color;
    Invalidate();
}

//
COLORREF MyEditBox::GetForeColor()
{
    return m_ForeColor;
}

//
void MyEditBox::SetBkColor(COLORREF color)
{
    m_BackColor = color;
    m_BkBrush.Detach();
    m_BkBrush.CreateSolidBrush( m_BackColor );
    Invalidate();
}

//
COLORREF MyEditBox::GetBkColor()
{
    return m_BackColor;
}

//
void MyEditBox::SetTextFont(int FontSize,LPCTSTR FontName)
{
    if ( p_Font )    delete p_Font;
	p_Font = new CFont;
    p_Font->CreatePointFont( FontSize, FontName );
    SetFont( p_Font );
    m_FontSize = FontSize;
    m_FontName = FontName;
}

//
int MyEditBox::GetFontSize()
{
    return m_FontSize;
}

//
CString MyEditBox::GetFontName()
{
    return m_FontName;
}
