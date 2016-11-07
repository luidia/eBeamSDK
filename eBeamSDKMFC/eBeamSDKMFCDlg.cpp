
// eBeamSDKMFCDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "eBeamSDKMFC.h"
#include "eBeamSDKMFCDlg.h"
#include "afxdialogex.h"
#include "CalibrationDlg.h"
#include "Caliration2Dlg.h"
#include "eBeamData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CeBeamSDKMFCDlg 대화 상자




CeBeamSDKMFCDlg::CeBeamSDKMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CeBeamSDKMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CeBeamSDKMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CeBeamSDKMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LISTEN, &CeBeamSDKMFCDlg::OnBnClickedBtnListen)
	ON_MESSAGE(WM_EBEAM_PEN_DATA,&CeBeamSDKMFCDlg::OnMsgEbeamPenData)
	ON_MESSAGE(WM_EBEAM_DEVICE_STATUS,&CeBeamSDKMFCDlg::OnMsgEbeamDeviceStatus)
	ON_BN_CLICKED(IDC_CHK_DRAW, &CeBeamSDKMFCDlg::OnBnClickedChkDraw)
	ON_BN_CLICKED(IDC_BTN_CALIBRATION2, &CeBeamSDKMFCDlg::OnBnClickedBtnCalibration2)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CeBeamSDKMFCDlg::OnBnClickedBtnClear)
END_MESSAGE_MAP()


// CeBeamSDKMFCDlg 메시지 처리기

BOOL CeBeamSDKMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
		bDraw = FALSE;
		bClicked = FALSE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CeBeamSDKMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CeBeamSDKMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{


		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CeBeamSDKMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CeBeamSDKMFCDlg::OnBnClickedBtnListen()
{
	TRACE(L"Listener Start!!!");
	
	EBeamStartListener(this->GetSafeHwnd());

}
LRESULT CeBeamSDKMFCDlg::OnMsgEbeamPenData(WPARAM wParam,LPARAM lParam)
{
	EBeamPenData *ev = (EBeamPenData *) wParam;
	//CString ss;
	//ss.Format(L"Main Windows Get X=%.f Y=%.f",ev->pos.x,ev->pos.y);
	//SetDlgItemText(IDC_EDIT1,ss);
	CString ss;
	ss.Format(L"%d",ev->RawX);
	SetDlgItemText(IDC_EDIT_X,ss);
	ss.Format(L"%d",ev->RawY);
	SetDlgItemText(IDC_EDIT_Y,ss);

	ss.Format(L"%d",ev->Color);
	SetDlgItemText(IDC_EDIT_COLOR,ss);
	ss.Format(L"%d",ev->btn);
	SetDlgItemText(IDC_EDIT_BUTTON,ss);
	ss.Format(L"%d",ev->flag);
	SetDlgItemText(IDC_EDIT_FLAG,ss);
	ss.Format(L"%d",ev->X);
	SetDlgItemText(IDC_EDIT_CALED_X,ss);
	ss.Format(L"%d",ev->Y);
	SetDlgItemText(IDC_EDIT_CALED_Y,ss);
	ColorCode=ev->Color;
	if(bDraw == TRUE )
	{
		if(ev->btn == 1 )
		{
			if(bClicked == FALSE)  // First Down
			{
				ptOld = ptNew = Gdiplus::Point(ev->X,ev->Y);
			}
			else	//Drawing
			{
//
				ptNew = Point(ev->X,ev->Y);
				DrawStrokeFrame();
				ptOld = ptNew;

			}
			bClicked= TRUE;
		}
		else
		{
			if(bClicked == TRUE) // Pen Up
			{
					
			}
			else	//Hovering
			{
			}
			bClicked = FALSE;
		}
	}

	//TRACE(ss);



	return 0;
}

LRESULT CeBeamSDKMFCDlg::OnMsgEbeamDeviceStatus(WPARAM wParam,LPARAM lParam)
{
	EBeamDeviceStatus *ev = (EBeamDeviceStatus *) wParam;
	//CString ss;
	//ss.Format(L"Main Windows Get X=%.f Y=%.f",ev->pos.x,ev->pos.y);
	//SetDlgItemText(IDC_EDIT1,ss);
	CString ss;
	ss.Format(L"%d",ev->Connected);
	SetDlgItemText(IDC_EDIT_CONNECTION,ss);

	//TRACE(ss);



	return 0;
}



void CeBeamSDKMFCDlg::OnBnClickedChkDraw()
{
	// TODO: ¿©±â¿¡ ÄÁÆ®·Ñ ¾Ë¸² Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	bDraw = ((CButton *) GetDlgItem(IDC_CHK_DRAW))->GetCheck();
}


int CeBeamSDKMFCDlg::DrawStrokeFrame(void)
{
		CDC *pDC = GetDlgItem(IDC_FRAME_DRAW)->GetDC();
		Graphics  gr(pDC->m_hDC);

		Pen	pn(Color(255,0,0,255));
		switch(ColorCode)
		{
		case 0:
			break;
		case 1: //red
		pn.SetColor(Color(255,255,0,0));

			break;
		case 2: //blue
		pn.SetColor(Color(255,0,0,255));
			break;
		case 3: //green
		pn.SetColor(Color(255,0,255,0));
			break;
		case 4: //black
		pn.SetColor(Color(255,0,0,0));
			break;
		case 5:
		pn.SetColor(Color(255,255,255,255));
			break;
		case 6: //big eraser
		pn.SetColor(Color(255,255,255,255));
		pn.SetWidth(10);
			break;
		case 7: //eraser cap
		pn.SetColor(Color(255,255,255,255));
		pn.SetWidth(3);
			break;
		}
		gr.DrawLine(&pn,ptOld,ptNew);
		return 0;
}




void CeBeamSDKMFCDlg::OnBnClickedBtnCalibration2()
{
	// TODO: ¿©±â¿¡ ÄÁÆ®·Ñ ¾Ë¸² Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	// TODO: 
	CCalibrationDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		Caliration2Dlg ddlg;
		ddlg.m_nSensorPosition  = dlg.m_SensorPosition ;
		if(ddlg.DoModal() == IDOK)
		{

			CString ss;
			ss.Format(L"%.f",ddlg.m_CalTLX);
			SetDlgItemText(IDC_EDIT_CAL_TL_X,ss);
			ss.Format(L"%.f",ddlg.m_CalTLY);
			SetDlgItemText(IDC_EDIT_CAL_TL_Y,ss);
			ss.Format(L"%.f",ddlg.m_CalBRX);
			SetDlgItemText(IDC_EDIT_CAL_BR_X,ss);
			ss.Format(L"%.f",ddlg.m_CalBRY);
			SetDlgItemText(IDC_EDIT_CAL_BR_Y,ss);

			RECT rt;
			GetDlgItem(IDC_FRAME_DRAW)->GetClientRect(&rt);

			EBeamSetCalibration(ddlg.m_CalTLX,ddlg.m_CalTLY,ddlg.m_CalBRX,ddlg.m_CalBRY,
				rt.left,rt.top,rt.right,rt.bottom,ddlg.m_nSensorPosition);

		}
	}

	EBeamSetReceiveHandle(this->GetSafeHwnd());

}


void CeBeamSDKMFCDlg::OnBnClickedBtnClear()
{

	Invalidate(TRUE);
}
