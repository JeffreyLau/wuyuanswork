//IPCAM_NetCommon.h

/*##############################################################################
#��������:
#       IP���������
#
#�ļ�����:
# 
#������Ϣ:
#      ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x 
#  	   All rights reserved.
###############################################################################*/

#ifndef IPCAM_NET_COMMON_H
#define IPCAM_NET_COMMON_H




#define     SUPER_USER_NAME        ("lhy")
#define     SUPER_USER_PASSWORD    ("lhy")
#define     SUPER_PRV                0
#define     ADMIN_PRV                1
#define     NORMAL_PRV               2

#define 	TIMEOUT_SEC             (5)
#define 	TIMEOUT_USEC            (0)

#define	    MAX_CLIENT_NUM	        (5)




typedef struct 
{
	UINT                client_sock;				        //accept�õ���socket
	CHAR                client_ip[16];			            //���������Ŀͻ���IP
	UINT                client_port;				        //�ͻ�����ʹ�õ�client_port
	INT               	DTChannelID;
	CHAR                enable;
	CHAR                videoType;                          //�ͻ������IPC��Ƶ����NDVR������Ƶ
	BOOL                IsPS;                               //PS ������ʽΪPS
	pthread_mutex_t     DTMutex;
	CHAR 				client_name[16];
} CLINETNETINFO,*LPCLIENTNETINFO;

typedef struct
{
	CLINETNETINFO	 clientArray[MAX_CLIENT_NUM];
	USHORT	         count;
}CLIENTLIST ,*LPCLIENTLIST;

typedef struct 
{
	CLINETNETINFO clinetnetinfo;
    NETMSGPACKET  quarypkt;
}NDVRCLINETINFO,*LPNDVRCLINETINFO;


INT   IPCAM_NetCreateTcpSock  (INT port);
INT   IPCAM_NetCreateUdpSock  (INT port) ;
INT	  IPCAM_NetSendPacketVa   (INT fd, UCHAR *buf, INT size, ULONG sec, ULONG usec);
INT	  IPCAM_NetSendPacket     (INT fd, void *buf, INT  len);
void  IPCAM_NetMakePacket     (NETMSGPACKET	*sp, ULONG	msg_type, ULONG	sub_type,INT len, ULONG	err_code);
INT   IPCAM_NetSetPacketHeader(USHORT	*ph);
INT	IPCAM_NetRecvPacket       (INT fd, UCHAR *buf, INT size,INT timeout);

T_MSGHEAD *IPCAM_NetMakeResp  (ULONG	  msg_type,
                        	   ULONG      sub_type,
                        	   ULONG      len,
                        	   ULONG      err_code,
                        	   T_MSGHEAD *mh);



typedef enum{
	TESTSOCKET_READ		= 0,	
	TESTSOCKET_WRITE	= 1
}TESTCTRL;

INT IPCAM_TestSocket(INT SocketFD, TESTCTRL Contrl, INT timeout);
INT IPCAM_SendPacket(INT SocketFd, CHAR *buf, INT buflen, int waitsec);
INT IPCAM_RecvPacket(INT SocketFd, CHAR *buf, INT buflen, int waitsec);
INT IPCAM_NetSetOpenMaxFileNum(INT max_num);




////zeng add
INT IPCAM_MakeMsgHead(T_MSGHEAD* pMsgHead, ULONG	msg_type, ULONG	sub_type,INT len, ULONG err_code);
INT IPCAM_SendNetMessage(INT fd,UCHAR* lpData, INT nLength , INT nTimeout);
INT IPCAM_RecvNetMessage(INT fd,UCHAR* buf, INT* len , INT nTimeOut);



#endif

