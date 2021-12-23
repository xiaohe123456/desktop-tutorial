#include "..\..\DetectSystem\DetectSystem\DetectAlgorithm.h"
#include "pch.h"
#include "DetectAlgorithm.h"
#include "Test.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

CDetectAlgorithm::CDetectAlgorithm()
{
	m_pData = (void*)new CTestClass;
}

CDetectAlgorithm::~CDetectAlgorithm()
{
	if (m_pData)
	{
		delete ((CTestClass*)m_pData);
		m_pData = NULL;
	}
}

//初始化窗口与参数
bool CDetectAlgorithm::Detect_Init(s_CheckInitParam sInitParam)
{
    ((CTestClass*)m_pData)->init_Window(sInitParam.pHWnd);
	((CTestClass*)m_pData)->init_Mold(&sInitParam.chPath[0]);
	return false;
}


//释放内存
bool  CDetectAlgorithm::Detect_Free()
{
	delete ((CTestClass*)m_pData);
	m_pData = NULL;
	return 1;
}


//具体检测函数 金龙鱼标签
double* CDetectAlgorithm::Detect_JinLongYu(s_CheckInParam sCheckInParam)
{
	//int res;
	double* res;
	res = ((CTestClass*)m_pData)->DetectJinLongYu(sCheckInParam.Image, sCheckInParam.DisplayMode);
	return res;
}

//红狼色差
double* CDetectAlgorithm::Detect_SmokeColor(s_CheckInParam sCheckInParam)
{
	double* res;
	res = ((CTestClass*)m_pData)->DetectSmokeColor(sCheckInParam.Image, sCheckInParam.DisplayMode);
	return res;
}

//芙蓉王标签错位
double* CDetectAlgorithm::Detect_FuRongWang(s_CheckInParam sCheckInParamm)
{
	double* res;
	res = ((CTestClass*)m_pData)->DetectFuRongWang(sCheckInParamm.Image, sCheckInParamm.DisplayMode);
	return res;
}
//黄鹤楼拉墨
double* CDetectAlgorithm::Detect_HuangHeLou(s_CheckInParam sCheckInParamm)
{
	double* res;
	res = ((CTestClass*)m_pData)->DetectHuangHeLou(sCheckInParamm.Image, sCheckInParamm.DisplayMode);
	return res;
}


//图像缩放函数
void CDetectAlgorithm::ScaleImage(UINT nFlags, CRect rt, CRect rect, short zDelta, CPoint pt, HObject ho_Image)
{
	((CTestClass*)m_pData)->ScaleImage1(nFlags,  rt,  rect,  zDelta,  pt, ho_Image);

}


//模式设置
bool CDetectAlgorithm::SetModel(s_ModelInParam sModelInParam)
{
	((CTestClass*)m_pData)->show_Mold();
	return 1;
}

//模板创建
bool CDetectAlgorithm::ModelCreateJinLongYu(s_CheckInParam sCheckInParamm)
{
	((CTestClass*)m_pData)->Model_Create_JinLongYu(sCheckInParamm.Image);
	return 1;
}
//测试金龙鱼
void CDetectAlgorithm::TestJinLongYu(s_CheckInParam sCheckInParamm)
{
	((CTestClass*)m_pData)->Model_Test_JinLongYu(sCheckInParamm.Image);
}

void CDetectAlgorithm::SaveJinLongYu()
{
	((CTestClass*)m_pData)->SaveJinLongYu_Model();
}

//模板创建
bool CDetectAlgorithm::ModelCreateHongLang(s_CheckInParam sCheckInParamm)
{
	((CTestClass*)m_pData)->Model_Create_HongLang(sCheckInParamm.Image);
	return 1;
}
//测试红狼
void CDetectAlgorithm::TestHongLang(s_CheckInParam sCheckInParamm)
{
	((CTestClass*)m_pData)->Model_Test_HongLang(sCheckInParamm.Image);
}

void CDetectAlgorithm::SaveHongLang()
{
	((CTestClass*)m_pData)->SaveHongLang_Model();
}



//显示图像函数
void CDetectAlgorithm::ShowImage(HObject Image)
{
	((CTestClass*)m_pData)->ShowImage1(Image);
}

//窗口设置函数
void CDetectAlgorithm::SetWinodw(HObject Image, CRect m_rtImage)
{
	((CTestClass*)m_pData)->SetWindow1(Image, m_rtImage);
}


