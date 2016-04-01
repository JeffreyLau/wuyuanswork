//IPCAM_SysConfig.h

#ifndef __IPCAM_SYSCONFIG__
#define __IPCAM_SYSCONFIG__
#include "IPCAM_SysQueue.h"

#define MAX_MV_REGION                   4     //�ƶ�����������
#define MAX_WEEK_NUM			        7     //���������;
#define MAX_TIMESECTION_NUM             3     //ʱ���������
#define MAX_CHANNEL_NUM                 4     //���ͨ����
#define MAX_USER_NUM                    10    //����ע����û�����
#define MAX_PTZ_SCRIPT_NUM              2     //���ɴ��PTZ�ű�����

#define PTZ_SCRIPT_DIR                 "ptz/"//	"ptz-script" //��̨�ű�Ŀ¼

#define APP_TOP_DIR                     "/sys_app/"

#define SYSTEM_DEFAULT_FILE 		   "/mnt/mtd/ndvr/"


typedef struct {
	short left;
	short right;
	short top;
	short bottom;
}NDVRRECT;

typedef struct _IPCAM_MVCONFIG{
	short lev          [MAX_MV_REGION];
	char  isActive     [MAX_MV_REGION];
	NDVRRECT rect      [MAX_MV_REGION];
}IPCAM_CONFIGMV,*LPIPCAM_CONFIGMV;


/////////////////���Ҳ���/////////////////////////////////////////////////////
typedef struct tagCFGFACTORY
{
    CHAR        strDevName[24];            //��ʾ����
	CHAR		strFactoryName[32];		   //��������
	CHAR       	strDevSerialNumb[64];      //�������к�
    CHAR        strDevRegcode[26];         //�豸ע����
	CHAR		strDevVer[16];			  //�豸CPU ����
	CHAR		strHardVer[64];			  //Ӳ���汾��
	CHAR		strSoftVer[64];			  //����汾��
	
}CFG_FACTORYINFO,*LPCFG_FACTORYINFO;
////////////////�û�����////////////////////////////////
typedef enum{
 PRIV_ROOT    =0,                           //�����˻�,���ܸ���Ҳ���ܸ����룬ȫȨ��
 PRIV_ADMIN   =1,                           //����Ա�˻������ܸ��������޸����룬ȫȨ��
 PRIV_GUEST   =2,                           //��ͨ�˻�
}ENU_USERPRIV;
typedef struct{	
     CHAR         userName[16];       	     //�û�����  ��һ�������û������ṩ���û������ܱ��޸ģ������ж������Ա�û�������Ϊ��ͨ�û�
     USHORT       UserID;
	 CHAR         userPassword[16];          //�û�����
	 CHAR         Priority;           		 //�û�Ȩ�޹涨Ϊ3��   0:1:2   0Ȩ��ֻ��һ�������û� 1:����ԱȨ�޿����ж�� 2 ���Ȩ�ެֻ��admin�û��й���Ȩ��
     CHAR         Enable;             		 //�û�ʹ��
}CFG_USERS,*LPCFG_USERS;
typedef struct{	
	USHORT        UserCount;
	CFG_USERS     User[MAX_USER_NUM];
}CFG_USERINFO,*LPCFG_USERINFO;
/////////////////�������//////////////////////////////////////////////////////

typedef	enum{
		WIFFWEPCLOSE=0,
		WIFFWEP64   =1,
		WIFFWEP128  =2,
		WIFFWPA_PSK =3,
		WIFFWPA2_PSK=4
}ENU_WIFFWEPTYPE;
typedef enum{
		WIFFMANAGED     =0,
		WIFFPOINTTOPOINT=1
}ENU_WIFFISHOST;
typedef	enum{
        NETPARAM_IP_MODE 	=0,
        NETPARAM_DHCP_MODE 	=1,
        NETPARAM_PPPOE_MODE =2
}ENU_IPFETCHMODE;

