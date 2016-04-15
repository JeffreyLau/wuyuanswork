#pragma  once
#include "utils/HKDataBase.h"
#define AFX_EXT_CLASS
#ifdef __cplusplus
extern "C"
{
#endif
AFX_EXT_CLASS int				NetOpen();		
AFX_EXT_CLASS void				NetClose();

AFX_EXT_CLASS int				InitWAN( HKNETCALLBACK funCallBack );	// ��ʼ�� ������
AFX_EXT_CLASS void				UnInitWAN();							// ע��������

//  ��Ҫ���滻 ----
AFX_EXT_CLASS int				NetInit( HKNETCALLBACK funCallBack );              // �򿪱��ط���
AFX_EXT_CLASS void				NetUnInit();
AFX_EXT_CLASS int				NetBindPipe( unsigned int nPIPEID );			  // �󶨶Է��ܵ�
AFX_EXT_CLASS int				NetUnBindPipe( unsigned int nPIPEID );			      // �����

//-----------------

AFX_EXT_CLASS int				AddLocalHostInfo( HKHOSTInfo *rHostInfo );                                // ��ӱ��ؼ���
AFX_EXT_CLASS int				ConRemoteHostInfo( HKHOSTInfo *rHostInfo );                  // ����Զ�̷�����           															          
AFX_EXT_CLASS int				NetWrite( const HKPacketInfo *rPackInfo,char *pData,unsigned short nSize );    


AFX_EXT_CLASS int				NewPipe( unsigned int nPipeID );	  // �½�ͨ��
AFX_EXT_CLASS void              DelPipe( unsigned int nPipeID );

///////----------------------С���ӿ�

AFX_EXT_CLASS int			    InitLAN( HKLANNETCALLBACK lanCallBack );			// ��ʼ��С��
AFX_EXT_CLASS void			    UnInitLAN();
AFX_EXT_CLASS short				AddLANEP( char * szIP, unsigned short nPort );			// ���Զ��EP
AFX_EXT_CLASS void				RemLANEP( unsigned short nDstID );						// ɾ��Զ��EP
AFX_EXT_CLASS int				LANNetWrite( unsigned short nDstID,const HKPacketInfo *rPackInfo,char *pData,unsigned short nSize );               // nCHID = 0 SYSͨ��
AFX_EXT_CLASS short				GetLANEPNodeInfo( unsigned short nDstID,char *buf,short nLen );
AFX_EXT_CLASS int               LANConRemoteHostInfo( unsigned short nDstID );                    //Huqing 06-17 С������

AFX_EXT_CLASS void              LANReFlash( char *pBuf,unsigned short nLen );            //Huqing 06-20 С��ˢ�½ӿ�

AFX_EXT_CLASS void              SetMonPortInfoList( char *pBuf, unsigned short nLen );  //Huqing 10-23 ���Ӽ����˿���Ϣ�б�
#ifdef __cplusplus
}
#endif

