#include "pch.h"
#include "Test.h"
#include "ParamSet.h"
#include "ModelCreate.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

CTestClass::CTestClass()
{

}

CTestClass::~CTestClass()
{
}


void CTestClass::init_Window(int* pHWnd)
{
	CRect rt;
	int iWnd = *pHWnd;
	HWND hWnd = (HWND)iWnd;
	GetWindowRect(hWnd, rt);

	OpenWindow(0, 0, rt.Width(), rt.Height(), iWnd, "visible", "", &m_hWindow);

}



int CTestClass::init_Mold(char* strPath)
{
	//strPath = GetCurrentAppPath();	//	得到系统路径
	strModPath = strPath;
	CString str, strSegment;
	str = strModPath + "\\Para.ini";
	char buf[MAX_PATH];

	strSegment.Format("检测参数");

	GetPrivateProfileString(strSegment, "AbsThreshold1", "19", buf, 80, str);
	m_AbsThreshold1 = atof(buf);
	GetPrivateProfileString(strSegment, "VarThreshold1", "26", buf, 80, str);
	m_VarThreshold1 = atof(buf);
	GetPrivateProfileString(strSegment, "AbsThreshold2", "19", buf, 80, str);
	m_AbsThreshold2 = atof(buf);
	GetPrivateProfileString(strSegment, "VarThreshold2", "28", buf, 80, str);
	m_VarThreshold2 = atof(buf);
	GetPrivateProfileString(strSegment, "AbsThreshold3", "20", buf, 80, str);
	m_AbsThreshold3 = atof(buf);
	GetPrivateProfileString(strSegment, "VarThreshold3", "26", buf, 80, str);
	m_VarThreshold3 = atof(buf);
	GetPrivateProfileString(strSegment, "MinThreshold2", "-24.48", buf, 80, str);
	m_MinThreshold2 = atof(buf);
	GetPrivateProfileString(strSegment, "MaxThreshold2", "67.42", buf, 80, str);
	m_MaxThreshold2 = atof(buf);
	GetPrivateProfileString(strSegment, "MinThreshold1", "0.38", buf, 80, str);
	m_MinThreshold1 = atof(buf);
	GetPrivateProfileString(strSegment, "MaxThreshold1", "14.042", buf, 80, str);
	m_MaxThreshold1 = atof(buf);

	return 0;
}


int CTestClass::show_Mold()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ParamSet  Param;
	

	Param.m_AbsThreshold1 = m_AbsThreshold1;
	Param.m_VarThreshold1 = m_VarThreshold1;
	Param.m_AbsThreshold2 = m_AbsThreshold2;
	Param.m_VarThreshold2 = m_VarThreshold2;
	Param.m_AbsThreshold3 = m_AbsThreshold3;
	Param.m_VarThreshold3 = m_VarThreshold3;
	Param.m_MinThreshold2 = m_MinThreshold2;
	Param.m_MaxThreshold2 = m_MaxThreshold2;

	Param.m_MinThreshold1 = m_MinThreshold1;
	Param.m_MaxThreshold1 = m_MaxThreshold1;


	if (Param.DoModal() == IDOK)
	{
		CreateDirectory(strModPath, NULL);
		
		m_AbsThreshold1 = Param.m_AbsThreshold1;
		m_VarThreshold1 = Param.m_VarThreshold1;
		m_AbsThreshold2 = Param.m_AbsThreshold2;
		m_VarThreshold2 = Param.m_VarThreshold2;
		m_AbsThreshold3 = Param.m_AbsThreshold3;
		m_VarThreshold3 = Param.m_VarThreshold3;
		m_MinThreshold2 = Param.m_MinThreshold2;
		m_MaxThreshold2 = Param.m_MaxThreshold2;
		m_MinThreshold1 = Param.m_MinThreshold1;
		m_MaxThreshold1 = Param.m_MaxThreshold1;

		CString str;
		str = strModPath + "\\Para.ini";

		CString strSegment;
		strSegment.Format("检测参数");

		CString strTmp;
		strTmp.Format("%f", Param.m_AbsThreshold1);
		WritePrivateProfileString(strSegment, "AbsThreshold1", strTmp, str);
		strTmp.Format("%f", Param.m_VarThreshold1);
		WritePrivateProfileString(strSegment, "VarThreshold1", strTmp, str);

		strTmp.Format("%f", Param.m_AbsThreshold2);
		WritePrivateProfileString(strSegment, "AbsThreshold2", strTmp, str);
		strTmp.Format("%f", Param.m_VarThreshold2);
		WritePrivateProfileString(strSegment, "VarThreshold2", strTmp, str);

		strTmp.Format("%f", Param.m_AbsThreshold3);
		WritePrivateProfileString(strSegment, "AbsThreshold3", strTmp, str);
		strTmp.Format("%f", Param.m_VarThreshold3);
		WritePrivateProfileString(strSegment, "VarThreshold3", strTmp, str);

		strTmp.Format("%f", Param.m_MinThreshold2);
		WritePrivateProfileString(strSegment, "MinThreshold2", strTmp, str);
		strTmp.Format("%f", Param.m_MaxThreshold2);
		WritePrivateProfileString(strSegment, "MaxThreshold2", strTmp, str);

		strTmp.Format("%f", Param.m_MinThreshold1);
		WritePrivateProfileString(strSegment, "MinThreshold1", strTmp, str);

		strTmp.Format("%f", Param.m_MaxThreshold1);
		WritePrivateProfileString(strSegment, "MaxThreshold1", strTmp, str);
	
	}
	return 0;
}

