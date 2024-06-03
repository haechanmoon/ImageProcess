// CAngleInDialog.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProc2024_20201544_1.h"
#include "afxdialogex.h"
#include "CAngleInDialog.h"


// CAngleInDialog 대화 상자

IMPLEMENT_DYNAMIC(CAngleInDialog, CDialogEx)

CAngleInDialog::CAngleInDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ANGLE, pParent)
	, m_iAngle(0)
{

}

CAngleInDialog::~CAngleInDialog()
{
}

void CAngleInDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ANGLE_IN, m_iAngle);
}


BEGIN_MESSAGE_MAP(CAngleInDialog, CDialogEx)
END_MESSAGE_MAP()


// CAngleInDialog 메시지 처리기
