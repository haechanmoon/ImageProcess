﻿
// ImageProc2024_20201544_1View.h: CImageProc2024202015441View 클래스의 인터페이스
//

#pragma once


class CImageProc2024202015441View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CImageProc2024202015441View() noexcept;
	DECLARE_DYNCREATE(CImageProc2024202015441View)

// 특성입니다.
public:
	CImageProc2024202015441Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProc2024202015441View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMessagePrint();
//	afx_msg void OnPixelAdd();
	afx_msg void OnPixelSub();
	afx_msg void OnPixelMul();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelAdd();
//	afx_msg void OnPixelHistoEqual();
//	afx_msg void PixelStretching();
	afx_msg void OnPixelBinarization();
	afx_msg void OnPixelHistoEqual();
	afx_msg void OnPixelStretching();
	afx_msg void OnPixelTwoImageAdd();
	afx_msg void OnPixelTwoImageSub();
	afx_msg void OnRegionMeaning();
	void Convolve(unsigned char** InImg, unsigned char** ResImg, int cols, int rows, float  mask[][3], int bias, int depth);
	afx_msg void OnRegionSharpening();
	afx_msg void OnRegionEmbossing();
	afx_msg void OnRegionPrewitt();
	afx_msg void OnRegionRoberts();
	afx_msg void OnRegionSobel();
};

#ifndef _DEBUG  // ImageProc2024_20201544_1View.cpp의 디버그 버전
inline CImageProc2024202015441Doc* CImageProc2024202015441View::GetDocument() const
   { return reinterpret_cast<CImageProc2024202015441Doc*>(m_pDocument); }
#endif
