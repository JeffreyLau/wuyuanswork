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

/****************************************************
函数名称 : TFT_GPIO_Config
函数功能 : 初始化TFT屏的控制端口都为写状态,状态为0
函数参数 : 无
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
****************************************************/
void TFT_GPIO_Config()
{
    unsigned int val_read = 0;
    unsigned int val_set = 0; //pull down.
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;

    //GPIO:10_3 (背景光 BL_A).
    Hi_SetGpio_SetDir( 10, 3, GPIO_WRITE );
    Hi_SetGpio_SetBit( 10, 3, 0 );
    
    //GPIO:11_5 (片选端 CS).
    Hi_SetGpio_SetDir( 11, 5, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 5, 1 );
    
    //GPIO:11_4 (数据、命令切换端 RS).
    Hi_SetGpio_SetDir( 11, 4, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 4, 1 );
    
    //GPIO:11_6 (写控制端 WR).
    Hi_SetGpio_SetDir( 11, 6, GPIO_WRITE );
    Hi_SetGpio_SetBit( 11, 6, 1 );
          
    //GPIO:1_2 (读控制端 RD).
    Hi_SetGpio_SetDir( 1, 2, GPIO_WRITE );
    Hi_SetGpio_SetBit( 1, 2, 1 ); 
       
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

/****************************************************
函数名称 : TFT_Rst
函数功能 : TFT屏复位
函数参数 : 无
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
****************************************************/
void TFT_Rst(void)
{
    //GPIO:7_5 (软件复位端 RESET).
    Hi_SetGpio_SetDir( 7, 5, GPIO_WRITE );
    delayms(100);
    Hi_SetGpio_SetBit( 7, 5, 1 );//TFT_RST = 1;
    delayms(10);
    Hi_SetGpio_SetBit( 7, 5, 0); //TFT_RST = 0;
    delayms(20);
    Hi_SetGpio_SetBit( 7, 5, 1 );//TFT_RST = 1;
    delayms(10);
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


/****************************************************
函数名称 : initTFT
函数功能 : TFT 液晶屏初始化
函数参数 : 无
作    者 : 郑少欣
日    期 : 2016.6.14
备    注 : 无
****************************************************/
void initTFT()
{    
    printf("<<<<<<<<<<<<< [Init TFT GPIO] >>>>>>>>>>>>>>>>>>>\n");
    TFT_GPIO_Config();//液晶屏管脚的初始化
    TFT_Rst();

    TFT_WR_CMD(0xCB);
	TFT_WR_Data(0x01);

    TFT_WR_CMD(0xC0);
	TFT_WR_Data(0x26);
    TFT_WR_Data(0x08);

    TFT_WR_CMD(0xC1);
	TFT_WR_Data(0x10);

    TFT_WR_CMD(0xC5);
	TFT_WR_Data(0x2E);
    TFT_WR_Data(0x3C);

    TFT_WR_CMD(0x3A);
	TFT_WR_Data(0x55);

    TFT_WR_CMD(0x36);
	TFT_WR_Data(0x68);

    TFT_WR_CMD(0xB1);
	TFT_WR_Data(0x00);
    TFT_WR_Data(0x18);

    TFT_WR_CMD(0xB6);
	TFT_WR_Data(0x0A);
    TFT_WR_Data(0xC2);

    TFT_WR_CMD(0xC7);
	TFT_WR_Data(0xBB);

    TFT_WR_CMD(0xF2);
	TFT_WR_Data(0x00);

    TFT_WR_CMD(0x26);
	TFT_WR_Data(0x01);

    TFT_WR_CMD(0xE0);
	TFT_WR_Data(0x08);
    TFT_WR_Data(0x0E);
    TFT_WR_Data(0x17);
    TFT_WR_Data(0x05);
    TFT_WR_Data(0x03);
    TFT_WR_Data(0x09);
    TFT_WR_Data(0x4A);
    TFT_WR_Data(0x86);
    TFT_WR_Data(0x2B);
    TFT_WR_Data(0x0D);
    TFT_WR_Data(0x04);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);

    TFT_WR_CMD(0xE1);
	TFT_WR_Data(0x08);
    TFT_WR_Data(0x1A);
    TFT_WR_Data(0x20);
    TFT_WR_Data(0x07);
    TFT_WR_Data(0x0E);
    TFT_WR_Data(0x05);
    TFT_WR_Data(0x3A);
    TFT_WR_Data(0x8A);
    TFT_WR_Data(0x40);
    TFT_WR_Data(0x04);
    TFT_WR_Data(0x18);
    TFT_WR_Data(0x0F);
    TFT_WR_Data(0x3F);
    TFT_WR_Data(0x3F);
    TFT_WR_Data(0x3F);

    TFT_WR_CMD(0x2A);
	TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0x01);
    TFT_WR_Data(0x3f);

    TFT_WR_CMD(0x2B);
	TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0x00);
    TFT_WR_Data(0xef);

    TFT_WR_CMD(0x11);
    delayms(100);
    TFT_WR_CMD(0x29);
        
    TFT_ShowColor(RGB565(255,255,255),X_START,Y_START,X_MAX,Y_MAX); //   
}

