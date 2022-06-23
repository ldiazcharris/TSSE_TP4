//#ifndef _UART_DRIVER_H_
//#define _UART_DRIVER_H_

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

extern uint8_t transmit_buffer[8];

typedef uint16_t UART_HandleTypeDef;

typedef enum 
{
	HAL_OK = 0,
	HAL_FAULT
};

typedef struct
{
	UART_HandleTypeDef * uart_port;
	void (*transmit)(UART_HandleTypeDef * uart, char *message);
	bool (*receive)(UART_HandleTypeDef * uart, char *message, uint16_t length);
}uart_struct_t;

uart_struct_t uart_init(UART_HandleTypeDef * uart_handle);

void uart_transmit(UART_HandleTypeDef * uart_port, char * message);

bool uart_receive(UART_HandleTypeDef * uart_port, char * message, uint16_t length);


//#endif /* INC_UART_DRIVER_H_ */
