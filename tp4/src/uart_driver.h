
#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_

//#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"

extern char buffer[3];

typedef struct
{
	UART_HandleTypeDef * uart_port;
	void (*transmit)(UART_HandleTypeDef * uart, char *message);
	bool (*receive)(UART_HandleTypeDef * uart, char *message, uint16_t length);
	char (*receive_byte_1)(UART_HandleTypeDef * uart_port);
	bool (*receive_byte_2)(UART_HandleTypeDef * uart_port, char * message);
	char (*receive_byte_it)(UART_HandleTypeDef * uart_port);
	void (*transmit_it)(UART_HandleTypeDef * uart, char *message);
}uart_struct_t;
/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/
uart_struct_t uart_init(UART_HandleTypeDef * uart_handle);

void uart_transmit(UART_HandleTypeDef * uart_port, char * message);

bool uart_receive(UART_HandleTypeDef * uart_port, char * message, uint16_t length);


#endif /* INC_UART_DRIVER_H_ */
