
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
	void init_Window(int* pHWnd);//���ڳ�ʼ��
	//��������
	int show_Mold();
	//������ģ�崴��
	int Model_Create_JinLongYu(HObject ho_Image);
	//���Խ�����
	void Model_Test_JinLongYu(HObject ho_Image);
	//���������ģ��
	void SaveJinLongYu_Model();
	//����ģ�崴��
	int Model_Create_HongLang(HObject ho_Image);
	//���Ժ���
	void Model_Test_HongLang(HObject ho_Image);
	//�������ģ��
	void SaveHongLang_Model();
	//������ʼ��
	int init_Mold(char* strPath);

	//���������ǩ
	double* DetectJinLongYu(HObject  ho_Image, HTuple DisPlayMode);
	//�������̰�ɫ��
	double* DetectSmokeColor(HObject Image, HTuple DisPlayMode);
	//���ܽ�����̰���ǩ��λ
	double* DetectFuRongWang(HObject Image, HTuple DisPlayMode);
	//���ƺ�¥�̰���ī
	double* DetectHuangHeLou(HObject Image, HTuple DisPlayMode);
	//ͼ�����ź���
	void ScaleImage1(UINT nFlags, CRect rt, CRect rect,short zDelta, CPoint pt, HObject ho_Image);
	//ͼ����ʾ����
	void ShowImage1(HObject ho_Image);
	//ͼ����ʾ����
	void SetWindow1(HObject ho_Image, CRect m_rtImage);


	CString strPath;
	CString strModPath;//����·��

	HTuple m_hWindow;//��ʾ���ھ��
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

	//������ģ�Ͳ���
	// ģ��1ͼ��ͱ仯ģ��֮����С������ֵ
	float m_AbsThreshold1; // ģ��1ͼ��ͱ仯ģ��֮����С������ֵ
	float m_VarThreshold1; //ģ��1�л��ڱ仯ģ�͵Ĳ�����ֵ
	float m_AbsThreshold2; //ģ��2ͼ��ͱ仯ģ��֮����С������ֵ
	float m_VarThreshold2; //ģ��2�л��ڱ仯ģ�͵Ĳ�����ֵ
	//�����̰�������
	float m_AbsThreshold3; //ͼ��ͱ仯ģ��֮����С������ֵ
	float m_VarThreshold3; //ģ���л��ڱ仯ģ�͵Ĳ�����ֵ
	//�ƺ�¥��ī����
	float m_MinThreshold1; //ͼ��ָ���С��ֵ
	float m_MaxThreshold1; //ͼ��ָ������ֵ
	//ܽ�����̰�������
	float m_MinThreshold2; //ģ����ͼ��ͱ仯ģ��֮����С������ֵ
	float m_MaxThreshold2;  //ģ���л��ڱ仯ģ�͵Ĳ�����ֵ
	

	double  m_dDispImagePartRow0;
	double  m_dDispImagePartCol0;
	double  m_dDispImagePartRow1;
	double  m_dDispImagePartCol1;	




};





#endif // !defined(AFX_TEST_H__E83226C5_5553_4621_ADEB_1469857AA75E__INCLUDED_)


