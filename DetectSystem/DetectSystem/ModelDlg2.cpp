// ModelDlg2.cpp: 实现文件
//

#include "pch.h"
#include "DetectSystem.h"
#include "ModelDlg2.h"
#include "afxdialogex.h"


// ModelDlg2 对话框

IMPLEMENT_DYNAMIC(ModelDlg2, CDialogEx)

ModelDlg2::ModelDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

ModelDlg2::~ModelDlg2()
{
}

void ModelDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ModelDlg2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ModelDlg2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ModelDlg2::HongLang)
	ON_BN_CLICKED(IDC_BUTTON3, &ModelDlg2::TestHongLang)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON4, &ModelDlg2::DetectParamModel)
	ON_BN_CLICKED(IDC_BUTTON5, &ModelDlg2::SaveHongLang)
END_MESSAGE_MAP()


BOOL ModelDlg2::OnInitDialog()
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
	GetDlgItem(IDC_STATIC)->GetClientRect(&m_rtImage2);
	int hWnd = (int)hWnd1;

	sInitParam2.pHWnd = &hWnd;


	CString strPath = GetCurrentAppPath();	//	得到系统路径
	CString strModPath = strPath + "algorithmFiles";
	strcpy_s(sInitParam2.chPath, (LPSTR)(LPCTSTR)strModPath);
	m_hDetect.Detect_Init(sInitParam2);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


CString ModelDlg2::GetCurrentAppPath()
{
	char str[MAX_PATH], drive[MAX_PATH], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	GetModuleFileName(NULL, str, sizeof(str));
	_splitpath_s(str, drive, dir, fname, ext);
	strcat_s(drive, dir);
	CString AppPath;
	AppPath = drive;
	return AppPath;
}

// ModelDlg2 消息处理程序


void ModelDlg2::OnBnClickedButton1()
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

	sCheckInParam2.Image = ModelImage;
	UpdateData(TRUE);

	m_hDetect.SetWinodw(sCheckInParam2.Image, m_rtImage2);
	m_hDetect.ShowImage(sCheckInParam2.Image);
}


void ModelDlg2::HongLang()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox("请在图像上画出检测区域");
	m_hDetect.ModelCreateHongLang(sCheckInParam2);
	MessageBox("模型创建完毕");
}


void ModelDlg2::TestHongLang()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.TestHongLang(sCheckInParam2);
}


BOOL ModelDlg2::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rect);
	m_hDetect.ScaleImage(nFlags, m_rtImage2, rect, zDelta, pt, ModelImage);
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void ModelDlg2::DetectParamModel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.SetModel(sModelInParam2);
}


void ModelDlg2::SaveHongLang()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hDetect.SaveHongLang();
	MessageBox("保存成功");
}
