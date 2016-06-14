/*********************************************************
文件名 : Sx_TFTConfig.h
描  述 : 配置了数据类型和TFT端口的连接方式
设计者 : 郑少欣
日  期 : 2016.6.14
备  注 : 无
*********************************************************/

#ifndef __SX_TFTCONFIG_H__
#define __SX_TFTCONFIG_H__

#include "gpiodriver.h"

typedef signed char   s8; //8位有符号数据类型
typedef signed int    s16;//16位有符号数据类型
typedef signed long   s32;//32位有符号数据类型
typedef unsigned char u8; //8位无符号数据类型
typedef unsigned int  u16;//16位无符号数据类型
typedef unsigned long u32;//32位无符号数据类型

//5:6:5格式， 去除低位可以减少误差
#define RGB565(R,G,B) ((R>>3)<<11 | (G>>2)<<5 | (B>>3))

/**
TFT_LCD屏端口分配
BL_A     GPIO10_3    背景光
CS       GPIO11_5    片选端
RESET    GPIO7_5     软件复位端
RS       GPIO11_4    数据、命令切换端
WR       GPIO11_6    写控制端
RD       GPIO1_2     读控制端

数据传送端口
DB7      GPIO11_3
DB6      GPIO11_2
DB5      GPIO11_1
DB4      GPIO11_0
DB3      GPIO10_7
DB2      GPIO10_6
DB1      GPIO10_5
DB0      GPIO10_4
*/



#endif
