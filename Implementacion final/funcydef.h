#ifndef FUNCYDEF_H_INCLUDED
#define FUNCYDEF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS DE FUNCIONES */

int controltemp (int,int, int, unsigned char*);
int calentar(int, int, int, unsigned char*);

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


#endif // FUNCYDEF_H_INCLUDED