//模型创建
int CTestClass::Model_Create_JinLongYu(HObject ho_Image)
{

	HObject  ho_ModelImageScale, ho_ImageResult1, ho_ImageResult2;
	HObject  ho_Image13, ho_RectangleA, ho_RectangleB, ho_ImageReducedModel1;
	HObject  ho_RectangleSearchRegion1, ho_ImageReducedModel2;
	HObject  ho_RectangleSearchRegion2;
	HObject  ho_Image2, ho_ImageTrainScale1;
	HObject  ho_Image23, ho_ImageAffineTrans1, ho_ImageReducedTrain1;
	HObject  ho_ImageSub1, ho_ImageAffineTrans2, ho_ImageReducedTrain2;
	HObject  ho_ImageSub2;
	HObject ho_ImageRunScale1, ho_ImageAffineTransRuntime1;
	HObject  ho_ImageReducedSearch1, ho_ImageAffineTransRuntime2;
	HObject  ho_ImageReducedSearch2;


	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_HomMat2DIdentity;
	HTuple  hv_HomMat2DScaleBig, hv_Width1, hv_Height1, hv_WindowHandle;
	HTuple  hv_Area;
	HTuple  hv_ImageFiles, hv_J, hv_Row1;
	HTuple  hv_Column1, hv_Angle1, hv_Score1, hv_HomMat2DTrain1;
	HTuple  hv_Row2, hv_Column2, hv_Angle2, hv_Score2, hv_HomMat2DTrain2;
	HTuple  hv_ImageFiles1, hv_length, hv_RowR1, hv_ColumnR1;
	HTuple  hv_AngleR1, hv_ScoreR1, hv_HomMat2DRuntime1, hv_RowR2;
	HTuple  hv_ColumnR2, hv_AngleR2, hv_ScoreR2, hv_HomMat2DRutime2;

	hv_wScale = 1;
	hv_hScale = 1.18;
	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);
	AffineTransImage(ho_Image, &ho_ModelImageScale, hv_HomMat2DScaleBig, "constant", "false");
	Rgb1ToGray(ho_ModelImageScale, &ho_Image13);
	GetImageSize(ho_Image13, &hv_Width1, &hv_Height1);
	ShowImage1(ho_Image13);
	//创建模型1
	
	DrawRectangle1(m_hWindow, &hv_Row11, &hv_Column11, &hv_Row12, &hv_Column12);
	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	ReduceDomain(ho_Image13, ho_RectangleA, &ho_ImageReducedModel1);
	CreateShapeModel(ho_ImageReducedModel1, 5, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		"auto", "none", "use_polarity", 20, 10, &hv_ShapeModel1);
	//检测区域1
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);
	PaintRegion(ho_RectangleSearchRegion1, ho_Image13, &ho_ImageResult1, 255, "fill");
	ShowImage1(ho_ImageResult1);

	//创建多样性模型
	CreateVariationModel(hv_Width1, hv_Height1, "byte", "standard", &hv_VariationModel1);

	//创建模型2
	DrawRectangle1(m_hWindow, &hv_Row21, &hv_Column21, &hv_Row22, &hv_Column22);
	GenRectangle1(&ho_RectangleB, hv_Row21, hv_Column21, hv_Row22, hv_Column22);
	AreaCenter(ho_RectangleB, &hv_Area, &hv_ModelRow2, &hv_ModelColumn2);
	ReduceDomain(ho_Image13, ho_RectangleB, &ho_ImageReducedModel2);
	CreateShapeModel(ho_ImageReducedModel2, 5, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		"auto", "none", "use_polarity", 20, 10, &hv_ShapeModel2);
	//检测区域2
	CopyObj(ho_RectangleB, &ho_RectangleSearchRegion2, 1, 1);
	PaintRegion(ho_RectangleSearchRegion2, ho_ImageResult1, &ho_ImageResult2, 255, "fill");
	ShowImage1(ho_ImageResult2);
	CreateVariationModel(hv_Width1, hv_Height1, "byte", "standard", &hv_VariationModel2);

	//训练检测模型
	
	ListFiles("D:\\Project\\WorkFigure\\1JInLongYu\\Template",(HTuple("files").Append("follow_links")),  &hv_ImageFiles);

	{
		HTuple end_val85 = (hv_ImageFiles.TupleLength()) - 1;
		HTuple step_val85 = 1;
		for (hv_J = 0; hv_J.Continue(end_val85, step_val85); hv_J += step_val85)
		{
			ReadImage(&ho_Image2, HTuple(hv_ImageFiles[hv_J]));
			AffineTransImage(ho_Image2, &ho_ImageTrainScale1, hv_HomMat2DScaleBig, "constant", "false");
			Rgb1ToGray(ho_ImageTrainScale1, &ho_Image23);
			//查找模型1
			FindShapeModel(ho_Image23, hv_ShapeModel1, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
				0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_Row1, &hv_Column1, &hv_Angle1,
				&hv_Score1);
			if (0 != (int((hv_Score1.TupleLength()) == 1)))
			{
				VectorAngleToRigid(hv_Row1, hv_Column1, hv_Angle1, hv_ModelRow1, hv_ModelColumn1,
					0, &hv_HomMat2DTrain1);
				AffineTransImage(ho_Image23, &ho_ImageAffineTrans1, hv_HomMat2DTrain1, "constant",
					"false");
				ReduceDomain(ho_ImageAffineTrans1, ho_RectangleSearchRegion1, &ho_ImageReducedTrain1
				);
				SubImage(ho_ImageReducedTrain1, ho_ImageReducedModel1, &ho_ImageSub1, 1, 0);
				TrainVariationModel(ho_ImageReducedTrain1, hv_VariationModel1);
			}

			//查找模型2
			FindShapeModel(ho_Image23, hv_ShapeModel2, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
				0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_Row2, &hv_Column2, &hv_Angle2,
				&hv_Score2);
			if (0 != (int((hv_Score1.TupleLength()) == 1)))
			{
				VectorAngleToRigid(hv_Row2, hv_Column2, hv_Angle2, hv_ModelRow2, hv_ModelColumn2,
					0, &hv_HomMat2DTrain2);
				AffineTransImage(ho_Image23, &ho_ImageAffineTrans2, hv_HomMat2DTrain2, "constant",
					"false");
				ReduceDomain(ho_ImageAffineTrans2, ho_RectangleSearchRegion2, &ho_ImageReducedTrain2
				);
				SubImage(ho_ImageReducedTrain2, ho_ImageReducedModel2, &ho_ImageSub2, 1, 0);
				TrainVariationModel(ho_ImageReducedTrain2, hv_VariationModel2);
			}

		}
	}

	return 1;
}

