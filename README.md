# UTN FRA - INFORMÁTICA II - TP MÁQUINA DE ESTADOS

### Comisión: 2-12

### Profesores
- Prof. Viard, Gustavo
- Ayte. TP. Corbalan, Damian

### Integrantes
- Altuzarra, Alan
- Pereyra, Nicolas

### Descripción del proyecto
Lógica de control de temperatura (ON/OFF) para estación de soldado. La estación posee:
- Un cautín (iron) y una pistola de calor.
- Selector de Iron o Pistola.
- Selección de temperatura deseada.
- Selección de fuerza de salida de aire.
- Lectura de temperatura.

El funcionamiento está descrito básicamente por el diagrama de estados y transiciones. Para implementar dicho funcionamiento se utilizan los elementos descritos en la sección `Codigo`.
Al seleccionar un setpoint de temperatura, la máquina calienta la herramienta seleccionada hasta que esté a la temperatura deseada y luego la deja de calentar, permitiendo que baje una cantidad "C" de grados definida en el código como un margen para no encenderse de nuevo con cambios muy pequeños de temperatura.
Si está seleccionada la pistola de calor, además del control de temperatura, puede seleccionarse el flujo de aire. Si se selecciona el Iron, la salida de aire se desactiva.
Las funciones fueron programadas para permitir cambiar de opción (Iron o Pistola) rápidamente y que no ocurra, por ejemplo, que se tenga que esperar a que termine de calentarse el Iron para cambiar a la Pistola.

### Código
A continuación una descripción de las constantes, variables, estados y funciones del código y sus propósitos.

###### Constantes

- C: Margen de error para el control de temperatura. Revisar sección `Estados - CALIENTE`.

###### Variables de Entrada (funciones donde se encuentran)

- opcion (main): Selección entre iron (1) o pistola de calor (2).
- setpoint (main): La temperatura deseada, seleccionada por el usuario.
- set_aire (main): La fuerza seleccionada para la salida de aire de la pistola de calor.
- tactual (calentar, controltemp): Lectura actual de temperatura.

###### Variables de Salida (funcion donde se encuentran)

- salida (main, calentar): Salida de 8 bits. El bit 4 (IRONOUT) corresponde al iron, mientras que el bit 5 (PISTOLAOUT) corresponde a la pistola de calor. Se utiliza un control ON/OFF.
- salida_aire (main): Salida de aire para la pistola de calor. Será 0 cuando no se esté usando la pistola, y será set_aire cuando sí se esté usando.

###### Otras variables

- select_salida (main, calentar): Variable utilizada por el programa para determinar qué salida se controla según la `opcion` elegida.
- estado: Guarda el estado actual de la máquina. Inicializa en FRIO.

###### Estados

- FRIO (estado 0): Cuando la temperatura es menor al setpoint. Es el estado inicial de la máquina.
- CALIENTE (estado 1): Cuando la temperatura alcanza el valor seleccionado, y mientras no baje de setpoint - C grados.

###### Funciones

- Main: Dedicada al manejo de los estados y del selector de pistola o iron. Según el estado, llama a las otras funciones.
- Calentar: Función para calentar la salida seleccionada hasta alcanzar el setpoint.
- Controltemp: Función para leer la temperatura sin calentar, una vez que se ha alcanzado el estado CALIENTE, para volver al estado FRIO si es necesario.
