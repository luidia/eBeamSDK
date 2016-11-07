#pragma once


// Caliration2Dlg 대화 상자입니다.

class Caliration2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Caliration2Dlg)

public:
	Caliration2Dlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Caliration2Dlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CALIBRATION_2 };
	int m_nSensorPosition;
	int m_nCalProcess;
	double m_CalTLX;
	double m_CalTLY;
	double m_CalBRX;
	double m_CalBRY;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int ShowGuidePosition(void);
	afx_msg void OnBnClickedOk();
	LRESULT OnMsgEbeamPenData(WPARAM wParam, LPARAM lParam);
};
