﻿#pragma once


// ModelCreate 对话框

class ModelCreate : public CDialog
{
	DECLARE_DYNAMIC(ModelCreate)

public:
	ModelCreate(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ModelCreate();



// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
