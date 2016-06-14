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

/*********************************************************
*������ : initTFTGPIO
*��  �� : ��ʼ��TFT���Ŀ��ƶ˿ڶ�Ϊд״̬,״̬Ϊ0
*����� : ֣����
*��  �� : 2016.6.14
*��  ע : ��
**********************************************************/
void initTFTGPIO()
{
    unsigned int val_read = 0;
    unsigned int val_set = 0; //pull down.
    unsigned int groupnum = 0;
    unsigned int bitnum = 0;

    printf("<<<<<<<<<<<<< Init TFT GPIO >>>>>>>>>>>>>>>>>>>\n")��
        
    groupnum = 10;
    bitnum = 3; //GPIO:10_3 (������).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 5; //GPIO:11_5 (Ƭѡ��).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 7;
    bitnum = 5; //GPIO:7_5 (�����λ��).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 4; //GPIO:11_4 (���ݡ������л���).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );

    groupnum = 11;
    bitnum = 6; //GPIO:11_6 (д���ƶ�).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set );
      
    groupnum = 1;
    bitnum = 2; //GPIO:1_2 (�����ƶ�).
    Hi_SetGpio_SetDir( groupnum, bitnum, GPIO_WRITE );
    Hi_SetGpio_SetBit( groupnum, bitnum, val_set ); 
   
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

