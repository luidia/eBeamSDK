#pragma once


// CCalibrationDlg 대화 상자입니다.

class CCalibrationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalibrationDlg)

public:
	CCalibrationDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalibrationDlg();
	int m_SensorPosition;
// 대화 상자 데이터입니다.
	enum { IDD = IDD_CALIBRATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	virtual BOOL OnInitDialog();
};
