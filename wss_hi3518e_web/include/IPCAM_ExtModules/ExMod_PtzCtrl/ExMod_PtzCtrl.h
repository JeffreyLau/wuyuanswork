#ifndef EXMOD_PTZCTRL_H
#define EXMOD_PTZCTRL_H


#ifdef __cplusplus
extern "C" {
#endif


#ifndef HPTZ 
#define HPTZ  void*
#endif
#ifndef UCHAR 
#define UCHAR unsigned char 
#endif
#ifndef CHAR 
#define CHAR char
#endif
#ifndef INT
#define INT int
#endif
#ifndef ULONG
#define ULONG unsigned long
#endif
#ifndef BOOL 
#define BOOL unsigned int
#endif
#ifndef NULL
#define NULL (void *) 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

//// ��̨��������
typedef enum
{
	PTZ_COMMAND_UNKNOWN = 0,	//// δ֪������
	PTZ_STOP			= 1,	//// ֹͣ������̨����


	UP_START			=2,		//// ���Ͽ�ʼ
	UP_STOP,					//// ����ֹͣ
	DOWN_START,					//// ���¿�ʼ
	DOWN_STOP,					//// ����ֹͣ

	LEFT_START,				//// ����ʼ
	LEFT_STOP,					//// ����ֹͣ
	RIGHT_START,				//// ���ҿ�ʼ
	RIGHT_STOP,					//// ����ֹͣ

	LEFT_UP_START,				//// ���Ͽ�ʼ
	LEFT_UP_STOP,				//// ����ֹͣ
	RIGHT_UP_START,				//// ���Ͽ�ʼ
	RIGHT_UP_STOP,				//// ����ֹͣ
	LEFT_DOWN_START,			//// ���¿�ʼ
	LEFT_DOWN_STOP,				//// ����ֹͣ
	RIGHT_DOWN_START,			//// ���¿�ʼ
	RIGHT_DOWN_STOP,			//// ����ͣ�

	SCAN_ON,					//// ��ɨ�迪
	SCAN_OFF,					//// ��ɨ���

	IRIS_OPEN_START,			//// ����Ȧ��ʼ
	IRIS_OPEN_STOP,				//// ����Ȧֹͣ
	IRIS_CLOSE_START,			//// �ع�Ȧ��ʼ
	IRIS_CLOSE_STOP,			//// �ع�Ȧͣ

	FOCUS_NEAR_START,			//// �������ʼ
	FOCUS_NEAR_STOP,			//// �����ֹͣ
	FOCUS_FAR_START,			//// ����Զ��ʼ
	FOCUS_FAR_STOP,				//// ����Զֹͣ

	ZOOM_WIDE_START,			//// ͼ���С��ʼ
	ZOOM_WIDE_STOP,				//// ͼ���Сֹͣ
	ZOOM_TELE_START,			//// ͼ����ʼ
	ZOOM_TELE_STOP,				//// ͼ����ֹͣ

	CAMERA_ON,					//// �������Դ��
	CAMERA_OFF,					//// �������Դ��
	LAMP_ON,					//// �ƹ⿪
	LAMP_OFF,					//// �ƹ��
	WIPER_ON,					//// ��ˢ��
	WIPER_OFF,					//// ��ˢ��

	PRESET_POINT,				//// ����Ԥ��λ
	SET_POINT,					//// ����Ԥ��λ
	//// �����������.....
} X_PTZ_COMMAND;


typedef struct {
CHAR    protocolName[20];     //��̨Э������
ULONG   baudRate;             //������
CHAR    dataSize;             //����λ
CHAR    parity;               //��żУ��
CHAR    stopBit;              //ֹͣλ
CHAR    flowControl;          //����
}IPCAM_PTZINFO;


HPTZ  PTZM_Init           (CHAR *filePath);
BOOL  PTZM_DeInit         (HPTZ hPtz);
BOOL  PTZM_GetPtzProParam (HPTZ hPtz,IPCAM_PTZINFO *ptzInfo);
BOOL  PTZM_SetPtzProParam (HPTZ hPtz,UCHAR address,UCHAR speed);
BOOL  PTZM_GetPtzCommand  (HPTZ hPtz,X_PTZ_COMMAND command,UCHAR *param,UCHAR * buffer,INT *nSize);//param������������в���


#ifdef __cplusplus
}  /* End of the 'extern "C"' block */
#endif

#endif

