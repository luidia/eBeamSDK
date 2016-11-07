// Caliration2Dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "eBeamSDKMFC.h"
#include "Caliration2Dlg.h"
#include "afxdialogex.h"
#include "eBeamData.h"

// Caliration2Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(Caliration2Dlg, CDialogEx)
BOOL bClicked = FALSE;
Caliration2Dlg::Caliration2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Caliration2Dlg::IDD, pParent)
{

}

Caliration2Dlg::~Caliration2Dlg()
{
}

void Caliration2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Caliration2Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Caliration2Dlg::OnBnClickedOk)
	ON_MESSAGE(WM_EBEAM_PEN_DATA,&Caliration2Dlg::OnMsgEbeamPenData)
END_MESSAGE_MAP()


// Caliration2Dlg 메시지 처리기입니다.


BOOL Caliration2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ¿©±â¿¡ Ãß°¡ ÃÊ±âÈ­ ÀÛ¾÷À» Ãß°¡ÇÕ´Ï´Ù.
	this->m_nCalProcess = 0;

	GetDlgItem(IDC_BMP_SENSOR_LEFT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_SENSOR_RIGHT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_SENSOR_TOP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_SENSOR_BOTTOM)->ShowWindow(SW_HIDE);

	switch(m_nSensorPosition)
	{
	case EBEAM_LEFT:
	GetDlgItem(IDC_BMP_SENSOR_LEFT)->ShowWindow(SW_SHOW);
		break;
	case EBEAM_RIGHT:
	GetDlgItem(IDC_BMP_SENSOR_RIGHT)->ShowWindow(SW_SHOW);
		break;
	case EBEAM_TOP:
	GetDlgItem(IDC_BMP_SENSOR_TOP)->ShowWindow(SW_SHOW);
		break;
	case EBEAM_BOTTOM:
	GetDlgItem(IDC_BMP_SENSOR_BOTTOM)->ShowWindow(SW_SHOW);
		break;
	}

	ShowGuidePosition();

	EBeamSetReceiveHandle(this->GetSafeHwnd());
	return TRUE;  // return TRUE unless you set the focus to a control
	// ¿¹¿Ü: OCX ¼Ó¼º ÆäÀÌÁö´Â FALSE¸¦ ¹ÝÈ¯ÇØ¾ß ÇÕ´Ï´Ù.
}


int Caliration2Dlg::ShowGuidePosition(void)
{
	GetDlgItem(IDC_BMP_PEN_TL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_PEN_TR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_PEN_BL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMP_PEN_BR)->ShowWindow(SW_HIDE);

	if(m_nCalProcess == 0 )
	{
		GetDlgItem(IDC_BMP_PEN_TL)->ShowWindow(SW_SHOW);
	}
	else if(m_nCalProcess == 1 )
	{
		GetDlgItem(IDC_BMP_PEN_BR)->ShowWindow(SW_SHOW);
	}
	else  // Calibration End
	{
		AfxMessageBox(L"Calibration Finish");
		OnOK();
	}

	return 0;
}


void Caliration2Dlg::OnBnClickedOk()
{
// TODO: ¿©±â¿¡ ÄÁÆ®·Ñ ¾Ë¸² Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	//CDialogEx::OnOK();
}
LRESULT Caliration2Dlg::OnMsgEbeamPenData(WPARAM wParam,LPARAM lParam)
{
	EBeamPenData *ev = (EBeamPenData *) wParam;

	TRACE(L"Calibration  X=%.f Y=%.f button=%d Clicked=%d\n",
		ev->RawX,ev->RawY,ev->btn,bClicked);

	switch(ev->btn)
	{
	case 1:	/// down
		if(m_nCalProcess == 0 )
		{
			this->m_CalTLX = ev->RawX;
			this->m_CalTLY = ev->RawY;
		}
		else
		{
			this->m_CalBRX = ev->RawX;
			this->m_CalBRY = ev->RawY;
		}
		bClicked = TRUE;

		break;
	case 0: ///up
		if(bClicked == TRUE)
		{
			m_nCalProcess++;
			ShowGuidePosition();
			bClicked = FALSE;
		}
		break;
	}
	return 0;


}