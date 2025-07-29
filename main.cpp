#include "FreeRTOS.h"
#include "task.h"
#include "stm32f7xx.h"

#include "main.h"

__attribute__((aligned(32), section(".heap")))
uint8_t ucHeap[configTOTAL_HEAP_SIZE];

void vBlink(void *pv)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
    GPIOJ->MODER |= (1 << (13 * 2));

    for (;;)
    {
        GPIOJ->ODR ^= (1 << 13);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(int argc, char** argv)
{
    SystemInit();
    xTaskCreate(vBlink, "LED", 1024, NULL, 2, NULL);
    vTaskStartScheduler();

    while(1);
    return 0;
}
