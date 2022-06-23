#ifndef _UART_DRIVER_H_
#define _UART_DRIVER_H_
/*
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
*/
#include "mockup_hal.h"

typedef enum hal_state
{
	HAL_OK = 0,
	HAL_FAULT
};

typedef struct
{
	UART_HandleTypeDef *uart_port;
	void (*transmit)(UART_HandleTypeDef *uart, uint8_t *message);
	bool (*receive)(UART_HandleTypeDef *uart, uint8_t *buffer, uint16_t len);
} uart_struct_t;

uart_struct_t uart_init(UART_HandleTypeDef *uart_handle);

void uart_transmit(UART_HandleTypeDef *uart_port, uint8_t *message);

bool uart_receive(UART_HandleTypeDef *uart_port, uint8_t *buffer, uint16_t len);

#endif /* _UART_DRIVER_H_ */
