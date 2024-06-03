
// ImageProc2024_20201544_1View.cpp: CImageProc2024202015441View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProc2024_20201544_1.h"

# include "CAngleInDialog.h"
# include <Vfw.h>
#endif

#include "ImageProc2024_20201544_1Doc.h"
#include "ImageProc2024_20201544_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProc2024202015441View

IMPLEMENT_DYNCREATE(CImageProc2024202015441View, CScrollView)

BEGIN_MESSAGE_MAP(CImageProc2024202015441View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
//	ON_COMMAND(ID_MESSAGE_PRINT, &CImageProc2024202015441View::OnMessagePrint)
//ON_COMMAND(ID_32774, &CImageProc2024202015441View::OnPixelAdd)
ON_COMMAND(ID_PIXEL_SUB, &CImageProc2024202015441View::OnPixelSub)
ON_COMMAND(ID_PIXEL_MUL, &CImageProc2024202015441View::OnPixelMul)
ON_COMMAND(ID_PIXEL_DIV, &CImageProc2024202015441View::OnPixelDiv)
ON_COMMAND(ID_PIXEL_ADD, &CImageProc2024202015441View::OnPixelAdd)
//ON_COMMAND(ID_32782, &CImageProc2024202015441View::OnPixelHistoEqual)
//ON_COMMAND(ID_32783, &CImageProc2024202015441View::PixelStretching)
ON_COMMAND(ID_PIXEL_BINARIZATION, &CImageProc2024202015441View::OnPixelBinarization)
ON_COMMAND(ID_PIXEL_HISTO_EQUAL, &CImageProc2024202015441View::OnPixelHistoEqual)
ON_COMMAND(ID_PIXEL_STRETCHING, &CImageProc2024202015441View::OnPixelStretching)
ON_COMMAND(ID_PIXEL_TWO_IMAGE_ADD, &CImageProc2024202015441View::OnPixelTwoImageAdd)
ON_COMMAND(ID_PIXEL_TWO_IMAGE_SUB, &CImageProc2024202015441View::OnPixelTwoImageSub)
ON_COMMAND(ID_REGION_MEANING, &CImageProc2024202015441View::OnRegionMeaning)
ON_COMMAND(ID_REGION_SHARPENING, &CImageProc2024202015441View::OnRegionSharpening)
ON_COMMAND(ID_REGION_EMBOSSING, &CImageProc2024202015441View::OnRegionEmbossing)
ON_COMMAND(ID_REGION_PREWITT, &CImageProc2024202015441View::OnRegionPrewitt)
ON_COMMAND(ID_REGION_ROBERTS, &CImageProc2024202015441View::OnRegionRoberts)
ON_COMMAND(ID_REGION_SOBEL, &CImageProc2024202015441View::OnRegionSobel)
ON_COMMAND(ID_REGION_AVERAGE_FILTERING, &CImageProc2024202015441View::OnRegionAverageFiltering)
ON_COMMAND(ID_REGION_MEDIAN_FILTERING, &CImageProc2024202015441View::OnRegionMedianFiltering)
ON_COMMAND(ID_MOPOLOGY_COLOR_GRAY, &CImageProc2024202015441View::OnMopologyColorGray)
ON_COMMAND(ID_MOPOLOGY_BINARIZATION, &CImageProc2024202015441View::OnMopologyBinarization)
ON_COMMAND(ID_MOPOLOGY_EROSION, &CImageProc2024202015441View::OnMopologyErosion)
ON_COMMAND(ID_MOPOLOGY_DIALATION, &CImageProc2024202015441View::OnMopologyDialation)
ON_COMMAND(ID_GEOMETRY_ZOOMIN_PIXEL_COPY, &CImageProc2024202015441View::OnGeometryZoominPixelCopy)
ON_COMMAND(ID_GEOMETRY_ZOOMIN_INTERPOLATION, &CImageProc2024202015441View::OnGeometryZoominInterpolation)
ON_COMMAND(ID_MOPOLOGY_OPENING, &CImageProc2024202015441View::OnMopologyOpening)
ON_COMMAND(ID_MOPOLOGY_CLOSING, &CImageProc2024202015441View::OnMopologyClosing)
ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING, &CImageProc2024202015441View::OnGeometryZoomoutSubsampling)
ON_COMMAND(ID_GEOMETRY_ZOOMOUT_MEAN_SUB, &CImageProc2024202015441View::OnGeometryZoomoutMeanSub)
ON_COMMAND(ID_GEOMETRY_ZOOMOUT_AVG, &CImageProc2024202015441View::OnGeometryZoomoutAvg)
ON_COMMAND(ID_GEOMETRY_ROTATE, &CImageProc2024202015441View::OnGeometryRotate)
ON_COMMAND(ID_GEOMETRY_MIRROR, &CImageProc2024202015441View::OnGeometryMirror)
ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING, &CImageProc2024202015441View::OnGeometryZoomoutSubsampling)
ON_COMMAND(ID_GEOMETRY_FLIP, &CImageProc2024202015441View::OnGeometryFlip)
ON_COMMAND(ID_GEOMETRY_WARPING, &CImageProc2024202015441View::OnGeometryWarping)
ON_COMMAND(ID_GEOMETRY_MORPHING, &CImageProc2024202015441View::OnGeometryMorphing)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_COMMAND(ID_AVI_VIEW, &CImageProc2024202015441View::OnAviView)
END_MESSAGE_MAP()

// CImageProc2024202015441View 생성/소멸

