
#include "uart_driver.h"
#include "mockup_hal.h"

uart_struct_t uart_init(UART_HandleTypeDef * uart_handle)
{
	uart_struct_t uart_struct;

	uart_struct.uart_port = uart_handle;
	uart_struct.transmit = &uart_transmit;
	uart_struct.receive = &uart_receive;

	return uart_struct;
}

void uart_transmit(UART_HandleTypeDef *uart_port, uint8_t *message)
{
	if(message != NULL)
	{
		HAL_UART_Transmit(uart_port, message, (uint16_t) strlen(message), 0xFFF);
	}
	
}

bool uart_receive(UART_HandleTypeDef *uart_port, uint8_t *buffer, uint16_t len)
{
	if(buffer != NULL)
	{
		HAL_UART_Transmit(uart_port, buffer, len, 0xFFF);
	}

	
}
