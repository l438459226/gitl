#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"


//跑马灯实验 -库函数版本
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com

typedef  void (*iapfun)(void);				//定义一个函数类型的参数. 
typedef  void (*iapfun1)(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead);
typedef  void (*iapfun2)(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);

iapfun 				usebootfun;
iapfun 				W25QXX_Initf;
iapfun1  			W25QXX_Readf;	
iapfun2  			W25QXX_Writef;


#define LEDINIT					0x08000771
#define W25QXX_Init				0x08000A5B
#define W25QXX_Read				0x08000B41
#define W25QXX_Write			0x08000C9D

const u8 TEXT_Buffer[]={"test running ioa heeeo 4"};
#define SIZE sizeof(TEXT_Buffer)

int appmain(void)
{ 
 	u8 i=6;
	u32 FLASH_SIZE;
	u8 datatemp[SIZE];
	FLASH_SIZE=16*1024*1024;

	delay_init(168);		  //初始化延时函数
	//LED_Init();		        //初始化LED端口
	usebootfun = (iapfun)(LEDINIT);
	W25QXX_Initf = (iapfun)(W25QXX_Init);
	W25QXX_Readf = (iapfun1)(W25QXX_Read);
	W25QXX_Writef = (iapfun2)(W25QXX_Write);

	W25QXX_Initf();

    W25QXX_Writef("1234567890ABDESWEFHJU",16*1024*1024-10240,SIZE);

	W25QXX_Readf(datatemp,16*1024*1024-10240,SIZE);

	printf("w25a read data:");
	for(i=0;i<SIZE;i++){
		printf("%c ",datatemp[i]);
	}
	printf("\r\n");

	while(i--)
	{
		usebootfun();
		GPIO_SetBits(GPIOA,GPIO_Pin_6);  //LED0对应引脚GPIOA.6拉低，亮  等同LED0=0;
		GPIO_SetBits(GPIOA,GPIO_Pin_7);   //LED1对应引脚GPIOA.7拉高，灭 等同LED1=1;
		delay_ms(200);  		   //延时300ms
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);	   //LED0对应引脚GPIOA.6拉高，灭  等同LED0=1;
		GPIO_ResetBits(GPIOA,GPIO_Pin_7); //LED1对应引脚GPIOA.7拉低，亮 等同LED1=0;
		delay_ms(200);                     //延时300ms
	}
}



 



