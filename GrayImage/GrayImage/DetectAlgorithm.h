#pragma once
#if !defined(AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_)
#define AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_LENGTH		1024

#define	_EXPORTING
#ifdef _EXPORTING
#define CLASS_DECLSPEC    __declspec(dllexport)  //�������ʱʹ��
#else
#define CLASS_DECLSPEC    __declspec(dllimport)	 //��̬��Ӧ��ʱʹ��
#endif


#include "HalconCpp.h"
using namespace HalconCpp;
//�㷨�ӿ��Լ���������

// ��ʼ��
typedef struct _CheckInitParam
{
	int* pHWnd;					// ͼ����ʾ���ھ��
	char chPath[MAX_LENGTH];	// ��ȡ�����������ļ�·����ͳһΪ��ǰ��������Ŀ¼��\algorithmFiles��
}s_CheckInitParam;

// ����������
typedef struct _CheckInParam
{
	HObject  Image;          //����ͼ��
	HTuple   DisplayMode;    //0 Ϊ����ʾ��1Ϊ��ʾ�� 2ֻ��ʾ����ͼ�� 
}s_CheckInParam;

//����������
typedef struct _CheckOutParam
{
	int		iErrorType;					 //����0Ϊ��Ʒ��1Ϊȱ��Ʒ 
}s_CheckOutParam;

//���ģ��
typedef struct _ModelInParam
{
	char	 chModelName[MAX_PATH];//ģ������
	int		nOperateSig;     //0����ģ�壬1�޸�ģ�壬2��������
}s_ModelInParam;


class CLASS_DECLSPEC CDetectAlgorithm
{
public:
	void* m_pData;//ָ��TestClass��ָ�룬����ͼ������

	CDetectAlgorithm();
	virtual ~CDetectAlgorithm();

	//��ʼ����������1������Ϊ0
	bool  Detect_Init(s_CheckInitParam sInitParam);  //�㷨��ʼ������

	///�ڴ��ͷ���������1������Ϊ0
	bool  Detect_Free();                             //�ڴ��ͷź���


	//����������������1������Ϊ0
	bool SetModel(s_ModelInParam sModelInParam); //��������

	//�������ǩ���ģ�崴��
	bool ModelCreateJinLongYu(s_CheckInParam sCheckInParamm);
	//���Խ�����
	void TestJinLongYu(s_CheckInParam sCheckInParamm);
	//���������ģ��
	void SaveJinLongYu();

	//�����̰�ɫ���ǩ���ģ�崴��
	bool ModelCreateHongLang(s_CheckInParam sCheckInParamm);
	//���Խ�����
	void TestHongLang(s_CheckInParam sCheckInParamm);
	//�������ģ��
	void SaveHongLang();

	//���������ǩ����������1������Ϊ0
	double* Detect_JinLongYu(s_CheckInParam sCheckInParamm); //��⺯��
	//�������̰�ɫ��
	double* Detect_SmokeColor(s_CheckInParam sCheckInParamm); //��⺯��
	//���ܽ�����̰���ǩ��λ
	double* Detect_FuRongWang(s_CheckInParam sCheckInParamm); //��⺯��
	//���ƺ�¥�̰���ī
	double* Detect_HuangHeLou(s_CheckInParam sCheckInParamm); //��⺯��
	//����ͼ��
	void ScaleImage(UINT nFlags,  CRect rt, CRect rect, short zDelta, CPoint pt, HObject ho_Image);
	//��ʾͼ��	
	void ShowImage(HObject Image);
    //ͼ�񴰿���ʾ����
	void SetWinodw(HObject Image, CRect m_rtImage);


};



#endif // !defined(AFX_DETECTALGORITHM_H__6FFD4C26_DF62_47E6_8D18_0584BA91B442__INCLUDED_)

