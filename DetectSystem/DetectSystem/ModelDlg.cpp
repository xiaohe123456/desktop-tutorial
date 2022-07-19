// ModelDlg.cpp: 实现文件
//

#include "pch.h"
#include "DetectSystem.h"
#include "ModelDlg.h"
#include "afxdialogex.h"
#include "DetectAlgorithm.h"
#include "DetectSystemDlg.h"


// ModelDlg 对话框

IMPLEMENT_DYNAMIC(ModelDlg, CDialogEx)

ModelDlg::ModelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ModelDlg::~ModelDlg()
{
}

void ModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ModelDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ModelDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &ModelDlg::JinLongYu)
	ON_BN_CLICKED(IDC_BUTTON3, &ModelDlg::TestJinLongYu)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON4, &ModelDlg::DetectParamModel)
	ON_BN_CLICKED(IDC_BUTTON5, &ModelDlg::SaveJinLongYu)
END_MESSAGE_MAP()


// ModelDlg 消息处理程序

BOOL ModelDlg::OnInitDialog()
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


	// TODO: 在此添加额外的初始化代码

	
	HWND hWnd1 = GetDlgItem(IDC_STATIC)->GetSafeHwnd();
	GetDlgItem(IDC_STATIC)->GetClientRect(&m_rtImage1);
	int hWnd = (int)hWnd1;

	sInitParam1.pHWnd = &hWnd;


	CString strPath = GetCurrentAppPath();	//	得到系统路径
	CString strModPath = strPath + "algorithmFiles";
	strcpy_s(sInitParam1.chPath, (LPSTR)(LPCTSTR)strModPath);
	m_hDetect.Detect_Init(sInitParam1);




	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


CString ModelDlg::GetCurrentAppPath()
{
	char str[MAX_PATH], drive[MAX_PATH], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	GetModuleFileName(NULL, str, sizeof(str));
	_splitpath_s(str, drive, dir, fname, ext);
	strcat_s(drive, dir);
	CString AppPath;
	AppPath = drive;
	return AppPath;
}

void ModelDlg::OnBnClickedButton2()
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

	char* ch = (char*)LPCTSTR(path);
	ReadImage(&ModelImage, ch);          //读取文件
	//Rgb1ToGray(ModelImage, &GrayImage);

	sCheckInParam1.Image = ModelImage;
	UpdateData(TRUE);

	m_hDetect.SetWinodw(sCheckInParam1.Image, m_rtImage1);
	m_hDetect.ShowImage(sCheckInParam1.Image);
}

//模板创建
void ModelDlg::JinLongYu()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox("请在图像上画出两个检测区域");
	m_hDetect.ModelCreateJinLongYu(sCheckInParam1);
	MessageBox("模型创建完毕");
}


void ModelDlg::TestJinLongYu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.TestJinLongYu(sCheckInParam1);
	

}


BOOL ModelDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rect);
	m_hDetect.ScaleImage(nFlags, m_rtImage1, rect, zDelta, pt, ModelImage);
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void ModelDlg::DetectParamModel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.SetModel(sModelInParam1);
}


void ModelDlg::SaveJinLongYu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.SaveJinLongYu();
	MessageBox("保存成功");
}
