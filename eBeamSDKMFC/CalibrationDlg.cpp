// CalibrationDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "eBeamSDKMFC.h"
#include "CalibrationDlg.h"
#include "afxdialogex.h"
#include "eBeamData.h"

// CCalibrationDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCalibrationDlg, CDialogEx)

CCalibrationDlg::CCalibrationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalibrationDlg::IDD, pParent)
{

}

CCalibrationDlg::~CCalibrationDlg()
{
}

void CCalibrationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCalibrationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCalibrationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CCalibrationDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCalibrationDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CCalibrationDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CCalibrationDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CCalibrationDlg 메시지 처리기입니다.


void CCalibrationDlg::OnBnClickedOk()
{

	CDialogEx::OnOK();
}


void CCalibrationDlg::OnBnClickedRadio1()
{
	this->m_SensorPosition = EBEAM_TOP;
}


void CCalibrationDlg::OnBnClickedRadio2()
{
	this->m_SensorPosition = EBEAM_LEFT;
}


void CCalibrationDlg::OnBnClickedRadio3()
{
	this->m_SensorPosition = EBEAM_RIGHT;
}


void CCalibrationDlg::OnBnClickedRadio4()
{
	this->m_SensorPosition = EBEAM_BOTTOM;
}


BOOL CCalibrationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ¿©±â¿¡ Ãß°¡ ÃÊ±âÈ­ ÀÛ¾÷À» Ãß°¡ÇÕ´Ï´Ù.
	((CButton*) GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	this->m_SensorPosition = EBEAM_LEFT;
	return TRUE;  // return TRUE unless you set the focus to a control
	// ¿¹¿Ü: OCX ¼Ó¼º ÆäÀÌÁö´Â FALSE¸¦ ¹ÝÈ¯ÇØ¾ß ÇÕ´Ï´Ù.
}
