//IPCAM_NetCommunication.h
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
#ifndef IPCAM_NET_COMMUNICATION_H
#define IPCAM_NET_COMMUNICATION_H

#define  	MAX_STREAM_SLICE	    			1024
#define	    MAX_STREAM_BUFLEN		    		(150*1024)//(350 * 1024)

#define     PORT_UDP_RESP               		40001               //UDP�豸��Ѱ��Ӧ�˿�
#define     PORT_UDP_SEARCH               		40002               //UDP�豸��Ѱ�źŶ˿�
#define 	MULTICASE_ADDR						"230.1.1.1"
////////////������Ϣ����/////////////////////////////////////////////////
#define 	MSG_USERLOGIN_REQ		    		0x0101		//�û���½����
#define 	MSG_USERLOGIN_RESP			        0x0102		//�û���½��Ӧ	
#define 	MSG_PULSE_REQ		    		    0x0103		//��������
#define 	MSG_PULSE_RESP			            0x0104		//������Ӧ

#define 	MSG_USERQUERY_REQ		    		0x0201		//�û���ѯ����	
#define 	MSG_USERQUERY_RESP			        0x0202		//�û���ѯ��Ӧ	

#define 	MSG_USERADD_REQ			        	0x0203		//�û��������	
#define 	MSG_USERADD_RESP		    		0x0204		//�û���ӻ�Ӧ	

#define 	MSG_USERDELETE_REQ			        0x0205		//�û�ɾ������	
#define 	MSG_USERDELETE_RESP			        0x0206		//�û�ɾ����Ӧ

#define     MSG_USERLISTQUARY_REQ     		    0X0207      //�û��б��ѯ
#define     MSG_USERLISTQUARY_RESP 		        0X0208      //�û��б��ѯ��Ӧ
#define     MSG_USERLISTNEXT_REQ      		    0X0209      //�б���һҳ
#define     MSG_USERLISTNEXT_RESP   		    0X020A      
#define     MSG_USERMODIFY_REQ        		    0X020B      //�û��޸�
#define     MSG_USERMODIFY_RESP       		    0X020C      //�û��޸���Ӧ


#define 	MSG_LOGEVENTQUERY_REQ	        	0x0303		//��־�澯��ѯ����
#define 	MSG_LOGEVENTQUERY_RESP	 	        0x0304		//��־�澯��ѯ��Ӧ	
#define 	MSG_LOGEVENTCLEAN_REQ	     		0x0305		//��־�澯�������	
#define 	MSG_LOGEVENTCLEAN_RESP	 	        0x0306		//��־�澯�����Ӧ
#define 	MSG_LOGEVENTNEXT_REQ	     		0x0307		//��־�澯��һ���¼
#define 	MSG_LOGEVENTNEXT_RESP	     		0x0308		//��־�澯��һ���¼
#define 	MSG_LOGEVENTQUERY_NOTFY	        	0x0309		//��־�澯��ʱ�ź�,���ظ�

#define 	MSG_VIDEOSET_REQ		     		0x0401		//��Ƶ��������	
#define 	MSG_VIDEOSET_RESP		     		0x0402		//��Ƶ���û�Ӧ
#define 	MSG_VIDEOQUARY_REQ	     	  	    0x0403		//��Ƶ��ѯ����	
#define 	MSG_VIDEOQUARY_RESP	     		    0x0404		//��Ƶ��ѯ��Ӧ
#define 	MSG_PICTURESET_REQ	     			0x0405      //ͼ����������
#define 	MSG_PICTURESET_RESP	     		    0x0406      //ͼ�����û�Ӧ
#define 	MSG_PICTUREQUERY_REQ	     		0x0407      //ͼ���ѯ����
#define 	MSG_PICTUREQUERY_RESP	     		0x0408      //ͼ���ѯ��Ӧ
#define		MSG_RTSPPAWDAUTH_REQ				0x0409		//rtsp������֤��½ CGI�ص�ʱ��
#define		MSG_RTSPPAWDAUTH_RESP				0x040a		//