typedef struct{
	UCHAR   SevName[64];
	UCHAR   UsrName[32];
	UCHAR   UsrPwd[32];

}DDNSSERVER;
typedef enum {
	UNENABLE 	= 0,		//ʹ�ܿ��� �ر�״̬
	ENABLE		= 1			//ʹ�ܿ��� ��״̬
}ENU_ENABLESINGEL;

typedef struct tagCFGNETINFO
{
	//��Ӣ��
	INT		LanguageType ;	
	//�������
	UCHAR	NetIpFetchMode;	    //IP��ַ��ȡ��ʽ��ENU_IPFETCHMODE
	CHAR	NetIpAddr[16];		//IP ��ַ
	CHAR	NetHostName[24];    //������
	CHAR	NetGwAddr[16];		//gateway
	CHAR	NetSubMask[16];		//net mask
	CHAR	NetMacAddr[24];		//MAC addr
	SHORT	NetDnsEnable;		//ʹ��DNS
	CHAR   NetDnsSvI [16];      //DNS 
	CHAR   NetDnsSvII[16];
	USHORT  NetDhcpTimeInterval;	 //dhcp����� Сʱ
	
    //ϵͳ����˿�
	USHORT	NetWebPort;			//ϵͳWEB����˿�
	USHORT	NetRtspPort;		//ϵͳRTSP���˿�
	USHORT  NetServerPort;      //ϵͳ����ת���˿�
	USHORT  NetDataPort;		//ϵͳ˽��Э�����˿�
	USHORT  NetOnvifPort;		//onvif server port 
	
    //WIFI  ����
    UCHAR   WifiIsHost;         //ENU_WIFFISHOST
	UCHAR   WifiEncryptType;	//ENU_WIFFWEPTYPE
	UCHAR   WifiPassword[130];  //65 �޸�Ϊ128λ֧��
	UCHAR   WifiSsid[50];
	UCHAR   WifiKeySystem;		//0:ʮ������  1:ASCII
	//PPOE ����
	CHAR   PpoeEnable;
    CHAR   PpoeName[50];
	CHAR   PpoePassword [50];
	CHAR   PppoeIp[64];
	//DDNS ����
    CHAR   DdnsEnable;           //ʹ��DDNS
	CHAR   DdnsSevIndex;         //����������
    USHORT DdnsTimeInterval;     //ddnsʱ���� ����
    DDNSSERVER DdnsServerList[4];//���õ�DDNS��������
    //NTP  ����
    UCHAR  NtpEnable;
	UCHAR  NtpSevIndex;			//��������ĸ�������
	CHAR  NtpServer[2][50];
	USHORT NtpPort;
	SHORT  NtpTimeZone;
	USHORT NtpTimeInterval;		 //ntpʱ���� Сʱ
	UINT   NtpSysTime;
	
	//UPNP ����
	CHAR   UpnpEnable;
	//Rtsp ����
	CHAR   RtspEnable;
	CHAR   RtspPasswdAuth;

}CFG_NETINFO,*LPCFG_NETINFO;
//////////////��Ƶ����///////////////////////////////////

typedef enum
{
	ENC_RCLEVEL1	= 0,
	ENC_RCLEVEL2	= 1,
	ENC_RCLEVEL3	= 2,
	ENC_RCLEVEL4	= 3,
	ENC_RCLEVEL5	= 4,
	ENC_RCLEVEL6	= 5,
	ENC_RCLEVEL7	= 6,
	ENC_RCLEVEL8	= 7,
	ENC_RCLEVEL9	= 8,
	ENC_RCLEVEL10	= 9,
	ENC_RCLEVEL11	=10,
	ENC_RCLEVEL12	=11,
	ENC_RCLEVEL_NUM,
}ENU_RCLEVEL;                            //�ʿؼ���,ֵ��ӦCBR ��ͬ�趨���ʣ�VBR ��ͬ����
typedef enum
{
	//ENC_OFF = 0,
	ENC_VBR = 0,
	ENC_CBR	= 1,

}ENU_RCTYPE;                             //�ʿ�
typedef enum
{
    ENC_JPEG  = 0,
	ENC_MPEG4 = 1,
	ENC_AVC   = 2,

}ENU_ECNTYPE;                            //���뷽ʽ
typedef enum
{
	DISPLAY_OFF  = 0,
	DISPLAY_NTSC = 1,
	DISPLAY_PAL  = 2,	
}DISPLAY_TYPE;                           //��ʽ
//0:disable, 1:NTSC, 2:PAL

