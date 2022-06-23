#ifndef _MOCKUP_HAL_H
#define _MOCKUP_HAL_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

typedef uint16_t UART_HandleTypeDef;

extern uint8_t transmit_buffer[128];
extern uint8_t recv_buffer[128];

void HAL_UART_Transmit(UART_HandleTypeDef *huart_port, uint8_t *mensaje, uint16_t len, uint16_t time_out);

void HAL_UART_Receive(UART_HandleTypeDef *huart_port, uint8_t *buffer, uint16_t len, uint16_t time_out);


#endif // _MOCKUP_HAL_H