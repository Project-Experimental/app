#include "FreeRTOS.h"
#include "task.h"
#include "stm32f7xx.h"

#include "main.h"

#include <freex/rtos/kernel.hpp>
#include <freex/rtos/task.hpp>
#include <freex/board/stm32f7xx/gpio.hpp>

class BlankTask : public freex::rtos::TaskInterface 
{
protected:
    void Run(void* pv) override
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
        freex::board::stm32f7xx::GPIO<GPIOJ_BASE> gpio;
        gpio.Mode(1, GPIO_MODER_MODER13_Pos);
        while(1)
        {
            gpio.Toggle(GPIO_ODR_OD13_Pos);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
    }
};

[[noreturn]]
int main(int argc, char** argv)
{
    SystemInit();
    static BlankTask blanktask;
    
    blanktask.Start("LED");
    freex::rtos::Kernel::StartScheduler();

    while(1);
    // return 0;
}
