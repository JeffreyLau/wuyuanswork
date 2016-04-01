//IPCAM_NetDhcp.h

/*##############################################################################
#��������:
#       IP���������
#
#�ļ�����:
# 
#������Ϣ:
#        ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x 
#  	     All rights reserved.
###############################################################################*/

#ifndef IPCAM_NETDHCP_H
#define IPCAM_NETDHCP_H

#define DHCP_SCRIPT_FILE		"/usr/share/udhcpc/default.script"
//#define MAC_ETH0				"eth0"

#define NETPARAM_IP_MODE 			0
#define NETPARAM_DHCP_MODE 			1
#define NETPARAM_PPPOE_MODE 		2


INT IPCAM_NetGetDNS(CHAR *dns_addr);
INT IPCAM_SysNetToVariable();
INT IPCAM_SysNetToConfig();
BOOL IPCAM_SetNetEnv();




#endif //IPCAM_NETDHCP_H



