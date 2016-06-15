/*********************************************************
*文件名 : Sx_TFT.c 
*描  述 : TFT屏幕驱动，提供液晶屏操作的
          各个接口函数
*设计者 : 郑少欣
*日  期 : 2016.6.14
*备  注 : 无 
**********************************************************/

#include "Sx_TFT.h"
#include "Sx_TFTConfig.h"
#include "Sx_TFT_Table.h"

/*******************************************
函数名称 : delayms
函数功能 : 延时
函数参数 : ms 用户自定义延时时间
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
*******************************************/
void delayms(u16 ms)
{
    u16 i,j;
    for(i=0; i < ms; i++)
        for(j = 0; j < 1000; j++);

}


/*******************************************
函数名称 : Set_TFT_Data
函数功能 : 设置TFT8位数据端口的值
函数参数 : dat为8位数据位
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
*******************************************/
void Set_TFT_Data(u8 data)
{
    unsigned int val_set = 0;
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;
    /* 数据传送端口的高4位 */  
    groupnum = 11;
    bitnum = 3; //GPIO11_3 (数据端 D7).
    val_set = (data >> 7)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO11_2 (数据端 D6).
    val_set = (data >> 6)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO11_1 (数据端 D5).
    val_set = (data >> 5)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO11_0 (数据端 D4).
    val_set = (data >> 4)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    /* 数据传送端口的低4位 */
    groupnum = 11;
    bitnum = 3; //GPIO10_7 (数据端 D3).
    val_set = (data >> 3)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO10_6 (数据端 D2).
    val_set = (data >> 2)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO10_5 (数据端 D1).
    val_set = (data >> 1)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO10_4 (数据端 D0).
    val_set = (data >> 0)&0x1;
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );   
}

/*******************************************
函数名称 : TFT_WR_CMD
函数功能 : 向TFT写命令
函数参数 : cmd为写入的命令
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
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
函数名称 : TFT_WR_Data
函数功能 : 向TFT写8位数据
函数参数 : dat为8位数据位
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
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
函数名称 : TFT_WR_CMD_DATA
函数功能 : 写数据和命令
函数参数 : dat为8位数据位，cmd为命令
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
*******************************************/
void TFT_WR_CMD_DATA(u8 cmd,u16 dat)
{
	TFT_WR_CMD(cmd);
	TFT_WR_Data(dat);
}


/*******************************************
函数名称 : initTFTGPIO
函数功能 : 初始化TFT屏的控制端口都为写状态,状态为0
函数参数 : 无
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
*******************************************/
void initTFTGPIO()
{
    unsigned int val_read = 0;
    unsigned int val_set = 0; //pull down.
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;

    printf("<<<<<<<<<<<<< [Init TFT GPIO] >>>>>>>>>>>>>>>>>>>\n");

    //GPIO:7_5 (软件复位端 RESET).
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

	#ifdef SCAN_V_EN						//在Sx_TFT.h中配置
            TFT_WR_CMD_DATA(0x03,0x1030);   //关键控制字 bit3 AM = 0 水平扫描 AM = 1 垂直扫描
	#else
            TFT_WR_CMD_DATA(0x03,0x1018);   //关键控制字 bit3 AM = 0 水平扫描 AM = 1 垂直扫描
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
        
        //TFT_ShowColor(RGB565(255,255,255),X_START,Y_START,X_MAX,Y_MAX); //??°×?á
    
    
    //GPIO:10_3 (背景光 BL_A).
    Hi_SetGpio_SetDir( 10, 3, GPIO_WRITE );
    Hi_SetGpio_SetBit( 10, 3, val_set );

    //GPIO:11_5 (片选端 CS).
    Hi_SetGpio_SetDir( 11, 5, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 5, val_set );

    //GPIO:11_4 (数据、命令切换端 RS).
    Hi_SetGpio_SetDir( 11, 4, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 4, val_set );

    //GPIO:11_6 (写控制端 WR).
    Hi_SetGpio_SetDir( 11, 6, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 6, val_set );
      
    //GPIO:1_2 (读控制端 RD).
    Hi_SetGpio_SetDir( 1, 2, GPIO_WRITE );
    Hi_SetGpio_SetBit( 1, 2, val_set ); 
   
   /* 数据传送端口的高4位 */
    groupnum = 11;
    bitnum = 3; //GPIO11_3 (数据端 D7).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO11_2 (数据端 D6).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO11_1 (数据端 D5).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO11_0 (数据端 D4).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    /* 数据传送端口的低4位 */
    groupnum = 11;
    bitnum = 3; //GPIO10_7 (数据端 D3).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 2; //GPIO10_6 (数据端 D2).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 1; //GPIO10_5 (数据端 D1).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
    groupnum = 11;
    bitnum = 0; //GPIO10_4 (数据端 D0).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );   
}


