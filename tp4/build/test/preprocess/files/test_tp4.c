#include "src/uart_driver.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
UART_HandleTypeDef uart2 = 0x0a;

uart_struct_t uart_struct;

uint8_t transmit_buffer[8] = "";

uint8_t recv_buffer[8] = "";





void test_inicializacion_objeto_uart()

{

    uart_struct = uart_init(&uart2);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((&uart2)), (UNITY_INT)(UNITY_UINT16)((uart_struct.uart_port)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)((&uart_transmit)), (UNITY_INT)((uart_struct.transmit)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&uart_receive)), (UNITY_INT)((uart_struct.receive)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);



}





void test_transmision_un_byte()

{

    uint8_t caracter = 'C';

    uart_struct.transmit(uart_struct.uart_port, &caracter);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )(('C')), (UNITY_INT)(UNITY_UINT8 )((transmit_buffer[0])), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_UINT8);

}





void test_recepcion_un_byte()

{

    uint8_t caracter = 0;

    recv_buffer[0] = 'h';

    uart_struct.receive(uart_struct.uart_port, &caracter, 1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((recv_buffer[0])), (UNITY_INT)(UNITY_UINT8 )((caracter)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT8);

}
