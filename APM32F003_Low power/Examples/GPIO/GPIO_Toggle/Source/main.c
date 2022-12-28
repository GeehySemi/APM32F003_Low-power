#include "main.h"
#include "apm32f00x_gpio.h"
#include "apm32f00x_eint.h"
#include "apm32f00x_misc.h"

extern int Sleepflag;

int main(void) 
{
    GPIO_Config_T gpioConfig;

    gpioConfig.mode = GPIO_MODE_IN_PU;
    gpioConfig.pin = GPIO_PIN_ALL;			
    GPIO_Config(GPIOA, &gpioConfig);							
    GPIO_Config(GPIOB, &gpioConfig);					
    GPIO_Config(GPIOC, &gpioConfig);	
    gpioConfig.pin = ((uint8_t)0XF9); 
    GPIO_Config(GPIOD, &gpioConfig);	
	
//KEY1 PD6
    gpioConfig.mode = GPIO_MODE_IN_PU;
    gpioConfig.pin = GPIO_PIN_6;
    gpioConfig.intEn = GPIO_EINT_ENABLE;
    EINT_Config(EINT_PORT_D, EINT_TRIGGER_FALLING);
    NVIC_EnableIRQRequest(EINTD_IRQn, 0X01);
    GPIO_Config(GPIOD, &gpioConfig);		
																				
    while(1)	
    {
      if(Sleepflag)
      {								
        PMU_EnterHaltModeWFI();	
      }					
    }
}
