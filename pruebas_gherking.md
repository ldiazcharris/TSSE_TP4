### Pruebas escritas en lenguaje Gherking

***Prueba 1*** 

***Escenario:*** Inicialización de la estructura del objeto uart.
    ***Dado*** El programador debe inicializar el hardware necesario y proporcionar los registros u otros objetos propios de la HAL del microcontrolador que usa y pasarselos a la función uart_initi(). Además debe inicializar una estructura del tipo uart_struct_t.
    ***Cuando*** El programador llama a la función uart_init() con los parámetros correctos
    ***Entonces*** La función carga un objeto (estructura) del tipo uart_struct_t con los datos del hardware inicializado.


***Prueba 2***

***Escenario:***  Transmisión de un byte.
    ***Dada*** La inicialización del Hardware y la estructura,
    ***Cuando*** el programador llame al método *transmit* del objeto uart y le cargue el caracter a enviar
    ***Entonces*** se ejecutará la transmisión de datos por la uart, a través del puerto uart destinado.


***Prueba 3***

***Escenario:*** Se pude recibir un byte.
    ***Dado*** La inicialización del Hardware y la estructura,
    ***Cuando*** el programador llame al método *receive* del objeto uart y le indique la variable de destino para la recepción,
    ***Entonces*** se guardará el caracter recibido de la uart en la variable destinada.


***Prueba 4***

***Escenario:*** Se puede transmitir una cadena de caracteres
    ***Cuando*** La inicialización del Hardware y la estructura,
    ***Cuando*** el programador llame al método *transmit* del objeto uart y le cargue el puntero que guarda la la cadena de caracteres o a cadena en si misma a enviar,
    ***Entonces***  se ejecutará la transmisión de datos por la uart, a través del puerto uart destinado.


***Prueba 5***

***Escenario:*** Se puede recibir una cadena de caracteres
    ***Dado*** La inicialización del Hardware y la estructura,
    ***Cuando*** el programador llame al método *receive* del objeto uart y le indique el buffer de destino para la recepción,
    ***Entonces*** se guardará el caracter recibido de la uart en el buffer destinado.