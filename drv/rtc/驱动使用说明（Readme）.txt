1.����Ĭ�ϵ�ģʽΪ�ڲ��¶�У��ģʽ����У���¶���Դѡ��оƬ�ڲ��¶ȴ�������
  ��ģʽ��Ĭ����ΪоƬ�ڲ����������¶��뾧����¶����25�棨��ֵ�ǻ��ں�˼�������Ե�ƽ���¶Ȳ��ͬIPC���������幦���в�𣬸�ֵҲ�����в�𣩡�
  ʹ��ʱע�����¼���:
  1�����ͻ����������Ծ�������ߣ���ʹ�á�RTC����У���������ɱ��С���������һ���е�Ĭ�ϲ�������ʹ������ԭ��rtc_temp_lut_tbl.h���ɣ�
  2����ʹ�������¶ȴ�����ʱ,��Ҫ��muxctrl_reg79�Ĵ�������ΪRTC�ܽ�,������Ϊ0x2����оƬ�ֲᣩ��

2.��ȡ�����RTC��Ӧ�ü�������ϣ���ο����ϰ��еġ�RTCУ׼����Ӧ��ָ��.pdf����



1.The default setting of "Temperature Measurement Mode" in the driver for RTC is "Temperature obtained by the internal temperature sensor, automatic update " .
  In this mode,the temperature read in the internal temperature(let's define it as "Ta") sensor does not equal to the real temperature(define as "Tb") of the crystal.
  Ta-Tb��25��.This value "25��" which is a statistic value is set in the driver and is tested by Hislicon with its IPC .Different IPC has a different Power consumption,the value may be different.
  The follow tips maybe useful:
  1)In the condition that you don't get the equipments to measure the curve of the crystal,please use "RTC crystal correction parameter create table" and choose "multimetering" sheet and use the default configs for RTC.
    That is to say you will use the default "rtc_temp_lut_tbl.h file" in the driver.
  2)If you use external temperature sensor ,remember to config "muxctrl_reg79 "register to 0x2 so as to turn its function to RTC.
 
2.For more details,please refer the "RTC Correction Scheme Application Notes.pdf".











