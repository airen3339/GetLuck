
// MFCApplication1Dlg.h : 头文件
//

#pragma once

#include "commFun\MyEditBox.h"
#include "afxwin.h"
#include "Mydlg.h"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	Mydlg * m_pColorBasedSetting;
	int m_irand;
	std::vector<CString> m_users, m_luckusers;
	CString m_cstrShow;
	CBitmap m_bitmap;
	CBrush  m_brush;
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void MoveWnd();
	MyEditBox m_EditBoxShow;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void LoadData();
	CString GetCurDirectory();
	CString GetFolderPathFromFullPath(CString lpszFullPath);
	CString GetFileFullNameFromFullPath(CString lpszFullPath);
	void AddToLucy(CString user);
	BOOL isExitLuck(CString user);
	CString File_ReadAllLine(CString filepath);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	void LoadLuckUser();
	afx_msg void OnClose();
};
