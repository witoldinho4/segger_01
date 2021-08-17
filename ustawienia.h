#include <stdint.h>

#define BUTTON_B1 1U<<0
#define LED3      1U<<13
#define LED4      1U<<12
#define LED5      1U<<14
#define LED6      1U<<15

#define UART_PIN_RX     1U<<3
#define UART_PIN_TX     1U<<2

#define ZEGAR         16000000U
#define CZESTOTLIWOSC ZEGAR/4
#define UART2_SPEED   115200

#define ALTER_wartosc_AF7 0x07u
#define ALTER_PIN2  8u
#define ALTER_PIN3  12u


void config_LED(void);
void LED_ALL_ON(void);
void LED_ALL_OFF(void);
void UART2_konfig(void);
