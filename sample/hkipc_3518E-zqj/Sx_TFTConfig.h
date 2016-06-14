/*********************************************************
�ļ��� : Sx_TFTConfig.h
��  �� : �������������ͺ�TFT�˿ڵ����ӷ�ʽ
����� : ֣����
��  �� : 2016.6.14
��  ע : ��
*********************************************************/

#ifndef __SX_TFTCONFIG_H__
#define __SX_TFTCONFIG_H__

#include "gpiodriver.h"

typedef signed char   s8; //8λ�з�����������
typedef signed int    s16;//16λ�з�����������
typedef signed long   s32;//32λ�з�����������
typedef unsigned char u8; //8λ�޷�����������
typedef unsigned int  u16;//16λ�޷�����������
typedef unsigned long u32;//32λ�޷�����������

//5:6:5��ʽ�� ȥ����λ���Լ������
#define RGB565(R,G,B) ((R>>3)<<11 | (G>>2)<<5 | (B>>3))

/**
TFT_LCD���˿ڷ���
BL_A     GPIO10_3    ������
CS       GPIO11_5    Ƭѡ��
RESET    GPIO7_5     �����λ��
RS       GPIO11_4    ���ݡ������л���
WR       GPIO11_6    д���ƶ�
RD       GPIO1_2     �����ƶ�

���ݴ��Ͷ˿�
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