#define 	MSG_AUDIOSET_REQ		     		0x0501		//��Ƶ��������	
#define 	MSG_AUDIOSET_RESP		     		0x0502		//��Ƶ���û�Ӧ
#define 	MSG_AUDIOQUARY_REQ	     	  	    0x0503		//��Ƶ��ѯ����	
#define 	MSG_AUDIOQUARY_RESP	     		    0x0504		//��Ƶ��ѯ��Ӧ

#define 	MSG_MOTIONPARMSET_REQ	        	0x0601		//�˶���������������	
#define 	MSG_MOTIONPARMSET_RESP	 	        0x0602		//�˶����������û�Ӧ
#define 	MSG_MOTIONPARMQUERY_REQ		        0x0603		//�˶���������ѯ����	
#define 	MSG_MOTIONPARMQUERY_RESP	        0x0604		//�˶���������ѯ��Ӧ	

#define 	MSG_MASKPARMSET_REQ	        	    0x0701		//�����ڸǲ�����������	
#define 	MSG_MASKPARMSET_RESP	 	        0x0702		//�����ڸǲ������û�Ӧ
#define 	MSG_MASKPARMQUERY_REQ		        0x0703		//�����ڸǲ�����ѯ����	
#define 	MSG_MASKPARMQUERY_RESP	            0x0704		//�����ڸǲ�����ѯ��Ӧ	

#define     MSG_PTZPARAMSET_REQ          		0x0901      //PTZ ��������
#define     MSG_PTZPARAMSET_RESP         		0x0902      //PTZ ����������Ӧ
#define     MSG_PTZPARAMQUERY_REQ        	    0x0903      //PTZ ������ȡ
#define     MSG_PTZPARAMQUERY_RESP       	    0x0904      //PTZ ������ȡ��Ӧ

#define     MSG_PTZWRITE_REQ              		0x0905      //PTZ д
#define     MSG_PTZWRITE_RESP             		0x0906      //PTZ д��Ӧ
#define     MSG_PTZNAMEQUARY_REQ          	    0x0907      //PTZ Э���ѯ
#define     MSG_PTZNAMEQUARY_RESP         	    0x0908      //PTZ Э��ظ�

#define 	MSG_IOQUERY_REQ				        0x0A01		//IO������ѯ����	
#define 	MSG_IOQUERY_RESP			     	0x0A02		//IO������ѯ��Ӧ
#define 	MSG_IOSET_REQ				    	0x0A03		//IO������������	
#define 	MSG_IOSET_RESP				    	0x0A04		//IO�������û�Ӧ	

#define 	MSG_CLOCKSET_REQ			    	0x0B01		//ʱ��У������	
#define 	MSG_CLOCKSET_RESP			    	0x0B02		//ʱ��У�Ի�Ӧ
#define 	MSG_CLOCKQUERY_REQ			        0x0B03		//ʱ�Ӳ�ѯ����	
#define 	MSG_CLOCKQUERY_RESP			        0x0B04		//ʱ�Ӳ�ѯ��Ӧ	

#define 	MSG_NETPARMSET_REQ			        0x0C01		//���������������	
#define 	MSG_NETPARMSET_RESP			        0x0C02		//����������û�Ӧ
#define 	MSG_NETPARMQUERY_REQ		        0x0C03		//���������ѯ����	
#define 	MSG_NETPARMQUERY_RESP		        0x0C04		//���������ѯ��Ӧ
#define     MSG_NETWIFIPARAMSET_REQ             0x0C05      //WIFI��������
#define     MSG_NETWIFIPARAMSET_RESP            0x0C06      //WIFI�����趨��Ӧ
#define     MSG_NETWIFIPARAMQUARY_REQ           0x0C07      //WIFI������ѯ
#define     MSG_NETWIFIPARAMQUARY_RESP          0x0C08      //WIFI������ѯ��Ӧ

#define     MSG_DEVICEABILITYSET_REQ            0X0D01      //�豸������������
#define     MSG_DEVICEABILITYSET_RESP           0X0D02      //�豸����������Ӧ
#define     MSG_DEVICEABILITYGET_REQ            0X0D03      //�豸���ܲ�ѯ����
#define     MSG_DEVICEABILITYGET_RESP           0X0D04      //�豸���ܲ�ѯ��Ӧ

