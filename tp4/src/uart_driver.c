
#include "uart_driver.h"

uart_struct_t uart_init(UART_HandleTypeDef * uart_handle)
{
	uart_struct_t uart_struct;

	uart_struct.uart_port = uart_handle;
	uart_struct.transmit = &uart_transmit;
	uart_struct.receive = &uart_receive;
	uart_struct.receive_byte_1 = &uart_receive_byte_1;
	uart_struct.receive_byte_2 = &uart_receive_byte_2;
	uart_struct.receive_byte_it = &uart_receive_byte_it;
	uart_struct.transmit_it = &uart_transmit_it;

	return uart_struct;
}

void uart_transmit(UART_HandleTypeDef * uart_port, char *message)
{
	if(message != NULL)
	{
		HAL_UART_Transmit(uart_port, (uint8_t *) message, (uint16_t)strlen(message), 0xFFFF);
	}
}

bool uart_receive(UART_HandleTypeDef * uart_port, char * message, uint16_t length)
{
	bool status = false;
	if(message != NULL)
	{
		if(HAL_UART_Receive(uart_port,(uint8_t *) message, length, 0xFFFF) == HAL_OK)
		{
			status = true;
		}
	}
	return status;
}