CImageProc2024202015441View::CImageProc2024202015441View() noexcept
{
	bAviMode = false;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProc2024202015441View::~CImageProc2024202015441View()
{
}

BOOL CImageProc2024202015441View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImageProc2024202015441View 그리기

void CImageProc2024202015441View::OnDraw(CDC* pDC)
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int x, y;

	if (bAviMode) {
		LoadAVIFile(pDC);
		bAviMode = false;
		return;
	}

	if (pDoc->InputImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(x, y, 
						RGB(pDoc->InputImg[y][x], pDoc->InputImg[y][x], pDoc->InputImg[y][x]));
		}
		else
		{
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(x, y, 
						RGB(pDoc->InputImg[y][3*x+0], pDoc->InputImg[y][3 * x + 1], pDoc->InputImg[y][3 * x + 2]));
		}
	}

	if (pDoc->ResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, 
						RGB(pDoc->ResultImg[y][x], pDoc->ResultImg[y][x], pDoc->ResultImg[y][x]));
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, 
						RGB(pDoc->ResultImg[y][3 * x + 0], pDoc->ResultImg[y][3 * x + 1], pDoc->ResultImg[y][3 * x + 2]));
		}
	}

	if (pDoc->gResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x, pDoc->ImageWidth + 20 + y,
						RGB(pDoc->gResultImg[y][x], pDoc->gResultImg[y][x], pDoc->gResultImg[y][x]));
		}
		else {
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x,pDoc->ImageWidth + 20 + y,
						RGB(pDoc->gResultImg[y][3 * x + 0], pDoc->gResultImg[y][3 * x + 1], pDoc->gResultImg[y][3 * x + 2]));
		}
	}


	if (pDoc->InputImg2 != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel((pDoc->ImageWidth + 20) * 2 + x, y,RGB(pDoc->InputImg2[y][x], pDoc->InputImg2[y][x], pDoc->InputImg2[y][x]));
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel((pDoc->ImageWidth + 20) * 2 + x, y,RGB(pDoc->InputImg2[y][3 * x + 0], pDoc->InputImg2[y][3 * x + 1], pDoc->InputImg2[y][3 * x + 2]));
		}
	}
}
	

void CImageProc2024202015441View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = 2048;
	sizeTotal.cy = 1024;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImageProc2024202015441View 인쇄

BOOL CImageProc2024202015441View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProc2024202015441View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProc2024202015441View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageProc2024202015441View 진단

#ifdef _DEBUG
void CImageProc2024202015441View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProc2024202015441View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProc2024202015441Doc* CImageProc2024202015441View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProc2024202015441Doc)));
	return (CImageProc2024202015441Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProc2024202015441View 메시지 처리기


//void CImageProc2024202015441View::OnMessagePrint()
//{
//
//	AfxMessageBox("안녕하세요");
//}




void CImageProc2024202015441View::OnPixelSub()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	int value;
	int x, y;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] - 40;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;

		}
	Invalidate();
}


void CImageProc2024202015441View::OnPixelMul()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int value;
	int x, y;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] * 1.5;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;

		}
	Invalidate();
}


void CImageProc2024202015441View::OnPixelDiv()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL)	return;

	int value;
	int x, y;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] /1.4;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;

		}
	Invalidate();
}


void CImageProc2024202015441View::OnPixelAdd()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;
	int value;
	int x, y;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
				value = pDoc->InputImg[y][x] + 40;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
		}
	Invalidate();
}

void CImageProc2024202015441View::OnPixelHistoEqual()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	int x, y, k;
	int hist[256], sum[256];
	int acc_hist = 0;
	int N = pDoc->ImageHeight * pDoc->ImageWidth;//
	for (k = 0;k < 256;k++)
		hist[k] = 0;

	//히스토그램 구하기
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++)//고쳐야함
			hist[pDoc->InputImg[y][x]]++;
	//누적분포 구하기
	for (k = 0;k < 256;k++) {
		acc_hist += hist[k];
		sum[k] = acc_hist;
	}

	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++) {//고쳐야함
			k = pDoc->InputImg[y][x];
			pDoc->ResultImg[y][x] = (float)sum[k] * 255 / N;    //나눗셈 주의!!!! sum[k]/N하면 0.xx 나오기 때문에 정수처리 되어서 0이됨.!
			//해결방법은 간단 * 255를 먼저!
			//  OR 형변환 해주는게 좋을 것 같다!
			//  바꿔주면 좋아함 ㅋ ㅋ ㅋ 
		}

	Invalidate();


}


void CImageProc2024202015441View::OnPixelStretching()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	int x, y;
	int minPixelValue = 255;
	int maxPixelValue = 0;

	// 이미지의 최소 및 최대 픽셀 값을 찾기
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			int pixelValue = pDoc->InputImg[y][x];
			if (pixelValue < minPixelValue) {
				minPixelValue = pixelValue;
			}
			if (pixelValue > maxPixelValue) {
				maxPixelValue = pixelValue;
			}
		}
	}

	// 명암 대비 스트레칭 수식을 이용하여 픽셀 값 조정
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			int pixelValue = pDoc->InputImg[y][x];
			float stretchedPixelValue = ((float)(pixelValue - minPixelValue) / (maxPixelValue - minPixelValue)) * 255.0;

			// 결과 이미지에 적용
			pDoc->ResultImg[y][x] = (int)stretchedPixelValue;
		}
	}

	Invalidate();
}


//원본 void CImageProc2024202015441View::OnPixelStretching()// !과제 !! cpp파일로 제출!@!!@!@!@ 매우 중요!!
//{

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}







void CImageProc2024202015441View::OnPixelBinarization()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y;
	int threshold = 128;

	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++) {
			if (pDoc->InputImg[y][x] >= threshold)
				pDoc->ResultImg[y][x] = 255;
			else
				pDoc->ResultImg[y][x] = 0;
		}
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CImageProc2024202015441View::OnPixelTwoImageAdd()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	
	CFileDialog dlg(true);//MFC 에서는 대소문자 똑같이 받아들인다!
	CFile file;

	if (dlg.DoModal() == IDCANCEL) return;

	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSecondImageFile(ar);
	file.Close();

	int x, y;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++) {
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = 0.5 * pDoc->InputImg[y][x] + 0.5 * pDoc->InputImg2[y][x];		
			}
			/*else {
				pDoc->ResultImg[y][3 * x + 0] = 0.5 * pDoc->InputImg[y][3 * x + 0] + 0.5 * pDoc->InputImg2[y][3 * x + 0];
				pDoc->ResultImg[y][3 * x + 1] = 0.5 * pDoc->InputImg[y][3 * x + 1] + 0.5 * pDoc->InputImg2[y][3 * x + 1];
				pDoc->ResultImg[y][3 * x + 2] = 0.5 * pDoc->InputImg[y][3 * x + 2] + 0.5 * pDoc->InputImg2[y][3 * x + 2];
			}*/
		}
	Invalidate();
}


