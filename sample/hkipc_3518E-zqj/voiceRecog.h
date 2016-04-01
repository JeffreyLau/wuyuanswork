/************************************************************************ 
android/iphone/windows/linux����ͨѶ��
����ͨѶ�������� 
׼ȷ��95%���ϣ���ʵһ���ǲ������ġ� 
�ӿڷǳ��򵥣���������ʾ����3���ӾͿ��������Ӧ����������ͨѶ���� 
��������ǿ�����������������ô���ţ��źŶ���׼ȷ�� 
�����ı���Ϊ16���ƣ���ͨ������ɴ����κ��ַ� 
���ܷǳ�ǿ��û�����в��˵�ƽ̨������ͨ���ڴ���Ż�����ʱ����벻�ٷ������ڴ棬��7*24Сʱ���� 
��֧���κ�ƽ̨��������ƽ̨android, iphone, windows, linux, arm, mipsel����ʾ�� 
����ɲ鿴��http://blog.csdn.net/softlgh 
����: ҹ���� QQ:3116009971 �ʼ���3116009971@qq.com 
************************************************************************/  

#ifdef VOICE_RECOG_DLL
#define VOICERECOGNIZEDLL_API __declspec(dllexport)
//#else
//#ifdef WIN32
//#define VOICERECOGNIZEDLL_API __declspec(dllimport)
#else
#define VOICERECOGNIZEDLL_API
//#endif
#endif


#ifndef VOICE_RECOG_H
#define VOICE_RECOG_H

#ifdef __cplusplus
extern "C" {
#endif
	enum VRErrorCode
	{
		VR_SUCCESS = 0, VR_NoSignal = -1, VR_ECCError = -2, VR_NotEnoughSignal = 100
		, VR_NotHeaderOrTail = 101, VR_RecogCountZero = 102
	};

	enum DecoderPriority
	{
		CPUUsePriority = 1//��ռ�ڴ棬��CPU���ıȽϴ�һЩ
		, MemoryUsePriority = 2//��ռCPU�����ڴ����Ĵ�һЩ
	};

	typedef enum {vr_false = 0, vr_true = 1} vr_bool;

	typedef void (*vr_pRecognizerStartListener)(void *_listener, float _soundTime);
	//_result���ΪVR_SUCCESS�����ʾʶ��ɹ�������Ϊ�����룬�ɹ��Ļ�_data��������
	typedef void (*vr_pRecognizerEndListener)(void *_listener, float _soundTime, int _result, char *_data, int _dataLen);

	//��������ʶ����
	VOICERECOGNIZEDLL_API void *vr_createVoiceRecognizer(enum DecoderPriority _decoderPriority);
	VOICERECOGNIZEDLL_API void *vr_createVoiceRecognizer2(enum DecoderPriority _decoderPriority, int _sampleRate);

	//����ʶ����
	VOICERECOGNIZEDLL_API void vr_destroyVoiceRecognizer(void *_recognizer);

	//���ý���Ƶ��
	//�ܹ���16+3��Ƶ�ʣ�����Ϊ1����ʼ�ַ��� 0-f��16�����ַ���1���ظ���־�ַ���1�������ַ�
	//_freqs�����Ǿ�̬�ģ�������������в����ͷ�
	VOICERECOGNIZEDLL_API void vr_setRecognizeFreqs(void *_recognizer, int *_freqs, int _freqCount);

	//����ʶ���źŵļ�����
	VOICERECOGNIZEDLL_API void vr_setRecognizerListener(void *_recognizer, void *_listener, vr_pRecognizerStartListener _startListener, vr_pRecognizerEndListener _endListener);

	//��ʼʶ��
	//����һ�����̣߳����������ֹͣʶ��֮ǰ���᷵��
	VOICERECOGNIZEDLL_API void vr_runRecognizer(void *_recognizer);

	//��ͣ�źŷ���
	VOICERECOGNIZEDLL_API void vr_pauseRecognize(void *_recognizer, int _microSeconds);

	//ֹͣʶ�𣬸ú������ú�vr_runRecognizer�᷵��
	//�ú���ֻ����ʶ���̷߳����˳��źţ��ж�ʶ�����Ƿ������Ѿ��˳�Ҫʹ�����µ�vr_isRecognizerStopped����
	VOICERECOGNIZEDLL_API void vr_stopRecognize(void *_recognizer);

	//�ж�ʶ�����߳��Ƿ��Ѿ��˳�
	VOICERECOGNIZEDLL_API vr_bool vr_isRecognizerStopped(void *_recognizer);

	//Ҫ����������Ҫ��Ϊ44100����������16bits�������ȣ�С�˱������Ƶ����
	//С�˱��벻���ر���һ����¼�������ݶ���С�˱����
	VOICERECOGNIZEDLL_API int vr_writeData(void *_recognizer, char *_data, int _dataLen);	




	//Ӧ�ò����ӿ�

	int vr_decodeData(char *_hexs, int _hexsLen, int *_hexsCostLen, char *_result, int _resultLen);
	
	VOICERECOGNIZEDLL_API vr_bool vr_decodeString(int _recogStatus, char *_data, int _dataLen, char *_result, int _resultLen);

	//��������������ͱ�־
	enum InfoType
	{
		IT_WIFI = 0//˵�����������ΪWiFi
		, IT_SSID_WIFI = 1//ssid�����WIFI
		, IT_PHONE = 2//˵�����������Ϊ�ֻ�ע����Ϣ
		, IT_STRING = 3//�����ַ���
	};

	VOICERECOGNIZEDLL_API enum InfoType vr_decodeInfoType(char *_data, int _dataLen);

	//wifi����
	struct WiFiInfo
	{
		char mac[8];
		int macLen;
		char pwd[80];
		int pwdLen;
	};

	VOICERECOGNIZEDLL_API vr_bool vr_decodeWiFi(int _result, char *_data, int _dataLen, struct WiFiInfo *_wifi);

	struct SSIDWiFiInfo
	{
		char ssid[32];
		int ssidLen;
		char pwd[80];
		int pwdLen;
	};

	VOICERECOGNIZEDLL_API vr_bool vr_decodeSSIDWiFi(int _result, char *_data, int _dataLen, struct SSIDWiFiInfo *_wifi);

	struct PhoneInfo
	{
		char imei[18];
		int imeiLen;
		char phoneName[20];
		int nameLen;
	};

	VOICERECOGNIZEDLL_API vr_bool vr_decodePhone(int _result, char *_data, int _dataLen, struct PhoneInfo *_phone);


#ifdef __cplusplus
}
#endif

#endif


