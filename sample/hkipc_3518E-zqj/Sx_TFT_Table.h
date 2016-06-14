/*********************************************************
文件名 : Sx_TFT_Table.h
描  述 : TFT液晶屏显示数字、字体、字符串参数
设计者 : 郑少欣
日  期 : 2016.6.14
备  注 : 无
*********************************************************/
#ifndef __SX_TFT_TABLE_H__
#define __SX_TFT_TABLE_H__

#include "Sx_TFTConfig.h"

extern u8  digital[];		//显示测得PM2.5的数值
extern u8  digital1[];		//8*8数字
extern u8  font[10][72];	//汉字12*24
extern u8  font1[10][72];	//汉字12*24
extern u8  str[20][48];		//字符串12*24
extern u8  name[3][72];		//汉字12*24
extern u8  gImage_ST[];		//显示图片


#endif

