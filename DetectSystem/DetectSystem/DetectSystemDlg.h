
// DetectSystemDlg.h: 头文件
//
#if !defined(AFX_DETECTSYSTEMDLG_H__ABB7DA41_BC37_4720_8C5D_E959FA77CBF9__INCLUDED_)
#define AFX_DETECTSYSTEMDLG_H__ABB7DA41_BC37_4720_8C5D_E959FA77CBF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HalconCpp.h"


#include "DetectAlgorithm.h"
using namespace HalconCpp;
// CDetectSystemDlg 对话框
class CDetectSystemDlg : public CDialogEx
{
// 构造
public:
	
	CString GetCurrentAppPath();
	CString path1, path2;
	CDetectSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数
	
	s_CheckInParam sCheckInParam;

	s_ModelInParam sModelInParam;

	s_CheckOutParam sCheckOutParam;

	CDetectAlgorithm m_hDetect;
	Hlong m_hWindow;
	CRect m_rtImage;
	CRect m_rect;  
	HObject  ho_Image;
	bool flag;
	CPoint OldPoint;
	CPoint NewPoint;
	HTuple  hv_time, hv_t1, hv_t2;

	int  m_nRadio;
	int  m_Param;
	int posCurrent;


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DETECTSYSTEM_DIALOG };
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
	afx_msg void OpenImage();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void DetectParam();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	CComboBox m_CBox;
	afx_msg void OnCbnSelchangeCombo1();

	afx_msg void JinLongYuCreate();
	afx_msg void HongLang();
	afx_msg void UpImage();
	afx_msg void DownImage();
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETECTSYSTEMDLG_H__ABB7DA41_BC37_4720_8C5D_E959FA77CBF9__INCLUDED_)