#include "mockup_hal.h"

HAL_UART_Transmit(UART_HandleTypeDef *huart_port, uint8_t *mensaje, uint16_t len, uint16_t time_out)
{
    clock_t t0 = clock();
    while(t0 - clock() == (clock_t) time_out)
    {
        strncpy(transmit_buffer, mensaje, (size_t)len);
    }
    t0 = 0;
    
}

HAL_UART_Receive(UART_HandleTypeDef *huart_port, uint8_t *buffer, uint16_t len, uint16_t time_out)
{
    clock_t t0 = clock();
    while(t0 - clock() == (clock_t) time_out)
    {
       strncpy(recv_buffer, buffer, (size_t)len);
    }
    t0 = 0;
}
