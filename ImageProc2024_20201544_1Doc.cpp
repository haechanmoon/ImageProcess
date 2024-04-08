
// ImageProc2024_20201544_1Doc.cpp: CImageProc2024202015441Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProc2024_20201544_1.h"
#endif

#include "ImageProc2024_20201544_1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// #define _CRT_SECURE_NO_WARNINGS
// CImageProc2024202015441Doc

IMPLEMENT_DYNCREATE(CImageProc2024202015441Doc, CDocument)

BEGIN_MESSAGE_MAP(CImageProc2024202015441Doc, CDocument)
END_MESSAGE_MAP()


// CImageProc2024202015441Doc 생성/소멸

CImageProc2024202015441Doc::CImageProc2024202015441Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	InputImg = NULL;
	InputImg2 = NULL;
	ResultImg = NULL;

}

CImageProc2024202015441Doc::~CImageProc2024202015441Doc()
{
	int i;
	if (InputImg != NULL) {
		for (i = 0;i < ImageHeight;i++)
			free(InputImg[i]);
		free(InputImg);
	}
	if (InputImg2 != NULL) {
		for (i = 0;i < ImageHeight;i++)
			free(InputImg2[i]);
		free(InputImg2);
	}
	if (ResultImg != NULL) {
		for (i = 0;i < ImageHeight;i++)
			free(ResultImg[i]);
		free(ResultImg);
	}

}

BOOL CImageProc2024202015441Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CImageProc2024202015441Doc serialization

void CImageProc2024202015441Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar.Write(ResultImg, 256 * 256);
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		LoadImageFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CImageProc2024202015441Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CImageProc2024202015441Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageProc2024202015441Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageProc2024202015441Doc 진단

#ifdef _DEBUG
void CImageProc2024202015441Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProc2024202015441Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageProc2024202015441Doc 명령


void CImageProc2024202015441Doc::LoadSecondImageFile(CArchive& ar)
{
	int w, d, h;
	int maxValue, i;
	char type[16];
	char buf[256];
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();

	if (strcmp(strrchr(fname, '.'), ".ppm") == 0 || strcmp(strrchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strrchr(fname, '.'), ".pgm") == 0 || strcmp(strrchr(fname, '.'), ".PGM") == 0)
	{
		ar.ReadString(type, 15);
		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');

		sscanf(buf, "%d %d", &w, &h);

		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		sscanf(buf, "%d", &maxValue);

		if (strcmp(type, "P5") == 0)
			d = 1;
		else d = 3;


	}
	else if (strcmp(strrchr(fname, '.'), ".raw") == 0 || strcmp(strrchr(fname, '.'), ".RAW") == 0)
	{
		if (fp->GetLength() != 256 * 256) {
			AfxMessageBox("256*256크기의 파일만 가능합니다.");
			return;
		}

		w = 256;
		h = 256;
		d = 1;
	}//작은따음표 써야함 큰 따음표는 문자열

	if (ImageHeight != h || ImageWidth != w || depth != d)
		return;
	//메모리 할당
	InputImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	ResultImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));//메모리가 세로방향의 주소값생성

	for (i = 0;i < ImageHeight;i++) {
		InputImg[i] = (unsigned char*)malloc(ImageWidth * depth);
		ResultImg[i] = (unsigned char*)malloc(ImageWidth * depth);
	}





	//화일에서 데이터 읽기
	for (i = 0;i < ImageHeight;i++)
		ar.Read(InputImg2[i], ImageWidth * depth);//가로줄 한번 읽어서 거기다 넣고 ...나눠서 따로따로 읽을 수 밖에 없음!
	/*if (fp->GetLength() == 256 * 256)
		ar.Read(InputImg2, 256 * 256);
	else
		AfxMessageBox("256*256크기의 파일만 가능합니다.");*/
}////뭘 복사해서 뭐 어떻게 하는거임 inputimg2이렇게 따로 써야함


void CImageProc2024202015441Doc::LoadImageFile(CArchive& ar)
{
	// TODO: 여기에 구현 코드 추가.
	int maxValue,i;
	char type[16];
	char buf[256];
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();

	if (strcmp(strrchr(fname, '.'), ".ppm") == 0 || strcmp(strrchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strrchr(fname, '.'), ".pgm") == 0 || strcmp(strrchr(fname, '.'), ".PGM") == 0)
	{
		ar.ReadString(type, 15);
		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');

		sscanf(buf, "%d %d", &ImageWidth, &ImageHeight);

		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		sscanf(buf, "%d", &maxValue);

		if (strcmp(type, "P5") == 0)
			depth = 1;
		else depth = 3;
		 

	}
	else if (strcmp(strrchr(fname,'.'), ".raw") == 0|| strcmp(strrchr(fname,'.'),".RAW")==0)
	{
		if (fp->GetLength() != 256 * 256) {
			AfxMessageBox("256*256크기의 파일만 가능합니다.");
			return;
		}

		ImageWidth = 256;
		ImageHeight = 256;
		depth = 1;
	}//작은따음표 써야함 큰 따음표는 문자열

	//메모리 할당
	InputImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	ResultImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));//메모리가 세로방향의 주소값생성

	for (i = 0;i < ImageHeight;i++) {
		InputImg[i] = (unsigned char*)malloc(ImageWidth * depth);
		ResultImg[i] = (unsigned char*)malloc(ImageWidth * depth);
	}





	//화일에서 데이터 읽기
	for (i = 0;i < ImageHeight;i++)
		ar.Read(InputImg[i], ImageWidth * depth);//가로줄 한번 읽어서 거기다 넣고 ...나눠서 따로따로 읽을 수 밖에 없음!
	if (fp->GetLength() == 256 * 256)
		ar.Read(InputImg, 256 * 256);
	else
		AfxMessageBox("256*256크기의 파일만 가능합니다.");
}