void CTestClass::Model_Test_JinLongYu(HObject ho_Image)
{

	// Local iconic variables
	HObject  ho_RectangleA, ho_RectangleSearchRegion1;
	HObject  ho_RectangleB, ho_RectangleSearchRegion2, ho_EmptyRegion;
	HObject  ho_ImageRunScale1, ho_Image33, ho_ImageAffineTransRuntime1, result_Image;
	HObject  ho_ImageReducedSearch1, ho_RegionDiff1, ho_ImageAffineTransRuntime2;
	HObject  ho_ImageReducedSearch2, ho_RegionDiff2, ho_RegionUnion;


	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_HomMat2DIdentity;
	HTuple  hv_HomMat2DScaleBig, hv_Area;
	HTuple   hv_ImageFiles1, hv_length;
	HTuple  hv_J, hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1;
	HTuple  hv_HomMat2DRuntime1, hv_RowR2, hv_ColumnR2, hv_AngleR2;
	HTuple  hv_ScoreR2, hv_HomMat2DRutime2;
	

	hv_wScale = 1;
	hv_hScale = 1.18;

	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);

	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);

	GenRectangle1(&ho_RectangleB, hv_Row21, hv_Column21, hv_Row22, hv_Column22);
	AreaCenter(ho_RectangleB, &hv_Area, &hv_ModelRow2, &hv_ModelColumn2);
	CopyObj(ho_RectangleB, &ho_RectangleSearchRegion2, 1, 1);


	PrepareVariationModel(hv_VariationModel1, m_AbsThreshold1, m_VarThreshold1);
	PrepareVariationModel(hv_VariationModel2, m_AbsThreshold2, m_VarThreshold2);

	GenEmptyRegion(&ho_EmptyRegion);

	AffineTransImage(ho_Image, &ho_ImageRunScale1, hv_HomMat2DScaleBig, "constant",
		"false");
	Rgb1ToGray(ho_ImageRunScale1, &ho_Image33);
	//1
	FindShapeModel(ho_Image33, hv_ShapeModel1, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR1, &hv_ColumnR1, &hv_AngleR1,
		&hv_ScoreR1);
	if (0 != (int((hv_ScoreR1.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ModelRow1, hv_ModelColumn1,
			0, &hv_HomMat2DRuntime1);
		AffineTransImage(ho_Image33, &ho_ImageAffineTransRuntime1, hv_HomMat2DRuntime1,
			"constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime1, ho_RectangleSearchRegion1, &ho_ImageReducedSearch1
		);
		CompareVariationModel(ho_ImageReducedSearch1, &ho_RegionDiff1, hv_VariationModel1);
	}
	else
	{
		ho_RegionDiff1 = ho_EmptyRegion;
	}

	//2
	FindShapeModel(ho_Image33, hv_ShapeModel2, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR2, &hv_ColumnR2, &hv_AngleR2,
		&hv_ScoreR2);
	if (0 != (int((hv_ScoreR2.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR2, hv_ColumnR2, hv_AngleR2, hv_ModelRow2, hv_ModelColumn2,
			0, &hv_HomMat2DRutime2);
		AffineTransImage(ho_Image33, &ho_ImageAffineTransRuntime2, hv_HomMat2DRutime2,
			"constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime2, ho_RectangleSearchRegion2, &ho_ImageReducedSearch2
		);
		CompareVariationModel(ho_ImageReducedSearch2, &ho_RegionDiff2, hv_VariationModel2);
	}
	else
	{
		ho_RegionDiff2 = ho_EmptyRegion;
	}

	Union2(ho_RegionDiff1, ho_RegionDiff2, &ho_RegionUnion);
	Connection(ho_RegionUnion, &ho_ConnectedRegions);
	GenContourRegionXld(ho_ConnectedRegions, &ho_Contours, "border");
	PaintXld(ho_Contours, ho_ImageAffineTransRuntime2, &ho_ImageResult, 255);
	ShowImage1(ho_ImageResult);

}

void CTestClass::SaveJinLongYu_Model()
{
	WriteShapeModel(hv_ShapeModel1, //'D:/张玉河/考核材料/ShapeModel1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/ShapeModel1.shm");
	WriteVariationModel(hv_VariationModel1, //'D:/张玉河/考核材料/VariationModel1.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/VariationModel1.vam");
	WriteShapeModel(hv_ShapeModel2, //'D:/张玉河/考核材料/ShapeModel1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/ShapeModel2.shm");
	WriteVariationModel(hv_VariationModel2, //'D:/张玉河/考核材料/VariationModel1.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/VariationModel2.vam");
}

int CTestClass::Model_Create_HongLang(HObject ho_Image)
{
	// Local iconic variables
	HObject  ho_Image11, ho_Image12, ho_ImageResult1;
	HObject  ho_Image13, ho_Region, ho_ModelImageScale0, ho_ImageRotate;
	HObject  ho_RectangleA, ho_ImageReducedModel1, ho_RectangleSearchRegion1;
	HObject  ho_Image2, ho_Image21, ho_Image22, ho_Image23, ho_ModelImageScale1;
	HObject  ho_ImageRotate1, ho_ImageAffineTrans1, ho_ImageReducedTrain1;
	HObject  ho_ImageSub1, ho_EmptyRegion;
	HObject  ho_ImageRotate2, ho_ImageAffineTransRuntime1, ho_ImageReducedSearch1;


	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_WindowHandle;
	HTuple  hv_Width1, hv_Height1, hv_UsedThreshold, hv_Area;
	HTuple  hv_Row0, hv_Column0, hv_Angle, hv_Dist;
	HTuple  hv_HomMat2DIdentity, hv_HomMat2DScaleBig, hv_HomMat2DRotate;
	HTuple  hv_ImageFiles, hv_J, hv_Row1, hv_Column1, hv_Angle1;
	HTuple  hv_Score1, hv_HomMat2DTrain1, hv_ImageFiles1, hv_length;
	HTuple  hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1, hv_HomMat2DRuntime1;

	hv_wScale = 1;
	hv_hScale = 1.03;

	Decompose3(ho_Image, &ho_Image11, &ho_Image12, &ho_Image13);
	GetImageSize(ho_Image11, &hv_Width1, &hv_Height1);
	
	BinaryThreshold(ho_Image11, &ho_Region, "smooth_histo", "light", &hv_UsedThreshold);

	AreaCenter(ho_Region, &hv_Area, &hv_Row0, &hv_Column0);
	HoughLines(ho_Image11, 1, 128, 20, 77, &hv_Angle, &hv_Dist);
	TupleMean(hv_Angle, &hv_Mean);
	//图像缩放旋转校正
	SetSystem("clip_region", "false");
	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);
	AffineTransImage(ho_Image11, &ho_ModelImageScale0, hv_HomMat2DScaleBig, "constant",
		"false");
	HomMat2dRotate(hv_HomMat2DIdentity, hv_Mean, hv_Row0, hv_Column0, &hv_HomMat2DRotate);
	AffineTransImage(ho_ModelImageScale0, &ho_ImageRotate, hv_HomMat2DRotate, "constant",
		"false");
	ShowImage1(ho_Image11);
	//创建模型1
	DrawRectangle1(m_hWindow, &hv_Row11, &hv_Column11, &hv_Row12, &hv_Column12);
	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);

	ReduceDomain(ho_ModelImageScale0, ho_RectangleA, &ho_ImageReducedModel1);
	CreateShapeModel(ho_ImageReducedModel1, 5, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		"auto", "none", "use_polarity", 20, 10, &hv_ShapeModel1);
	//检测区域1
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);
	PaintRegion(ho_RectangleSearchRegion1, ho_Image13, &ho_ImageResult1, 255, "fill");
	ShowImage1(ho_ImageResult1);
	//创建多样性模型
	CreateVariationModel(hv_Width1, hv_Height1, "byte", "standard", &hv_VariationModel1);

	ListFiles("D:\\Project\\WorkFigure\\2HongLangRuan\\Template", (HTuple("files").Append("follow_links")), &hv_ImageFiles);
	{
		HTuple end_val89 = (hv_ImageFiles.TupleLength()) - 1;
		HTuple step_val89 = 1;
		for (hv_J = 0; hv_J.Continue(end_val89, step_val89); hv_J += step_val89)
		{
			ReadImage(&ho_Image2, HTuple(hv_ImageFiles[hv_J]));
			Decompose3(ho_Image2, &ho_Image21, &ho_Image22, &ho_Image23);
			AffineTransImage(ho_Image21, &ho_ModelImageScale1, hv_HomMat2DScaleBig, "constant",
				"false");
			AffineTransImage(ho_ModelImageScale1, &ho_ImageRotate1, hv_HomMat2DRotate, "constant",
				"false");
			FindShapeModel(ho_ImageRotate1, hv_ShapeModel1, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
				0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_Row1, &hv_Column1, &hv_Angle1,
				&hv_Score1);
			if (0 != (int((hv_Score1.TupleLength()) == 1)))
			{
				VectorAngleToRigid(hv_Row1, hv_Column1, hv_Angle1, hv_ModelRow1, hv_ModelColumn1,
					0, &hv_HomMat2DTrain1);
				AffineTransImage(ho_ImageRotate1, &ho_ImageAffineTrans1, hv_HomMat2DTrain1,
					"constant", "false");
				ReduceDomain(ho_ImageAffineTrans1, ho_RectangleSearchRegion1, &ho_ImageReducedTrain1
				);
				SubImage(ho_ImageReducedTrain1, ho_ImageReducedModel1, &ho_ImageSub1, 1, 0);
				TrainVariationModel(ho_ImageReducedTrain1, hv_VariationModel1);
			}
		}
	}

	return 0;
}

void CTestClass::Model_Test_HongLang(HObject ho_Image)
{
	// Local iconic variables
	HObject  ho_RectangleA, ho_RectangleSearchRegion1;
	HObject  ho_EmptyRegion, ho_Image31, ho_Image32;
	HObject  ho_Image33, ho_ModelImageScale3, ho_ImageRotate2, ho_ImageAffineTransRuntime1;
	HObject  ho_ImageReducedSearch1, ho_RegionDiff1, ho_ConnectedRegions;
	HObject  ho_RegionDilation;

	// Local control variables
	HTuple  hv_wScale, hv_hScale;
    HTuple  hv_Area;
	HTuple  hv_HomMat2DIdentity, hv_HomMat2DScaleBig, hv_HomMat2DRotate;
	HTuple  hv_ImageFiles1, hv_length;
	HTuple  hv_J, hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1;
	HTuple  hv_HomMat2DRuntime1;


	hv_wScale = 1;
	hv_hScale = 1.03;
	//hv_Row11 = 83.81;
	//hv_Column11 = 1379.34;
	//hv_Row12 = 666.29;
	//hv_Column12 = 2649.1;

	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);

	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);
	HomMat2dRotate(hv_HomMat2DIdentity, hv_Mean, hv_ModelRow1, hv_ModelColumn1, &hv_HomMat2DRotate);

	PrepareVariationModel(hv_VariationModel1, m_AbsThreshold3, m_VarThreshold3);

	GenEmptyRegion(&ho_EmptyRegion);
	//检测
	Decompose3(ho_Image, &ho_Image31, &ho_Image32, &ho_Image33);
	AffineTransImage(ho_Image31, &ho_ModelImageScale3, hv_HomMat2DScaleBig, "constant", "false");
	AffineTransImage(ho_ModelImageScale3, &ho_ImageRotate2, hv_HomMat2DRotate, "constant", "false");

	FindShapeModel(ho_ModelImageScale3, hv_ShapeModel1, HTuple(-10).TupleRad(),
		HTuple(20).TupleRad(), 0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR1, &hv_ColumnR1, &hv_AngleR1, &hv_ScoreR1);
	if (0 != (int((hv_ScoreR1.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ModelRow1, hv_ModelColumn1, 0, &hv_HomMat2DRuntime1);
		AffineTransImage(ho_ModelImageScale3, &ho_ImageAffineTransRuntime1, hv_HomMat2DRuntime1, "constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime1, ho_RectangleSearchRegion1, &ho_ImageReducedSearch1);
		CompareVariationModel(ho_ImageReducedSearch1, &ho_RegionDiff1, hv_VariationModel1);
	}
	else
	{
		ho_RegionDiff1 = ho_EmptyRegion;
	}

	Connection(ho_RegionDiff1, &ho_ConnectedRegions);

	DilationCircle(ho_ConnectedRegions, &ho_RegionDilation, 7);
	GenContourRegionXld(ho_RegionDilation, &ho_Contours, "border");
	PaintXld(ho_Contours, ho_ImageAffineTransRuntime1, &ho_ImageResult, 255);

	ShowImage1(ho_ImageResult);

}

void CTestClass::SaveHongLang_Model()
{
	WriteShapeModel(hv_ShapeModel1, //'D:/张玉河/考核材料/ShapeModel1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/ShapeModel1.shm");
	WriteVariationModel(hv_VariationModel1, //'D:/张玉河/考核材料/VariationModel1.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/VariationModel1.vam");
}



//显示窗口设置
void CTestClass::SetWindow1(HObject ho_Image, CRect m_rtImage)
{
	HTuple  hv_Width, hv_Height;
	GetImageSize(ho_Image, &hv_Width, &hv_Height); 
	//设置窗口
	float fImage = hv_Width.D() / hv_Height.D();
	float fWindow = (float)m_rtImage.Width() / m_rtImage.Height();
	float Row0 = 0, Col0 = 0, Row1 = hv_Height - 1, Col1 = hv_Width - 1;
	if (fWindow > fImage)
	{
		float w = fWindow * hv_Height;
		Row0 = 0;
		Col0 = -(w - hv_Width) / 2;
		Row1 = hv_Height - 1;
		Col1 = hv_Width + (w - hv_Width) / 2;
	}
	else
	{
		float h = hv_Width / fWindow;
		Row0 = -(h - hv_Height) / 2;
		Col0 = 0;
		Row1 = hv_Height + (h - hv_Height) / 2;
		Col1 = hv_Width - 1;
	}

	m_dDispImagePartRow0 = Row0;
	m_dDispImagePartCol0 = Col0;
	m_dDispImagePartRow1 = Row1;
	m_dDispImagePartCol1 = Col1;

}

//图像缩放
void CTestClass::ScaleImage1(UINT nFlags, CRect m_rtImage, CRect rect, short zDelta, CPoint pt, HObject ho_Image)
{
	if (rect.PtInRect(pt) && ho_ImageResult.IsInitialized())
	{
		Hlong  ImagePtX, ImagePtY;
		Hlong  Row0, Col0, Row1, Col1;
		double Scale = 0.1;

		if (zDelta > 0)
		{
			ImagePtX = m_dDispImagePartCol0 + (pt.x - rect.left) / (rect.Width() - 1.0) * (m_dDispImagePartCol1 - m_dDispImagePartCol0);
			ImagePtY = m_dDispImagePartRow0 + (pt.y - rect.top) / (rect.Height() - 1.0) * (m_dDispImagePartRow1 - m_dDispImagePartRow0);
			Row0 = ImagePtY - 1 / (1 - Scale) * (ImagePtY - m_dDispImagePartRow0);
			Row1 = ImagePtY - 1 / (1 - Scale) * (ImagePtY - m_dDispImagePartRow1);
			Col0 = ImagePtX - 1 / (1 - Scale) * (ImagePtX - m_dDispImagePartCol0);
			Col1 = ImagePtX - 1 / (1 - Scale) * (ImagePtX - m_dDispImagePartCol1);

			m_dDispImagePartRow0 = Row0;
			m_dDispImagePartCol0 = Col0;
			m_dDispImagePartRow1 = Row1;
			m_dDispImagePartCol1 = Col1;
		}
		else
		{
			ImagePtX = m_dDispImagePartCol0 + (pt.x - rect.left) / (rect.Width() - 1.0) * (m_dDispImagePartCol1 - m_dDispImagePartCol0);
			ImagePtY = m_dDispImagePartRow0 + (pt.y - rect.top) / (rect.Height() - 1.0) * (m_dDispImagePartRow1 - m_dDispImagePartRow0);
			Row0 = ImagePtY - 1 / (1 + Scale) * (ImagePtY - m_dDispImagePartRow0);
			Row1 = ImagePtY - 1 / (1 + Scale) * (ImagePtY - m_dDispImagePartRow1);
			Col0 = ImagePtX - 1 / (1 + Scale) * (ImagePtX - m_dDispImagePartCol0);
			Col1 = ImagePtX - 1 / (1 + Scale) * (ImagePtX - m_dDispImagePartCol1);

			m_dDispImagePartRow0 = Row0;
			m_dDispImagePartCol0 = Col0;
			m_dDispImagePartRow1 = Row1;
			m_dDispImagePartCol1 = Col1;
		}
		ShowImage1(ho_ImageResult);
	}
}

//显示图像
void CTestClass::ShowImage1(HObject ho_Image)
{


	if (m_hWindow != 0)
	{
		SetSystem("flush_graphic", "false");
		ClearWindow(m_hWindow);
		//显示
		if (ho_Image.IsInitialized())
		{
			SetPart(m_hWindow, m_dDispImagePartRow0, m_dDispImagePartCol0, m_dDispImagePartRow1 - 1, m_dDispImagePartCol1 - 1);
			DispObj(ho_Image, m_hWindow);
		}

		SetSystem("flush_graphic", "true");
		HObject emptyObject;
		emptyObject.GenEmptyObj();
		DispObj(emptyObject, m_hWindow);
	}
}


//检测金龙鱼标签
 double* CTestClass::DetectJinLongYu(HObject  ho_Image, HTuple DisPlayMode)
{

	// Local iconic variables
	HObject  ho_RectangleA, ho_RectangleSearchRegion1;
	HObject  ho_RectangleB, ho_RectangleSearchRegion2, ho_EmptyRegion;
	HObject  ho_ImageRunScale1, ho_Image33, ho_ImageAffineTransRuntime1, result_Image;
	HObject  ho_ImageReducedSearch1, ho_RegionDiff1, ho_ImageAffineTransRuntime2;
	HObject  ho_ImageReducedSearch2, ho_RegionDiff2, ho_RegionUnion;
	

	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_HomMat2DIdentity;
	HTuple  hv_HomMat2DScaleBig, hv_Row11, hv_Column11, hv_Row12;
	HTuple  hv_Column12, hv_Row21, hv_Column21, hv_Row22, hv_Column22;
	HTuple  hv_Row31, hv_Column31, hv_Row32, hv_Column32, hv_Area;
	HTuple  hv_ModelRow1, hv_ModelColumn1, hv_ModelRow2, hv_ModelColumn2;
	HTuple  hv_ShapeModelID1, hv_VariationModelID1, hv_ShapeModelID2;
	HTuple  hv_VariationModelID2, hv_ImageFiles1, hv_length;
	HTuple  hv_J, hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1;
	HTuple  hv_HomMat2DRuntime1, hv_RowR2, hv_ColumnR2, hv_AngleR2;
	HTuple  hv_ScoreR2, hv_HomMat2DRutime2;
	

	hv_wScale = 1;
	hv_hScale = 1.18;

	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);

	//区域1
	hv_Row11 = 99.25;
	hv_Column11 = 1768.46;
	hv_Row12 = 349.92;
	hv_Column12 = 2684.94;

	//区域2
	hv_Row21 = 349.92;
	hv_Column21 = 1768.46;
	hv_Row22 = 672.2;
	hv_Column22 = 2705.42;

	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);

	GenRectangle1(&ho_RectangleB, hv_Row21, hv_Column21, hv_Row22, hv_Column22);
	AreaCenter(ho_RectangleB, &hv_Area, &hv_ModelRow2, &hv_ModelColumn2);
	CopyObj(ho_RectangleB, &ho_RectangleSearchRegion2, 1, 1);


	ReadShapeModel(//'D:/张玉河/考核材料/Model/JinLongYu/ShapeModel1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/JinLongYu/ShapeModel1.shm",
		&hv_ShapeModelID1);
	ReadVariationModel(//'D:/张玉河/考核材料/Model/JinLongYu/VariationModel1.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/JinLongYu/VariationModel1.vam",
		&hv_VariationModelID1);

	ReadShapeModel(//'D:/张玉河/考核材料/Model/JinLongYu/ShapeModel2.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/JinLongYu/ShapeModel2.shm",
		&hv_ShapeModelID2);
	ReadVariationModel(//'D:/张玉河/考核材料/Model/JinLongYu/VariationModel2.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/JinLongYu/VariationModel2.vam",
		&hv_VariationModelID2);

	PrepareVariationModel(hv_VariationModelID1, m_AbsThreshold1, m_VarThreshold1);
	PrepareVariationModel(hv_VariationModelID2, m_AbsThreshold2, m_VarThreshold2);

	GenEmptyRegion(&ho_EmptyRegion);

	CountSeconds(&hv_t1);

	AffineTransImage(ho_Image, &ho_ImageRunScale1, hv_HomMat2DScaleBig, "constant",
		"false");
	Rgb1ToGray(ho_ImageRunScale1, &ho_Image33);
	//1
	FindShapeModel(ho_Image33, hv_ShapeModelID1, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR1, &hv_ColumnR1, &hv_AngleR1,
		&hv_ScoreR1);
	if (0 != (int((hv_ScoreR1.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ModelRow1, hv_ModelColumn1,
			0, &hv_HomMat2DRuntime1);
		AffineTransImage(ho_Image33, &ho_ImageAffineTransRuntime1, hv_HomMat2DRuntime1,
			"constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime1, ho_RectangleSearchRegion1, &ho_ImageReducedSearch1
		);
		CompareVariationModel(ho_ImageReducedSearch1, &ho_RegionDiff1, hv_VariationModelID1);
	}
	else
	{
		ho_RegionDiff1 = ho_EmptyRegion;
	}

	//2
	FindShapeModel(ho_Image33, hv_ShapeModelID2, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR2, &hv_ColumnR2, &hv_AngleR2,
		&hv_ScoreR2);
	if (0 != (int((hv_ScoreR2.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR2, hv_ColumnR2, hv_AngleR2, hv_ModelRow2, hv_ModelColumn2,
			0, &hv_HomMat2DRutime2);
		AffineTransImage(ho_Image33, &ho_ImageAffineTransRuntime2, hv_HomMat2DRutime2,
			"constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime2, ho_RectangleSearchRegion2, &ho_ImageReducedSearch2
		);
		CompareVariationModel(ho_ImageReducedSearch2, &ho_RegionDiff2, hv_VariationModelID2);
	}
	else
	{
		ho_RegionDiff2 = ho_EmptyRegion;
	}

	Union2(ho_RegionDiff1, ho_RegionDiff2, &ho_RegionUnion);
	Connection(ho_RegionUnion, &ho_ConnectedRegions);
	GenContourRegionXld(ho_ConnectedRegions, &ho_Contours, "border");
	PaintXld(ho_Contours, ho_ImageAffineTransRuntime2, &ho_ImageResult, 255);
	CountSeconds(&hv_t2);
	hv_time = (hv_t2 - hv_t1) * 1000;
	double* res = new double[2];
	if (DisPlayMode == 1 && ho_RegionUnion != ho_EmptyRegion)
		ShowImage1(ho_ImageResult);
	if (DisPlayMode == 1 && ho_RegionUnion == ho_EmptyRegion)
	{
		ho_ImageResult = ho_Image;
		ShowImage1(ho_Image);
	}
	if (DisPlayMode == 0)
		ClearWindow(m_hWindow);
	if (ho_RegionUnion == ho_EmptyRegion)
		res[0] = 0;
	else
		res[0] = 1;
	res[1] = hv_time.D();
	
	return res;

}

//检测红狼烟包色差
double* CTestClass::DetectSmokeColor(HObject  ho_Image, HTuple DisPlayMode)
{
	// Local iconic variables
	HObject  ho_RectangleA, ho_RectangleSearchRegion1;
	HObject  ho_EmptyRegion,  ho_Image31, ho_Image32;
	HObject  ho_Image33, ho_ModelImageScale3, ho_ImageRotate2, ho_ImageAffineTransRuntime1;
	HObject  ho_ImageReducedSearch1, ho_RegionDiff1, ho_ConnectedRegions;
	HObject  ho_RegionDilation;

	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_Row11, hv_Column11;
	HTuple  hv_Row12, hv_Column12, hv_Area, hv_ModelRow1, hv_ModelColumn1;
	HTuple  hv_HomMat2DIdentity, hv_HomMat2DScaleBig, hv_HomMat2DRotate, hv_ShapeModelID1;
	HTuple  hv_VariationModelID1, hv_ImageFiles1, hv_length;
	HTuple  hv_J, hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1;
	HTuple  hv_HomMat2DRuntime1;


	hv_wScale = 1;
	hv_hScale = 1.03;
	hv_Row11 = 58.2591;
	hv_Column11 = 1384.46;
	hv_Row12 = 666.288;
	hv_Column12 = 2643.95;


	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	CopyObj(ho_RectangleA, &ho_RectangleSearchRegion1, 1, 1);

	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, hv_hScale / hv_wScale, 1, 0, 0, &hv_HomMat2DScaleBig);
	HomMat2dRotate(hv_HomMat2DIdentity, 0.0137337, 404.467, 2067.37, &hv_HomMat2DRotate);


	ReadShapeModel(//'D:/张玉河/考核材料/Model/HongLang/ShapeModel1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/HongLang/ShapeModel1.shm",
		&hv_ShapeModelID1);
	ReadVariationModel(//'D:/张玉河/考核材料/Model/HongLang/VariationModel1.vam'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/HongLang/VariationModel1.vam",
		&hv_VariationModelID1);

	PrepareVariationModel(hv_VariationModelID1, m_AbsThreshold3, m_VarThreshold3);

	GenEmptyRegion(&ho_EmptyRegion);
	//检测
	CountSeconds(&hv_t1);
	Decompose3(ho_Image, &ho_Image31, &ho_Image32, &ho_Image33);
	AffineTransImage(ho_Image31, &ho_ModelImageScale3, hv_HomMat2DScaleBig, "constant","false");
	AffineTransImage(ho_ModelImageScale3, &ho_ImageRotate2, hv_HomMat2DRotate, "constant","false");

	FindShapeModel(ho_ModelImageScale3, hv_ShapeModelID1, HTuple(-10).TupleRad(),
		HTuple(20).TupleRad(), 0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR1, &hv_ColumnR1,	&hv_AngleR1, &hv_ScoreR1);
	if (0 != (int((hv_ScoreR1.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ModelRow1, hv_ModelColumn1, 0, &hv_HomMat2DRuntime1);
		AffineTransImage(ho_ModelImageScale3, &ho_ImageAffineTransRuntime1, hv_HomMat2DRuntime1,"constant", "false");
		ReduceDomain(ho_ImageAffineTransRuntime1, ho_RectangleSearchRegion1, &ho_ImageReducedSearch1);
		CompareVariationModel(ho_ImageReducedSearch1, &ho_RegionDiff1, hv_VariationModelID1);
	}
	else
	{
		ho_RegionDiff1 = ho_EmptyRegion;
	}

	Connection(ho_RegionDiff1, &ho_ConnectedRegions);

	DilationCircle(ho_ConnectedRegions, &ho_RegionDilation, 7);
	GenContourRegionXld(ho_RegionDilation, &ho_Contours, "border");
	PaintXld(ho_Contours, ho_ModelImageScale3, &ho_ImageResult, 255);
	CountSeconds(&hv_t2);
	hv_time = (hv_t2 - hv_t1) * 1000;
	double* res = new double[2];

	if (DisPlayMode == 1 && ho_ConnectedRegions != ho_EmptyRegion)
		ShowImage1(ho_ImageResult);
	if (DisPlayMode == 1 && ho_ConnectedRegions == ho_EmptyRegion)
	{
		ho_ImageResult = ho_Image;
		ShowImage1(ho_ImageResult);
	}
		
	if (DisPlayMode == 0)
		ClearWindow(m_hWindow);
	if (ho_ConnectedRegions == ho_EmptyRegion)
		res[0] =  0;
	else
		res[0] = 1;
	
	res[1] = hv_time.D();

	return res;


}


//检测芙蓉王烟包标签错位
double* CTestClass::DetectFuRongWang(HObject Image, HTuple DisPlayMode)
{
	HObject  ho_ImagePart1, ho_ImageConverted1, ho_RegionMark, ho_RegionDiff;
	HObject  ho_ModelImageScale, ho_Image42, ho_ImageAffineTrans2;
	HObject  ho_ImagePart2, ho_ImageConverted2, ho_ImageSub;
	HObject  ho_Regions1, ho_RegionComplement, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_SelectedRegions1, ho_Contours;
	HObject  ho_EmptyRegion;

	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_HomMat2DIdentity;
	HTuple  hv_HomMat2DScaleBig, hv_Row11, hv_Column11, hv_Row12;
	HTuple  hv_Column12, hv_area, hv_ModelRow, hv_ModelColumn;
	HTuple  hv_ModelID, hv_ImageFiles1, hv_i, hv_Row, hv_Column;
	HTuple  hv_Angle, hv_Score, hv_HomMat2D3, hv_Area1;

	//读取图像
	hv_wScale = 1.52;
	hv_hScale = 1;
	int result = 0;
	ReadImage(&ho_ImagePart1, //'D:/张玉河/考核材料/Model/FuRongWangCuoWei/ImagePart1.bmp'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/FuRongWangCuoWei/ImagePart1.bmp");
	ConvertImageType(ho_ImagePart1, &ho_ImageConverted1, "real");
	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, 1, hv_hScale / hv_wScale, 0, 0, &hv_HomMat2DScaleBig);


	hv_Row11 = 232.374;
	hv_Column11 = 2014.22;
	hv_Row12 = 421.744;
	hv_Column12 = 2183.18;

	//定位区域
	//draw_rectangle1 (WindowHandle, Row11, Column11, Row12, Column12)
	GenRectangle1(&ho_RegionMark, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RegionMark, &hv_area, &hv_ModelRow, &hv_ModelColumn);

	ReadShapeModel(//'D:/张玉河/考核材料/Model/FuRongWangCuoWei/ShapeMode1.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/FuRongWangCuoWei/ShapeMode1.shm",
		&hv_ModelID);

	GenEmptyRegion(&ho_EmptyRegion);

	CountSeconds(&hv_t1);
	AffineTransImage(Image, &ho_ModelImageScale, hv_HomMat2DScaleBig, "constant","false");
	Rgb1ToGray(ho_ModelImageScale, &ho_Image42);
	FindShapeModel(ho_Image42, hv_ModelID, HTuple(-10).TupleRad(), HTuple(20).TupleRad(),
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_Row, &hv_Column, &hv_Angle, &hv_Score);

	if (0 != (int((hv_Score.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_Row, hv_Column, hv_Angle, hv_ModelRow, hv_ModelColumn,
			0, &hv_HomMat2D3);
		AffineTransImage(ho_Image42, &ho_ImageAffineTrans2, hv_HomMat2D3, "constant",
			"false");
		CropPart(ho_ImageAffineTrans2, &ho_ImagePart2, hv_Row11, hv_Column11, hv_Column12 - hv_Column11,
			hv_Row12 - hv_Row11);
		ConvertImageType(ho_ImagePart2, &ho_ImageConverted2, "real");
		SubImage(ho_ImageConverted2, ho_ImageConverted1, &ho_ImageSub, 1, 0);

		Threshold(ho_ImageSub, &ho_Regions1, m_MinThreshold2, m_MaxThreshold2);

		Complement(ho_Regions1, &ho_RegionComplement);
		Connection(ho_RegionComplement, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "row", "and", 5, 90);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions1, "area", "and", 110, 1500);
		GenContourRegionXld(ho_SelectedRegions1, &ho_Contours, "border");
		PaintXld(ho_Contours, ho_ImagePart2, &ho_ImageResult, 255);
		AreaCenter(ho_SelectedRegions1, &hv_Area1, &hv_Row, &hv_Column);
		if (0 != (int((hv_Area1.TupleLength()) == 0)))
		{
			result = 0;
			ho_ImageResult = Image;
		}
			
		else
			result = 1;
	}
	CountSeconds(&hv_t2);
	hv_time = (hv_t2 - hv_t1) * 1000;

	double* res = new double[2];

	if (DisPlayMode == 1 && result == 1)
	{
		ClearWindow(m_hWindow);
		SetPart(m_hWindow, m_dDispImagePartRow0, m_dDispImagePartCol0 - 3000, m_dDispImagePartRow1 - 1, m_dDispImagePartCol1 - 2000);
		DispObj(ho_ImageResult, m_hWindow);
	}
	if (DisPlayMode == 1 && result == 0)
		ShowImage1(Image);
	if (DisPlayMode == 0)
		ClearWindow(m_hWindow);
	if (result == 0)
		res[0] = 0;
	else
		res[0] = 1;

	res[1] = hv_time.D();
	return res;

}




//检测黄鹤楼烟包拉墨
double* CTestClass::DetectHuangHeLou(HObject Image, HTuple DisPlayMode)
{
	HObject  ho_ImagePart1, ho_RectangleA, ho_ImageConverted1, ho_SelectedRegions2;
	HObject  ho_ImageRunScale1, ho_Image33, ho_ImageAffineTransRuntime1;
	HObject  ho_ImagePart2, ho_ImageConverted2, ho_ImageSub;
	HObject  ho_Regions1, ho_RegionComplement, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_SelectedRegions1, ho_EmptyRegion;

	// Local control variables
	HTuple  hv_wScale, hv_hScale, hv_HomMat2DIdentity;
	HTuple  hv_HomMat2DScaleBig, hv_Row11, hv_Column11, hv_Row12;
	HTuple  hv_Column12, hv_Area, hv_ModelRow1, hv_ModelColumn1;
	HTuple  hv_ShapeModelID1, hv_ImageFiles1, hv_length, hv_J;
	HTuple  hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ScoreR1, hv_HomMat2DRuntime1;
	HTuple  hv_Area1, hv_Row, hv_Column;
	//读取图像
	hv_wScale = 0.1;
	hv_hScale = 0.192;
	int result = 0;

	ReadImage(&ho_ImagePart1, //'D:/张玉河/考核材料/Model/HuangHeLouLaMo/ImagePart1.bmp'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/HuangHeLouLaMo/ImagePart1.bmp");
	ConvertImageType(ho_ImagePart1, &ho_ImageConverted1, "real");
	HomMat2dIdentity(&hv_HomMat2DIdentity);
	HomMat2dScale(hv_HomMat2DIdentity, 1, hv_wScale / hv_hScale, 0, 0, &hv_HomMat2DScaleBig);

	//创建模型1
	hv_Row11 = 191.106;
	hv_Column11 = 713.74;
	hv_Row12 = 548.77;
	hv_Column12 = 887.82;

	GenRectangle1(&ho_RectangleA, hv_Row11, hv_Column11, hv_Row12, hv_Column12);
	AreaCenter(ho_RectangleA, &hv_Area, &hv_ModelRow1, &hv_ModelColumn1);
	

	ReadShapeModel(//'D:/张玉河/考核材料/Model/HuangHeLouLaMo/ShapeModel.shm'
		"D:/\345\274\240\347\216\211\346\262\263/\350\200\203\346\240\270\346\235\220\346\226\231/Model/HuangHeLouLaMo/ShapeModel.shm",
		&hv_ShapeModelID1);

	GenEmptyRegion(&ho_EmptyRegion);
	//检测
	CountSeconds(&hv_t1);
	AffineTransImage(Image, &ho_ImageRunScale1, hv_HomMat2DScaleBig, "constant","false");
	Rgb1ToGray(ho_ImageRunScale1, &ho_Image33);

	FindShapeModel(ho_Image33, hv_ShapeModelID1, HTuple(-10).TupleRad(), HTuple(20).TupleRad(), 
		0.5, 1, 0.5, "least_squares", 0, 0.9, &hv_RowR1, &hv_ColumnR1, &hv_AngleR1,&hv_ScoreR1);
	if (0 != (int((hv_ScoreR1.TupleLength()) == 1)))
	{
		VectorAngleToRigid(hv_RowR1, hv_ColumnR1, hv_AngleR1, hv_ModelRow1, hv_ModelColumn1,	0, &hv_HomMat2DRuntime1);
		AffineTransImage(ho_Image33, &ho_ImageAffineTransRuntime1, hv_HomMat2DRuntime1,	"constant", "false");
		CropPart(ho_ImageAffineTransRuntime1, &ho_ImagePart2, hv_Row11, hv_Column11,hv_Column12 - hv_Column11, hv_Row12 - hv_Row11);
		ConvertImageType(ho_ImagePart2, &ho_ImageConverted2, "real");
		SubImage(ho_ImageConverted2, ho_ImageConverted1, &ho_ImageSub, 1, 0);
		Threshold(ho_ImageSub, &ho_Regions1, m_MinThreshold1, m_MaxThreshold1);
		Complement(ho_Regions1, &ho_RegionComplement);
		Connection(ho_RegionComplement, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "height", "and", 5, 130);
		SelectShape(ho_SelectedRegions, &ho_SelectedRegions1, "row", "and", 5, 80);
		SelectShape(ho_SelectedRegions1, &ho_SelectedRegions2, "column", "and", 106,133);
		GenContourRegionXld(ho_SelectedRegions2, &ho_Contours, "border");
		PaintXld(ho_Contours, ho_ImagePart2, &ho_ImageResult, 255);
	    
		AreaCenter(ho_SelectedRegions2, &hv_Area1, &hv_Row, &hv_Column);
		if (0 != (int((hv_Area1.TupleLength()) == 0)))
		{
			result = 0;
			ho_ImageResult = Image;
		}
		else
			result = 1;
	}

	CountSeconds(&hv_t2);
	hv_time = (hv_t2 - hv_t1) * 1000;

	double* res = new double[2];

	if (DisPlayMode == 1 && result == 1)
	{
		ClearWindow(m_hWindow);
		SetPart(m_hWindow, m_dDispImagePartRow0, m_dDispImagePartCol0 - 3000, m_dDispImagePartRow1 - 1, m_dDispImagePartCol1 - 2000);
		DispObj(ho_ImageResult, m_hWindow);
	}
	if (DisPlayMode == 1 && result == 0)
		ShowImage1(Image);
	if (DisPlayMode == 0)
		ClearWindow(m_hWindow);
	if (result == 0)
		res[0] = 0;
	else
		res[0] = 1;

	res[1] = hv_time.D();
	return res;

}