void CImageProc2024202015441View::OnPixelTwoImageSub()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	CFileDialog dlg(true);//MFC 에서는 대소문자 똑같이 받아들인다!
	CFile file;

	if (dlg.DoModal() == IDCANCEL) return;

	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSecondImageFile(ar);
	file.Close();

	int x, y;
	int value;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++) {
			value = abs(pDoc->InputImg[y][x] - pDoc->InputImg2[y][x]);
			if (value > 24) value = 255;
			else value = 0;
			pDoc->ResultImg[y][x] = value;

		}
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProc2024202015441View::OnRegionMeaning()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float mask[3][3] = {
	{1 / 9.0f,1 / 9.0f,1 / 9.0f},
	{ 1 / 9.0f,1 / 9.0f,1 / 9.0f },
	{ 1 / 9.0f,1 / 9.0f,1 / 9.0f }
	};  //교수님은 1/9.0 d이렇게 하심 double 로 남는다하심

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, mask, 0, pDoc->depth);
	Invalidate();
}


void CImageProc2024202015441View::Convolve(unsigned char** InImg, unsigned char** ResImg, int cols, int rows, float mask[][3] , int bias, int depth)
{
	int x, y, i, j; //j  가 y 축이다!
	int sum;	
	int rsum, gsum, bsum;
	// 0,0 부터 시작하면 오류가 날 수 있기 때문에 1,1부터 시작!!!
	for (y = 1;y < rows - 1;y++)// row 열 collum 행!!!아 이거 맨날 헷갈려 ㅋㅋㅋ레전드 
		for (x = 1;x < cols - 1;x++) {
			if (depth == 1)
			{
				sum = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						sum += InImg[y + j][x + i] * mask[j + 1][i + 1];
					}
				sum += bias;

				if (sum > 255)
					sum = 255;
				else if (sum < 0)
					sum = 0;
				ResImg[y][x] = sum;
			}////여기까지가 흑백!!!!!
			else {
				rsum = 0, gsum = 0, bsum = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						rsum += InImg[y + j][3*(x + i)+0] * mask[j + 1][i + 1];
						gsum += InImg[y + j][3 * (x + i) + 1] * mask[j + 1][i + 1];
						bsum += InImg[y + j][3 * (x + i) + 2] * mask[j + 1][i + 1];
					}
				rsum += bias, gsum += bias, bsum += bias;

				if (rsum > 255)
					rsum = 255;
				else if (rsum < 0)
					rsum = 0;

				if (gsum > 255)
					gsum = 255;
				else if (gsum < 0)
					gsum = 0;

				if (bsum > 255)
					bsum = 255;
				else if (bsum < 0)
					bsum = 0;
				ResImg[y][3 * x + 0] = rsum;
				ResImg[y][3 * x + 1] = gsum;
				ResImg[y][3 * x + 2] = bsum;
			}

		}
}


void CImageProc2024202015441View::OnRegionSharpening()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float mask[3][3] = {
	{0,-1,0},
	{-1,5,-1},
	{0,-1,0}
	};  //mask 만 바꾸면 됨!!!

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, mask, 0, pDoc->depth);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProc2024202015441View::OnRegionEmbossing()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float mask[3][3] = {
	{-1,0,0},
	{0,0,0},
	{0,0,1}
	};  //mask 만 바꾸면 됨!!!

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, mask, 128, pDoc->depth);//bias를 128로 하면 그 이상은 하얗게 
	//그이하는 검게 해서 128이 약간 경계느낌????엠보싱. 재밌네.허
	Invalidate();
}


void CImageProc2024202015441View::OnRegionPrewitt()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float maskH[3][3] = {
	{-1,-1,-1},
	{0,0,0},
	{1,1,1}
	};
	float maskV[3][3] = {
	{1,0,-1},
	{1,0,-1},
	{1,0,-1}
	};//mask 만 바꾸면 됨!!!

	unsigned char** Er, ** Ec;
	int i;
	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));//메모리가 세로방향의 주소값생성

	for (i = 0;i < pDoc->ImageHeight;i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}



	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, maskV, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, maskH, 0, pDoc->depth);

	int x, y;
	int sum;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth*pDoc->depth;x++) {
			sum = sqrt(Er[y][x] * Er[y][x] + Ec[y][x]* Ec[y][x]);
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			pDoc->ResultImg[y][x] = sum;//
		}
	for (i = 0;i < pDoc->ImageHeight;i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);
	Invalidate();
	
}


void CImageProc2024202015441View::OnRegionRoberts()//과제
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float maskH[3][3] = {
	{-1,0,0},
	{0,1,0},
	{0,0,0}
	};
	float maskV[3][3] = {
	{0,0,-1},
	{0,1,0},
	{0,0,0}
	};//mask 만 바꾸면 됨!!!

	unsigned char** Er, ** Ec;
	int i;
	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));//메모리가 세로방향의 주소값생성

	for (i = 0;i < pDoc->ImageHeight;i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}



	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, maskV, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, maskH, 0, pDoc->depth);

	int x, y;
	int sum;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth * pDoc->depth;x++) {
			sum = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			pDoc->ResultImg[y][x] = sum;//
		}
	for (i = 0;i < pDoc->ImageHeight;i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);
	Invalidate();

}


void CImageProc2024202015441View::OnRegionSobel()//과제
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float maskH[3][3] = {
	{-1,-2,-1},
	{0,0,0},
	{1,2,1}
	};
	float maskV[3][3] = {
	{1,0,-1},
	{2,0,-2},
	{1,0,-1}
	};//mask 만 바꾸면 됨!!!

	unsigned char** Er, ** Ec;
	int i;
	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));//메모리가 세로방향의 주소값생성

	for (i = 0;i < pDoc->ImageHeight;i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}



	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, maskV, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, maskH, 0, pDoc->depth);

	int x, y;
	int sum;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth * pDoc->depth;x++) {
			sum = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			pDoc->ResultImg[y][x] = sum;//
		}
	for (i = 0;i < pDoc->ImageHeight;i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);
	Invalidate();

}


