#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"


//�����ʵ�� -�⺯���汾
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com

typedef  void (*iapfun)(void);				//����һ���������͵Ĳ���. 
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

	delay_init(168);		  //��ʼ����ʱ����
	//LED_Init();		        //��ʼ��LED�˿�
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
		GPIO_SetBits(GPIOA,GPIO_Pin_6);  //LED0��Ӧ����GPIOA.6���ͣ���  ��ͬLED0=0;
		GPIO_SetBits(GPIOA,GPIO_Pin_7);   //LED1��Ӧ����GPIOA.7���ߣ��� ��ͬLED1=1;
		delay_ms(200);  		   //��ʱ300ms
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);	   //LED0��Ӧ����GPIOA.6���ߣ���  ��ͬLED0=1;
		GPIO_ResetBits(GPIOA,GPIO_Pin_7); //LED1��Ӧ����GPIOA.7���ͣ��� ��ͬLED1=0;
		delay_ms(200);                     //��ʱ300ms
	}
}



 



