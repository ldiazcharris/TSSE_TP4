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
#include "mockup_hal.h"


/** -----------------------------PRUEABAS A REALIZAR------------------------------------------
 *  1. Se inicializa la estructura del objeto uart con el hardware inicializado ---- OK
 *  2. Se pude transmitr un byte ---- OK
 *  3. Se pude recibir un byte ---- OK
 *  4. Se puede transmitir una cadena de caracteres ---- OK
 *  5. Se puede recibir una cadena de caracteres ---- OK
 *  
 */

UART_HandleTypeDef uart2 = 0x0a;
uart_struct_t uart_struct;
uint8_t transmit_buffer[128] = "";

//uint8_t recv_buffer[128] = "";

// 1. Se inicializa la estructura del objeto uart con el hardware inicializado
void test_inicializacion_objeto_uart()
{
    uart_struct = uart_init(&uart2);

    TEST_ASSERT_EQUAL_UINT16(&uart2, uart_struct.uart_port);
    TEST_ASSERT_EQUAL_INT(&uart_transmit, uart_struct.transmit);
    TEST_ASSERT_EQUAL_INT(&uart_receive, uart_struct.receive);

}

// 2. Se pude transmitr un byte
void test_transmision_un_byte()
{
    uint8_t caracter[128] = "C";
    uart_struct.transmit(uart_struct.uart_port, caracter);
    TEST_ASSERT_EQUAL_STRING(caracter, transmit_buffer);
}

// 3. Se pude recibir un byte
void test_recepcion_un_byte()
{
    uint8_t buffer_a_guardar[128];
    strcpy(recv_buffer, "h");
    uart_struct.receive(uart_struct.uart_port, buffer_a_guardar, 128);
    TEST_ASSERT_EQUAL_STRING(recv_buffer, buffer_a_guardar);
}

// 4. Se puede transmitir una cadena de caracteres 
void test_transmision_un_string()
{
    uint8_t string[] = "Hola Mundo";
    uart_struct.transmit(uart_struct.uart_port, string);
    TEST_ASSERT_EQUAL_STRING(string, transmit_buffer);
    
}

// 5. Se pude recibir una cadena de caracteres 
void test_recepcion_un_string()
{
    uint8_t buffer_a_guardar[128];
    strcpy(recv_buffer, "Hola Maquina");
    uart_struct.receive(uart_struct.uart_port, buffer_a_guardar, 128);
    TEST_ASSERT_EQUAL_STRING(recv_buffer, buffer_a_guardar);
}