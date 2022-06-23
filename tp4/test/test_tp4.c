/**
 * @file test_tp4.c
 * @author Luis David Diaz Charris (lddiazcharris@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Creative Commons 2022
 * 
 */

#include "unity.h"
#include "uart_driver.h"


/** -----------------------------PRUEABAS A REALIZAR------------------------------------------
 *  1. Se inicializa la estructura del objeto uart con el hardware inicializado 
 *  2. Se pude transmitr un byte
 *  3. Se pude recibir un byte
 *  4. Se puede transmitir una cadena de caracteres
 *  5. Se puede recibir una cadena de caracteres
 *  
 */

UART_HandleTypeDef uart2 = 0x0a;
uart_struct_t uart_struct;

// Se inicializa la estructura del objeto uart con el hardware inicializado 
void test_inicializacion_objeto_uart()
{
    uart_struct = uart_init(&uart2);

    TEST_ASSERT_EQUAL_UINT16(&uart2, uart_struct.uart_port);
    TEST_ASSERT_EQUAL_INT(&uart_transmit, uart_struct.transmit);
    TEST_ASSERT_EQUAL_INT(&uart_receive, uart_struct.receive);

}

// Se pude transmitr un byte
void test_transmision_un_byte()
{
    uint8_t caracter = 'C';
    uart_struct.transmit(uart_struct.uart_port, (char *) &caracter);
    TEST_ASSERT_EQUAL_UINT8('C', transmit_buffer[0]);
}