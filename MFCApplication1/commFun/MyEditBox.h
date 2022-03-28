#if !defined(AFX_MYEDITBOX_H__7E0B13ED_72E2_4164_A3FE_E6807EFCE800__INCLUDED_)
#define AFX_MYEDITBOX_H__7E0B13ED_72E2_4164_A3FE_E6807EFCE800__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEditBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyEditBox window

class MyEditBox : public CEdit
{
// Construction
public:
	MyEditBox();
	virtual ~MyEditBox();

// Attributes
public:
	void SetForeColor(COLORREF color);
	COLORREF GetForeColor();
	void SetBkColor(COLORREF color);
	COLORREF GetBkColor();
	void SetTextFont(int FontSize,LPCTSTR FontName);
	int GetFontSize();
    CString GetFontName();

private:
	virtual void PreSubclassWindow();

	COLORREF    m_ForeColor;       //text color
	COLORREF    m_BackColor;       //back color
	CBrush      m_BkBrush;         //back brush
	CFont*      p_Font;            //point to font
	int         m_FontSize;        //sizo of font
    CString     m_FontName;        //name of font
	//{{AFX_MSG(MyEditBox)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDITBOX_H__7E0B13ED_72E2_4164_A3FE_E6807EFCE800__INCLUDED_)
