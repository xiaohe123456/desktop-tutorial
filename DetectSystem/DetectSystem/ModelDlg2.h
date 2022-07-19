#pragma once

#include "DetectAlgorithm.h"
using namespace HalconCpp;
// ModelDlg2 对话框

class ModelDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(ModelDlg2)

public:
	ModelDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ModelDlg2();

	s_CheckInitParam sInitParam2;
	s_CheckInParam sCheckInParam2;
	s_ModelInParam sModelInParam2;
	CDetectAlgorithm m_hDetect;
	CString GetCurrentAppPath();

	HObject ModelImage;
	CRect m_rtImage2;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void HongLang();
	afx_msg void TestHongLang();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void DetectParamModel();
	afx_msg void SaveHongLang();
};
