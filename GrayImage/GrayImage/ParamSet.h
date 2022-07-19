#pragma once

#include "HalconCpp.h"
using namespace HalconCpp;
// ParamSet 对话框

class ParamSet : public CDialog
{
	DECLARE_DYNAMIC(ParamSet)

public:
	ParamSet(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ParamSet();


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_AbsThreshold1;
	float m_VarThreshold1;
	float m_AbsThreshold2;
	float m_VarThreshold2;
	float m_AbsThreshold3;
	float m_VarThreshold3;
	float m_MinThreshold1;
	float m_MaxThreshold1;
	float m_MinThreshold2;
	float m_MaxThreshold2;

	afx_msg void OnBnClickedOk();
};