void CImageProc2024202015441View::OnRegionAverageFiltering()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y,i,j;
	int sum,rsum,gsum,bsum;
	// 5*5 영역의 평균값

	for (y = 2;y < pDoc->ImageHeight-2;y++)
		for (x = 2;x < pDoc->ImageWidth-2;x++) {
			if (pDoc->depth == 1) {
				sum = 0;
				for (j = -2;j <= 2;j++)
					for (i = -2;i <= 2;i++) {
						sum += pDoc->InputImg[y + j][x + i];
					}
				sum /= 25;
				if (sum > 255)
					sum = 255;
				else if (sum < 0)
					sum = 0;
				pDoc->ResultImg[y][x] = sum;
			}
			else {
				rsum = 0; gsum = 0, bsum = 0;
				for (j = -2;j <= 2;j++)
					for (i = -2;i <= 2;i++) {
						rsum += pDoc->InputImg[y + j][3 * (x + i) + 0];//x+i x+i가 좌표값!!!
						gsum += pDoc->InputImg[y + j][3 * (x + i) + 1];
						bsum += pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
				rsum /= 25; gsum /= 25, bsum /= 25;
				if (rsum > 255)
					rsum = 255;				
				else if (rsum < 0)
					rsum = 0;

				if (gsum > 255)
					gsum = 255;
				else if (gsum < 0)
					gsum = 0;

				if (bsum > 255)
					bsum = 255;
				else if (bsum < 0)
					bsum = 0;
				pDoc->ResultImg[y][3 * x + 0] = rsum;
				pDoc->ResultImg[y][3 * x + 1] = gsum;
				pDoc->ResultImg[y][3 * x + 2] = bsum;
			}
		}
	Invalidate();
}


void CImageProc2024202015441View::OnRegionMedianFiltering()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y, i, j;
	int n[9];
	int temp;
	for (y = 1;y < pDoc->ImageHeight - 1;y++)
		for (x = 1;x < pDoc->ImageWidth - 1;x++) {
			for (j = -1;j <= 1;j++)
				for (i = -1;i <= 1;i++) {
					if (pDoc->depth == 1) {
						//n[(j+1)*3+(i+1)] = pDoc->InputImg[y + j][x + i] 이것도 가능하다!!
						n[0] = pDoc->InputImg[y - 1][x - 1];
						n[1] = pDoc->InputImg[y - 1][x + 0];
						n[2] = pDoc->InputImg[y - 1][x + 1];
						n[3] = pDoc->InputImg[y - 0][x - 1];
						n[4] = pDoc->InputImg[y - 0][x + 0];
						n[5] = pDoc->InputImg[y - 0][x + 1];
						n[6] = pDoc->InputImg[y + 1][x - 1];
						n[7] = pDoc->InputImg[y + 1][x + 0];
						n[8] = pDoc->InputImg[y + 1][x + 1];
						//큰거가 8부터쌓이고 그다음 7에쌓이고....이런식으로!
						//버블정렬=오름차순

						for (i = 8;i > 0;i--)
							for (j = 0;j < i;j++) {
								if (n[j] > n[j + 1]) {
									temp = n[j + 1];
									n[j + 1] = n[j];
									n[j] = temp;
								}
								pDoc->ResultImg[y][x] = n[4];
							}
					}
					else {
						n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 0];
						n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 0];
						n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 0];
						n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 0];
						n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 0];
						n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 0];
						n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 0];
						n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 0];
						n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 0];
						pDoc->ResultImg[y][x * 3 + 0] = n[4];

						n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 1];
						n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 1];
						n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 1];
						n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 1];
						n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 1];
						n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 1];
						n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 1];
						n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 1];
						n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 1];
						pDoc->ResultImg[y][x * 3 + 1] = n[4];

						n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 2];
						n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 2];
						n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 2];
						n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 2];
						n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 2];
						n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 2];
						n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 2];
						n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 2];
						n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 2];
						pDoc->ResultImg[y][x * 3 + 2] = n[4];
					}
				}
		}
		Invalidate();
}

void CImageProc2024202015441View::OnMopologyColorGray()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	if (pDoc->depth == 1)
		return;

	int x, y;
	int gray;

	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth * pDoc->depth;x++) {
			gray = (pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2]) / 3;
			pDoc->InputImg[y][3 * x + 0] = gray;
			pDoc->InputImg[y][3 * x + 1] = gray;
			pDoc->InputImg[y][3 * x + 2] = gray;
		}
	Invalidate();
}


void CImageProc2024202015441View::OnMopologyBinarization()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y;
	int threshold = 100;

	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++) {
			if (pDoc->depth == 1) {
				if (pDoc->InputImg[y][x] >= threshold)
					pDoc->InputImg[y][x] = 255;
				else
					pDoc->InputImg[y][x] = 0;
			}
			else {
				if (pDoc->InputImg[y][3 * x + 0] >= threshold) {
					pDoc->InputImg[y][3 * x + 0] = 255;
					pDoc->InputImg[y][3 * x + 1] = 255;
					pDoc->InputImg[y][3 * x + 2] = 255;
				}
				else {
					pDoc->InputImg[y][3 * x + 0] = 0;
					pDoc->InputImg[y][3 * x + 1] = 0;
					pDoc->InputImg[y][3 * x + 2] = 0;
				}
			}
		}
	Invalidate();
}


void CImageProc2024202015441View::OnMopologyErosion()
{

	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y, j, i;
	int min, rmin, gmin, bmin;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				min = 255;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][x + i] < min)
							min = pDoc->InputImg[y + j][x + i];
					}
				pDoc->ResultImg[y][x] = min;
			}
			else {
				rmin = 255; gmin = 255; bmin = 255;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][3*(x + i)] < rmin) rmin = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3*(x + i)] < gmin) gmin = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3*(x + i)] < bmin) bmin = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
			}
		}
	Invalidate();
}


void CImageProc2024202015441View::OnMopologyDialation()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y, j, i;
	int max,rmax,bmax,gmax;
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				max = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][x + i] > max)
							max = pDoc->InputImg[y + j][x + i];
					}
				pDoc->ResultImg[y][x] = max;
			}
			else {
				rmax = 0; gmax = 0; bmax = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][3 * (x + i)] > rmax) rmax = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3 * (x + i)] > gmax) gmax = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3 * (x + i)] > bmax) bmax = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
			}
		}
	Invalidate();
}


