
#include "uart_driver.h"

uart_struct_t uart_init(UART_HandleTypeDef * uart_handle)
{
	uart_struct_t uart_struct;

	uart_struct.uart_port = uart_handle;
	uart_struct.transmit = &uart_transmit;
	uart_struct.receive = &uart_receive;

	return uart_struct;
}

void uart_transmit(UART_HandleTypeDef * uart_port, uint8_t *message)
{
	transmit_buffer[0] = *message;
}

bool uart_receive(UART_HandleTypeDef * uart_port, char * message, uint16_t length)
{
	
}
