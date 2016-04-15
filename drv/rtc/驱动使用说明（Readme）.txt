1.驱动默认的模式为内部温度校正模式，即校正温度来源选择芯片内部温度传感器。
  本模式下默认认为芯片内部传感器的温度与晶振的温度相差25℃（该值是基于海思样机测试的平均温度差，不同IPC样机的整体功耗有差别，该值也会稍有差别）。
  使用时注意以下几点:
  1）若客户无条件测试晶振的曲线，请使用《RTC晶体校正参数生成表》中“多点测量”一表中的默认参数，即使用驱动原有rtc_temp_lut_tbl.h即可；
  2）若使用外置温度传感器时,需要把muxctrl_reg79寄存器复用为RTC管脚,即配置为0x2（见芯片手册）；

2.获取更多的RTC的应用及相关资料，请参考资料包中的《RTC校准方案应用指导.pdf》。



1.The default setting of "Temperature Measurement Mode" in the driver for RTC is "Temperature obtained by the internal temperature sensor, automatic update " .
  In this mode,the temperature read in the internal temperature(let's define it as "Ta") sensor does not equal to the real temperature(define as "Tb") of the crystal.
  Ta-Tb≈25℃.This value "25℃" which is a statistic value is set in the driver and is tested by Hislicon with its IPC .Different IPC has a different Power consumption,the value may be different.
  The follow tips maybe useful:
  1)In the condition that you don't get the equipments to measure the curve of the crystal,please use "RTC crystal correction parameter create table" and choose "multimetering" sheet and use the default configs for RTC.
    That is to say you will use the default "rtc_temp_lut_tbl.h file" in the driver.
  2)If you use external temperature sensor ,remember to config "muxctrl_reg79 "register to 0x2 so as to turn its function to RTC.
 
2.For more details,please refer the "RTC Correction Scheme Application Notes.pdf".











