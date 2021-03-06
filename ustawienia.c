#include "ustawienia.h"
#include "stm32f407xx.h"


void config_LED(void)
{
RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN; // wlaczenie magistrali LED  gpioD
GPIOD->MODER|=GPIO_MODER_MODE13_0| GPIO_MODER_MODE12_0| GPIO_MODER_MODE14_0 |GPIO_MODER_MODE15_0; //ustawienie jako OUT


}

void LED_ALL_ON(void)
{
GPIOD->ODR|=LED3|LED4|LED5|LED6;


}

void LED_ALL_OFF(void)
{
GPIOD->ODR&=~(LED3|LED4|LED5|LED6);
}

void UART2_konfig(void)
{
 
RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
__DSB();
GPIOA->MODER|=2u<<6u;
GPIOA->MODER|=2u<<4u; //GPIO_MODER_MODE2_1

GPIOA->AFR[0]|=7u<<8U;
GPIOA->AFR[0]|=7u<<12U;
//GPIOA->AFR[1]|=7u<<16u;

USART2->BRR=ZEGAR/UART2_SPEED;
USART2->CR1=USART_CR1_UE|USART_CR1_RXNEIE|USART_CR1_TE| USART_CR1_RE;





}