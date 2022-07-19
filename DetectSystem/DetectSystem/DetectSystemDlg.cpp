
// DetectSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DetectSystem.h"
#include "DetectSystemDlg.h"
#include "DetectAlgorithm.h"
#include "afxdialogex.h"
#include "ModelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "ModelDlg2.h"
#include <vector>




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



// CDetectSystemDlg 对话框



CDetectSystemDlg::CDetectSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DETECTSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDetectSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CBox);
}

BEGIN_MESSAGE_MAP(CDetectSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDetectSystemDlg::OpenImage)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON2, &CDetectSystemDlg::DetectParam)
	ON_COMMAND(IDC_RADIO1, &CDetectSystemDlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CDetectSystemDlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &CDetectSystemDlg::OnRadio3)

	ON_CBN_SELCHANGE(IDC_COMBO1, &CDetectSystemDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDetectSystemDlg::JinLongYuCreate)
	ON_BN_CLICKED(IDC_BUTTON4, &CDetectSystemDlg::HongLang)
	ON_BN_CLICKED(IDC_BUTTON6, &CDetectSystemDlg::UpImage)
	ON_BN_CLICKED(IDC_BUTTON7, &CDetectSystemDlg::DownImage)
END_MESSAGE_MAP()


// CDetectSystemDlg 消息处理程序

BOOL CDetectSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: 在此添加额外的初始化代码

	s_CheckInitParam sInitParam;
	HWND hWnd1 = GetDlgItem(IDC_STATIC)->GetSafeHwnd();
	GetDlgItem(IDC_STATIC)->GetClientRect(&m_rtImage);
	int hWnd = (int)hWnd1;
	
	sInitParam.pHWnd = &hWnd;
	

	CString strPath = GetCurrentAppPath();	//	得到系统路径
	CString strModPath = strPath + "algorithmFiles";
	strcpy_s(sInitParam.chPath, (LPSTR)(LPCTSTR)strModPath);
	m_hDetect.Detect_Init(sInitParam);

	m_CBox.InsertString(0, "金龙鱼标签检测");
	m_CBox.InsertString(1, "红狼烟包色差检测");
	m_CBox.InsertString(2, "芙蓉王烟包标签检测");
	m_CBox.InsertString(3, "黄鹤楼烟包拉墨检测");



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDetectSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDetectSystemDlg::OnPaint()
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
HCURSOR CDetectSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


std::vector<CString> m_FileList;
int numImageNow;
int numImageMax;
void CDetectSystemDlg::OpenImage()
{
	// TODO: 在此添加控件通知处理程序代码
	CString path;

	CFileDialog dlgL(TRUE, _T("*.png"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("image files (*.png; *.bmp; *.jpg) |*.png;*.bmp;*.jpg|All Files (*.*)|*.*||"), NULL);
	
	dlgL.m_ofn.lpstrTitle = _T("打开图像");
	if (IDOK == dlgL.DoModal()) //当点击确定按钮时候，会记录文件路径
	{
		path = dlgL.GetPathName();
	}
	else
	{
		return;
	}

	path2 = dlgL.GetFolderPath();
	int iEndPos = 0;
	iEndPos = path.ReverseFind('\\');
	path1 = path.Left(iEndPos);

	
	HANDLE file;
	WIN32_FIND_DATA fileData;

	
	m_FileList.clear();
	path1 += "\\*.bmp";
	file = FindFirstFile(path1.GetBuffer(), &fileData);
	m_FileList.push_back(fileData.cFileName);
	bool bState = false;
	bState = FindNextFile(file, &fileData);
	while (bState) {
		m_FileList.push_back(fileData.cFileName);
		bState = FindNextFile(file, &fileData);
	}
	numImageMax = m_FileList.size();
	int length = m_FileList.at(0).GetLength();
	CString name1 = path.Right(length);
	
	for (int i = 0; i < numImageMax; i++)
	{
		if (name1.Compare(m_FileList.at(i)) == 0)
			numImageNow =  i;
		
	}
	char* ch = (char*)LPCTSTR(path);
	ReadImage(&ho_Image, ch);          //读取文件
	
	sCheckInParam.Image = ho_Image;
	UpdateData(TRUE);
	sCheckInParam.DisplayMode = m_nRadio;
	
	m_hDetect.SetWinodw(sCheckInParam.Image, m_rtImage);
	m_hDetect.ShowImage(sCheckInParam.Image);


}


CString CDetectSystemDlg::GetCurrentAppPath()
{
	char str[MAX_PATH], drive[MAX_PATH], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	GetModuleFileName(NULL, str, sizeof(str));
	_splitpath_s(str, drive, dir, fname, ext);
	strcat_s(drive, dir);
	CString AppPath;
	AppPath = drive;
	return AppPath;
}





//滑动鼠标滚轮缩放图像
BOOL CDetectSystemDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect rect;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rect); 
	m_hDetect.ScaleImage(nFlags, m_rtImage, rect, zDelta, pt, ho_Image);
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CDetectSystemDlg::DetectParam()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.SetModel(sModelInParam);
}



//显示图像
void CDetectSystemDlg::OnRadio1()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
	m_nRadio = 1;
	sCheckInParam.DisplayMode = m_nRadio;
	
}