void CImageProc2024202015441View::OnGeometryZoominPixelCopy()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int scale_x = 3;
	int scale_y = 2;
	int i, j, x, y;
	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->ImageWidth * scale_x;
	pDoc->gImageHeight = pDoc->ImageHeight * scale_y;

	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//전방향사상

	/*for (y = 0; y < pDoc->ImageHeight; y++)
	   for (x = 0; x < pDoc->ImageWidth; x++)
	   {
		  for(i=0; j<scale_y; j++)
			 for(i = 0; i < scale_x; i ++)
				  pDoc->gResultImg[y*scale_y+j][x*scale_x+i] = pDoc->Inputimg[y][x];
	   }*/

	   //역방향사상

	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->InputImg[y / scale_y][x / scale_x];
			else
			{
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y / scale_y][3 * (x / scale_x) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y / scale_y][3 * (x / scale_x) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y / scale_y][3 * (x / scale_x) + 2];
			}
		}
	Invalidate();
}



/*CAngleInDialog dig
dlg.m_iAngle = angle;
if (dlg.DoModal(); == IDCANCEL) return;
angle = dlg.m_iAngle;*/

//void CImageProc2024202015441View::OnGeometryZoominInterpolation()
//{
//	CImageProc2024202015441Doc* pDoc = GetDocument();
//	
//
//
//	int i, j, x, y;
//	if (pDoc->gResultImg != NULL) {
//			for (i = 0; i < pDoc->gImageHeight; i++) {
//				free(pDoc->gResultImg[i]);
//			}
//		free(pDoc->gResultImg);
//		pDoc->gResultImg = NULL;
//	}
//	//메모리 할당함 +1 로 메모리 할당함
//
//	pDoc->gImageWidth = pDoc->ImageWidth * scale_x;
//	pDoc->gImageHeight = pDoc->ImageHeight * scale_y;
//	
//	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
//	for (i = 0; i < pDoc->gImageHeight; i++)
//	{
//		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
//	}
//	   //역방향사상
//
//	for (y = 0; y < pDoc->gImageHeight; y++)
//		for (x = 0; x < pDoc->gImageWidth; x++)
//		{
//			src_x = x / scale_x;
//			src_y = y / scale_y;
//			alpha = src_x - (int)src_x;
//			beta = src_y - (int)src_y;
//			Ax = (int)src_x;
//			Ay = (int)src_y;
//			Bx = Ax + 1;
//			By = Ay;
//			Cx = Ax;
//			Cy = Ay + 1;
//			Dx = Ax + 1;
//			Dy = Ay + 1;
//
//			if (Bx > pDoc->gImageWidth - 1)
//				Bx = pDoc->gImageWidth - 1;
//			if (Cy > pDoc->gImageHeight - 1)
//				Cy = pDoc->gImageHeight- 1;
//			if (Dx > pDoc->gImageWidth - 1)
//				Dx = pDoc->gImageWidth - 1;
//			if (Dy > pDoc->gImageHeight- 1)
//				Dy = pDoc->gImageHeight - 1;
//
//			if (pDoc->depth == 1) {
//				E = (1 - alpha) * pDoc->InputImg[Ay][Ax] + alpha * pDoc->InputImg[By][Bx];
//				F = (1 - alpha) * pDoc->InputImg[Cy][Cx] + alpha * pDoc->InputImg[Dy][Dx];
//				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
//			}
//			else
//			{
//				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 0] + alpha * pDoc->InputImg[By][3 * Bx + 0];
//				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 0] + alpha * pDoc->InputImg[Dy][3 * Dx + 0];
//				pDoc->gResultImg[y][3 * x + 0] = (1 - beta) * E + beta * F;
//
//				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 1] + alpha * pDoc->InputImg[By][3 * Bx + 1];
//				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 1] + alpha * pDoc->InputImg[Dy][3 * Dx + 1];
//				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;
//
//				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 1] + alpha * pDoc->InputImg[By][3 * Bx + 1];
//				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 1] + alpha * pDoc->InputImg[Dy][3 * Dx + 1];
//				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;
//
//				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 2] + alpha * pDoc->InputImg[By][3 * Bx + 2];
//				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 2] + alpha * pDoc->InputImg[Dy][3 * Dx + 2];
//				pDoc->gResultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
//			}
//		}
//	Invalidate();
//}


void CImageProc2024202015441View::OnGeometryZoominInterpolation()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	float scale_x = 1.7;
	float scale_y = 1.2;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;

	int i, j, x, y;
	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->ImageWidth * scale_x;
	pDoc->gImageHeight = pDoc->ImageHeight * scale_y;

	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	for (y = 0; y < pDoc->gImageHeight; y++)
	{
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			src_x = x / scale_x;
			src_y = y / scale_y;
			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;
			Ax = (int)src_x;
			Ay = (int)src_y;
			Bx = Ax + 1;
			By = Ay;
			Cx = Ax;
			Cy = Ay + 1;
			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->gImageWidth - 1)
				Bx = pDoc->gImageWidth - 1;
			if (Cy > pDoc->gImageHeight - 1)
				Cy = pDoc->gImageHeight - 1;
			if (Dx > pDoc->gImageWidth - 1)
				Dx = pDoc->gImageWidth - 1;
			if (Dy > pDoc->gImageHeight - 1)
				Dy = pDoc->gImageHeight - 1;

			if (pDoc->depth == 1) {
				E = (1 - alpha) * pDoc->InputImg[Ay][Ax] + alpha * pDoc->InputImg[By][Bx];
				F = (1 - alpha) * pDoc->InputImg[Cy][Cx] + alpha * pDoc->InputImg[Dy][Dx];
				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else
			{
				for (j = 0; j < pDoc->depth; j++) { // 각 색상 채널에 대해 처리
					E = (1 - alpha) * pDoc->InputImg[Ay][pDoc->depth * Ax + j] + alpha * pDoc->InputImg[By][pDoc->depth * Bx + j];
					F = (1 - alpha) * pDoc->InputImg[Cy][pDoc->depth * Cx + j] + alpha * pDoc->InputImg[Dy][pDoc->depth * Dx + j];
					pDoc->gResultImg[y][pDoc->depth * x + j] = (1 - beta) * E + beta * F;
				}
			}
		}
	}
	Invalidate();
}


