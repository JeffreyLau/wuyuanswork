
typedef enum
{
	ONVIF_PTZ_CMD_UNKNOWN = 0,	//// δ֪������
	ONVIF_PTZ_STOP			= 1,	//// ֹͣ������̨����

	ONVIF_UP_START			=2,		//// ���Ͽ�ʼ
	ONVIF_UP_STOP,					//// ����ֹͣ
	ONVIF_DOWN_START,					//// ���¿�ʼ
	ONVIF_DOWN_STOP,					//// ����ֹͣ

	ONVIF_LEFT_START,				//// ����ʼ
	ONVIF_LEFT_STOP,					//// ����ֹͣ
	ONVIF_RIGHT_START,				//// ���ҿ�ʼ
	ONVIF_RIGHT_STOP,					//// ����ֹͣ

	ONVIF_LEFT_UP_START,				//// ���Ͽ�ʼ
	ONVIF_LEFT_UP_STOP,				//// ����ֹͣ
	ONVIF_RIGHT_UP_START,				//// ���Ͽ�ʼ
	ONVIF_RIGHT_UP_STOP,				//// ����ֹͣ
	ONVIF_LEFT_DOWN_START,			//// ���¿�ʼ
	ONVIF_LEFT_DOWN_STOP,				//// ����ֹͣ
	ONVIF_RIGHT_DOWN_START,			//// ���¿�ʼ
	ONVIF_RIGHT_DOWN_STOP,			//// ����ͣ?
	//// �����������.....
} ONVIF_PTZ_COMMAND;
typedef  int  (*CBPTZTEST)();