typedef enum
{
	ENC_RSLEVEL_PAL_QCIF   = 0,
	ENC_RSLEVEL_PAL_CIF    = 1,
	ENC_RSLEVEL_PAL_D1     = 2,
	ENC_RSLEVEL_NTSC_QCIF  = 3,
	ENC_RSLEVEL_NTSC_CIF   = 4,
	ENC_RSLEVEL_NTSC_D1    = 5,
	ENC_RSLEVEL_CMOS_QQVGA = 6,            //ֱ��CCD ʹ����ͬ�ֱ��ʽ���
	ENC_RSLEVEL_CMOS_QVGA  = 7,
	ENC_RSLEVEL_CMOS_VGA   = 8,
	ENC_RSLEVEL_CMOS_720P  = 9,
	ENC_RSLEVEL_CMOS_960P  =10,	
	ENC_RSLEVEL_CMOS_1204P =11,	
	ENC_RSLEVEL_CMOS_1080P =12,	
	ENC_RSLEVEL_NUM,
}ENU_RSLEVEL;                              //�ֱ��ʷּ�
typedef enum{
    ENC_FPS_01             = 0,            //1fps
    ENC_FPS_02             = 1,            //6 fps
    ENC_FPS_03             = 2,            //10fps
    ENC_FPS_04             = 3,            //15fps
    ENC_FPS_05             = 4,            //20fps
    ENC_FPS_06             = 5,            //25fps
    ENC_FPS_07             = 6,            //30fps
    
}ENU_FRAMERATELEVEL;                      //֡�ʼ���
typedef enum{
  VIDEO_POWER_50HZ = 50,
  VIDEO_POWER_60HZ = 60,
}ENU_VIDEOPOWERMODE;
typedef struct{
	 UINT	Resolution;		                //�ֱ���ģʽֵ               : ENU_RSLEVEL
	 UINT	FrameRate;			            //֡��
	 UINT	nBitRate;						//����	 
	 UCHAR	RcMode;		                    //�ʿ� .CBR��VBR	         : ENU_ENCRCTYPE
	 UINT 	RcLevel;		                //�ʿ� .CBR��VBR�ȼ�ENU_ENCRCLEVEL
	 UCHAR 	IsVideo;		                //video open
	 UCHAR  IsMjpeg;                        //��������Jpeg��
	 UCHAR  EncType;                        //��������=ENC_TYPE_AVC etc..:ENU_ECNTYPE

}VIDEOSTREAMSET;

typedef struct {
	 UCHAR             bEnable;     //ʹ���ڸ�
	 UCHAR 			   strName[24]; //�ڸ�����
	 UCHAR			   nX0; 		//����ٷֱ�[0-100]
	 UCHAR 			   nY0;   		//����ٷֱ�[0-100]
	 UCHAR 			   nX1;   		//����ٷֱ�[0-100]
	 UCHAR 			   nY1;  		//����ٷֱ�[0-100]
}VIDEOMASK,*LPVIDEOMASK;


typedef struct {
	 UCHAR             bEnable;     //ʹ��IRCUT
	 UCHAR 			   nMode;   	//ʹ��IRCUT ģʽ
	 UINT			   nTime1; 		//ʹ�ÿ�ʼʱ��
	 UINT 			   nTime2;   	//ʹ�ý���ʱ��
}VIDEOIRCUT,*LPVIDEOIRCUT;


