/* discovery F4 stm32f407VG 
File    : main.c

*/

#include <stdio.h>
#include <stdlib.h>
#include "stm32f407xx.h"
#include "ustawienia.h"

/*********************************************************************
*
*       main()
*
*/


int i; //=LED3;

void USART2_write (int ch);
void delayMs(int delay);
  void GPIO_proc(void);

int main(void) {
  
  __disable_irq(); 
  config_LED();
  LED_ALL_ON();
  GPIO_proc();
  UART2_konfig();
  


  NVIC_EnableIRQ(USART2_IRQn);
  NVIC_EnableIRQ(EXTI0_IRQn);
  SysTick_Config(CZESTOTLIWOSC);

__enable_irq(); 
 //__DSB();

  // RCC->AHB1ENR=1;
  
  while (1)
  {


//USART2_write('A');
delayMs(200); 

  }





}

void USART2_write (int ch) {
     // wait until Tx buffer empty
    while (!(USART2->SR & 0x0080)) {}   
    USART2->DR = (ch & 0xFF);
}


void delayMs(int delay) {
    int i;
    for (; delay > 0; delay--)
        for (i = 0; i < 3195; i++) ;
}
   //USART2_IRQHandler
__attribute__((interrupt))  void USART2_IRQHAndler(void) 
{
uint32_t tmp;
if(USART2->SR & USART_SR_RXNE)
  {
    USART2->SR &=~USART_SR_RXNE;
  // int tmp;
   // tmp=USART2->DR ;
   // USART2->DR=tmp ;
   GPIOD->ODR^=LED6;

  }
}

__attribute__((interrupt)) void SysTick_Handler(void)
{
	GPIOD->ODR^=LED3;
	// BB(GPIOB->ODR, GPIO_ODR_OD2) ^= 1;

//GPIOB->ODR^=1;
}

void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR0)
	{
		EXTI->PR=EXTI_PR_PR0;
	//	BB(GPIOD->ODR,GPIO_ODR_ODR_15)^=1;

        GPIOD->ODR^=LED4;
	}
        }

void GPIO_proc(void)
{
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;
RCC->APB2ENR|=RCC_APB2ENR_SYSCFGEN;
__DSB();
//GPIOD->MODER|=0x55000000; //0x4000000; //0x40;
//GPIOD->ODR|=(1<<13)|1<<14|1<<12|1<<15;
GPIOB->MODER|=1|1<<4; // PB0,PB2
GPIOA->MODER&=~(1<<0|1<<1); // input dla PA0
GPIOA->PUPDR|=1<<1; //GPIO_PUPDR_PUPD0_0;
SYSCFG->EXTICR[0]=SYSCFG_EXTICR1_EXTI0_PA; // isr dla PA0
EXTI->FTSR=EXTI_FTSR_TR0; // fall edge PA0
EXTI->IMR=EXTI_IMR_MR0;



}

/*************************** End of file ****************************/
/*
for (i = 0; i < 100; i++) {
    printf("Hello World %d!\n", i);
  }


if (GPIOA->IDR & BUTTON_B1 == 1)
{
  LED_ALL_OFF();
}
 else
  {
    LED_ALL_ON();
    }

  */

