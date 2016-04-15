#Created by liucan, 2012/12/26

ifeq ($(PARAM_FILE), )
        PARAM_FILE:=../../mpp/Makefile.param
        include $(PARAM_FILE)
endif

obj-m := hidmac.o
hidmac-y += hi_dmac.o

EXTRA_CFLAGS += -D$(HIARCH) -DHICHIP=$(HICHIP) -D$(HIDBG) -D$(HI_FPGA)

default:
	@echo -e "\e[0;32;1m--Compiling 'hidmac'...\e[0;36;1m"
	@@echo -e "\e[0m" 
	@make -C $(LINUX_ROOT) M=$(PWD) modules 
	@cp hidmac.ko $(REL_KO)

clean: 
	@make -C $(LINUX_ROOT) M=$(PWD) clean 
	@rm -rf $(REL_KO)/hidmac.ko