typedef enum{
	IRCUT_TIMER = 0,
	IRCUT_DAYTIME,
	IRCUT_NIGHTTIME,
	IRCUT_AUTO,
}VIDEO_IRCUTMODE;

typedef enum {
	ENCPROFILE_BASE      =0,
	ENCPROFILE_MAIN		 =1,
	ENCPROFILE_HIGH      =2,
}ENU_PROFILETYPE;

typedef enum {
	SERNSOR_MOD_DAY 	= 0,
	SERNSOR_MOD_NIGHT	= 1,
}ENU_DAYNIGHT;

typedef enum {
	SERNSOR_MOD_INDOOR 	= 0,
	SERNSOR_MOD_OUTDOOR	= 1,
	SERNSOR_MOD_AUTO	= 2,
}ENU_OUTDOOR;


typedef struct tagCFGVIDEOINFO
{
	 //Sernsor ����
	 UCHAR			   bzDayNight;			// 0 : night mode 	1: day mode
	 //�Զ���ƽ��
	 UCHAR			   bWhiteBalance;		// 0 : indoor	1: outdoor	2: Auto


	 INT 			   nSernsorType;		//ENU_CAPTURETYPE ��ʲô����sernsor
	 ///������
	 UCHAR			   bSernsorMode;		//
	 ////3a�Ƿ�����
	 UCHAR			   bAwebEnable;			//�����Ƿ������Զ���ƽ��
 
	 //��Ƶ��������
	 UCHAR			bzBright;			//����
	 UCHAR			bzContrast;		    //�Աȶ�
	 UCHAR			bzSaturation;		//���Ͷ�
	 
	 UCHAR 			   bzBackLight;			// median=128 ,hight>128, low<128  
	 UCHAR			   bzSharpness;			// median=128 ,hight>128, low<128  
	 
	 
     //��Ƶ�����������
	 UCHAR             FlipVertical;        //��ֱ��ת(�ص�����ͷ����)
	 UCHAR             FlipHorizontal;      //ˮƽ��ת(�ص�����ͷ����)
	 UCHAR             FreqPower;           //��ԴƵ��(50hz/60hz ,�ض�����ͷʹ��)

	 UCHAR			bMainStream;			///1��ʾ������  0��ʾ������ 

	 //��ƵOSD��������
	 INT               OsdIsEnableTime;     //��ʱ����ʾ
	 INT               OsdIsEnableName;     //���豸����(�豸λ����ʾ)
	 BOOL              OsdIsEnglish   ;     //OSD ʹ��Ӣ�ı�עʱ��
	 
	 //��Ƶ������������
	 UCHAR			   CompositeVideo;      //0:�ر� 1:NTSC 2:PAL
	 //��Ƶ�ڸ�
	 VIDEOMASK         VideoMask[4];     	//ʹ���ڸ�4������	 
     //��Ƶͨ���趨
	VIDEOSTREAMSET	   ChannelInfo[4];      //��Ƶͨ������video_set[4];			// 0 ~ 3
	VIDEOIRCUT		   VideoIrCut;
	//encode profile
	ENU_PROFILETYPE	   EncProfileType;	////0 =baseline , 1 =mainline, 2 =highline
}CFG_VIDEOINFO,*LPCFG_VIDEOINFO;

typedef enum {//��IPCAM_NetCommunication.h�ļ�ƥ��
	ENU_AUDIO_PCM8X8K	 	=6,
	ENU_AUDIO_PCM16X8K	 	=7,
	ENU_AUDIO_ADPCM16X8K  	=8,
	ENU_AUDIO_AMR16X8K	 	=9,
	ENU_AUDIO_G711UL 	 	=10,
	ENU_AUDIO_G711AL 	 	=11,
	ENU_AUDIO_AAC		 	=12,
}ENU_AUDIOENCODE;				// ��Ƶѹ������


