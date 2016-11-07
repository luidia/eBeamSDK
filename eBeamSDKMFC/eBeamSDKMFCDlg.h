
// eBeamSDKMFCDlg.h : 헤더 파일
//

#pragma once


// CeBeamSDKMFCDlg 대화 상자
class Caliration2Dlg;
class CeBeamSDKMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CeBeamSDKMFCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
// 대화 상자 데이터입니다.
	enum { IDD = IDD_EBEAMSDKMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	BOOL	bDraw ;
	Gdiplus::Point  ptOld;
	Gdiplus::Point  ptNew;
	int		ColorCode;
	BOOL	bClicked;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnListen();
	LRESULT OnMsgEbeamPenData(WPARAM wParam, LPARAM lParam);
	LRESULT OnMsgEbeamDeviceStatus(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedChkDraw();
	int DrawStrokeFrame(void);
	afx_msg void OnBnClickedBtnCalibration2();
	afx_msg void OnBnClickedBtnClear();
};
