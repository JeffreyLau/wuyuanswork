//IPCAM_NetNtp.h

/*##############################################################################
#��������:
#       IP���������
#
#�ļ�����:
# 
#������Ϣ:
#         ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x 
#  	   All rights reserved.
###############################################################################*/

#ifndef IPCAM_NETNTP_H
#define IPCAM_NETNTP_H

#define NTP_SERVER_NAME 		"clock.isc.org"
#define NTP_PATH				"/mnt/mtd/ntpdate"

BOOL IPCAM_StartNtp(CHAR *ServerName, INT TimeZone);

#endif