////////////////��Ƶ����//////////////////////////////////
typedef struct _IPCAM_AUDIOCONFIG{
    UCHAR  bzAudioEnable;                   //��Ƶʹ��
    UCHAR  bzAiType;						
	UCHAR  bzEncodeType; 	                //��Ƶѹ������ Ĭ��10    ENU_AUDIOENCODE
	UCHAR  bzSampleSize; 	                //������ȣ�8 �� 16 �� 32 
	UCHAR  usSampleSpeed; 	                //����Ƶ�ʣ�8K 
	UCHAR  bzStereo;  		                ////1��ʾ������ 0 ��ʾ������
} CFG_AUDIOINFO, *LPCFG_AUDIOINFO;
////////////////��̨����/////////////////////////////////
typedef struct { 	
	UCHAR          ptzName[48];             //��̨�ű��ļ�����
	UCHAR          address;
    UCHAR          speed;
}CFG_PTZ,*LPCFG_PTZ;

////////////////����¼��////////////////////////////////
typedef struct {
	UCHAR         hour;
	UCHAR         minute;
	UCHAR         second;
}RECTIME,*LPRECTIME;
typedef struct{
  	CHAR           isOpen;                   //���õ�ǰʱ���//
	RECTIME        startTime;	             // the section 1 start time//
	RECTIME        endTime;		             //the section 1 end time/
} RECTIMESET,*LPRECTIMESET;

typedef struct{
	UCHAR        timeCheckType ;              //���ͣ�0,ʱ��Σ�1,ȫ��///
	RECTIMESET   recordTime[MAX_TIMESECTION_NUM];//����ʱ���
}RECPARAMTER,*LPRECPARAMTER;

typedef struct {
	UCHAR TmRecEnable;
	ULONG TmRecStart;
	ULONG TmRecEnd;
}TMRECTIME;
typedef struct {
	TMRECTIME TmRecDay[3];
}TMRECDAYTIME;
typedef struct tagCFGRECORDINFO
{
	UCHAR   RecEnable;
    UCHAR   RecFullCover;                    //ռ������ sd���洢�������Ƿ�ɾ�����ļ�
	UCHAR   RecCheckByIoAlarm;
	UCHAR   RecCheckByMoAlarm;
    UCHAR   RecDevisionType;                 //0:���ߴ�� 1:��ʱ���
    UCHAR   RecDevisionValue;                //0:5 1:10 2:15 3:20
	RECPARAMTER timeParamSet[MAX_WEEK_NUM];
	TMRECDAYTIME RecTimer[MAX_WEEK_NUM];
}CFG_RECORDINFO, *LPCFG_RECORDINFO;
///////////////��������/////////////////////////////////////
typedef struct{
	INT    IsEnable;
	time_t TmBegin;
	time_t TmEnd;
}MOTMSECTION;
typedef struct {
	USHORT map;
}IOMAPINFO,*PIOMAPINFO;
typedef struct{
	UCHAR 	IsSendtoSd; 
	UCHAR   IsSendtoMail;			              //�Ƿ��͵��ʼ�
	UCHAR   IsSendtoFtp;			              //�Ƿ��͵�ftp
}MOTIONDATECTGRAB;


typedef struct {
	 UCHAR			   nX0; 		//����ٷֱ�[0-100]
	 UCHAR 			   nY0;   		//����ٷֱ�[0-100]
	 UCHAR 			   nX1;   		//����ٷֱ�[0-100]
	 UCHAR 			   nY1;  		//����ٷֱ�[0-100]
}MDAREA;

typedef struct {
	 UCHAR 	mdIsOpen;		                      //�ƶ�������򿪱�״̬0~�ر�,1~���� ��λ��ʾ b001,b011,b111 etc��
	 CHAR	mdAreaName[24];						  //�ƶ������������
	 UCHAR	mdSensitive;	                      //�ƶ���������ȣ�0~32
	 MDAREA	mdArea;								  //�ƶ��������Χ
}MOTIONDETECTION,*LPMOTIONDETECTION;
	