#define 	MSG_STARTUPNP_REQ					0X0E01		//����upnp����		CGI
#define 	MSG_STARTUPNP_RESP 					0X0E02		//����upnp��Ӧ		CGI
#define 	MSG_REBOOT_REQ						0X0E03		//�豸��������		CGI
#define 	MSG_REBOOT_RESP						0X0E04		//�豸������Ӧ		CGI
#define 	MSG_STARTDDNS_REQ					0X0E05		//����ddns����		CGI
#define 	MSG_STARTDDNS_RESP					0X0E06		//����ddns��Ӧ		CGI
#define 	MSG_LOADCFG_REQ						0X0E07		//�ָ�������������	CGI
#define 	MSG_LOADCFG_RESP					0X0E08		//�ָ��������û�Ӧ	CGI
#define 	MSG_SAVECFG_REQ						0X0E09		//������������		CGI
#define 	MSG_SAVECFG_RESP					0X0E0A		//�������û�Ӧ		CGI
#define 	MSG_STARTNTP_REQ					0X0E0B		//����ntp����		CGI
#define  	MSG_STARTNTP_RESP					0X0E0C		//����ntp��Ӧ		CGI
#define 	MSG_SETSYSTIME_REQ					0X0E0D		//����ϵͳʱ������	CGI
#define		MSG_SETSYSTIME_RESP					0X0E0E		//����ϵͳʱ���Ӧ	CGI
#define 	MSG_SETSERVICEPORT_REQ				0X0E0F		//�ı����˿�����	CGI
#define 	MSG_SETSERVICEPORT_RESP				0X0E10		//�ı������Ʒ��Ӧ	CGI
#define 	MSG_SETPPPOE_PARAM_REQ				0X0E11		//����pppoe��������	CGI
#define 	MSG_SETPPPOE_PARAM_RESP				0X0E12		//����pppoe������Ӧ	CGI
#define 	MSG_OPENIRCUT_REQ					0X0E13		//��IR-CUT����
#define 	MSG_OPENIRCUT_RESP					0X0E14		//��IR-CUT��Ӧ
#define 	MSG_CLOSEIRCUT_REQ					0X0E15		//�ر�IR-CUT����
#define 	MSG_CLOSEIRCUT_RESP					0X0E16		//�ر�IR-CUT��Ӧ

#define 	MSG_ALARMSTATUS_REQ					0X0F01		//������ѯ����(����Ӧ�ó�������б���)
#define 	MSG_ALARMSTATUS_RESP				0X0F02		//������ѯ��Ӧ


#define     MSG_SEARCHQUERY_REQ                 0x2001      //�豸����
#define     MSG_SEARCHQUERY_RESP                0x2002      //�豸������Ӧ
#define     MSG_DEVREGIST_REQ                   0x2003      //�豸ע��
#define     MSG_DEVREGIST_RESP                  0x2004      //�豸ע����Ӧ

#define		MSG_FACTORYINFOSET_REQ			    0x2005		//������Ϣ����
#define		MSG_FACTORYINFOSET_RESP				0x2006		//������Ϣ���û�Ӧ
#define     MSG_FACTORYINFOQUARY_REQ            0x2007
#define     MSG_FACTORYINFOQUARY_RESP           0x2008      //

#define		MSG_UPDATE_REQ						0x2101		//������̨Э��
#define		MSG_UPDATE_RESP						0x2102		//����Ӧ�ó���

