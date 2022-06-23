#include "src/uart_driver.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
UART_HandleTypeDef uart2 = 0x0a;

uart_struct_t uart_struct;





void test_inicializacion_objeto_uart()

{

    uart_struct = uart_init(&uart2);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((&uart2)), (UNITY_INT)(UNITY_UINT16)((uart_struct.uart_port)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)((&uart_transmit)), (UNITY_INT)((uart_struct.transmit)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&uart_receive)), (UNITY_INT)((uart_struct.receive)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);



}
