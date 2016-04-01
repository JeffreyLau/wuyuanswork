//IPCAM_SysQueue.h

#ifndef __IPCAM_SYSQUEUE__
#define __IPCAM_SYSQUEUE__


#define MAX_VIDEO_BUFFSIZE 		  (400*1024)
#define MAX_AUDIO_BUFFSIZE 		  (4*1024)
#define MAX_MJPEG_BUFFSIZE		  (400*1024)


#define IPCAM_LOCAL_CHN 		  (2)  
#define IPCAM_NETWORK_CHN	 	  (0)

#define VIDEO_MAX_NUM			  (5)  // 32
#define AUDIO_MAX_NUM			  (50)
#define MJPEG_MAX_NUM			  (2)
#define VIDEO_MAX_IPB             (20)
#define VIDEO_MIX_IPB             (5)

#define VIDEO_I_FRAME			  (0)
#define VIDEO_P_FRAME			  (1)
#define VIDEO_B_FRAME			  (2)



#define VIDEO_LOCAL_RECORD		  (0)
#define VIDEO_NET_RECORD		  (1)


#define VOIDEO_MEDIATYPE_VIDEO	  (0)
#define VOIDEO_MEDIATYPE_AUDIO	  (1)
#define VOIDEO_MEDIATYPE_MJPEG	  (2)



typedef struct _IPCAM_VIDEO_BUFFER{
	CHAR	bzEncType;                                 //��������
	CHAR	dwBufferType;                              //������Ƶ �� IPC������Ƶ
	CHAR	dwFrameType;                               // 0 I Frame , 1 P frame  ,2  B frame 
	ULONG	dwFameSize;                                //֡�ߴ�
	ULONG	dwFrameNumber;                             //֡��ţ�ʼ�յ���
	USHORT	dwWidth;
	USHORT 	dwHeight;	
	UINT 	dwSec;		                               //֡��ʱ���,��ȷ�����뼶
	UINT 	dwUsec;		                               //֡��ʱ���,��ȷ��΢�뼶
	CHAR	VideoBuffer[MAX_VIDEO_BUFFSIZE];           ////ʵ��֡����100K	
	pthread_mutex_t	video_mutex;
}IPCAM_VIDEOBUFFER , *LPIPCAM_VIDEOBUFFER;
typedef struct _IPCAM_AUDIO_BUFFER{
 	CHAR	    bzEncType;                             //��������
	UINT		dwBufferType;                          //0������Ƶ �� 1 IPC������Ƶ
	UINT		dwFameSize;
	UINT		dwFrameNumber;
	UINT		dwSec;
	UINT		dwUsec;
	UCHAR	    AudioBuffer[MAX_AUDIO_BUFFSIZE];        //4K
	pthread_mutex_t	audio_mutex;
}IPCAM_AUDIOBUFFER , *LPIPCAM_AUDIOBUFFER;

typedef struct _IPCAM_JPG_BUFFER{
	UINT		dwBufferType; 	                        ///////������Ƶ �� IPC������Ƶ
	UINT		dwFameSize;		                        ////15k
	UINT		dwFrameNumber;
	UINT		dwWidth;
	UINT 	    dwHeight;	
	UINT		dwSec;
	UINT		dwUsec;
	CHAR	    MjpegBuffer[MAX_MJPEG_BUFFSIZE];         /////350K	
	pthread_mutex_t	jpg_mutex;
}IPCAM_MJPEGBUFFER , *LPIPCAM_MJPEGBUFFER;

typedef struct  _IPCAM_SYSBUFFER {
	VOID* 					pVideoList[IPCAM_LOCAL_CHN];	
	IPCAM_MJPEGBUFFER	 	MjpegBuffer[MJPEG_MAX_NUM]; 
	IPCAM_AUDIOBUFFER		AudioBuffer[AUDIO_MAX_NUM]; 
	INT						j_wIndex;
	INT						a_wIndex;
} IPCAM_SYSBUFFER, *LPIPCAM_SYSBUFFER;



/*********************************************************************************************************
����:�������ڴ����ģ���ṩ�ӿ�
***********************************************************************************************************/


#define HANDSYSBUFFER 		void*
#define HANDDATABUFFER 		void*
/***************************************************
����:
��ʼ��ϵͳ�ڴ�BUFFER����
���أ�
����NULL ����ʼ��ʧ��
���ط�NULL����ʼ���ɹ�
****************************************************/
HANDSYSBUFFER   Context_InitSysteBuffer();
void            Context_DelInitSysteBuffer();

