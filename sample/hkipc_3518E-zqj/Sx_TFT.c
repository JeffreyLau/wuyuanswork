/*********************************************************
*�ļ��� : Sx_TFT.c 
*��  �� : TFT��Ļ�������ṩҺ����������
          �����ӿں���
*����� : ֣����
*��  �� : 2016.6.14
*��  ע : �� 
**********************************************************/

#include "Sx_TFT.h"
#include "Sx_TFTConfig.h"
#include "Sx_TFT_Table.h"

/*******************************************
�������� : delayms
�������� : ��ʱ
�������� : ms �û��Զ�����ʱʱ��
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void delayms(u16 ms)
{
    u16 i,j;
    for(i=0; i < ms; i++)
        for(j = 0; j < 1000; j++);

}


/*******************************************
�������� : Set_TFT_Data
�������� : ����TFT8λ���ݶ˿ڵ�ֵ
�������� : datΪ8λ����λ
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void Set_TFT_Data(u8 data)
{
    unsigned int val_set = 0;
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;
    /* ���ݴ��Ͷ˿ڵĸ�4λ */  
    groupnum = 11;
    bitnum = 3; //GPIO11_3 (���ݶ� D7).
    val_set = (data >> 7)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO11_2 (���ݶ� D6).
    val_set = (data >> 6)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO11_1 (���ݶ� D5).
    val_set = (data >> 5)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO11_0 (���ݶ� D4).
    val_set = (data >> 4)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    /* ���ݴ��Ͷ˿ڵĵ�4λ */
    groupnum = 11;
    bitnum = 3; //GPIO10_7 (���ݶ� D3).
    val_set = (data >> 3)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO10_6 (���ݶ� D2).
    val_set = (data >> 2)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO10_5 (���ݶ� D1).
    val_set = (data >> 1)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO10_4 (���ݶ� D0).
    val_set = (data >> 0)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );   
}