//不显示图像
void CDetectSystemDlg::OnRadio2()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
	m_nRadio = 0;
	sCheckInParam.DisplayMode = m_nRadio;
}

//异常图像
void CDetectSystemDlg::OnRadio3()
{
	// TODO: 在此添加命令处理程序代码
	m_nRadio = 2;
	UpdateData(TRUE);
	sCheckInParam.DisplayMode = m_nRadio;
}



//检测
void CDetectSystemDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	posCurrent = m_CBox.GetCurSel();
	//int res;
	double* result = new double[2];
	if (posCurrent == 0)
	{
		result = m_hDetect.Detect_JinLongYu(sCheckInParam);
		if (result[0] == 0)
			SetDlgItemText(IDC_TEXT, "好品");
		else
			SetDlgItemText(IDC_TEXT, "坏品");
		CString time;
		time.Format("%lf", result[1]);
		SetDlgItemText(IDC_TEXT2, time + " ms");
		
	}
	   
	if (posCurrent == 1)
	{
		result = m_hDetect.Detect_SmokeColor(sCheckInParam);
		if (result[0] == 0)
			SetDlgItemText(IDC_TEXT, "好品");
		else
			SetDlgItemText(IDC_TEXT, "坏品");
		CString time;
		time.Format("%lf", result[1]);
		SetDlgItemText(IDC_TEXT2, time + " ms");
		
	}

	if (posCurrent == 2)
	{
		result = m_hDetect.Detect_FuRongWang(sCheckInParam);
		if (result[0] == 0)
			SetDlgItemText(IDC_TEXT, "好品");
		else
			SetDlgItemText(IDC_TEXT, "坏品");
		CString time;
		time.Format("%lf", result[1]);
		SetDlgItemText(IDC_TEXT2, time + " ms");
	}
		
	if (posCurrent == 3)
	{
		result = m_hDetect.Detect_HuangHeLou(sCheckInParam);
		if (result[0] == 0)
			SetDlgItemText(IDC_TEXT, "好品");
		else
			SetDlgItemText(IDC_TEXT, "坏品");
		CString time;
		time.Format("%lf", result[1]);
		SetDlgItemText(IDC_TEXT2, time + " ms");
	}
	//delete result;

	
}


//模板设置
void CDetectSystemDlg::JinLongYuCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	ModelDlg  ModelDlg1;
	ModelDlg1.DoModal();
}


void CDetectSystemDlg::HongLang()
{
	// TODO: 在此添加控件通知处理程序代码
	ModelDlg2  ModelDlg;
	ModelDlg.DoModal();

}


//上一张
void CDetectSystemDlg::UpImage()
{
	CString model;
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(posCurrent, model);
	--numImageNow;

	if (numImageNow < 0) {
		MessageBox("这是第一张图像");

	}
	else
	{
		if (numImageNow >= numImageMax)
			numImageNow = numImageMax-1;
		ReadImage(&ho_Image, HTuple(path2 + "\\" +  m_FileList.at(numImageNow)));
		sCheckInParam.Image = ho_Image;
		UpdateData(TRUE);
		sCheckInParam.DisplayMode = m_nRadio;
		m_hDetect.ShowImage(sCheckInParam.Image);
		//int res;
		double* result = new double[2];
		if (model.Compare("金龙鱼标签检测") == 0)
		{
			result = m_hDetect.Detect_JinLongYu(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("红狼烟包色差检测") == 0)
		{
			result = m_hDetect.Detect_SmokeColor(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("芙蓉王烟包标签检测") == 0)
		{
			result = m_hDetect.Detect_FuRongWang(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("黄鹤楼烟包拉墨检测") == 0)
		{
			result = m_hDetect.Detect_HuangHeLou(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

	}

}

//下一张
void CDetectSystemDlg::DownImage()
{
	// TODO: 在此添加控件通知处理程序代码

	CString model;
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(posCurrent, model);
	++numImageNow;

	if (numImageNow >= numImageMax) {

		MessageBox("这是最后一张图像");

	}
	else
	{
		if (numImageNow < 0)
			numImageNow = 0;
		ReadImage(&ho_Image, HTuple(path2 + "\\" + m_FileList.at(numImageNow)));
		sCheckInParam.Image = ho_Image;
		UpdateData(TRUE);
		sCheckInParam.DisplayMode = m_nRadio;
		m_hDetect.ShowImage(sCheckInParam.Image);

		//int res;
		double* result = new double[2];
		if (model.Compare("金龙鱼标签检测") == 0)
		{
			result = m_hDetect.Detect_JinLongYu(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("红狼烟包色差检测") == 0)
		{
			result = m_hDetect.Detect_SmokeColor(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("芙蓉王烟包标签检测") == 0)
		{
			result = m_hDetect.Detect_FuRongWang(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

		if (model.Compare("黄鹤楼烟包拉墨检测") == 0)
		{
			result = m_hDetect.Detect_HuangHeLou(sCheckInParam);
			if (result[0] == 0)
				SetDlgItemText(IDC_TEXT, "好品");
			else
				SetDlgItemText(IDC_TEXT, "坏品");
			CString time;
			time.Format("%lf", result[1]);
			SetDlgItemText(IDC_TEXT2, time + " ms");
		}

	}
}

