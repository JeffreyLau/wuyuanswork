//IPCAM_NetCommunicationT.h
/*##############################################################################
#��������:
#       IP���������
#
#�ļ�����:
#      ���������Э��ӿڡ�
#      �ò���Э���Ӧ�ṹΪ�豸�Ϳͻ��˹��У��ͻ���SDKԭ����ֻ��Ҫ֧������Ҫ����
#      �硢��ý�塢��̨���Ƽ���Ʒ��Ϣ���ɣ�������������Ӧ��������CGI�����ӿ�����
#      �ṩ��
# 
#������Ϣ:
#         ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x 
#  	   All rights reserved.
#ע��    :
#      ����ļ�ΪIPCAM ��PC SDK �����ĵ����޸�Ҫע�ⲻҪ����ϵͳ�������ֶ�����
#      ���Ӷ���ע��淶�� 
###############################################################################*/
#ifndef IPCAM_NET_COMMUNICATIONT_H
#define IPCAM_NET_COMMUNICATIONT_H


typedef struct 
{
	UCHAR       		devModel[20];               //�����ͺ�
	UCHAR				devSerialNumb[64];          //�������
    UCHAR       		devRegcode[26];             //�豸ע����
	CHAR				devName[24];                //�豸��ʾ����
	CHAR				szFactoryName[32];			//��������
}T_IPCFACTORYPARAM;

typedef struct 
{
	USHORT          AbiVideoChannels;      			//��Ƶ·��
	USHORT          AbiVideoSubMedia;      			//�Ƿ�֧�ִ�������
	USHORT		    AbiAudioChannels;      			//��Ƶ·��
    USHORT          AbiVideoEncodeType;    			//����

	USHORT          AbiVideoMax_X   ;      			//��Ƶ������ֱ���
	USHORT          AbiVideoMax_Y   ;      			//��Ƶ�������ֱ���
	ULONG           AbiVideoResultion[32];   		//��������Ƶ�ֱ��ʣ���16λ����16λ�ߣ�
    ULONG       	AbiVideoResultionSub[32];		//��������Ƶ�ֱ��ʣ���16λ����16λ�ߣ�
	USHORT          AbiIoAlarmInSize;      			//IO�����������
	USHORT          AbiIoAlarmOutSize;     			//IO�����������
	
}T_IPCABILITYYPARAM;
//����
typedef struct{
	UCHAR			ipFetchMode;	       //��̬IP���߶�̬DHCP����IP
	UCHAR			ipAddr    [24];		   //IP ��ַ
	UCHAR			gwAddr    [24];		   //����
	UCHAR			netMask   [24];		   //��������
	UCHAR			macAddr   [24];		   //MAC ��ַ
	UCHAR           NetDnsSvI [16];        //DNS 
	UCHAR           NetDnsSvII[16];
	UCHAR           HostName  [16];        //������
}T_IPCNETPARAM;

typedef struct{
	UCHAR          channel;                //ͨ����
	UCHAR          videoType;              //��Ƶ��ʽPAL, N ��,(IPC��ʹ�ø���)
	UCHAR	       frameRate;			   //֡��
	UCHAR          rateType;               //VBR CBR
	UCHAR 	       rateLevel;		       //���ʻ�����������  ��5������     
}T_IPCVIDEOPARAM;