void CImageProc2024202015441View::OnMopologyOpening()
{
	OnMopologyErosion(); // 이부분 3번
	CopyResultToInput();

	OnMopologyErosion();
	CopyResultToInput();

	OnMopologyErosion();
	CopyResultToInput();

	OnMopologyDialation(); // <<이부분 3번
	CopyResultToInput();
	OnMopologyDialation();
	CopyResultToInput();
	OnMopologyDialation();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProc2024202015441View::CopyResultToInput()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();
	int x, y;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++)
			pDoc->InputImg[y][x] = pDoc->ResultImg[y][x];
}


void CImageProc2024202015441View::OnMopologyClosing()
{
	OnMopologyDialation();
	CopyResultToInput();
	OnMopologyDialation();
	CopyResultToInput();
	OnMopologyDialation();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
}



void CImageProc2024202015441View::OnGeometryZoomoutSubsampling()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();


	int scale_x = 3;		//1/3
	int scale_y = 2;		//1/2

	int i, j, x, y;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->ImageWidth / scale_x;
	pDoc->gImageHeight = pDoc->ImageHeight / scale_y;
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 역방향사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->InputImg[y * scale_y][x * scale_x];
			else
			{
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y * scale_y][3 * (x * scale_x) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y * scale_y][3 * (x * scale_x) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y * scale_y][3 * (x * scale_x) + 2];
			}
		}
	Invalidate();
}


void CImageProc2024202015441View::OnGeometryZoomoutMeanSub()
{
	OnRegionMeaning();
	CopyResultToInput();
	OnGeometryZoomoutSubsampling();
}


void CImageProc2024202015441View::OnGeometryZoomoutAvg()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();


	int scale_x = 3;
	int scale_y = 2;
	int x, y, i, j;

	int sum, gsum, bsum, rsum;
	int src_x, src_y;

	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth / scale_x + 1;
	pDoc->gImageHeight = pDoc->ImageHeight / scale_y + 1;

	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);


	}

	//정방향 사상
	for (y = 0; y < pDoc->ImageHeight; y + scale_y)
		for (x = 0; x < pDoc->ImageWidth; x += scale_x)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				for (j = 0; j < scale_y; j++)
					for (i = 0; i = scale_x; i++)
					{
						src_x = x + i;
						src_y = y + j;

						if (src_x > pDoc->ImageWidth - 1)src_x = pDoc->ImageWidth - 1;
						if (src_y > pDoc->ImageHeight - 1)src_y = pDoc->ImageHeight - 1;

						sum += pDoc->InputImg[src_y][src_x];

					}
				pDoc->gResultImg[y / scale_x][x / scale_y] = sum / (scale_x * scale_y);
			}


			else {
				rsum = 0; gsum = 0; bsum = 0;

				for (j = 0; j < scale_y; j++)
					for (i = 0; i = scale_x; i++)
					{
						src_x = x + i;
						src_y = y + j;

						if (src_x > pDoc->ImageWidth - 1)src_x = pDoc->ImageWidth - 1;
						if (src_y > pDoc->ImageHeight - 1)src_y = pDoc->ImageHeight - 1;

						sum += pDoc->InputImg[src_y][src_x];

					}
				pDoc->gResultImg[y / scale_x][3 * (x / scale_y) + 0] = rsum / (scale_x * scale_y);
				pDoc->gResultImg[y / scale_x][3 * (x / scale_y) + 1] = gsum / (scale_x * scale_y);
				pDoc->gResultImg[y / scale_x][3 * (x / scale_y) + 2] = bsum / (scale_x * scale_y);

			}
		}
	Invalidate();
}

#define PI 3.1415926535
void CImageProc2024202015441View::OnGeometryRotate()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	int i, x, y;
	int angle = 30;		//dgree
	float radian;
	int Cx, Cy, Oy;
	int xdiff, ydiff;
	int x_source, y_source;

	CAngleInDialog dlg;
	dlg.m_iAngle = angle;
	if (dlg.DoModal() == IDCANCEL)		return;
	angle = dlg.m_iAngle;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}
	radian = 2 * PI / 360 * angle;
	pDoc->gImageWidth = pDoc->ImageHeight * fabs(cos(PI / 2 - radian)) + pDoc->ImageWidth * fabs(cos(radian));
	pDoc->gImageHeight = pDoc->ImageHeight * fabs(cos(radian)) + pDoc->ImageWidth * fabs(cos(PI / 2 - radian));
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//중심점
	Cx = pDoc->ImageWidth / 2;		Cy = pDoc->ImageHeight / 2;
	//y의 마지막
	Oy = pDoc->ImageHeight - 1;
	xdiff = (pDoc->gImageWidth - pDoc->ImageWidth) / 2;
	ydiff = (pDoc->gImageHeight - pDoc->ImageHeight) / 2;

	//역방향사상
	for (y = -ydiff;y < pDoc->gImageHeight - ydiff;y++)
		for (x = -xdiff; x < pDoc->gImageWidth; x++)
		{
			x_source = ((Oy - y) - Cy) * sin(radian) + (x - Cx) * cos(radian) + Cx;
			y_source = Oy - (((Oy - y) - Cy) * cos(radian) - (x - Cx) * sin(radian) + Cy);

			if (pDoc->depth == 1)
			{
				if (x_source<0 || x_source>pDoc->ImageWidth - 1 ||
					y_source<0 || y_source>pDoc->ImageHeight - 1)
					pDoc->gResultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gResultImg[y + ydiff][x + xdiff] = pDoc->InputImg[y_source][x_source];
			}
			else
			{
				if (x_source<0 || x_source>pDoc->ImageWidth - 1 ||
					y_source<0 || y_source>pDoc->ImageHeight - 1)
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = 255;
				}
				else
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = pDoc->InputImg[y_source][3 * x_source + 0];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = pDoc->InputImg[y_source][3 * x_source + 1];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = pDoc->InputImg[y_source][3 * x_source + 2];
				}
			}
		}
	Invalidate();
}

void CImageProc2024202015441View::OnGeometryMirror()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	int x, y;
	for(y=0;y<pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth;x++)
		{
			if (pDoc->depth == 1)
				pDoc->ResultImg[y][x] = pDoc->InputImg[y][pDoc->ImageWidth - 1 - x];
			else
			{
				pDoc->ResultImg[y][3 * x + 0] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 0];
				pDoc->ResultImg[y][3 * x + 1] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 1];
				pDoc->ResultImg[y][3 * x + 2] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 2];

			}
		}
	Invalidate();
}




