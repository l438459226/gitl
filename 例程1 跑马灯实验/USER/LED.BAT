SET PATH=E:\Keil_v5\ARM\BIN40\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\AMD\ATI.ACE\Core-Static
SET ARMCC41INC=E:\Keil_v5\ARM\RV31\INC
SET ARMCC41LIB=E:\Keil_v5\ARM\RV31\LIB
SET CPU_TYPE=STM32F407VE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=LED
SET CPU_CLOCK=0x007A1200
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\main.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\stm32f4xx_it.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\system_stm32f4xx.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\led.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\delay.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\sys.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\usart.__i"
"E:\Keil_v5\ARM\BIN40\ArmAsm" --Via "..\obj\startup_stm32f40_41xxx._ia"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\misc.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\stm32f4xx_gpio.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\stm32f4xx_rcc.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\stm32f4xx_syscfg.__i"
"E:\Keil_v5\ARM\BIN40\ArmCC" --Via "..\obj\stm32f4xx_usart.__i"
"E:\Keil_v5\ARM\BIN40\ArmLink" --Via "..\OBJ\LED.lnp"
E:\Keil_v5\ARM\BIN40\fromelf.exe "..\OBJ\LED.axf" --i32combined --output "..\OBJ\LED.hex"
E:\Keil_v5\ARM\ARMCC\bin\fromelf.exe --bin -o ../output/test.bin ../OBJ/LED.axf

pause

