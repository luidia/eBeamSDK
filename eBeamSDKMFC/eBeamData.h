#ifndef EBEAM_PEN_DATA_H
#define EBEAM_PEN_DATA_H

typedef struct {
	int Color;
	int RawX;
	int RawY;
	int X;
	int Y;
	int btn;
	int flag;
} EBeamPenData;

typedef struct 
{
	int Connected;
	int LowBattery;
} EBeamDeviceStatus;

typedef enum
{
    EBEAM_TOP=0,
    EBEAM_LEFT,
    EBEAM_RIGHT,
    EBEAM_BOTTOM
} EBeamSensorPosition;

typedef enum
{
    EBEAM_DEVICE_NOT_CONNECTED=0,
    EBEAM_DEVICE_CONNECTED=1,
    EBEAM_DRIVER_NOT_RUNNING
} EBeamDeviceConnection;


#define WM_EBEAM_PEN_DATA			WM_USER + 10
#define WM_EBEAM_DEVICE_STATUS		WM_USER + 11
#define WM_EBEAM_STLUS_FUNC_BTN		WM_USER + 13
extern "C" __declspec(dllimport) int  WINAPI EBeamStartListener(HWND hWnd);
extern "C" __declspec(dllimport) int  WINAPI EBeamStopListener();
extern "C" __declspec(dllimport) int  WINAPI EBeamSetReceiveHandle(HWND hWnd);
extern "C" __declspec(dllimport) int  WINAPI EBeamSetCalibration(int TopLeftX,int TopLeftY,int BottomRightX,int BottomRightY,
					      int TargetTopLeftX,int TargetTopLeftY,int TargetBottomRightX,int TargetBottomRightY,int SensorPosition);

#endif
