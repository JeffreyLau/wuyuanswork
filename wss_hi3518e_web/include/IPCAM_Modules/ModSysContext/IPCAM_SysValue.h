//IPCAM_SysValue.h
#ifndef __IPCAM_SYSVALUE__
#define __IPCAM_SYSVALUE__

//#include "IPCAM_Export.h"

//Ӳ����Ϣ
//�ͻ��������б�ʱ��У��
//����¼��״̬
//����˿�
//�汾��Ϣ
//����Уʱ��Ϣ



typedef struct _LOCALSQL
{
	INT				nSQLenable;
	CHAR			strSQLpath[256];
}IPCAM_LOCALSQL , *LPIPCAM_LOCALSQL;

typedef struct _LOCALSYSTEMFILE
{
	CHAR			ConfigFilePath[256];
	CHAR			DatabaseFilePath[256];
}IPCAM_LOCALSYSTEMFILE , *LPIPCAM_LOCALSYSTEMFILE;

typedef struct _SYSTEMTIME
{
    ULONG           SystemTimeStart;
    ULONG           SystemTimeCur ;
    
}IPCAM_SYSTEMTIME,*LPIPCAM_SYSTEMTIME;

typedef struct tagSYSNETINFO{
	UCHAR	NetIpAddr[16];		//IP ��ַ
	UCHAR	NetGwAddr[16];		//gateway
	UCHAR	NetSubMask[16];		//net mask
	UCHAR	NetMacAddr[24];		//MAC addr
	UCHAR   NetDnsSvI [16];     //DNS1
	UCHAR   NetDnsSvII[16];	    //DNS2
	INT 	ServicePort;
}IPCAM_SYSNETINFO, *LPIPCAM_SYSNETINFO;
//next struct add by jsk at 7-2
typedef struct {
	UCHAR UPNP_Status;  			/*ENABLE -->����  UNENABLE-->�ر�*/
	UINT  UPNP_RotePort;
	UCHAR UPNP_DisplayName[12];		/*·��upnp�����п��Կ��õ�������*/
	UCHAR UPNP_Roteaddr[20];
	UCHAR UPNP_Protocols[5]; 		/*UDP / TCP*/
}IPCAM_UPNPINFO, *LPIPCAM_UPNPINFO;
typedef struct {
	UCHAR  AlarmFlag;	//������־λ   ENABLE  UNENABLE
	time_t AlmLastTime;	//�ϴν��ղ�������ʱ��
	time_t AlmClsTime;
}ALARMINFO;
typedef struct tagALARMSTATUS{
	ALARMINFO  AlarmIO;			
	ALARMINFO  AlarmMd;
	ALARMINFO  AlarmNet;
	ALARMINFO  AlarmIoOut;
	ALARMINFO  AlarmVideo;
	ALARMINFO  AlarmAudio;
	UCHAR  	   AlarmJpgProc;	//���ڽ��д���jpg ENABLE  û�д��� UNENABLE
	UCHAR      AlarmRecProc;	//record == ENABLE 
	UCHAR 	   TimerRecProc;	//record == enalble
}IPCAM_ALARMSTATUS, *LPIPCAM_ALARMSTATUS;
typedef struct tagSdState{
	UCHAR 	SD_State;		/*ENABLE -->���� UNENABLE -->δ����*/
	LONG	SD_Total;		/*�ܴ�С MB*/
	LONG 	SD_Free;		/*ʣ���С MB*/
}IPCAM_SDINFO, *LPIPCAM_SDINFO;
typedef struct {
	CHAR PtzName[20];
}IPCAM_PTZSTATUS;

typedef enum
{
    SYSTEM_VALUE_STATUS_STOP = 0, 
    SYSTEM_VALUE_STATUS_RUN , 
    SYSTEM_VALUE_STATUS_START ,  
    SYSTEM_VALUE_STATUS_ERROR,  
    SYSTEM_VALUE_STATUS_UNKOWN,
} SYSTEM_STATUS;


typedef struct _IPCAM_SYSVALUE{
	IPCAM_LOCALSQL              localSQL;
	IPCAM_LOCALSYSTEMFILE 	    localSystemFile;
	//IPCAM_SYSTEMSTATUS			localSystemStatus;
	IPCAM_SYSTEMTIME            localSystemTmStatus;
	IPCAM_SYSNETINFO			localSystemNetInfo;
	IPCAM_ALARMSTATUS			localAlarmStatus;
	IPCAM_PTZSTATUS				localPtzStatus;//��̨����
	IPCAM_UPNPINFO				localUpnpInfo;
	IPCAM_SDINFO				localSdinfo;
   	INT  regist ; 
} IPCAM_VARIABLE,*LPIPCAM_VARIABLE;

INT IPCAM_SetSystemStatus(INT nStatus);
INT IPCAM_GetSystemStatus();

INT IPCAM_SetSDStatus(INT nStatus);
INT IPCAM_GetSDStatus();
INT IPCAM_SetDatabaseStatus(INT nStatus);
INT IPCAM_GetDatabaseStatus();
INT IPCAM_SetEncStatus(INT ch_num , INT nStatus);
INT IPCAM_GetEncStatus(INT ch_num);
INT IPCAM_SetSDStoreStatus(INT ch_num , INT nStatus);
INT IPCAM_GetSDStoreStatus(INT ch_num);


#define IPCAM_MAX_CONNECTVIDEO		2
#define IPCAM_MAX_CONNECTAUDIOIN	1
#define IPCAM_MAX_CONNECTAUDIOOUT	2

INT IPCAM_AddOneVideoConnectCount(int channel);
INT IPCAM_DelOneVideoConnectCount(int channel);
INT IPCAM_GetVideoConnectCount(INT channel);
INT IPCAM_GetMaxVideoConnectCount();
#endif
