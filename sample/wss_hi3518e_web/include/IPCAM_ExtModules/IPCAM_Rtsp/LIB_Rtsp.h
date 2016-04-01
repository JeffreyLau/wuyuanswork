//LIB_RTSP.H
/*##############################################################################
#Project Description:
#      
#
# The File Description:
# �ÿ�֧��TCP������������ʱ����ΪTCP�ۺϷ����һ���֣����֧����Ƶ����ΪMPEG1,
# MPEG4 ,H264,��Ƶ֧��PCM8X8000,AMR�ȣ��ܼ���QT,Real,VLC��������������RTSP_Init()
# ���ó�ʼ��RTSP��,�������ṩRTSPCALLBACK��ģ��ص���ڣ��ص����û��봴��������
# �߳��Լ���������Ϣ����Ч��Ӧ(�ο�ʵ������)��RTSP_StreamCreate(),RTSP_StreamInit()
# ���ڴ���������pStreamSampleΪ������������Ƶ����������ҪIframe�����ڳ�ʼ��������.
# ���RTSP_StreamCreate()����ʱ���ṩ����������RTSP_StreamInit()�ɲ��ص��á�
# RTSP_Start()�ṩTCP��RTSP�������,RTSP_StreamSendData()���������ݣ�RTSP_StreamGetStatus()
# �����ڷ����߳��м��������״̬��
# Authors:
#       
#       
#Copyright:
#       Copyright(c) 2008~200x 
#  	  Fifo2005@gmail All rights reserved.
###############################################################################*/
 
#ifndef __LIB_RTSP_H
#define __LIB_RTSP_H

#ifndef HRTSPSERVER 
#define HRTSPSERVER INT
#endif//HRTSPSERVER
#ifndef HRTSPSTREAM
#define HRTSPSTREAM INT
#endif//HRTSPSTREAM


#ifndef CHAR
#define CHAR char
#endif//CHAR
#ifndef INT 
#define INT int
#endif
#ifndef UINT 
#define UINT unsigned int
#endif
#ifndef VOID
#define VOID void
#endif
#ifndef BOOL 
#define BOOL int
#endif
#ifndef TRUE
#define TRUE (INT) 1
#endif
#ifndef FALSE
#define FALSE (INT)0
#endif
typedef enum {
  STREAM_NULL          =0,
  STREAM_VIDEO_MPEG1   =1,
  STREAM_VIDEO_MPEG4   =2,
  STREAM_VIDEO_H264X   =3,
  STREAM_AUDIO_PCM     =4,
  STREAM_AUDIO_G722    =5,
  STREAM_AUDIO_G723    =6,
  STREAM_AUDIO_AAC     =7,
  STREAM_AUDIO_AMR     =8,
  STREAM_AUDIO_ULAW    =9,
  STREAM_AUDIO_ALAW    =10,
}ENU_STREAMTYPE;

typedef enum{
    RTSP_PLAY          =5,
    RTSP_REPLAY        =6,
    RTSP_PAUSE         =7,
    RTSP_TEARDOWN      =8,
    RTSP_ERROR         =11,  
    RTSP_DESTROY       =15,    
}ENU_RTSPMSG;

typedef enum{
    RTSP_MEDIA_NULL   =0,
    RTSP_MEDIA_TEXT   =1,
    RTSP_MEDIA_VIDEO  =2,
    RTSP_MEDIA_AUDIO  =4,  
}ENU_RTSPMEDIA;

typedef  INT  (*CBNEWSTREAM)(VOID * obj,CHAR* uMsg);
typedef  INT  (*CBAUTHCHECK)(CHAR *UserName,CHAR *Password); //LIBRTSP���ݿͻ����û���.�ʺ�,��������TRUE ͨ����֤��FALSE δͨ��

INT  			RTSP_Init                   (int Rtsp_port,CBNEWSTREAM  CallBackStream,BOOL isAuthCheck,CBAUTHCHECK CallBackAuth);
VOID    		RTSP_DeInit ();
INT             RTSP_StreamSendData       (INT  hRtspStream,ENU_RTSPMEDIA  MediaType, CHAR *pBuf, INT nLen,int nFrameRate,int nASendTime);
ENU_RTSPMSG     RTSP_StreamGetStatus      (INT  hRtspStream);
UINT            RTSP_StreamGetMediaType   (INT  hRtspStream);
CHAR           *RTSP_StreamGetPath        (INT  hRtspStream);
UINT               RTSP_StremExit(INT  hRtspStream);
VOID            RTSP_StreamSetDTInterval  (INT  hRtspStream,ENU_RTSPMEDIA  MediaType,INT DTInterval);

BOOL            RTSP_IsRTSP               (CHAR *pBuff,INT nBuffLen);

#endif

