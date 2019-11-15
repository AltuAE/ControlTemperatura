#include "funcydef.h"

/* FUNCIÓN DE CALENTAMIENTO */

int calentar (int setpoint, int select_salida,int tactual,unsigned char *salida)
{
    int estado;

    /* Si la temperatura es menor a la deseada caliento la salida correspondiente */

    if (tactual<setpoint)
    {
        SET_BIT(*salida,select_salida);
        estado=FRIO;
    }

    /* Si la temperatura alcanzó el valor seteado, dejo de calentar */
    else
    {
        CLR_BIT(*salida,select_salida);
        estado=CALIENTE;
    }
    return estado;
}

/* FUNCION DE LECTURA SIN CALENTAR */

int controltemp (int setpoint,int tactual)
{
    int estado;

    /* Asigno el estado FRIO cuando la temp. es mas baja que setpoint - C grados */
    if (tactual<setpoint-C)
        estado=FRIO;

    /* Si t sigue siendo mayor que setpoint - C grados, sigo en el mismo estado */
    else
        estado=CALIENTE;

    return estado;
}
