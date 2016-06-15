/*********************************************************
�ļ��� : Sx_FTF.h
��  �� : ����TFTҺ����������궨��
����� : ֣����
��  �� : 2016.6.14
��  ע : ��
*********************************************************/
#ifndef __SX_FTF_H__
#define __SX_FTF_H__

#include "Sx_TFTConfig.h"

#define     SCAN_V_EN				1	      //ˮƽɨ�裬����Ǵ�ֱɨ�裬�����θö���    

#define 	PI						3.1415	  // ��

#define 	X_MAX					176		  //ȫ������ֵ	
#define 	Y_MAX					220       //

#define 	X_START					0	      //TFT������ʼ����		
#define 	Y_START					0         //

#define 	font_digital_size    	64		  //16*32����
#define 	font_digital_size_x  	16        //
#define 	font_digital_size_y  	32        //

#define 	font_digital1_size    	8		  // 8*8����		
#define 	font_digital1_size_x  	8         //
#define 	font_digital1_size_y  	8         //

#define 	DIGITAL_X_S  			100		  // PM2.5������ʾ����ʼ����
#define 	DIGITAL_Y_S  			85        //

#define 	DIGITAL1_X_S  			50	      //  y  1λ8*8������ʾ����ʼ����
#define 	DIGITAL1_Y_S  			115       //  x

#define 	DIGITAL2_X_S  			126		  //  2λ8*8������ʾ����ʼ����
#define 	DIGITAL2_Y_S  			50        //

#define 	DIGITAL3_X_S  			126		  //  3λ8*8������ʾ����ʼ����
#define 	DIGITAL3_Y_S  			100       //

#define		IMAGEA_ST_X_S			40		  //  ͼƬ��ʼ����	
#define		IMAGEA_ST_Y_S			65        //

#define		IMAGEA_ST_X_MAX			92		  //  ͼƬ����		
#define		IMAGEA_ST_Y_MAX			89        //

#define 	DATA_BIT_HUD     		0		  //  PM2.5��λ����		
#define 	DATA_BIT_TEN     		1  		  //  PM2.5ʮλ����	
#define 	DATA_BIT_ONE     		2		  //  PM2.5��λ����		

#define 	CIRCLE_CENTRE_X_S  		88		  //  Բ������ x	
#define 	CIRCLE_CENTRE_Y_S  		110		  //  Բ������ y
#define 	CIRCLE_R           		40 		  //  ��Բ�뾶
#define 	CIRCLE_W           		20 		  //  Բ�����

#define 	H_START					0x0000	  //  TFT��ˮƽ��ʼ����					
#define 	H_END					0x00AF	  //  TFT��ˮƽ��������		
#define 	V_START					0x0000	  //  TFT����ֱ��ʼ����			
#define 	V_END					0x00DB	  //  TFT����ֱ��������						



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