typedef struct{
	UCHAR           channel;               //ͨ����
	UINT	        bright;			       //����
	UINT	        contrast;		       //�Աȶ�
	UINT	        saturation;		       //���Ͷ�
	UINT		 sharpness;			//���
}T_IPCPICTUERPARAM;
typedef struct {
    UCHAR           channel;
    UCHAR           bzAiType;              //���뷽ʽ:0 mic,1 line
	UCHAR           bzEncodeType; 	       //��Ƶѹ������ Ĭ��0 
	UCHAR           bzSampleSize; 	       //������ȣ�8 �� 16 �� 32 
	UCHAR           usSampleSpeed; 	       //����Ƶ�ʣ�8K 
	UCHAR           bzStereo;  		       ////1��ʾ������ 0 ��ʾ������
} T_IPCAUDIOPARAM;
typedef struct {
    UCHAR           channel;
    UINT            uzTime ;               //����ʱ��
	 INT            uzTimeZone;            //ʱ��
	UINT            uzIsUsedNtp;           //0=FALSE 1:TRUE
	CHAR            NtpServer[64];         //ָ��ʱ�������
} T_IPCTIMEPARAM;
typedef enum
{
	OSD_POZITON_NULL    =0,
	OSD_POZITON_LEFTTOP   ,
	OSD_POZITON_MIDTOP    ,
	OSD_POZITON_RIGHTTOP  ,
	OSD_POZITON_LEFTMID   ,
	OSD_POZITON_MIDMID    ,
	OSD_POZITON_RIGHTMID  ,
	OSD_POZITON_LEFTBOTTOM,
	OSD_POZITON_MIDBOTTOM ,
	OSD_POZITON_RIGHTBOTTOM ,
}ENU_OSDPOZITION;
typedef enum
{
	OSD_TIMESTYE_NULL    =0,
	OSD_TIMESTYE_01        ,   //1970-01-01 23:59:59
	OSD_TIMESTYE_02        ,   //1970/01/01 23:59:59
	OSD_TIMESTYE_03        ,   //1970/01/01 ����5 23:59:59
	OSD_TIMESTYE_04        ,   //Jul.01 1970 Fri 23:59:59
	OSD_TIMESTYE_05		   ,   //1970��01��01�� 23:59:59
}ENU_OSDTIMESTYE;
typedef struct {
    UCHAR           channel;
    UCHAR           uzChannelName[16] ;        //ͨ������(�ַ�Ϊ�ղ���ʾ) 
	ENU_OSDPOZITION ChannelNamePoziton;        //��ʾλ��(λ��Ϊ�ղ���ʾ����Щ�豸������ʾλ����Ч)
	ENU_OSDTIMESTYE ShowTimeOsdStype;          //ʱ����ʾ����Ϊ��ʱ����ʾ
	ENU_OSDPOZITION TimeOsdPoziton;            //��ʾλ��(λ��Ϊ�ղ���ʾ����Щ�豸������ʾλ����Ч)
} T_IPCOSDPARAM;
////////////////��̨����/////////////////////////////////
typedef struct { 
	UCHAR           channel;
	UCHAR           ptzScriptName[32];     //��ǰ��̨�ű��ļ�����(ֻ��)
	UCHAR           ptzAddress;
    UCHAR           ptzSpeed;
}T_IPCPTZPARAM;
typedef	struct { 

	USHORT          channel;               //ͨ��ѡ��
	USHORT          cmd;                   //��̨����
	ULONG           timeount;              //���뼶
} T_IPCPTZCOMMAND;
///////////////������ϵͳ��Ϣ///////////////////////////
typedef	struct { 

	UCHAR           channel;               //ͨ��
	USHORT          cmd;                   //��Ϣ����
	ULONG           time;                  //ʱ���
} T_IPCSIGNALNOTIFY;
///////////////����Ϊ��Ҫ�ӿڿͻ���SDK�ɲ���֧��////////////
//IO.�ƶ�������
typedef struct{
	
	UINT            outputRelationAlarm;   //�������IO���� 0-1BIT ��ʾ���IO
}T_IPCREALPARAM;
typedef struct{

	UCHAR           channel;                //ͨ��ѡ��
	UCHAR 	        isOpen;			        //�ƶ����ʹ��
	UINT	        outputRelationAlarm;    //�������IO���� //�������IO���� 0-1BIT ��ʾ���IO
	CHAR            ChannelName[24];        //����ͨ������
}T_IPCIOALARMPARAM;
typedef struct{

	UCHAR           channel;                //ͨ��ѡ��
	UCHAR 	        isOpen[4];			    //�ƶ����ʹ��,ÿ����Ƶͨ��������4������
	UINT 	        sensitivity[4];	        //������ 0 -5
    UCHAR	        area[4][4];             //�ƶ��������,4��
	UINT	        outputRelationAlarm[4]; //�������IO���� 
	CHAR            ChannelName[4][24];     //����ͨ������
}T_IPCMOTIONALARMPARAM,T_IPCMASKPARAM;      //�ƶ�������ͼ�ڸ�ʹ����ͬ�ṹ
//�˻��������
typedef struct{
	
    CHAR             userName[16];          //�û�����  ��һ�������û������ṩ���û������ܱ��޸ģ�������һ������Ա�û�������Ϊ��ͨ�û�
    CHAR             userPassword[16];      //�û�����
    CHAR             Priority;              //�û�Ȩ�޹涨Ϊ2��    ���Ȩ�޺͹���Ȩ�ޣ�ֻ��admin�û��й���Ȩ��
    CHAR             Enable;                //�û�ʹ��
} T_IPCUSERPARAM;  