/****************************************************
函数名称 : TFT_SetWindow
函数功能 : 显示区域设置
函数参数 : (HEA, HSA)为水平方向的起点坐标
           (VEA, VSA)为垂直方向的终点坐标
作    者 : 郑少欣
日    期 : 2016.6.15
备    注 : 无
****************************************************/
void TFT_SetWindow(u16 HEA, u16 HSA, u16 VEA, u16 VSA)
{
    TFT_WR_CMD_DATA(0x36, HEA); //x轴起点坐标
    TFT_WR_CMD_DATA(0x37, HSA); //x轴终点坐标
    TFT_WR_CMD_DATA(0x38, VEA); //y轴终点坐标
    TFT_WR_CMD_DATA(0x39, VSA); //y轴终点坐标
    TFT_WR_CMD(0X22);
    TFT_WR_CMD_DATA(0X20, HSA); //RAM addr1 AD0~AD7 HSA
    TFT_WR_CMD_DATA(0X21, VSA); //RAM addr2 AD15~AD8 VSA
    TFT_WR_CMD(0X22);
}

/****************************************************
函数名称 : TFT_ShowColor
函数功能 : 显示颜色
函数参数 : color 为显示的颜色
           (xStart, yStart)为起点坐标
            xLong 为x轴方向上的长度
            yLong 为y轴方向上的长度
作    者 : 郑少欣
日    期 : 2016.6.15
备    注 : 无
****************************************************/
void TFT_ShowColor(u16 color, u16 xStart, u16 yStart, u16 xLong, u16 yLong )
{
    u8 x, y, CH, CL;

    CH = (u8) (color >> 8 & 0x00FF);
    CL = (u8) (color & 0x00FF);

    TFT_SetWindow(xLong + xStart - 1, xStart, 
                  yLong + yStart - 1, yStart); //定位坐标

    /** 数据首次写入 **/
    for( x = 0; x < xLong; x++)
    {
        for (y = 0; y < yLong; y++)
        {
            TFT_WR_Data(CH);
            TFT_WR_Data(CL);
        }
    }
    
    delayms(5);
}

/****************************************************
函数名称 : TFT_ShowPoint
函数功能 : 像素点的显示
函数参数 : (x,y)为用户设置的像素点
            color 为像素点显示的颜色
作    者 : 郑少欣
日    期 : 2016.6.15
备    注 : 无
****************************************************/
void TFT_ShowPoint(u16 x, u16 y, u16 color)
{
    TFT_WR_CMD_DATA(0x36, x);   //x轴的起点坐标
    TFT_WR_CMD_DATA(0x37, x);   //x轴的终点坐标
    TFT_WR_CMD_DATA(0x38, y);   //y轴的起点坐标
    TFT_WR_CMD_DATA(0x39, y);   //y轴的终点坐标

    TFT_WR_CMD_DATA(0x20, x);   //设置x坐标的位置
    TFT_WR_CMD_DATA(0x21, y);   //设置y坐标的位置

    TFT_WR_CMD(0x22);
    TFT_WR_Data(color);
}

/****************************************************
函数名称 : TFT_ShowCirclePixel
函数功能 : 像素单位显示
函数参数 : (x,y)为像素单位中心
            (a,b)为滚动像素点
            color 为像素点显示的颜色
作    者 : 郑少欣
日    期 : 2016.6.15
备    注 : 无
****************************************************/
void TFT_ShowCirclePixl(u16 x, u16 y, s16 a, s16 b, u16 color)
{
    TFT_ShowPoint(x - a, y - b, color); //0~7 --> 1
    TFT_ShowPoint(x - b, y - a, color); //6~7 --> 2
    TFT_ShowPoint(x - b, y + a, color); //6~5 --> 3
    TFT_ShowPoint(x - a, y + b, color); //4~6 --> 4

    TFT_ShowPoint(x + a, y + b, color); //4~3 --> 5
    TFT_ShowPoint(x + b, y + a, color); //2~3 --> 6
    TFT_ShowPoint(x + b, y - a, color); //2~1 --> 7
    TFT_ShowPoint(x + a, y - b, color); //0~1 --> 8
}