#define     MSG_OSDQUARY_REQ                    0x2201      //OSD������ѯ
#define     MSG_OSDQUARY_RESP                   0x2202      //OSD������ѯ��Ӧ
#define     MSG_OSDSET_REQ                      0x2203      //OSD��������
#define     MSG_OSDSET_RESP                     0x2204      //OSD�������û�Ӧ
//DVR.�ط�
#define     MSG_REPLAY_REQ                      0X5001      //DVR�ط�
#define     MSG_REPLAY_RESP                     0X5002      //DVR�ط���Ӧ
#define     MSG_REPLAY_SUB_PAUSE                0x50A1      //DVR�ط�.��������
#define     MSG_REPLAY_SUB_NOMAL                0x50A2      //DVR�ط�.�������
#define     MSG_REPLAY_SUB_FASTx2               0x50A3      //DVR�ط�.�������
#define     MSG_REPLAY_SUB_FASTx4               0x50A4      //DVR�ط�.�ı����
#define     MSG_REPLAY_SUB_FASTx8               0x50A5      //DVR�ط�.�˱����
#define     MSG_REPLAY_SUB_BACK                 0x50A6      //DVR�ط�.�����˲�
#define     MSG_REPLAY_SUB_BACKx2               0x50A7      //DVR�ط�.�����˲�
#define     MSG_REPLAY_SUB_BACKx4               0x50A8      //DVR�ط�.�ı��˲�
#define     MSG_REPLAY_SUB_BACKx8               0x50A9      //DVR�ط�.�˱��˲�
#define     MSG_REPLAY_SUB_SETFILE              0x50AA      //DVR�ط�.����ָ���ļ�
//DVR.����
#define     MSG_FILESEARCH_REQ                  0x5101      //DVR.�ļ���ѯ
#define     MSG_FILESEARCH_RESP                 0x5102      //DVR.�ļ���ѯ��Ӧ
//DVR.����
#define     MSG_FILEDOWNLOAD_REQ                0X5201      //DVR.�ļ�����
#define     MSG_FILEDOWNLOAD_RESP               0X5202      //DVR.�ļ�������Ӧ

//PRECOMMAND ��������Ԥ��������(��Ҫ�����ж���ǰ���ӵ���������)
#define     MSG_CONNECT_SESSION            		0XFF01
#define     MSG_CONNECT_GETVIDEO           		0XFF02
#define     MSG_CONNECT_GETAUDIO           		0XFF03
#define     MSG_CONNECT_ALARM              		0XFF04
#define     MSG_CONNECT_PUTVIDEO           		0XFF05
#define     MSG_CONNECT_PUTAUDIO           		0XFF06
#define     MSG_CONNECT_UPDATE             		0XFF07       //update
#define     MSG_CONNECT_DVRPLAY            		0XFF08       //dvr play
#define     MSG_CONNECT_DVRDOWNLOAD        		0XFF09       //file download
#define     MSG_CONNECT_DVRFILESEARCH     		0XFF0A       //DVR �ļ���ѯ
#define 	MSG_CONNECT_LOGSEARCH				0XFF0B		 //��־��ѯ
#define     MSG_CONNECT_REFUSE             		0XFFFF       //refuse

#define 	MSG_DATA_VIDEO				   		0xFE01	     //-ʵʱ��Ƶ����	
#define 	MSG_DATA_AUDIO				   		0xFE02	     //-ʵʱ��Ƶ����
#define     MSG_DATE_FILEDOWLOAD                0xFE03       //�ļ��������ݸ���
#define     MSG_DATE_FILESEARCH                 0xFE04       //�ļ���Ѱ���ݸ���
#define     MSG_DATE_DVRREPLAY_VIDEO            0xFE05       //�ļ��ط����ݸ���.��Ƶ
#define     MSG_DATE_DVRREPLAY_AUDIO            0xFE06       //�ļ��ط����ݸ���.��Ƶ
#define     MSG_DATE_END                        0xFE07       //���ݽ���
#define     MSG_DATA_HEAD                       0xFE08       //���ݽ���
#define     MSG_DATA_TS							0xFE09       //���ݽ���
#define     MSG_DATA_PS							0xFE0A       //���ݽ���


