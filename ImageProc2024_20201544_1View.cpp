
// ImageProc2024_20201544_1View.cpp: CImageProc2024202015441View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProc2024_20201544_1.h"
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
END_MESSAGE_MAP()

// CImageProc2024202015441View 생성/소멸

CImageProc2024202015441View::CImageProc2024202015441View() noexcept
{
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

	if (pDoc->InputImg2 != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel((pDoc->ImageWidth + 20) * 2 + x, y,RGB(pDoc->InputImg2[y][x], pDoc->InputImg2[y][x], pDoc->InputImg2[y][x]));
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel((pDoc->ImageWidth + 20) * 2 + x, y, 
						RGB(pDoc->InputImg2[y][3 * x + 0], pDoc->InputImg2[y][3 * x + 1], pDoc->InputImg2[y][3 * x + 2]));
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