#pragma once
#if !defined(AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_)
#define AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_LENGTH		1024

#define	_EXPORTING
#ifdef _EXPORTING
#define CLASS_DECLSPEC    __declspec(dllexport)  //程序编译时使用
#else
#define CLASS_DECLSPEC    __declspec(dllimport)	 //动态库应用时使用
#endif


#include "HalconCpp.h"
using namespace HalconCpp;
//算法接口以及参数设置

// 初始化
typedef struct _CheckInitParam
{
	int* pHWnd;					// 图像显示窗口句柄
	char chPath[MAX_LENGTH];	// 读取参数与配置文件路径（统一为当前程序运行目录下\algorithmFiles）
}s_CheckInitParam;

// 检测输入参数
typedef struct _CheckInParam
{
	HObject  Image;          //输入图像
	HTuple   DisplayMode;    //0 为不显示，1为显示， 2只显示错误图像 
}s_CheckInParam;

//检测输出参数
typedef struct _CheckOutParam
{
	int		iErrorType;					 //返回0为好品，1为缺陷品 
}s_CheckOutParam;

//检测模板
typedef struct _ModelInParam
{
	char	 chModelName[MAX_PATH];//模版名称
	int		nOperateSig;     //0加载模板，1修改模板，2参数设置
}s_ModelInParam;


class CLASS_DECLSPEC CDetectAlgorithm
{
public:
	void* m_pData;//指向TestClass的指针，调用图像处理函数

	CDetectAlgorithm();
	virtual ~CDetectAlgorithm();

	//初始化正常返回1，否则为0
	bool  Detect_Init(s_CheckInitParam sInitParam);  //算法初始化函数

	///内存释放正常返回1，否则为0
	bool  Detect_Free();                             //内存释放函数


	//参数设置正常返回1，否则为0
	bool SetModel(s_ModelInParam sModelInParam); //参数设置

	//金龙鱼标签检测模板创建
	bool ModelCreateJinLongYu(s_CheckInParam sCheckInParamm);
	//测试金龙鱼
	void TestJinLongYu(s_CheckInParam sCheckInParamm);
	//保存金龙鱼模型
	void SaveJinLongYu();

	//红狼烟包色差标签检测模板创建
	bool ModelCreateHongLang(s_CheckInParam sCheckInParamm);
	//测试金龙鱼
	void TestHongLang(s_CheckInParam sCheckInParamm);
	//保存红狼模型
	void SaveHongLang();

	//检测金龙鱼标签。正常返回1，否则为0
	double* Detect_JinLongYu(s_CheckInParam sCheckInParamm); //检测函数
	//检测红狼烟包色差
	double* Detect_SmokeColor(s_CheckInParam sCheckInParamm); //检测函数
	//检测芙蓉王烟包标签错位
	double* Detect_FuRongWang(s_CheckInParam sCheckInParamm); //检测函数
	//检测黄鹤楼烟包拉墨
	double* Detect_HuangHeLou(s_CheckInParam sCheckInParamm); //检测函数
	//缩放图像
	void ScaleImage(UINT nFlags,  CRect rt, CRect rect, short zDelta, CPoint pt, HObject ho_Image);
	//显示图像	
	void ShowImage(HObject Image);
    //图像窗口显示设置
	void SetWinodw(HObject Image, CRect m_rtImage);


};



#endif // !defined(AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_)

