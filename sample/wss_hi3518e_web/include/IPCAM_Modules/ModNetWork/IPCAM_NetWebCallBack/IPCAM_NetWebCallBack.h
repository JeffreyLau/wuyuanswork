//IPCAM_NetWebCallback.c

/*##############################################################################
#��������:
#       IP���������
#
#�ļ�����:
# 
#������Ϣ:
#       ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x 
#  	    All rights reserved.
###############################################################################*/


#ifndef _NETWEBCALLBACK_H
#define _NETWEBCALLBACK_H

//#include "IPCAM_Export.h"


INT  CallBack_Cgi(HWEBCGI hWebCgi,CHAR *CgiPath);
INT  Callback_Mjpeg    (INT Socket,INT Channel ,INT GetType);
INT     CallBackNetConfig (INT socket,ULONG msgType,void *data);
INT                   Callback_AuthCheck(CHAR *pzUserName,CHAR* pzPassword);

#endif//_NETWEBCALLBACK_H