#define	    ERR_UNKNOW			    			(0xFFFF)
#define     ERR_STREAM_NODATA                   (0xff01)
#define	    ERR_NO_ERROR						(0x0001)
#define	    ERR_NO_THIS_USER					(0x0002)
#define	    ERR_PASSOWRD						(0x0003)
#define	    ERR_USER_EXISTED					(0x0004)
#define	    ERR_DEL_ADMIN						(0x0005)	
#define	    ERR_NO_PRIORITY						(0x0006)
#define     ERR_DVRFILE_SEARCH                  (0x0007)     //����.DVR�ļ���Ѱ����
#define     ERR_DVRFILE_DOWNLAOD                (0x0008)     //����.DVR�ļ����ش���
////////////������Ϣ.Э��ṹ����////////////////////////////////////////////
#define     __start_code__              ((USHORT)0xE0AF)

#include "IPCAM_NetCommunicationT.h"
typedef struct {                      //��ͷ
	USHORT     sync;
	USHORT	   msgType;
	USHORT     subType;
	USHORT	   len;
	USHORT	   errCode;
    USHORT     reserve;
	char	lpData[];
	      
}T_MSGHEAD; 
typedef struct {
	T_MSGHEAD  head;
	CHAR       msgbuf[532];
}T_MSGBUF;

typedef struct{
	
	T_MSGHEAD		   head;
	T_IPCVIDEOPARAM    videoParam;	
}IPCAM_VIDEO_PARAM_SET_REQ,  IPCAM_VIDEO_PARAM_SET_RESP,
 IPCAM_VIDEO_PARAM_QUARY_REQ,IPCAM_VIDEO_PARAM_QUARY_RESP;
typedef struct{

    T_MSGHEAD	       head;
	T_IPCPICTUERPARAM  picParam;
}IPCAM_PICTURE_PARAM_SET_REQ,IPCAM_PICTURE_PARAM_SET_RESP,
 IPCAM_PICTURE_PARAM_QUARY_REQ,IPCAM_PICTURE_PARAM_QUARY_RESP;
typedef struct{
	T_MSGHEAD		    head;
    T_IPCNETPARAM       netparam;
}IPCAM_NET_PARAM_SET_REQ,  IPCAM_NET_PARAM_SET_RESP,
 IPCAM_NET_PARAM_QUARY_REQ,IPCAM_NET_PARAM_QUARY_RESP;
typedef struct{
	T_MSGHEAD		    head;
    T_IPCNETWIFIPARAM   WifiParam;
}IPCAM_NET_WIFIPARAM_SET_REQ,  IPCAM_NET_WIFIPARAM_SET_RESP,
 IPCAM_NET_WIFIPARAM_QUARY_REQ,IPCAM_NET_WIFIPARAM_QUARY_RESP;
typedef struct{
	T_MSGHEAD		     head;
    T_IPCIOALARMPARAM    ioAlarm;
}IPCAM_IO_ALARM_SET_REQ,  IPCAM_IO_ALARM_SET_RESP,
 IPCAM_IO_ALARM_QUARY_REQ,IPCAM_IO_ALARM_QUARY_RESP;

typedef struct{
	T_MSGHEAD		      head;
    T_IPCMOTIONALARMPARAM motionAlaram;
}IPCAM_MOTION_ALARM_SET_REQ, IPCAM_MOTION_ALARM_SET_RESP,
IPCAM_MOTION_ALARM_QUARY_REQ,IPCAM_MOTION_ALARM_QUARY_RESP;
typedef	struct { 
	T_MSGHEAD		      head;
    T_IPCMASKPARAM        MaskParam;
}IPCAM_MASK_SET_REQ, IPCAM_MASK_SET_RESP,
 IPCAM_MASK_QUARY_REQ,IPCAM_MASK_QUARY_RESP;
typedef	struct { 
	T_MSGHEAD		      head;
	T_IPCPTZPARAM         ptzName;
} IPCAM_PTZ_PARAM_SET_REQ,  IPCAM_PTZ_PARAM_SET_RESP,
  IPCAM_PTZ_PARAM_QUARY_REQ,IPCAM_PTZ_PARAM_QUARY_RESP;

typedef	struct { 
	T_MSGHEAD		      head;
	T_IPCPTZPARAM         ptzScriptName[10];
	INT                   ptzScriptCount;
}IPCAM_PTZ_NAME_QUARY_REQ,IPCAM_PTZ_NAME_QUARY_RESP;
typedef	struct { 
	T_MSGHEAD		      head;
    T_IPCPTZCOMMAND       ptzcommand;
} IPCAM_PTZ_COMMAND_REQ,IPCAM_PTZ_COMMAND_RESP;

