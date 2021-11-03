#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_Def.h"
#include "Timer.h"



void Systick_Handler(void){
        HAL_IncTick();
    }


void Init_GPIO_LEDS(void){
      GPIO_InitTypeDef GPIO_InitStruct;

      __HAL_RCC_GPIOD_CLK_ENABLE();

      GPIO_InitStruct.Pin  = GPIO_PIN_12;
      GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

      GPIO_InitStruct.Pin  = GPIO_PIN_13;
      GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

      GPIO_InitStruct.Pin  = GPIO_PIN_14;
      GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

      GPIO_InitStruct.Pin  = GPIO_PIN_15;
      GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

      //PULSADOR

      __HAL_RCC_GPIOA_CLK_ENABLE();

      GPIO_InitStruct.Pin  = GPIO_PIN_0;
      GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      GPIO_InitStruct.Pull = GPIO_PULLDOWN;
      HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);



  }
int
main(int argc, char* argv[])
{
    HAL_Init();

    Systick_Handler();
    Init_GPIO_LEDS();
    // At this stage the system clock should have already been configured
  // at high speed.

  // Infinite loop
  while (1)
    {
      // Add your code here.
      //PUNTO 1 AGREGAR DELAYS DE VERDAD

      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
      HAL_Delay(300);

      // APAGAR EL VERDE Y PRENDER EL NARANJA
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
      HAL_Delay(300);

      // APAGAR EL NARANJA Y PRENDER EL ROJO
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
      HAL_Delay(300);

      // APAGAR EL ROJO Y PRENDER EL AZUL
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
      HAL_Delay(300);

      // APAGAR EL AZUL
      HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
      HAL_Delay(300);



}
}
#pragma GCC diagnostic pop
