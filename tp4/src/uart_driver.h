//#ifndef _UART_DRIVER_H_
//#define _UART_DRIVER_H_

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

extern uint8_t transmit_buffer[8];
extern uint8_t recv_buffer[8];

typedef uint16_t UART_HandleTypeDef;

typedef enum hal_state
{
	HAL_OK = 0,
	HAL_FAULT
};

typedef struct
{
	UART_HandleTypeDef * uart_port;
	void (*transmit)(UART_HandleTypeDef * uart, uint8_t *message);
	bool (*receive)(UART_HandleTypeDef * uart, uint8_t *message, uint16_t length);
}uart_struct_t;

uart_struct_t uart_init(UART_HandleTypeDef * uart_handle);

void uart_transmit(UART_HandleTypeDef * uart_port, uint8_t * message);

bool uart_receive(UART_HandleTypeDef * uart_port, uint8_t * message, uint16_t length);


//#endif /* INC_UART_DRIVER_H_ */
