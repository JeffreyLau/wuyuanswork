//IPCAM_export.h

#ifndef __IPCAM_EXPORT__
#define __IPCAM_EXPORT__


////////////ȫ�ֶ���/////////////////////////
#include "IPCAM_Global.h"
////////////��չ��///////////////////////////

//Web������
#include "IPCAM_ExtModules/IPCAM_WebServer/IPCAM_WebServer.h"
//XML
#include "IPCAM_ExtModules/IPCAM_Xml/LIB_Xml.h"
//onvif������
//#include "IPCAM_ExtModules/IPCAM_Onvif/OVF_Export.h"
#include "IPCAM_ExtModules/ExMod_OnvifServer/onvif_api.h"
//RTSP��׼��֧��
#include "IPCAM_ExtModules/IPCAM_Rtsp/LIB_Rtsp.h"
//PTZЭ��֧��
#include "IPCAM_ExtModules/ExMod_PtzCtrl/ExMod_PtzCtrl.h"
//DDNS
#include "IPCAM_ExtModules/ExMod_Ddns/ExMod_Ddns.h"

//20150317 Onvif ��ʼ��
#include "IPCAM_Modules/ModOnvifServer/OnvifServerPtz.h"

//ϵͳ������
#include "IPCAM_Modules/ModSysContext/IPCAM_SysContext.h"
//������ģ�� 
#include "IPCAM_Modules/ModMulLang/IPCAM_MulLang.h"
//�������
#include "IPCAM_Modules/ModNetWork/IPCAM_Netexport.h"
//RTSP��ʼ��
//#include "IPCAM_Modules/ModRtsp/IPCAM_NetSvRtsp.h"
//ONVIF��ʼ��
//#include "IPCAM_Modules/ModOnvif/IPCAM_Onvif.h"

//������־��д�����ȡ
#include "IPCAM_Modules/ModLog/IPCAM_Log.h"
#endif//__IPCAM_EXPORT__