typedef struct tagCFGALARMINFO
{

	 MOTIONDETECTION 		MotiDetection[4]; 
	 UCHAR  				mdEnableTmSection   ;           //�ƶ����ʱ���
     MOTMSECTION   			mdTmSectionCheck[MAX_WEEK_NUM];	//ʱ�μ�鰴����

     UCHAR 					IoAlarmEnable;              //ʹ��IO����
     UCHAR 					IoAlarmCheckInterval;       //IO�������ʱ��

	 IOMAPINFO     			IoMap[16];	                // I/O relation policy      //IO����ӳ��
	 IOMAPINFO     			MoMap;                      // move i/O  relation 
	 
     //��������
	 USHORT            		GrabNum;			        //����ץ��ͼƬ����  0:��ץ��
     USHORT            		GrabIntervalTime;          	//ץ�ļ��ʱ��

	 USHORT 				VideoTime;					//¼����Ƶʱ�� ��λ�� 0:��ʾ��¼��
	 USHORT 				VideoChannel;				//0 ������  1 ������		

	 MOTIONDATECTGRAB  		GrabRecordInfo[2];          //ץ�ļ�¼���ϴ�������������� 0:grab picture    1: grab video

}CFG_ALARMINFO,*LPCFG_ALARMINFO;
/////////////////�ϴ�����////////////////////////////////
#define MAX_UPLOAD_SERVERS 2

typedef enum {
PORT_FTPTYPE	= 0,
PASV_FTPTYPE    = 1
}ENU_FTPSERVEICETYPE;

typedef struct{
	CHAR    ServerName[64];
	USHORT  ServerPort;
	CHAR    UserName[32];
	CHAR    Password[32];
	CHAR    ServerType;
}UPLOAD_FTPSERVER;
typedef struct{
	CHAR ServerName[64];
	USHORT ServerPort;
	CHAR UserName[32];
	CHAR Password[32];
	CHAR MailFrom[64];          
	CHAR MailTo[64];
}UPLOAD_MAILSERVER;

typedef struct{
   CHAR Enable;
   time_t t_start;
   time_t t_end;
}JPEG_SEND_DATEINFO;
typedef struct tagCFGUPLOADINFO
{ 
	//ftp �������ϴ����
	 UCHAR             FtpEnable;
     UCHAR             FtpType;		//ENU_FtpServiceType
	 UPLOAD_FTPSERVER  FtpServerList[MAX_UPLOAD_SERVERS];

     //MAIL�������ϴ����
     UCHAR             MailEnable;
     UPLOAD_MAILSERVER MailServerList[MAX_UPLOAD_SERVERS];
     //ͼ��ʱ�ϴ����
	 UCHAR              JpgTimeSendEnable;
	 UCHAR 	            JpgTimeSendEnableByDay;
	 SHORT              JpgTimeSendInterval;
	 JPEG_SEND_DATEINFO JpgTimeSendTmCheck[7];

}CFG_UPLOADINFO,*LPCFG_UPLOADINFO;
////////////////////////////////////////////////////////


//�Զ�ά��
typedef struct tarCFG_AUTOMAINTAININFO
{
	UCHAR			  AutoRebootEnable;
	UCHAR			  Day;
	RECTIME			  Time;	
}CFG_AUTOMAINTAININFO, *LPCFG_AUTOMAINTAININFO;


typedef struct  _IPCAM_SYSCONFIG{
    CFG_FACTORYINFO                    ConfigFactory;
  	CFG_USERINFO            	       ConfigUser;
    CFG_NETINFO                        ConfigNet;
    CFG_VIDEOINFO   	               ConfigVideo;
	CFG_AUDIOINFO                      ConfigAudio;
	CFG_PTZ            	               ConfigPtz;
	CFG_RECORDINFO          	       ConfigRecord;
    CFG_ALARMINFO                      ConfigAlarm;
    CFG_UPLOADINFO                     ConfigUpload;
	CFG_AUTOMAINTAININFO 			   ConfigAutoMaintain;
} IPCAM_SYSCONFIG ,*LPIPCAM_SYSCONFIG; 


#endif