#ifndef MAX_PTZ_SCRIPT_NUM
	#define MAX_PTZ_SCRIPT_NUM 2
#endif
//����PTZЭ���ѯ
typedef struct {
	T_IPCPTZPARAM       ptzName[MAX_PTZ_SCRIPT_NUM];  //�豸���ܹ��Ľű�����
}T_IPCPTZNAME;
//wifi����
typedef struct{
    UCHAR           WifiIsHost;             //ENU_WIFFISHOST
	UCHAR           WifiEncryptType;	    //ENU_WIFFWEPTYPE
	UCHAR           WifiPassword[130];      //65 �޸�Ϊ128λ֧��
	UCHAR           WifiSsid[50];
	UCHAR           WifiKeySystem;		    //0:ʮ������  1:ASCII
}T_IPCNETWIFIPARAM;

typedef struct{
	INT					iServerPort;
	INT					ipFetchMode;	       //��̬IP���߶�̬DHCP����IP				
	UCHAR				NetIpAddr[16];				//IP ��ַ
	UCHAR				NetGwAddr[16];				//gateway
	UCHAR				NetSubMask[16];				//net mask
	UCHAR				NetMacAddr[24];				//MAC addr
	UCHAR				NetDnsSvI [16];				//DNS1
	UCHAR				NetDnsSvII[16];				//DNS2

	UCHAR				devModel[20];               //�����ͺ�
	UCHAR				devSerialNumb[64];          //�������
	UCHAR				devRegcode[26];             //�豸ע����
	CHAR				devName[24];                //�豸��ʾ����
	CHAR				szFactoryName[32];			//��������

	CHAR                nVideoChannel;              //��Ƶͨ����
	CHAR                bIsVideoSubChannel;         //�Ƿ�����Ƶ������
	CHAR                nAudioChannel;              //��Ƶͨ����
}T_DEVSEARCHINFO;

typedef enum {
ALARMTYPE_IO     =0,
ALARMTYPE_MV     =1,
}ENU_ALARMTYPE;

typedef struct {
	UCHAR	Channel;
	UCHAR 	AlarmType;							//=ENU_ALARAMTYPE
	ULONG   AlarmParam;							//Md=��������IO=�����˿�							//bit 0��ʾmd����1��������Ŀǰֻ֧�� bit 0
	ULONG   AlaramTime;							//��������ʱ��
}T_ALARMSTATUS;

typedef enum{
LOGTYPE_USR			= 1,						
LOGTYPE_SYS			= 2,
LOGTYPE_APP 		= 3,
}ENU_LOGTYPE;
typedef struct {
	UCHAR   LogType;							//�����ʱ��ʾ��������ENU_LOGTYPE  	  0��ʾ���������
												//��־��ʱ��ʾENU_LOGTYPE
	ULONG   SerialNu;							//�����ʱ��ʾ������ʼʱ��    0��ʾ����������
												//��־��ʱ��ʾ���������	  Ϊ0ʱ��ʾ�Ѿ��������
	ULONG   LogTime;							//�����ʱ��ʾ��������ʱ��	  SerialNu != -1ʱ����һ��Ҫд
												//��־��ʱ��ʾ��־��¼��ʱ��
	CHAR    LogUsr[10];							//�����ʱ��ʾҪ�������û�      strlen() == 0;ʱ��ʾ����������
												//��־��ʱ��ʾ��־���û�
	CHAR    LogMsg[120];						//�����ʱ������д
												//��־��ʱ��ʾ��־����
}T_LOGINFO;