/***************************************************
����:
����Ƶ���ݣ���Ƶ���ݣ�JPG����Ͷ�����ڴ���������ݴ�
����:
1,HandSysBuffer:����Context_InitSysteBuffer()��ʼ���ɹ�����ָ��
2,IsLocalRecord:��ʶ�Ƿ��Ǳ���¼��(VIDEO_LOCAL_RECORD)
������¼��(VIDEO_NET_RECORD)
3,nchannel:��ʶ¼��ͨ���ŷ�Χ(0,1,2,3)
4,mediaType:��ʶ¼������:
��Ƶ���ͣ�VOIDEO_MEDIATYPE_VIDEO
��Ƶ���ͣ�VOIDEO_MEDIATYPE_AUDIO
ͼ�����ͣ�VOIDEO_MEDIATYPE_MJPEG
5,pDataBuffer:���ڴ������Ͷ��¼���������ṹ���Ӧ�ã�
��Ƶ���ͣ�VOIDEO_MEDIATYPE_VIDEO        ��Ӧ��LPIPCAM_VIDEOBUFFER �ṹ
��Ƶ���ͣ�VOIDEO_MEDIATYPE_AUDIO        ��Ӧ��LPIPCAM_AUDIOBUFFER�ṹ
ͼ�����ͣ�VOIDEO_MEDIATYPE_MJPEG		��Ӧ��LPIPCAM_MjpegBuffer�ṹ
���أ�
����FALSE ��Ͷ������������ʧ��
����TRUE��Ͷ�����������ݳɹ�
****************************************************/
INT  IPCAM_PutStreamData( INT IsLocalRecord, INT  nchannel , INT  mediaType, HANDDATABUFFER pDataBuffer);

/***************************************************
����:
����Ƶ���ݣ���Ƶ���ݣ�JPG�������ڴ�������ڻ�ȡ
����:

IsLocalRecord:��ʶ�Ƿ��Ǳ���¼��(VIDEO_LOCAL_RECORD)
������¼��(VIDEO_NET_RECORD)

nchannel:��ʶ¼��ͨ���ŷ�Χ(1,2,3,4)

mediaType:��ʶ¼������:
��Ƶ���ͣ�VOIDEO_MEDIATYPE_VIDEO
��Ƶ���ͣ�VOIDEO_MEDIATYPE_AUDIO
ͼ�����ͣ�VOIDEO_MEDIATYPE_MJPEG
pBufferIndex��ָ������ȡ���ݶ�������

pDataBuffer:��ȡ�ڴ������¼���������ṹ���Ӧ�ã�
��Ƶ���ͣ�VOIDEO_MEDIATYPE_VIDEO       ��Ӧ��LPIPCAM_VIDEOBUFFER �ṹ
��Ƶ���ͣ�VOIDEO_MEDIATYPE_AUDIO       ��Ӧ��LPIPCAM_AUDIOBUFFER�ṹ
ͼ�����ͣ�VOIDEO_MEDIATYPE_MJPEG		��Ӧ��LPIPCAM_MjpegBuffer�ṹ
���أ�
����FALSE ��Ͷ������������ʧ��
����TRUE��Ͷ�����������ݳɹ�
****************************************************/
INT  IPCAM_GetStreamData( INT IsLocalRecord, INT nchannel , INT mediaType , INT* pBufferIndex , HANDDATABUFFER pDataBuffer);

INT  IPCAM_GetStreamDataEX( INT localType, INT channel , INT mediaType , INT* pBufferIndex, HANDDATABUFFER pVDataInstance,HANDLE pReadVHandle);

/***************************************************
����:
�������ݶ���
����:
IsLocalRecord:��ʶ�Ƿ��Ǳ���¼��(VIDEO_LOCAL_RECORD)
������¼��(VIDEO_NET_RECORD)
nchannel:��ʶ¼��ͨ���ŷ�Χ(1,2,3,4)
mediaType:��ʶ¼������:
��Ƶ���ͣ�VOIDEO_MEDIATYPE_VIDEO
��Ƶ���ͣ�VOIDEO_MEDIATYPE_AUDIO
ͼ�����ͣ�VOIDEO_MEDIATYPE_MJPEG

���أ�
����FALSE ���������ݶ���ʧ��
����TRUE���������ݶ��гɹ�
****************************************************/
INT IPCAM_ClearStreamDataQueue(UCHAR localType, UCHAR nchannel , UCHAR mediaType);

#endif