typedef	struct {           //DVR.�ط�
    T_MSGHEAD		   head;
    T_DVRREPLAY            file;
}DVR_REPLAY_REQ,DEV_REPLAY_RESP;

typedef	struct {          //DVR.�ļ�����
    T_MSGHEAD		   head;
    T_DVRFILESEARCH        file;
}DVR_FILE_QUARY_REQ,DEV_FILE_QUARY_RESP;

typedef	struct {           //DVR.�ļ�����
    T_MSGHEAD		   head;
    T_DVRFILEDOWNLOAD      file;
}DVR_FILE_DOWNLOAD_REQ,DEV_FILE_DOWNLOAD_RESP;

typedef struct               //�û���¼����
{
	T_MSGHEAD		      head;
	UCHAR	      		  userName[16];
	UCHAR	      		  password[16];	
}IPCAM_LOGIN_REQ,IPCAM_LOGIN_RESP;

typedef struct             //�û���ѯ���Լ��޸ģ��������ɾ��
{
	T_MSGHEAD		     head;
	T_IPCUSERPARAM       userlist[10];
}IPCAM_USER_QUERY_REQ,IPCAM_USER_QUERY_RESP,
 IPCAM_USER_SET_REQ,  IPCAM_USER_SET_RESP;

typedef struct{				//�豸����
	T_MSGHEAD			head;
	T_DEVSEARCHINFO		DevSearchInfo;
}IPCAM_DEV_SEARCH_REG, IPCAM_DEV_SEARCH_RESP;

typedef struct{
	T_MSGHEAD			head;
	T_DEVUPDATE			DevUpdate;
}IPCAM_DEV_UPDATE_REG, IPCAM_DEV_UPDATE_RESP;

typedef struct{
	T_MSGHEAD			head;
	T_IPCFACTORYPARAM	FactoryParam;
}IPCAM_FACTORY_PARAM_REQ;

typedef struct{
	T_MSGHEAD			head;
	T_IPCAUDIOPARAM		AudioParam;
}IPCAM_AUDIO_PARAM_REQ;
typedef struct 
{
	T_MSGHEAD		     head;
	T_IPCSIGNALNOTIFY    SignalNotify;
}IPCAM_SIGNAL_NOTIFY;
typedef struct 
{
	T_MSGHEAD			head;
	T_IPCABILITYYPARAM	DevAbility;
}IPCAM_DEVABILITY_REQ, IPCAM_DEVABILITY_RESP;
typedef struct
{
	T_MSGHEAD			head;
	T_ALARMSTATUS		AlarmStatus;
}IPCAM_ALARMSTATUS_REQ;
typedef struct 
{
	T_MSGHEAD head;
	T_LOGINFO LogInfo;
}IPCAM_LOG_REQ, IPCAM_LOG_RESP;
typedef struct
{
	T_MSGHEAD head;
	T_IPCTIMEPARAM IpcTime;
}IPCAM_TIME_REQ, IPCAM_TIME_RESP;
typedef struct 
{
	T_MSGHEAD head;
	T_IPCOSDPARAM OsdInfo;
}IPCAM_OSDSET_REQ, IPCAM_OSDSET_RESP;


typedef struct{
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	USHORT 	    SliceNum;		 	       //��Ƭ�����
	USHORT	    SliceSize;			       //Ƭ�ߴ�

	USHORT	    Reserve1;		           //�����ֽ�
	USHORT 	    Reserve2;			       //�����ֽ�

	USHORT 	    EncType;                   //�������� //,ENU_STREAMENCTYPE
	USHORT      Reserve3;                  //�����ֽ�
	
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
	UCHAR		Data[MAX_STREAM_BUFLEN];   // frame valid data
}NETAUDIODATAPS,*LPNETAUDODATAPS;



