
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include <fstream>

#include<random>  
#include<time.h>  

using std::cout;
using std::endl;
using std::cin;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditBoxShow);
	DDX_Text(pDX, IDC_EDIT1, m_cstrShow);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码
	COLORREF color = RGB(0, 255, 0);
	m_EditBoxShow.SetForeColor(color);

	m_EditBoxShow.SetBkColor(RGB(0, 0, 0));
	m_EditBoxShow.SetTextFont(650, _T("FangSong_GB2312"));
	m_EditBoxShow.SetWindowTextA("\r\n2022新年快乐！");
	m_EditBoxShow.SetSel(-1,-1, 0);

	m_bitmap.LoadBitmap(IDB_BK);
	m_brush.CreatePatternBrush(&m_bitmap);
	//
	//MoveWnd();
	LoadLuckUser();//加载已中奖列表
	LoadData();//加载抽奖列表

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//if (NULL == m_pColorBasedSetting)
	//{
	//	m_pColorBasedSetting = new Mydlg;
	//	//define Color_Based_SettingDlg dialog
	//	m_pColorBasedSetting->Create(IDD_DIALOG1, this);
	//}
	//m_pColorBasedSetting->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	//m_pColorBasedSetting->ShowWindow(SW_SHOW);
	//m_pColorBasedSetting->SetActiveWindow();

	m_EditBoxShow.SetTextFont(600, _T("FangSong_GB2312"));
	m_EditBoxShow.SetForeColor(RGB(0, 255, 0));
	CString str;
	if (GetDlgItemText(IDC_BUTTON1, str), str == "抽奖" || str == "Lucky-Button")
	{
		SetDlgItemText(IDC_BUTTON1, "停止");
		srand((unsigned)time(NULL));
		SetTimer(1001, 10, NULL);
	}
	else
	{
		SetDlgItemText(IDC_BUTTON1, "抽奖");
		KillTimer(1001);
		CString luckyMan=m_users[m_irand];
		Sleep(10);
		//加入到中奖名单中
		AddToLucy(luckyMan);
		//Sleep(10);
		//将中奖者从列表中删除
		for (auto it = m_users.begin(); it != m_users.end(); ) {
			if (*it == luckyMan) {
				it = m_users.erase(it);
			}
			else {
				++it;
			}
		}
		//GetDlgItemText(IDC_EDIT1, luckyMan);
		//luckyMan.Delete(0, 1);

		int nameLength = luckyMan.GetLength();
		CString flgStr('-', (nameLength));
		flgStr = "";
		CString finalShow;
		//finalShow.Format("===Congratulation===\r\n-------------\r\n|" + luckyMan + "|\r\n-------------\r\nYou are the lottery",)
		finalShow = "=====恭喜=====\r\n" + flgStr + "\r\n" + luckyMan + "\r\n" + flgStr + "\r\n中奖啦!";
		m_EditBoxShow.SetTextFont(400, _T("FangSong_GB2312"));
		m_EditBoxShow.SetForeColor(RGB(255, 0, 0));
		//SetDlgItemText(IDC_EDIT1, luckyMan);
		m_EditBoxShow.SetWindowText(finalShow);
		//MessageBox(LPCTSTR(luckyMan));
	}
}


void CMFCApplication1Dlg::MoveWnd()
{
	int screenwidth = GetSystemMetrics(SM_CXFULLSCREEN);//获取屏幕分辨率宽度,不包括任务栏等区域
	int screenheight = GetSystemMetrics(SM_CYFULLSCREEN);//获取屏幕分辨率高度,不包括任务栏等区域
														 //
	int w = 1200;
	int h = 800;
	int x = (screenwidth - w) / 2;
	int y = (screenheight - h) / 2;
	//
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, x, y, w, h, SWP_NOZORDER);
	CenterWindow();
	//
	CRect rc;
	m_EditBoxShow.GetClientRect(&rc);
	m_EditBoxShow.MoveWindow(230, 220, rc.Width(), rc.Height(), TRUE);
}


HBRUSH CMFCApplication1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	/*switch (nCtlColor)
	{
	case CTLCOLOR_DLG:
		return m_brush;
	}
*/
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1001:      //ID为1001的定时器代码部分
	{
		//SetDlgItemText(IDC_Show, LuckyName[rand()%9].c_str());
		/*(rand()*LuckyName.size())/(RAND_MAX+1.0)*/
		int iSize = m_users.size();
		if (iSize<1)
		{
			break;
		}
		//Sleep(10);
		
		static std::default_random_engine e;
		static std::uniform_int_distribution<unsigned> u(0, iSize-1);
		m_irand = u(e);
		
		m_cstrShow = "\r\n";
		CString name = m_users[m_irand];
		m_cstrShow += name;
		//m_cstrShow += LuckyName[m_team][u(e)].c_str();
		//SetDlgItemText(IDC_EDIT1, m_cstrShow);
		m_EditBoxShow.SetWindowText(m_cstrShow);
		//update
		/*m_EditBoxShow.SetTextFont(600, _T("FangSong_GB2312"));
		m_EditBoxShow.SetForeColor(RGB(0, 255, 0));*/
		UpdateData(FALSE);
		break;
	}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplication1Dlg::LoadLuckUser()
{
	CString filepath;
	filepath = GetCurDirectory() + "\\luckdata.txt";
	CStdioFile file;
	//打开文件
	if (!file.Open(filepath, CFile::modeRead))
	{
		AfxMessageBox(_T("文件打开失败。"));
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		if (strText != _T("")) {
			//判断是否在中奖名单中
			//写入
			m_luckusers.push_back(strText);
		}
	}
	//关闭文件
	file.Close();
}

