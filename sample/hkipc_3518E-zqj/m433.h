#ifndef __M433_H__
#define __M433_H__

#define GPIO_BIT        21
#define REFERENCE_MAX   32

#define START			10
#define PAUSE			11
#define PROBE			12
#define PWSETUP         13

#define SETALARM        0x20
#define M433SIG         0x21
#define SETCON          0x22
#define SETUNCON        0x23

#define CLEARTABLE      0x2D
#define FILLTABLE       0x2E
#define GETSTATE        0x30
#define SETSTATE        0x31


#define NORMAL_MODE     0x32
#define LEARN_MODE      0x33
#define TEST_MODE       0x34                

#define FLAG_ALARM      0x35
#define FLAG_UNALARM    0x36
#define FLAG_TEST       0x37
#define FLAG_LEARN      0x38

#define DELMODULE       0x40
#define TELECONTROL     0x41
#define DELCODE         0x42
#define M433_PATH "/mnt/sif/m433.conf"
//#define PATH_SDRECORD "/mnt/mmc/snapshot"
//#define PATH_M433_SNAPSHOT "/mnt/mmc/snapshot/m433"
#define PATH_SDRECORD "/mnt/mmc/"
#define PATH_M433_SNAPSHOT "/mnt/mmc/m433"
#define M433_CODE "code"

/** Light  **/
#define DM_LIGHT_CONF "/mnt/sif/light.conf"
#define STARTTIME  "starttime"
#define ENDTIME    "endtime"
#define TIMEOPEN "timeopen"
#define SPLITFLAG  "-"
#define OPEN_LIGHT_ARLAMING "openalarming"
#define LIGHT_CUR_STATUS "status"
#define USER_OPEN     1
#define ALARMING_OPEN 2
#define ONTIME_OPEN   4
#define REMOTE_OPEN   8


#define GPIO_READ  0
#define GPIO_WRITE 1

#define MAXINDEX    64

struct M433DEV {
    unsigned int accept_ad;
    unsigned int short_pulse;
    unsigned int long_pulse;
    int normal_mode;
    int telecontrol;
    unsigned int timeout;
};

struct m433_data_t {
    int keep_run;
    int current_ad;
    int alarm_flag;
    int test_flag;
    int reference_table[REFERENCE_MAX];
};

struct transe_t {
    int code;
    int flag;
    int mode;
};

unsigned int g_EnableSnapImg;

void sig_handler(int signo);

#endif //__M433_H__