typedef struct{
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	USHORT 	    SliceNum;		 	       //��Ƭ�����
	USHORT	    SliceSize;			       //Ƭ�ߴ�

	USHORT	    Reserve1;		           //�����ֽ�
	USHORT 	    Reserve2;			       //�����ֽ�
	USHORT 	    EncType;                   //�������� //,ENU_STREAMENCTYPE

	USHORT      Reserve3;                  //�����ֽ�
	
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
	UCHAR		Data[MAX_STREAM_SLICE];    // frame valid data
}NETAUDIODATATS,*LPNETAUDODATATS;


typedef union{
	
	T_MSGHEAD		               MsgHead;
	T_MSGBUF                       MsgBuf;
	NETAUDIODATATS 				   MsgAudio;		
	IPCAM_LOGIN_REQ                MsgUserLogin;
    //�˻�����
	IPCAM_USER_QUERY_REQ           MsgUserInfo;	
	//�����趨 SET
	IPCAM_FACTORY_PARAM_REQ		   MsgFactoryParam;
	//VIDEO SET
	IPCAM_VIDEO_PARAM_SET_REQ	   MsgVideoParam;
	//��Ƶ������ѯ
	IPCAM_AUDIO_PARAM_REQ          MsgAudioParam;
    //PICTURE SET
	IPCAM_PICTURE_PARAM_QUARY_REQ  MsgPictureParam;
	//NET PARAM SET
	IPCAM_NET_PARAM_SET_REQ	       MsgNetParam;
    //NET WIFI SET
    IPCAM_NET_WIFIPARAM_SET_REQ    MsgNetWifiParam;
	//IO ALARM SET
	IPCAM_IO_ALARM_SET_REQ	       MsgAlarmParam;
	//MOTION ALARM SET
	IPCAM_MOTION_ALARM_SET_REQ	   MsgMotionParam;
	//�ڸ�
	IPCAM_MASK_SET_REQ             MsgMaskParam;
	//PTZ SET
	IPCAM_PTZ_PARAM_SET_REQ	       MsgPtzParam;
	//PTZ SCRIPT SEARCH
	IPCAM_PTZ_NAME_QUARY_REQ       MsgPtzNameParam;
	//PTZ COMMAND 
	IPCAM_PTZ_COMMAND_REQ	       MsgPtzCommand;
	//�豸����
	IPCAM_DEV_SEARCH_REG		   MsgDevSearch;
	//�豸����
	IPCAM_DEV_UPDATE_REG		   MsgDevUpdate;
	//NOTIFY
	IPCAM_SIGNAL_NOTIFY            MsgSignalNotify;
	//�豸����
	IPCAM_DEVABILITY_REQ		   MsgDevAbility;
	//����״̬��ѯ
	IPCAM_ALARMSTATUS_REQ		   MsgAlarmStatus;
	//��־��ѯ
	IPCAM_LOG_REQ				   MsgLog;
	//ʱ���ѯ�趨
	IPCAM_TIME_REQ				   MsgTime;
	//OSD��ѯ������
	IPCAM_OSDSET_REQ			   MsgOsd;
		
	//DVR.�ļ���ѯ
	DVR_FILE_QUARY_REQ             MsgFileSearch;
	//DVR.�ļ�����
    DVR_FILE_DOWNLOAD_REQ          MsgFileDowLoad;
    //DVR.�ط�
    DVR_REPLAY_REQ                 MsgReplay;
	


}NETMSGPACKET,*LPNETMSGPACKET;
#define  	SIZEOFNETMSGHEAD	         (sizeof(T_MSGHEAD))
#define     SIZEOFNETMSGPACK             (sizeof(NETMSGPACKET))  