void CImageProc2024202015441View::OnGeometryFlip()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	int x, y;
	for (y = 0;y < pDoc->ImageHeight;y++)
		for (x = 0;x < pDoc->ImageWidth*pDoc->depth;x++)
		{
			pDoc->ResultImg[pDoc->ImageHeight - 1 - y][x] = pDoc->InputImg[y][x];
		}
	Invalidate();
}




//void CImageProc2024202015441View::OnGeometryWarping()
//{
//	CImageProc2024202015441Doc* pDoc = GetDocument();
//
//	control_line source_lines[5] = { {100,100,150,150},
//						 {0,0,pDoc->ImageWidth,0},
//						 {pDoc->ImageWidth,0,pDoc->ImageWidth - 1,pDoc->ImageHeight - 1},
//						 {pDoc->ImageWidth - 1,pDoc->ImageHeight - 1,0,pDoc->ImageHeight - 1},
//						 {0,pDoc->ImageHeight - 1,0,0} };
//
//	control_line dest_lines[5] = { {100,100,200,200},
//							 {0,0,pDoc->ImageWidth,0},
//							 {pDoc->ImageWidth,0,pDoc->ImageWidth - 1,pDoc->ImageHeight - 1},
//							 {pDoc->ImageWidth - 1,pDoc->ImageHeight - 1,0,pDoc->ImageHeight - 1},
//							 {0,pDoc->ImageHeight - 1,0,0} };
//	int x=0, y=0;
//
//	double u;
//	double h;
//	double d;
//	double tx=0.0, ty=0.0;
//	double xp, yp;
//
//	double weight;
//	double totalweight=0.0;
//	double a = 0.001;
//	double b = 2.0;
//	double p = 0.75;
//
//	int x1, x2, y1, y2;
//	int src_x1, src_x2, src_y1, src_y2;
//	double src_line_length, dest_line_length;
//
//	int num_lines = 5;
//	int line;
//	int source_x, source_y;
//	int last_row, last_col;
//
//	last_col = pDoc->ImageWidth - 1;
//	last_row = pDoc->ImageHeight - 1;
//		for (line = 0; line < num_lines;line++) {
//			x1 = dest_lines[line].Px;
//			y1 = dest_lines[line].Py;
//			x2 = dest_lines[line].Px;
//			y2 = dest_lines[line].Px;
//
//			dest_line_length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
//			u = (double)((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1)) /
//				(double)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
//			h = (double)((y - y1) * (x2 - x1) - (x - x1) * (y2 - y1)) / dest_line_length;
//
//			if (u < 0)
//				d = sqrt((x - x1)*(x-x1) + (y - y1)*(y-y1));
//			else if (u > 1)
//				d = sqrt((x - x2) * (x - x2) + (y - y2)*(y-y2));
//			else
//				d = fabs(h);
//
//			src_x1 = source_lines[line].Px;
//			src_y1 = source_lines[line].Py;
//			src_x2 = source_lines[line].Qx;
//			src_y2 = source_lines[line].Qy;
//
//			src_line_length = sqrt((src_x2 - src_x1) ^ 2 + (src_y2 - src_y1) ^ 2);
//
//			xp = src_x1 + u * (src_x2 - src_x1) - h * (src_y2 - src_y1) / src_line_length;
//			yp = src_x1 + u * (src_y2 - src_y1) + h * (src_x2 - src_x1) / src_line_length;
//
//			weight = pow(dest_line_length, p) / (a + d), b;
//			tx += (xp - x) * weight;
//			ty += (yp - y) * weight;
//			totalweight += weight;
//
//		}
//	source_x = x + (int)(tx / totalweight + 0.5);
//	source_y = y + (int)(ty / totalweight + 0.5);
//
//	if (source_x < 0)
//		source_x = 0;
//	if (source_x > last_col)
//		source_x = last_col;
//	if (source_y < 0)
//		source_y = 0;
//	if (source_y > last_row)
//		source_y = last_row;
//
//	pDoc->ResultImg[y][x] = pDoc->InputImg[source_y][source_x];
//
//
//	Invalidate();
//}

typedef struct
{
	int Px, Py, Qx, Qy;
} control_line;

control_line mctrl_source = { 100,100,150,150 };
control_line mctrl_dest = { 100,100,200,200 };

