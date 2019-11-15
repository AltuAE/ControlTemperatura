#include "funcydef.h"

int(*pcalentar)(int,int,int,unsigned char*)=calentar;
int(*pcontrol)(int,int)=controltemp;

int main()
{
    /* Variables para setpoint de temp. y  de aire, lectura de temperatura,
    y estado actual (inicial frio) */

    int setpoint, set_aire, select_salida, tactual, estado=FRIO;

    /* Selector de iron o pistola. Bit 0: Iron. Bit 1: Pistola de aire */

    unsigned char opcion=0;

    /* Salida para calentar. Bit 4 = cautin y bit 5 = pistola, inicializo apagado */

    unsigned char salida=0;

    /* Control de flujo de aire. */

    int salida_aire=0;


    while(1)
    {
        /* Switch de Iron o Pistola */
        switch (opcion)
        {
            case IRON:
                salida_aire=0;
                select_salida=IRONOUT;
            break;

            case PISTOLA:
                salida_aire=set_aire;
                select_salida=PISTOLAOUT;
            break;
        }


        /* Manejo de estados */
        switch (estado)
        {
            case FRIO:
                estado = (*pcalentar)(setpoint,select_salida,tactual,&salida);
            break;

            case CALIENTE:
                estado = (*pcontrol)(setpoint,tactual);
            break;
        }

    }
    return 1;
}


