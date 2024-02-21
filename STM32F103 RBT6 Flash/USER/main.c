#include "sys.h"
#include "led.h"
#include "usart.h"
#include "delay.h"	 	 
#include "string.h"	   
#include "stmflash.h"

int main(void)
{	 	
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	LED_Init();
//	memset(A_Parameter,0,sizeof(A_Parameter));
//	memset(B_Parameter,0,sizeof(B_Parameter));
//	memset(Flash_Parameter,0,sizeof(Flash_Parameter));
	while(1){
		Flash_Write();//д������
		LED1=0;
		delay_ms(500);
		
		Flash_Read();//��ȡ����
		LED1=1;
		delay_ms(100);	
	}
}
