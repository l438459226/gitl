#<code class="hljs ruby">	#armasm.exe程序的路径
ASMCOMPILE_PATH = E:\Keil_v5\ARM\ARMCC\bin\armasm.exe
#汇编编译选项
#--cpu Cortex-M4.fp cpu型号是Cortex-M4.fp
#--pd "__UVISION_VERSION SETA 514"  编译之前将__UVISION_VERSION赋值为514，后者同理
ASMCOMPILE_FLAG = --cpu Cortex-M4.fp "..\obj\main.o" "..\obj\stm32f4xx_it.o" "..\obj\system_stm32f4xx.o" "..\obj\led.o" "..\obj\delay.o" "..\obj\sys.o" "..\obj\usart.o" "..\obj\startup_stm32f40_41xxx.o" "..\obj\misc.o" "..\obj\stm32f4xx_gpio.o" "..\obj\stm32f4xx_rcc.o" "..\obj\stm32f4xx_syscfg.o" "..\obj\stm32f4xx_usart.o" --strict --scatter "..\OBJ\LED.sct"
 
#armcc.exe程序的路径
CCOMPILE_PATH = E:\Keil_v5\ARM\ARMCC\bin\armcc.exe
#汇编编译选项
#--cpu Cortex-M4.fp cpu型号是Cortex-M4.fp
#后面的解释看上面的相关指令选项注释
CCOMPILE_FLAG = --cpu Cortex-M4.fp -g -O0 --apcs=interwork --split_sections -D__UVISION_VERSION="514" -DSTM32F40_41xxx
 
#fromelf.exe程序的路径
FROM_ELF_PATH = E:\Keil_v5\ARM\ARMCC\bin\fromelf.exe
#intel 32位hex格式
#输出文件名为test_prj.hex
#基地址为0x08000000
FROM_ELF_FLAG = --i32 --output=.\test_prj.hex --base=0x20010000
 
#头文件查找目录，如果要添加直接添加CINCLUDE_FILE +=样式即可
CINCLUDE_FILE += -I..\system\sys
CINCLUDE_FILE += -I..\system\delay
CINCLUDE_FILE += -I..\hardware\head
CINCLUDE_FILE += -I..\system\usart
CINCLUDE_FILE += -I \e\ProjectFiles\keil5\STM32\test_prj\user\RTE
CINCLUDE_FILE += -I \d\msprograms\keil5\ARM\PACK\Keil\STM32F4xx_DFP\1.0.8\Device\Include
CINCLUDE_FILE += -I \d\msprograms\keil5\ARM\CMSIS\Include
 
#目标文件列表
OBJS += ..\user\startup_stm32f40_41xxx.o
OBJS += ..\system\usart\usart.o
OBJS += ..\system\sys\sys.o
OBJS += ..\system\delay\delay.o
OBJS += ..\hardware\src\gpio.o
OBJS += ..\user\test.o
 
LINK_PATH = E:\Keil_v5\ARM\ARMCC\bin\armlink.exe
 
LINK_FLAG = --cpu Cortex-M4.fp --strict --scatter "test_prj.sct" --summary_stderr --info summarysizes --map --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --list "..\obj\test_prj.map"
 
test_prj.axf : $(OBJS)
#    echo "hellow"
	$(LINK_PATH) $(LINK_FLAG) -o $@ $^ 
	$(FROM_ELF_PATH) $(FROM_ELF_FLAG) .\test_prj.axf
%.o : %.c
	$(CCOMPILE_PATH) $(CINCLUDE_FILE) $(CCOMPILE_FLAG) -o $@ -c $< --omf_browse $(subst .c,.crf,$<) --depend $(subst .c,.d,$<)
%.o : %.s
	$(ASMCOMPILE_PATH) $(CINCLUDE_FILE) $(ASMCOMPILE_FLAG) -o $@ $< --list $(subst .s,.lst,$<) --depend $(subst .s,.d,$<)
 
clean :
	rm -rf $(OBJS)
 
#字符串查找替换
#$(subst <from>,<to>,<text>)
#把text中的from字符串替换为to字符串
#例：$(subst he,HE,hellow)
#把hellow中的he替换为HE<\text><\to><\from><\code>