void CImageProc2024202015441View::OnGeometryWarping()
{
	CImageProc2024202015441Doc* pDoc = GetDocument();

	control_line source_lines[5] = {
		{100, 100, 150, 150},
		{0, 0, pDoc->ImageWidth, 0},
		{pDoc->ImageWidth, 0, pDoc->ImageWidth - 1, pDoc->ImageHeight - 1},
		{pDoc->ImageWidth - 1, pDoc->ImageHeight - 1, 0, pDoc->ImageHeight - 1},
		{0, pDoc->ImageHeight - 1, 0, 0}
	};

	control_line dest_lines[5] = {
		{100, 100, 200, 200},
		{0, 0, pDoc->ImageWidth, 0},
		{pDoc->ImageWidth, 0, pDoc->ImageWidth - 1, pDoc->ImageHeight - 1},
		{pDoc->ImageWidth - 1, pDoc->ImageHeight - 1, 0, pDoc->ImageHeight - 1},
		{0, pDoc->ImageHeight - 1, 0, 0}
	};

	source_lines[0] = mctrl_source;
	dest_lines[0] = mctrl_dest;

	double u, h, d, tx, ty, xp, yp, weight, totalweight;
	double a = 0.001, b = 2.0, p = 0.75;
	int x1, x2, y1, y2, src_x1, src_x2, src_y1, src_y2;
	double src_line_length, dest_line_length;
	int num_lines = 5, line, source_x, source_y;
	int last_row = pDoc->ImageHeight - 1, last_col = pDoc->ImageWidth - 1;

	for (int y = 0; y <= last_row; y++) {
		for (int x = 0; x <= last_col; x++) {
			tx = 0;
			ty = 0;
			totalweight = 0;

			for (line = 0; line < num_lines; line++) {
				x1 = dest_lines[line].Px;
				y1 = dest_lines[line].Py;
				x2 = dest_lines[line].Qx;
				y2 = dest_lines[line].Qy;

				dest_line_length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
				u = static_cast<double>(((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1))) /
					((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
				h = static_cast<double>(((y - y1) * (x2 - x1) - (x - x1) * (y2 - y1))) / dest_line_length;

				if (u < 0)
					d = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
				else if (u > 1)
					d = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
				else
					d = fabs(h);

				src_x1 = source_lines[line].Px;
				src_y1 = source_lines[line].Py;
				src_x2 = source_lines[line].Qx;
				src_y2 = source_lines[line].Qy;

				src_line_length = sqrt((src_x2 - src_x1) * (src_x2 - src_x1) + (src_y2 - src_y1) * (src_y2 - src_y1));

				xp = src_x1 + u * (src_x2 - src_x1) - h * (src_y2 - src_y1) / src_line_length;
				yp = src_y1 + u * (src_y2 - src_y1) + h * (src_x2 - src_x1) / src_line_length;

				weight = pow(dest_line_length, p) / pow(a + d, b);
				tx += (xp - x) * weight;
				ty += (yp - y) * weight;
				totalweight += weight;
			}

			source_x = x + static_cast<int>(tx / totalweight + 0.5);
			source_y = y + static_cast<int>(ty / totalweight + 0.5);

			if (source_x < 0)
				source_x = 0;
			if (source_x > last_col)
				source_x = last_col;
			if (source_y < 0)
				source_y = 0;
			if (source_y > last_row)
				source_y = last_row;

			if(pDoc->depth==1)
				pDoc->ResultImg[y][x] = pDoc->InputImg[source_y][source_x];
			else {
				pDoc->ResultImg[y][3 * x + 0] = pDoc->InputImg[source_y][3 * source_x + 0];
				pDoc->ResultImg[y][3 * x + 1] = pDoc->InputImg[source_y][3 * source_x + 1];
				pDoc->ResultImg[y][3 * x + 2] = pDoc->InputImg[source_y][3 * source_x + 2];
			}
		}
	}

	Invalidate();
}



void CImageProc2024202015441View::OnGeometryMorphing()
{

}

CPoint mpos_st, mpos_end;
void CImageProc2024202015441View::OnLButtonDown(UINT nFlags, CPoint point)
{
	mpos_st = point;

	CScrollView::OnLButtonDown(nFlags, point);
}


void CImageProc2024202015441View::OnLButtonUp(UINT nFlags, CPoint point)
{
	mpos_end = point;
	CDC* pDC = GetDC();
	CPen rpen;
	rpen.CreatePen(PS_SOLID, 0, RGB(255,0,0));
	pDC->SelectObject(&rpen);
	pDC->MoveTo(mpos_st);
	pDC->LineTo(mpos_end);
	ReleaseDC(pDC);

	int Ax, Ay, Bx, By;
	Ax = mpos_st.x;
	Ay = mpos_st.y;
	Bx = mpos_st.x;
	By = mpos_end.y;

	if (Ax < Bx)
		 mctrl_source.Px = Ax - (Bx - Ax) / 2;
	else
		mctrl_source.Px = Ax - (Bx - Ax) / 2;
	if (Ay < By)
		mctrl_source.Py = Ay - (By - Ay) / 2;
	else
		mctrl_source.Py = Ay - (By - Ay) / 2;

	mctrl_dest.Px = mctrl_source.Px;
	mctrl_dest.Py = mctrl_source.Py;

	mctrl_source.Qx = mpos_st.x;
	mctrl_source.Qy = mpos_st.y;
	mctrl_dest.Qx = mpos_end.x;
	mctrl_dest.Qy = mpos_end.y;					
	CScrollView::OnLButtonUp(nFlags, point);
}


void CImageProc2024202015441View::OnAviView()
{
	CFileDialog dlg(true,"", "", OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT, "Avi File(*.avi)|*.avi|모든파일|*.*");
	//true = 읽기용 false = 저장용 // 읽기 파일만 쓰겠다. OFNHideOnly

	if (dlg.DoModal() == IDOK); {
		AVIFileName = dlg.GetPathName();
		bAviMode = true;
		Invalidate();
	}
}


void CImageProc2024202015441View::LoadAVIFile(CDC* pDC)
{
	PAVIFILE pavi; //포인터
	AVIFILEINFO fi;
	int stm;
	PAVISTREAM pstm = NULL;
	AVISTREAMINFO si;
	PGETFRAME pfrm = NULL;
	int frame;
	LPBITMAPINFOHEADER pbmpih;
	unsigned char* image;
	int x, y;
	
	AVIFileInit();
	AVIFileOpen(&pavi, AVIFileName, OF_READ | OF_SHARE_DENY_NONE, NULL);
	AVIFileInfo(pavi, &fi, sizeof(AVIFILEINFO));

	for (stm = 0;stm < fi.dwStreams;stm++) {
		AVIFileGetStream(pavi, &pstm, 0, stm);
		AVIStreamInfo(pstm, &si, sizeof(si));
		if (si.fccType == streamtypeVIDEO) {
			pfrm = AVIStreamGetFrameOpen(pstm, NULL);
			for (frame = 0;frame < si.dwLength;frame++) { //si.dwLength
				pbmpih = (LPBITMAPINFOHEADER)AVIStreamGetFrame(pfrm, frame);
					if (!pbmpih)
						continue;

					image = (unsigned char*)((LPSTR)pbmpih + pbmpih->biSize);
					/*for (y = 0;y<fi.dwHeight;y++)
						for (x = 0;x < fi.dwWidth;x++) {
							pDC->SetPixel(x, fi.dwHeight - 1 - y,
								RGB(image[(y * fi.dwWidth + x) * 3 + 2],
									image[(y * fi.dwWidth + x) * 3 + 1],
									image[(y * fi.dwWidth + x) * 3 + 0]));
						}*/
					pDC->SetStretchBltMode(COLORONCOLOR);
					::SetDIBitsToDevice(pDC->GetSafeHdc(), 0, 0, fi.dwWidth, fi.dwHeight,
						0, 0, 0, fi.dwWidth, image, (BITMAPINFO*)pbmpih, DIB_RGB_COLORS);
					Sleep(3);
			}
		}
	}
	AVIStreamGetFrameClose(pfrm);
	AVIStreamRelease(pstm);
	AVIFileRelease(pavi);
	AVIStreamExit();
}
