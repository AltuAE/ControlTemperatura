#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS */

int controltemp (int);
//int control_pistola(int,int);
int calentar(int, int);

/* DEFINICIONES */

#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define TOGGLE_BIT(reg,bit) reg^=(1<<bit)
#define C 5
#define IRONOUT 4
#define PISTOLAOUT 5
#define IRON 1
#define PISTOLA 2
#define FRIO 0
#define CALIENTE 1


int main()
{
    /* Variables para setpoint de temp. y  de aire, estado actual (inicial frio)  */

    int setpoint, set_aire, select_salida, estado=FRIO;

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
                estado = calentar(setpoint,select_salida);
            break;

            case CALIENTE:
                estado = controltemp(setpoint);
            break;
        }

    }
    return 1;
}


/* FUNCIÓN DE CALENTAMIENTO */

int calentar (int setpoint, int select_salida)
{
    int tactual, estado;
    unsigned char salida;

    /* Si la temperatura es menor a la deseada caliento la salida correspondiente */

    if (tactual<setpoint)
    {
        SET_BIT(salida,select_salida);
        estado=FRIO;
    }

    /* Si la temperatura alcanzó el valor seteado, dejo de calentar */
    else
    {
        CLR_BIT(salida,select_salida);
        estado=CALIENTE;
    }
    return estado;
}

/* FUNCION DE LECTURA SIN CALENTAR */

int controltemp (int setpoint)
{
    int tactual, estado;

    /* Asigno el estado FRIO cuando la temp. es mas baja que setpoint - C grados */
    if (tactual<setpoint-C)
        estado=FRIO;

    /* Si t sigue siendo mayor que setpoint - C grados, sigo en el mismo estado */
    else
        estado=CALIENTE;

    return estado;
}



