// ParamSet.cpp: 实现文件
//

#include "pch.h"
#include "GrayImage.h"
#include "ParamSet.h"
#include "afxdialogex.h"



// ParamSet 对话框

IMPLEMENT_DYNAMIC(ParamSet, CDialog)

ParamSet::ParamSet(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_AbsThreshold1(0)
	, m_VarThreshold1(0)
	, m_AbsThreshold2(0)
	, m_VarThreshold2(0)
	, m_AbsThreshold3(0)
	, m_VarThreshold3(0)
	, m_MinThreshold1(0)
	, m_MaxThreshold1(0)
	, m_MinThreshold2(0)
	, m_MaxThreshold2(0)
	
{

}

ParamSet::~ParamSet()
{
}

void ParamSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT12, m_AbsThreshold1);
	DDX_Text(pDX, IDC_EDIT1, m_VarThreshold1);
	DDX_Text(pDX, IDC_EDIT3, m_AbsThreshold2);
	DDX_Text(pDX, IDC_EDIT4, m_VarThreshold2);
	DDX_Text(pDX, IDC_EDIT5, m_AbsThreshold3);
	DDX_Text(pDX, IDC_EDIT6, m_VarThreshold3);
	DDX_Text(pDX, IDC_EDIT7, m_MinThreshold1);
	DDX_Text(pDX, IDC_EDIT8, m_MaxThreshold1);
	DDX_Text(pDX, IDC_EDIT9, m_MinThreshold2);
	DDX_Text(pDX, IDC_EDIT10, m_MaxThreshold2);

	
	
}


BEGIN_MESSAGE_MAP(ParamSet, CDialog)

	ON_BN_CLICKED(IDOK, &ParamSet::OnBnClickedOk)
END_MESSAGE_MAP()


// ParamSet 消息处理程序


void ParamSet::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	UpdateData();


}