//取得参数
void CMFCApplication1Dlg::LoadData()
{
	CString filepath;
	filepath = GetCurDirectory() + "\\data.txt";
	CStdioFile file;
	//打开文件
	if (!file.Open(filepath, CFile::modeRead))
	{
		AfxMessageBox(_T("文件打开失败。"));
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		if (strText != _T("")) {
			//判断是否在中奖名单中
			if (!isExitLuck(strText)) {
				//写入
				m_users.push_back(strText);
			}
			
		}
	}
	//关闭文件
	file.Close();
}
/**
* 取得当前目录
*/
CString CMFCApplication1Dlg::GetCurDirectory()
{
	TCHAR szPath[MAX_PATH];                            //存放路径的变量       
	GetCurrentDirectory(MAX_PATH, szPath);             //获取程序的当前目录
	CString strtemp = (CString)szPath;
	return strtemp;
}
/**
* 取得文件路径( 包含"/")
*/
CString CMFCApplication1Dlg::GetFolderPathFromFullPath(CString lpszFullPath)
{
	ASSERT(!lpszFullPath.IsEmpty());
	// 获取文件路径：
	// 注意不是“/”以结尾,因为使用过程中加上一个“/”容易，减去一个不容易
	CString m_strOriFileName = lpszFullPath;
	//m_strOriFileName.Replace(_T("\\"), _T("/"));

	CString strPath;
	int n = m_strOriFileName.ReverseFind('\\') + 1;
	strPath = m_strOriFileName.Left(n);
	return strPath;
}
/**
* 取得文件名（全名）
*/
CString CMFCApplication1Dlg::GetFileFullNameFromFullPath(CString lpszFullPath)
{
	ASSERT(!lpszFullPath.IsEmpty());
	// 获取文件名：
	CString m_strOriFileName = lpszFullPath;
	//m_strOriFileName.Replace(_T("\\"), _T("/"));

	CString strPath;
	int n = m_strOriFileName.GetLength() - m_strOriFileName.ReverseFind('\\') - 1;
	strPath = m_strOriFileName.Right(n);

	return strPath;
}
//加入到中奖名单
void CMFCApplication1Dlg::AddToLucy(CString user)
{
	//CString filepath;
	//filepath = GetCurDirectory() + "\\luckdata.txt";

	//CFile   fileDst;
	//fileDst.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	////保存数据
	//fileDst.SeekToEnd();
	//user += _T("\r\n");
	//fileDst.Write(user, user.GetLength());
	////-------------
	//fileDst.Close();//
	m_luckusers.push_back(user);
}

//判断是否在中奖名单中
BOOL CMFCApplication1Dlg::isExitLuck(CString user)
{
	BOOL isExist = FALSE;
	/*CString filepath;
	filepath = GetCurDirectory() + "\\luckdata.txt";
	CString strContent = File_ReadAllLine(filepath);
	if (strContent.Find(user) != -1) {
		isExist = TRUE;
	}*/
	//从m_luckusers中查询是否存在
	for (auto item : m_luckusers) {
		if (item== user)
		{
			isExist = TRUE;
			break;
		}
	}

	return isExist;
}
//读取文本内容（按行读取）unicode环境下读取ansi文本中文乱码
CString CMFCApplication1Dlg::File_ReadAllLine(CString filepath)
{
	CStdioFile file;
	//打开文件
	if (!file.Open(filepath, CFile::modeRead))
	{
		//AfxMessageBox(_T("文件打开失败。"));
		return _T("");
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		//写入
		strText += _T("\r\n");
		strContent += strText;//-------注释部分，全部一起保存
	}
	//关闭文件
	file.Close();
	//
	return strContent;
}

void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication1Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//OnBnClickedButton1();

	CDialogEx::OnLButtonDblClk(nFlags, point);
}



void CMFCApplication1Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString filepath;
	filepath = GetCurDirectory() + "\\luckdata.txt";
	// 打开文件并清空内容
	CFile   fileDst;
	fileDst.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	// 清空文件内容
	fileDst.SetLength(0);
	//保存中奖列表
	for (auto item : m_luckusers) {
		CString user = item+ _T("\r\n");
		fileDst.SeekToEnd();
		fileDst.Write(user, user.GetLength());
	}
	//关闭文件
	fileDst.Close();

	CDialogEx::OnClose();
}
