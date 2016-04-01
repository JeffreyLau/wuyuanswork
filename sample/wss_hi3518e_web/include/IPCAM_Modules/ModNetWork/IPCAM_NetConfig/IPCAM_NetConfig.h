//IPCAM_NetConfig.h

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

#ifndef __IPCAM_NETCONFIG__
#define __IPCAM_NETCONFIG__

#include "IPCAM_Export.h"
/*****************************************
�ص���������:NETCONFIGCALLBACK 
����ֵ:0 ���� >0����
ע��:�������ֵ����0����Ӧ�Ľ�����ͻ��˵����󷵻�һ�������Ӧ��
 ******************************************/
typedef INT(*NETCONFIGCALLBACK)(INT socket,ULONG msgType,VOID *data);
INT IPCAM_NetConfig(NETMSGPACKET	*sp, INT sock,NETCONFIGCALLBACK func);

#endif