///////DVR ���///////////////////////////////////////////////
typedef enum{
	UPDATE_TYPE_BOOT    =0X01, //����
	UPDATE_TYPE_LINUX   =0X02, //�ں�
	UPDATE_TYPE_ROOTFS  =0X03, //�ļ�ϵͳ
	UPDATE_TYPE_APP     =0X04, //���þ���
	UPDATE_TYPE_PTZ     =0X05, //PTZ�ű�

}ENU_UPDATETYPE;
typedef struct{
	INT                 nFileType;                  //�ļ����� (ENU_UPDATETYPE)
	INT					iFileLen;                   //�ļ�����
	CHAR				szUpdateFileName[128];      //�ļ�����(���ϴ洢���ƣ���ȫ·��)

}T_DEVUPDATE;


typedef struct{                                     //DVR.�ط�

	ULONG                StartTime ;                //�ļ���ʼʱ��
	ULONG                EndTime;                   //�ļ�����ʱ��
	CHAR                 FilePath[128];             //�ļ�����  
}T_DVRREPLAY;
typedef enum{
	FT_V_IOALM    =0,										//IO����¼���ļ�
	FT_V_MDALM    =1,										//�ƶ�֡�ⱨ��¼���ļ�
	FT_V_TMREC    =2,										//��ʱ¼���ļ�
	FT_V_NULL	  =3,										//�ļ���ѯʱ�������Ͳ�ѯ
}ENU_FILETYPE;
typedef struct{                                     //DVR.�ļ���ѯ
	USHORT               nChn;                      //�ļ�¼��ͨ��      //1CH=00,2CH=01,...����ͨ�� 0XFFFF
	USHORT               FileType;                  //�ļ�����:			ENU_FILETYPE       
	ULONG                FileSize;                  //�ļ���С
	ULONG                StartTime ;                //�ļ���ʼʱ��
	ULONG                EndTime;                   //�ļ�����ʱ��
	CHAR                 FileName[128];             //�ļ�����
}T_DVRFILESEARCH;

typedef struct{                                     //DVR.�ļ�����
    INT                  FileSize;                  //�ļ���С
    CHAR                 FileName[128];             //�ļ�����
}T_DVRFILEDOWNLOAD;
typedef enum {
    DVR_FILDOWNLOAD_ERR     =0X01,
	DVR_FILDOWNLOAD_FILINFO =0X02,                 //�ļ���Ϣ(T_DVRFILEDOWNLOADRESP)
	DVR_FILDOWNLOAD_DATA    =0X03,                 //�ļ�����
    DVR_FILDOWNLOAD_ENDDATA =0X04,                 //���ݽ���(IPC_DvrDonloadFil()��������)
}ENU_DVRFILDOWNLOADRET;
typedef enum {
 PLAYBACK_PAUSE             =0x50A1,               //DVR�ط�.��������
 PLAYBACK_NOMAL             =0x50A2,               //DVR�ط�.�������
 PLAYBACK_FASTx2            =0x50A3,               //DVR�ط�.�������
 PLAYBACK_FASTx4            =0x50A4,               //DVR�ط�.�ı����
 PLAYBACK_FASTx8            =0x50A5,               //DVR�ط�.�˱����
 PLAYBACK_BACK              =0x50A6,               //DVR�ط�.�����˲�
 PLAYBACK_BACKx2            =0x50A7,               //DVR�ط�.�����˲�
 PLAYBACK_BACKx4            =0x50A8,               //DVR�ط�.�ı��˲�
 PLAYBACK_BACKx8            =0x50A9,               //DVR�ط�.�˱��˲�
}ENU_PLAYBACKCTRL;
#endif


