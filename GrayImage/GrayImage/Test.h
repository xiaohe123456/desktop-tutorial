
#if !defined(AFX_TEST_H__E83226C5_5553_4621_ADEB_1469857AA75E__INCLUDED_)
#define AFX_TEST_H__E83226C5_5553_4621_ADEB_1469857AA75E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HalconCpp.h"
using namespace HalconCpp;

class CTestClass
{
public:
	CTestClass();
	virtual ~CTestClass();
	void init_Window(int* pHWnd);//窗口初始化
	//参数设置
	int show_Mold();
	//金龙鱼模板创建
	int Model_Create_JinLongYu(HObject ho_Image);
	//测试金龙鱼
	void Model_Test_JinLongYu(HObject ho_Image);
	//保存金龙鱼模型
	void SaveJinLongYu_Model();
	//红狼模板创建
	int Model_Create_HongLang(HObject ho_Image);
	//测试红狼
	void Model_Test_HongLang(HObject ho_Image);
	//保存红狼模型
	void SaveHongLang_Model();
	//参数初始化
	int init_Mold(char* strPath);

	//检测金龙鱼标签
	double* DetectJinLongYu(HObject  ho_Image, HTuple DisPlayMode);
	//检测红狼烟包色差
	double* DetectSmokeColor(HObject Image, HTuple DisPlayMode);
	//检测芙蓉王烟包标签错位
	double* DetectFuRongWang(HObject Image, HTuple DisPlayMode);
	//检测黄鹤楼烟包拉墨
	double* DetectHuangHeLou(HObject Image, HTuple DisPlayMode);
	//图像缩放函数
	void ScaleImage1(UINT nFlags, CRect rt, CRect rect,short zDelta, CPoint pt, HObject ho_Image);
	//图像显示函数
	void ShowImage1(HObject ho_Image);
	//图像显示函数
	void SetWindow1(HObject ho_Image, CRect m_rtImage);


	CString strPath;
	CString strModPath;//参数路径

	HTuple m_hWindow;//显示窗口句柄
	HObject  ho_ImageResult;
	HObject ho_ConnectedRegions;
	HObject ho_Contours;
	HTuple  hv_time, hv_t1, hv_t2;
	//HTuple hv_ShapeModelID1, hv_VariationModelID1, hv_ShapeModelID2, hv_VariationModelID2;
	//HTuple  hv_ModelID, hv_InspectModelID;

	HTuple hv_Row11, hv_Column11, hv_Row12, hv_Column12, hv_Row21, hv_Column21, hv_Row22, hv_Column22;
	HTuple  hv_ModelRow1, hv_ModelColumn1, hv_ModelRow2, hv_ModelColumn2;
	HTuple  hv_ShapeModel1, hv_ShapeModel2, hv_VariationModel1, hv_VariationModel2;
	HTuple  hv_Row0, hv_Column0, hv_Mean;

	//金龙鱼模型参数
	// 模型1图像和变化模型之间最小绝对阈值
	float m_AbsThreshold1; // 模型1图像和变化模型之间最小绝对阈值
	float m_VarThreshold1; //模型1中基于变化模型的差异阈值
	float m_AbsThreshold2; //模型2图像和变化模型之间最小绝对阈值
	float m_VarThreshold2; //模型2中基于变化模型的差异阈值
	//红狼烟包检测参数
	float m_AbsThreshold3; //图像和变化模型之间最小绝对阈值
	float m_VarThreshold3; //模型中基于变化模型的差异阈值
	//黄鹤楼拉墨参数
	float m_MinThreshold1; //图像分割最小阈值
	float m_MaxThreshold1; //图像分割最大阈值
	//芙蓉王烟包检测参数
	float m_MinThreshold2; //模型中图像和变化模型之间最小绝对阈值
	float m_MaxThreshold2;  //模型中基于变化模型的差异阈值
	

	double  m_dDispImagePartRow0;
	double  m_dDispImagePartCol0;
	double  m_dDispImagePartRow1;
	double  m_dDispImagePartCol1;	




};





#endif // !defined(AFX_TEST_H__E83226C5_5553_4621_ADEB_1469857AA75E__INCLUDED_)


