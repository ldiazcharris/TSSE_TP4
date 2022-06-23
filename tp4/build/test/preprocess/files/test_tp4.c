#include "src/mockup_hal.h"
#include "src/uart_driver.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
UART_HandleTypeDef uart2 = 0x0a;

uart_struct_t uart_struct;

uint8_t transmit_buffer[128] = "";

uint8_t recv_buffer[128] = "hola persona";





void test_inicializacion_objeto_uart()

{

    uart_struct = uart_init(&uart2);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((&uart2)), (UNITY_INT)(UNITY_UINT16)((uart_struct.uart_port)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)((&uart_transmit)), (UNITY_INT)((uart_struct.transmit)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&uart_receive)), (UNITY_INT)((uart_struct.receive)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);



}





void test_transmision_un_byte()

{

    uint8_t caracter[128] = "C";

    uart_struct.transmit(uart_struct.uart_port, caracter);

    UnityAssertEqualString((const char*)((caracter)), (const char*)((transmit_buffer)), (

   ((void *)0)

   ), (UNITY_UINT)(47));

}





void test_recepcion_un_byte()

{

    uint8_t buffer_a_guardar[128];

    uart_struct.receive(uart_struct.uart_port, buffer_a_guardar, 128);

    UnityAssertEqualString((const char*)((recv_buffer)), (const char*)((buffer_a_guardar)), (

   ((void *)0)

   ), (UNITY_UINT)(55));

}





void test_transmision_un_string()

{

    uint8_t string[] = "Hola Mundo";

    uart_struct.transmit(uart_struct.uart_port, string);

    UnityAssertEqualString((const char*)((string)), (const char*)((transmit_buffer)), (

   ((void *)0)

   ), (UNITY_UINT)(63));

}





void test_recepcion_un_string()

{

    uint8_t buffer_a_guardar[128];

    uart_struct.receive(uart_struct.uart_port, buffer_a_guardar, 128);

    UnityAssertEqualString((const char*)((recv_buffer)), (const char*)((buffer_a_guardar)), (

   ((void *)0)

   ), (UNITY_UINT)(71));

}
