#ifndef HK_RS_H__
#define HK_RS_H__

#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct RSObject RSObject;

///
typedef void (*RSObjectIRQEvent)(RSObject*, const char*, const char*, unsigned int);

///
//
struct RSObject
{
    ///Compare
    // 
    // �˺�������outpin �� inpin�ܷ����ӡ�
    // ����С��0Ϊ�������ӣ����ӣ�
    // 
    // char* myout = Compare( /*srcOut*/ "Type: Monitor\r\n"
    //                      "PinType: OUT\r\n"
    //                      "Capabilities: MPEG,MJPEG\r\n"
    //                      "Resolution: CIF,D1\r\n");
    //  if (myout)
    //  {
    //      // do something ...
    //      free(myout);
    //  }
    //
    char* (*Compare)(const char* src_out);

    ///SetIRQCallback
    //
    // ��Դ���¼��Ļص���������
    // �ص�����ԭ�ͣ�void (RSObject* from, const char* dev, int obj, const char* event)
    // �ص���Ϊ������
    //   RSObject* cam;
    //   RSObjectIRQEvent(cam, "DEV1", 8, "Content-Type: text/plain\r\n\r\nhello world!");
    //   RSObjectIRQEvent(cam, "DEV1", 8, "Content-Type: image/png\r\n"
    //                                  "Content-Length: 15\r\n\r\n...bin...data.");
    //   RSObjectIRQEvent(cam, "DEV2", 5, "RateModified: 15FS\r\n\r\n");
    //   RSObjectIRQEvent(cam, "DEV2", 0, "Offline: DEV3\r\n\r\n");
    //   RSObjectIRQEvent(cam, "DEV3", 0, "Online: DEV4\r\n\r\n");
    //
    void (*SetIRQEventCallback)(RSObjectIRQEvent irq);

    ///Retrive
    //
    // ������ʵ���������б����磺
    //
    // "DEV1,DEV2,DEV3,DEV4\r\n"
    //
    const char* (*Retrieve)();

    ///GetObjectInfo
    //
    // ��ȡ��Դ���������Ϣ��������ʽ������
    //
    // "Type: Monitor\r\n"
    // "PinType: OUT\r\n"
    // "Capabilities: MPEG5,H264,MJPEG\r\n"
    // "Resolution: CIF,D1,QCIF,QVGA\r\n"
    // "Rate: 12FS\r\n"
    // "Control: PTZ,RATE,CONTRAST\r\n"
    // 
    // "Type: Audio\r\n"
    // "PinType: OUT\r\n"
    // "Capabilities: G.723.1,G.729,G.711\r\n"
    //
    const char* (*GetObjectInfo)();

    ///Open
    //
    // ������ʵ�������ƣ�����ʵ����ʵ����
    //
    // int obj = Open("DEV1", "PinType: OUT\r\nEncode: MPEG4\r\nRate: 12FS\r\n");
    // ʧ�ܷ���-1
    // ����xmethod����ʶ����ͨ��Readȡ�ã�����ͨ���ص��������ա�
    //
    int (*Open)(const char* name, const char* args, int* imethod);

    ///Close
    //
    // �ر�һ���򿪵���ʵ����
    //
    void (*Close)(int obj);

    ///DoEvent
    //
    // ����ʵ�����Ͳ����¼������磺
    //
    // int obj = Open("DEV1", "Encode: MPEG4\r\n");
    // DoEvent("DEV1", obj, "Control: Rate=15FS\r\n");
    // DoEvent("DEV2", obj, "Control: PTZ=LEFT\r\n");
    //
    int (*DoEvent)(const char* dev, int obj, const char* ev);

    ///Write
    //
    // ����ʵ��д�����ݡ�
    //
    int (*Write)(int obj, const char* data, unsigned int len, long flags);

    ///Read
    //
    // ����ʵ����ȡ���ݡ�
    //
    int (*Read)(int obj, char* buf, unsigned int bufsiz, long* flags);

    ///Convert
    //
    // �˺�������filter��ʵ���������豸��������Դ����Ҫ�ṩ���������
    // ת�����ݣ�һ���Ǳ�����߽��룺
    //
    int (*Convert)(int obj, const char* in, unsigned int* ilen, char* out, unsigned int* olen, long* flags);
};

typedef void (*RegisterFunctType)(struct RSObject*);

#ifdef _WIN32
#  define DRV_EXPORT_API __declspec(dllexport)
#else
#  define DRV_EXPORT_API
#endif
DRV_EXPORT_API void RSLoadObjects(RegisterFunctType reg);
DRV_EXPORT_API void RSUnloadObject(RSObject* cls);

#define RS_LOAD_OBJECTS_NAME "RSLoadObjects"
#define RS_UNLOAD_OBJECTS_NAME "RSUnloadObject"

#if !defined(HK_SYSTEM_API)
#if defined(_WIN32)
#  ifdef HK_SYSTEM_EXPORTS
#    define HK_SYSTEM_API __declspec(dllexport)
#  else
#    define HK_SYSTEM_API __declspec(dllimport)
#  endif
#else
#  define HK_SYSTEM_API
#endif
#endif

#if defined(__cplusplus)
}
#endif

#endif // HK_RS_H__

