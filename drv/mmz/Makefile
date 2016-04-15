# Create by liucan,2012/12/26

ifeq ($(PARAM_FILE), )
    PARAM_FILE:=../../mpp/Makefile.param
    include $(PARAM_FILE)
endif

obj-m := mmz.o
mmz-y += media-mem.o mmz-userdev.o kcom.o

all:
	@echo -e "\e[0;32;1m--Compiling 'mmz'...\e[0;36;1m" 
	@echo -e "\e[0m" 
	@make -C $(LINUX_ROOT) M=$(PWD) modules
	@cp mmz.ko $(REL_KO)

clean: 
	@make -C $(LINUX_ROOT) M=$(PWD) clean 
	@rm -rf $(REL_KO)/mmz.ko