/////////////////////////ý����Э��ṹ����/////////////////////
typedef enum{
 STREAM_ENCTYPE_VIDEO_MJPEG       =0,
 STREAM_ENCTYPE_VIDEO_MPEG4       =1,
 STREAM_ENCTYPE_VIDEO_h264        =2,
 STREAM_ENCTYPE_AUDIO_PCM8X8K     =6,
 STREAM_ENCTYPE_AUDIO_PCM16X8K    =7,
 STREAM_ENCTYPE_AUDIO_ADPCM16X8K  =8,
 STREAM_ENCTYPE_AUDIO_AMR16X8K    =9,
 STREAM_ENCTYPE_AUDIO_G711UL      =10,
 STREAM_ENCTYPE_AUDIO_G711AL      =11,
 STREAM_ENCTYPE_AUDIO_AAC         =12,

}ENU_STREAMENCTYPE;
typedef enum{
STREAM_VIDEO_I_FRAME			 =0,
STREAM_VIDEO_P_FRAME			 =1,
STREAM_VIDEO_B_FRAME			 =3,
}ENU_STREAMFRAMTYPE;

//����ƵЭ��
typedef struct {
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	ULONG 	    SliceNum;		 	       //��Ƭ�����
	ULONG	    SliceSize;			       //Ƭ�ߴ�
	USHORT	    ResolutionX;		       //I֡P֡��ϵ���ţ�ʼ�յ���
	USHORT 	    ResolutionY;			   //��һ��֡����е����

	USHORT 	    EncType;                   //�������� 0-MJPEG 1-MPEG4 ,2-H264 ENU_STREAMENCTYPE
	USHORT      FrameType;                 //֡���ͣ�0-I֡, 1-P֡
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
}NETVIDEODATAPSHEAD,NETAUDIODATAPSHEAD;
typedef struct {
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	USHORT 	    Reserve1;		 	       //����
	USHORT	    Reserve2;			       //����
	USHORT	    ResolutionX;		       //I֡P֡��ϵ���ţ�ʼ�յ���
	USHORT 	    ResolutionY;			   //��һ��֡����е����

	USHORT 	    EncType;                   //�������� 0-MJPEG 1-MPEG4 ,2-H264 ENU_STREAMENCTYPE
	USHORT      FrameType;                 //֡���ͣ�0-I֡, 1-P֡
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
	UCHAR	    Data[MAX_STREAM_BUFLEN];   //ʵ��֡����
} NETVIDEODATAPS,*LPVIDEODATAPS;           //PS �ṹ����

typedef struct{
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	USHORT 	    SliceNum;		 	       //��Ƭ�����
	USHORT	    SliceSize;			       //Ƭ�ߴ�
	USHORT	    ResolutionX;		       //I֡P֡��ϵ���ţ�ʼ�յ���
	USHORT 	    ResolutionY;			   //��һ��֡����е����

	USHORT 	    EncType;                   //�������� 0-MJPEG 1-MPEG4 ,2-H264, ENU_STREAMENCTYPE
	USHORT      FrameType;                 //֡���ͣ�0-I֡, 1-P֡
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
//	UCHAR		Data[MAX_STREAM_SLICE];    // frame valid data
}NETVIDEODATATS_HEAD,*LPVIDEODATATS_HEAD;            //TS�����ṹ

typedef struct{
	T_MSGHEAD   MsgHead;                   //��׼��ͷ
	ULONG 	    FrameNumber;	 	       //֡��ţ�ʼ�յ���
	ULONG	    FrameSize;		           //֡�ߴ�
	USHORT 	    SliceNum;		 	       //��Ƭ�����
	USHORT	    SliceSize;			       //Ƭ�ߴ�
	USHORT	    ResolutionX;		       //I֡P֡��ϵ���ţ�ʼ�յ���
	USHORT 	    ResolutionY;			   //��һ��֡����е����

	USHORT 	    EncType;                   //�������� 0-MJPEG 1-MPEG4 ,2-H264, ENU_STREAMENCTYPE
	USHORT      FrameType;                 //֡���ͣ�0-I֡, 1-P֡
	time_t		time;			           //֡��ʱ���,��ȷ�����뼶
	time_t		usec;
	UCHAR		Data[MAX_STREAM_SLICE];    // frame valid data
}NETVIDEODATATS,*LPVIDEODATATS;         //TS�����ṹ


#define SIZEOFNETVIDEOTS (sizeof(NETVIDEODATATS))
#define SIZEOFNETAUDIOTS (sizeof(NETAUDIODATATS))

#endif