/*******************************************
�������� : TFT_WR_CMD
�������� : ��TFTд����
�������� : cmdΪд�������
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void TFT_WR_CMD(u8 cmd)
{
	Hi_SetGpio_SetBit( 11, 4, 0 ); //TFT_RS = 0
	Hi_SetGpio_SetBit( 11, 5, 0 );  //TFT_CS = 0
	Hi_SetGpio_SetBit( 1,  2, 1 );  //TFT_RD = 1
	Set_TFT_Data(0x00);            //TFT_DATA = 0x00
	Hi_SetGpio_SetBit( 11, 6, 0 );  //TFT_WR = 0
	Hi_SetGpio_SetBit( 11, 6, 1 );  //TFT_WR = 1
	Set_TFT_Data(cmd);             //TFT_DATA = cmd
	Hi_SetGpio_SetBit( 11, 6, 0 );  //TFT_WR = 0
	Hi_SetGpio_SetBit( 11, 6, 1 );//TFT_WR = 1;
	Hi_SetGpio_SetBit( 11, 5, 1 );//TFT_CS = 1;
}

/*******************************************
�������� : TFT_WR_Data
�������� : ��TFTд8λ����
�������� : datΪ8λ����λ
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void TFT_WR_Data(u8 dat)
{
    Hi_SetGpio_SetBit( 11, 4, 1 ); //TFT_RS = 1;
	Hi_SetGpio_SetBit( 11, 5, 0 ); //TFT_CS = 0;
	Hi_SetGpio_SetBit( 1, 2, 1 );  //TFT_RD = 1;
	Set_TFT_Data(dat);             //TFT_DATA = byte;
	Hi_SetGpio_SetBit( 11, 6, 0);  //TFT_WR = 0;
	Hi_SetGpio_SetBit( 11, 6, 1 ); //TFT_WR = 1;
	Hi_SetGpio_SetBit( 11, 5, 1 ); //TFT_CS = 1;   
}

/*******************************************
�������� : TFT_WR_CMD_DATA
�������� : д���ݺ�����
�������� : datΪ8λ����λ��cmdΪ����
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void TFT_WR_CMD_DATA(u8 cmd,u16 dat)
{
	TFT_WR_CMD(cmd);
	TFT_WR_Data(dat);
}


/*******************************************
�������� : initTFTGPIO
�������� : ��ʼ��TFT���Ŀ��ƶ˿ڶ�Ϊд״̬,״̬Ϊ0
�������� : ��
��    �� : ֣����
��    �� : 2016.6.14
��    ע : ��
*******************************************/
void initTFTGPIO()
{
    unsigned int val_read = 0;
    unsigned int val_set = 0; //pull down.
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;

    printf("<<<<<<<<<<<<< [Init TFT GPIO] >>>>>>>>>>>>>>>>>>>\n");

    //GPIO:7_5 (�����λ�� RESET).
    Hi_SetGpio_SetDir( 7, 5, GPIO_WRITE );

    delayms(100);
    Hi_SetGpio_SetBit( 7, 5, 1 );//TFT_RST = 1;
    delayms(10);
    Hi_SetGpio_SetBit( 7, 5, 0); //TFT_RST = 0;
    delayms(20);
    Hi_SetGpio_SetBit( 7, 5, 1 );//TFT_RST = 1;
    delayms(10);

    TFT_WR_CMD_DATA(0x01,0x011C);
	TFT_WR_CMD_DATA(0x02,0x0100);

	#ifdef SCAN_V_EN						//��Sx_TFT.h������
            TFT_WR_CMD_DATA(0x03,0x1030);   //�ؼ������� bit3 AM = 0 ˮƽɨ�� AM = 1 ��ֱɨ��
	#else
            TFT_WR_CMD_DATA(0x03,0x1018);   //�ؼ������� bit3 AM = 0 ˮƽɨ�� AM = 1 ��ֱɨ��
	#endif
        TFT_WR_CMD_DATA(0x08,0x0808);
        TFT_WR_CMD_DATA(0x0C,0x0000);
        TFT_WR_CMD_DATA(0x0F,0x0E01);
        TFT_WR_CMD_DATA(0x20,0x0000);
        TFT_WR_CMD_DATA(0x21,0x0000);
        
        //power on sequence
        delayms(10);
        TFT_WR_CMD_DATA(0x10,0x0900);
        TFT_WR_CMD_DATA(0x11,0x1038);
        delayms(10);
        TFT_WR_CMD_DATA(0x12,0x1121);
        TFT_WR_CMD_DATA(0x13,0x0065);
        TFT_WR_CMD_DATA(0x14,0x5058);
        
        //set GRAM area
        TFT_WR_CMD_DATA(0x30,0x0000);
        TFT_WR_CMD_DATA(0x31,0x00AF);
        TFT_WR_CMD_DATA(0x32,0x0000);
        TFT_WR_CMD_DATA(0x33,0x0000);
        TFT_WR_CMD_DATA(0x34,0x00DB);
        TFT_WR_CMD_DATA(0x35,0x0000);
        TFT_WR_CMD_DATA(0x36,0x00AF);
        TFT_WR_CMD_DATA(0x37,0x0000);
        TFT_WR_CMD_DATA(0x38,0x00DB);
        TFT_WR_CMD_DATA(0x39,0x0000);
        
        //adjust the gamma curve
        TFT_WR_CMD_DATA(0x50,0x0400);
        TFT_WR_CMD_DATA(0x51,0x060B);
        TFT_WR_CMD_DATA(0x52,0x0C0A);
        TFT_WR_CMD_DATA(0x53,0x0105);
        TFT_WR_CMD_DATA(0x54,0x0A0C);
        TFT_WR_CMD_DATA(0x55,0x0B06);
        TFT_WR_CMD_DATA(0x56,0x0004);
        TFT_WR_CMD_DATA(0x57,0x0501);
        TFT_WR_CMD_DATA(0x58,0x0E00);
        TFT_WR_CMD_DATA(0x59,0x000E);
        delayms(10);
        TFT_WR_CMD_DATA(0x07,0x1017);
        TFT_WR_CMD(0x22);
        
        //TFT_ShowColor(RGB565(255,255,255),X_START,Y_START,X_MAX,Y_MAX); //??���?��
    
    
    //GPIO:10_3 (������ BL_A).
    Hi_SetGpio_SetDir( 10, 3, GPIO_WRITE );
    Hi_SetGpio_SetBit( 10, 3, val_set );

    //GPIO:11_5 (Ƭѡ�� CS).
    Hi_SetGpio_SetDir( 11, 5, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 5, val_set );

    //GPIO:11_4 (���ݡ������л��� RS).
    Hi_SetGpio_SetDir( 11, 4, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 4, val_set );

    //GPIO:11_6 (д���ƶ� WR).
    Hi_SetGpio_SetDir( 11, 6, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 6, val_set );
      
    //GPIO:1_2 (�����ƶ� RD).
    Hi_SetGpio_SetDir( 1, 2, GPIO_WRITE );
    Hi_SetGpio_SetBit( 1, 2, val_set ); 
   
   /* ���ݴ��Ͷ˿ڵĸ�4λ */
    groupnum = 11;
    bitnum = 3; //GPIO11_3 (���ݶ� D7).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO11_2 (���ݶ� D6).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO11_1 (���ݶ� D5).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO11_0 (���ݶ� D4).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    /* ���ݴ��Ͷ˿ڵĵ�4λ */
    groupnum = 11;
    bitnum = 3; //GPIO10_7 (���ݶ� D3).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO10_6 (���ݶ� D2).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO10_5 (���ݶ� D1).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO10_4 (���ݶ� D0).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );   
}


