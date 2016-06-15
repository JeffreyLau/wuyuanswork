/*********************************************************
文件名 : Sx_FTF.h
描  述 : 配置TFT液晶屏函数与宏定义
设计者 : 郑少欣
日  期 : 2016.6.14
备  注 : 无
*********************************************************/
#ifndef __SX_FTF_H__
#define __SX_FTF_H__

#include "Sx_TFTConfig.h"

#define     SCAN_V_EN				1	      //水平扫描，如果是垂直扫描，则屏蔽该定义    

#define 	PI						3.1415	  // π

#define 	X_MAX					176		  //全屏像素值	
#define 	Y_MAX					220       //

#define 	X_START					0	      //TFT屏的起始坐标		
#define 	Y_START					0         //

#define 	font_digital_size    	64		  //16*32数字
#define 	font_digital_size_x  	16        //
#define 	font_digital_size_y  	32        //

#define 	font_digital1_size    	8		  // 8*8数字		
#define 	font_digital1_size_x  	8         //
#define 	font_digital1_size_y  	8         //

#define 	DIGITAL_X_S  			100		  // PM2.5数据显示的起始坐标
#define 	DIGITAL_Y_S  			85        //

#define 	DIGITAL1_X_S  			50	      //  y  1位8*8数据显示的起始坐标
#define 	DIGITAL1_Y_S  			115       //  x

#define 	DIGITAL2_X_S  			126		  //  2位8*8数据显示的起始坐标
#define 	DIGITAL2_Y_S  			50        //

#define 	DIGITAL3_X_S  			126		  //  3位8*8数据显示的起始坐标
#define 	DIGITAL3_Y_S  			100       //

#define		IMAGEA_ST_X_S			40		  //  图片起始坐标	
#define		IMAGEA_ST_Y_S			65        //

#define		IMAGEA_ST_X_MAX			92		  //  图片像素		
#define		IMAGEA_ST_Y_MAX			89        //

#define 	DATA_BIT_HUD     		0		  //  PM2.5百位数据		
#define 	DATA_BIT_TEN     		1  		  //  PM2.5十位数据	
#define 	DATA_BIT_ONE     		2		  //  PM2.5个位数据		

#define 	CIRCLE_CENTRE_X_S  		88		  //  圆心坐标 x	
#define 	CIRCLE_CENTRE_Y_S  		110		  //  圆心坐标 y
#define 	CIRCLE_R           		40 		  //  内圆半径
#define 	CIRCLE_W           		20 		  //  圆环宽度

#define 	H_START					0x0000	  //  TFT屏水平起始坐标					
#define 	H_END					0x00AF	  //  TFT屏水平结束坐标		
#define 	V_START					0x0000	  //  TFT屏垂直起始坐标			
#define 	V_END					0x00DB	  //  TFT屏垂直结束坐标						



extern void delayms(u16 ms);
extern void Set_TFT_Data(u8 data);
extern void TFT_WR_CMD(u8 cmd);
extern void TFT_WR_Data(u8 dat);
extern void TFT_WR_CMD_DATA(u8 cmd,u16 dat);
extern void initTFTGPIO();
extern void TFT_SetWindow(u16 HEA, u16 HSA, u16 VEA, u16 VSA);
extern void TFT_ShowColor(u16 color, u16 xStart, u16 yStart, u16 xLong, u16 yLong );
extern void TFT_ShowPoint(u16 x, u16 y, u16 color);
extern void TFT_ShowCirclePixl(u16 x, u16 y, s16 a, s16 b, u16 color);







#endif
