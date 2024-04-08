
// ImageProc2024_20201544_1Doc.h: CImageProc2024202015441Doc 클래스의 인터페이스
//


#pragma once


class CImageProc2024202015441Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProc2024202015441Doc() noexcept;
	DECLARE_DYNCREATE(CImageProc2024202015441Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProc2024202015441Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	unsigned char **InputImg; //[y][x]
	unsigned char **InputImg2;
	unsigned char **ResultImg;
	int ImageWidth;
	int ImageHeight;
	int depth;  //1==흑백, 3==컬러
	void LoadSecondImageFile(CArchive& ar);
	void LoadImageFile(CArchive& ar);
};
