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

/*********************************************************
*函数名 : initTFTGPIO
*功  能 : 初始化TFT屏的控制端口都为写状态,状态为0
*设计者 : 郑少欣
*日  期 : 2016.6.14
*备  注 : 无
**********************************************************/
void initTFTGPIO()
{
    unsigned int val_read = 0;
    unsigned int val_set = 0; //pull down.
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;

    printf("<<<<<<<<<<<<< Init TFT GPIO >>>>>>>>>>>>>>>>>>>\n")；
        
    groupnum = 10;
    bitnum = 3; //GPIO:10_3 (背景光).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 5; //GPIO:11_5 (片选端).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 7;
    bitnum = 5; //GPIO:7_5 (软件复位端).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 4; //GPIO:11_4 (数据、命令切换端).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 6; //GPIO:11_6 (写控制端).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
      
    groupnum = 1;
    bitnum = 2; //GPIO:1_2 (读控制端).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set ); 
   
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

