#pragma once

#include "DetectAlgorithm.h"
using namespace HalconCpp;
// ModelDlg 对话框

class ModelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ModelDlg)

public:
	ModelDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ModelDlg();
	s_CheckInitParam sInitParam1;
	s_CheckInParam sCheckInParam1;
	s_ModelInParam sModelInParam1;
	CDetectAlgorithm m_hDetect;
	CString GetCurrentAppPath();

	HObject ModelImage;
	CRect m_rtImage1;



// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void JinLongYu();
	afx_msg void TestJinLongYu();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void DetectParamModel();
	afx_msg void SaveJinLongYu();
};
