
// MFCApplication1Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MAXIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	COLORREF color = RGB(0, 255, 0);
	m_EditBoxShow.SetForeColor(color);

	m_EditBoxShow.SetBkColor(RGB(0, 0, 0));
	m_EditBoxShow.SetTextFont(650, _T("FangSong_GB2312"));
	m_EditBoxShow.SetWindowTextA("\r\n2022������֣�");
	m_EditBoxShow.SetSel(-1,-1, 0);

	m_bitmap.LoadBitmap(IDB_BK);
	m_brush.CreatePatternBrush(&m_bitmap);
	//
	//MoveWnd();
	LoadLuckUser();//�������н��б�
	LoadData();//���س齱�б�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	if (GetDlgItemText(IDC_BUTTON1, str), str == "�齱" || str == "Lucky-Button")
	{
		SetDlgItemText(IDC_BUTTON1, "ֹͣ");
		srand((unsigned)time(NULL));
		SetTimer(1001, 10, NULL);
	}
	else
	{
		SetDlgItemText(IDC_BUTTON1, "�齱");
		KillTimer(1001);
		CString luckyMan=m_users[m_irand];
		Sleep(10);
		//���뵽�н�������
		AddToLucy(luckyMan);
		//Sleep(10);
		//���н��ߴ��б���ɾ��
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
		finalShow = "=====��ϲ=====\r\n" + flgStr + "\r\n" + luckyMan + "\r\n" + flgStr + "\r\n�н���!";
		m_EditBoxShow.SetTextFont(400, _T("FangSong_GB2312"));
		m_EditBoxShow.SetForeColor(RGB(255, 0, 0));
		//SetDlgItemText(IDC_EDIT1, luckyMan);
		m_EditBoxShow.SetWindowText(finalShow);
		//MessageBox(LPCTSTR(luckyMan));
	}
}


void CMFCApplication1Dlg::MoveWnd()
{
	int screenwidth = GetSystemMetrics(SM_CXFULLSCREEN);//��ȡ��Ļ�ֱ��ʿ��,������������������
	int screenheight = GetSystemMetrics(SM_CYFULLSCREEN);//��ȡ��Ļ�ֱ��ʸ߶�,������������������
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

	// TODO:  �ڴ˸��� DC ���κ�����
	/*switch (nCtlColor)
	{
	case CTLCOLOR_DLG:
		return m_brush;
	}
*/
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1001:      //IDΪ1001�Ķ�ʱ�����벿��
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
	//���ļ�
	if (!file.Open(filepath, CFile::modeRead))
	{
		AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		if (strText != _T("")) {
			//�ж��Ƿ����н�������
			//д��
			m_luckusers.push_back(strText);
		}
	}
	//�ر��ļ�
	file.Close();
}

//ȡ�ò���
void CMFCApplication1Dlg::LoadData()
{
	CString filepath;
	filepath = GetCurDirectory() + "\\data.txt";
	CStdioFile file;
	//���ļ�
	if (!file.Open(filepath, CFile::modeRead))
	{
		AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		if (strText != _T("")) {
			//�ж��Ƿ����н�������
			if (!isExitLuck(strText)) {
				//д��
				m_users.push_back(strText);
			}
			
		}
	}
	//�ر��ļ�
	file.Close();
}
/**
* ȡ�õ�ǰĿ¼
*/
CString CMFCApplication1Dlg::GetCurDirectory()
{
	TCHAR szPath[MAX_PATH];                            //���·���ı���       
	GetCurrentDirectory(MAX_PATH, szPath);             //��ȡ����ĵ�ǰĿ¼
	CString strtemp = (CString)szPath;
	return strtemp;
}
/**
* ȡ���ļ�·��( ����"/")
*/
CString CMFCApplication1Dlg::GetFolderPathFromFullPath(CString lpszFullPath)
{
	ASSERT(!lpszFullPath.IsEmpty());
	// ��ȡ�ļ�·����
	// ע�ⲻ�ǡ�/���Խ�β,��Ϊʹ�ù����м���һ����/�����ף���ȥһ��������
	CString m_strOriFileName = lpszFullPath;
	//m_strOriFileName.Replace(_T("\\"), _T("/"));

	CString strPath;
	int n = m_strOriFileName.ReverseFind('\\') + 1;
	strPath = m_strOriFileName.Left(n);
	return strPath;
}
/**
* ȡ���ļ�����ȫ����
*/
CString CMFCApplication1Dlg::GetFileFullNameFromFullPath(CString lpszFullPath)
{
	ASSERT(!lpszFullPath.IsEmpty());
	// ��ȡ�ļ�����
	CString m_strOriFileName = lpszFullPath;
	//m_strOriFileName.Replace(_T("\\"), _T("/"));

	CString strPath;
	int n = m_strOriFileName.GetLength() - m_strOriFileName.ReverseFind('\\') - 1;
	strPath = m_strOriFileName.Right(n);

	return strPath;
}
//���뵽�н�����
void CMFCApplication1Dlg::AddToLucy(CString user)
{
	//CString filepath;
	//filepath = GetCurDirectory() + "\\luckdata.txt";

	//CFile   fileDst;
	//fileDst.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	////��������
	//fileDst.SeekToEnd();
	//user += _T("\r\n");
	//fileDst.Write(user, user.GetLength());
	////-------------
	//fileDst.Close();//
	m_luckusers.push_back(user);
}

//�ж��Ƿ����н�������
BOOL CMFCApplication1Dlg::isExitLuck(CString user)
{
	BOOL isExist = FALSE;
	/*CString filepath;
	filepath = GetCurDirectory() + "\\luckdata.txt";
	CString strContent = File_ReadAllLine(filepath);
	if (strContent.Find(user) != -1) {
		isExist = TRUE;
	}*/
	//��m_luckusers�в�ѯ�Ƿ����
	for (auto item : m_luckusers) {
		if (item== user)
		{
			isExist = TRUE;
			break;
		}
	}

	return isExist;
}
//��ȡ�ı����ݣ����ж�ȡ��unicode�����¶�ȡansi�ı���������
CString CMFCApplication1Dlg::File_ReadAllLine(CString filepath)
{
	CStdioFile file;
	//���ļ�
	if (!file.Open(filepath, CFile::modeRead))
	{
		//AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
		return _T("");
	}
	CString strContent;
	CString strText = _T("");
	while (file.ReadString(strText))
	{
		//д��
		strText += _T("\r\n");
		strContent += strText;//-------ע�Ͳ��֣�ȫ��һ�𱣴�
	}
	//�ر��ļ�
	file.Close();
	//
	return strContent;
}

void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication1Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//OnBnClickedButton1();

	CDialogEx::OnLButtonDblClk(nFlags, point);
}



void CMFCApplication1Dlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString filepath;
	filepath = GetCurDirectory() + "\\luckdata.txt";
	// ���ļ����������
	CFile   fileDst;
	fileDst.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	// ����ļ�����
	fileDst.SetLength(0);
	//�����н��б�
	for (auto item : m_luckusers) {
		CString user = item+ _T("\r\n");
		fileDst.SeekToEnd();
		fileDst.Write(user, user.GetLength());
	}
	//�ر��ļ�
	fileDst.Close();

	CDialogEx::OnClose();
}
