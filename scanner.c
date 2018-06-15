#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

int tt[9][5] = {
                    {2,1,0,5,7 },
                    {5,1,3,5,3 },
                    {2,2,4,5,4 },
                    {99,99,99,99,99},
                    {99,99,99,99,99},
                    {6,6,6,5,6 },
                    {99,99,99,99,99},
                    {99,99,99,99,99}
                };

enum token{T_LETRA, T_NUMERO,T_ESPACIOS,T_EOF,T_ERROR};
enum tipo {LETRA, NUMERO, ESPACIOS, ERROR, CEOF };  /*columnas*/
enum estado {ACEPTOR_LETRA = 4, ACEPTOR_NUMERO = 3,ESTADO_ERROR = 6, ESTADO_EOF= 7, CENTINELA = 99};

int scanner(FILE *automata)
{
	char caracter;
    int estado = 0;
    int token = T_ERROR;
    /*funcion scanner*/
    while (!debo_parar(estado))
    {
        caracter = getchar();
        estado = tt[estado][obtener_columna(caracter)];
    }

    if (estado == CENTINELA || estado == ESTADO_ERROR)
    {
        ungetc(caracter, automata);
    }

    switch(estado)
    {
    case ACEPTOR_LETRA:
        token = T_LETRA;
        break;
    case ACEPTOR_NUMERO:
        token = T_NUMERO;
        break;
    case ESTADO_EOF:
        token = T_EOF;
        break;
    case ESTADO_ERROR:
        token = T_ERROR;
        break;
    default:
        printf("algo anda muy mal aca!"); // para evitar warnings
    }
    return token;
};
/*funcion scanner*/

/* funcion para obtener la columna*/
int obtener_columna (char caracter)
{
    int tipoCaracter;

    if (esLetra(caracter))
    {
        tipoCaracter = LETRA;
    }
    else if (esNumero(caracter))
    {
        tipoCaracter = NUMERO;
    }
    else if (esEspacio(caracter) || esVacio(caracter))
    {
        tipoCaracter = ESPACIOS;
    }
    else if (caracter == EOF)
    {
        tipoCaracter = CEOF;
    }
    else
    {
        tipoCaracter = ERROR;
    }
    return tipoCaracter;
}
/* funcion para obtener la columna*/

/*aceptor */
int debo_parar(int estado)
{
    switch (estado)
    {
        case ACEPTOR_LETRA:
        case ACEPTOR_NUMERO:
        case ESTADO_EOF:
        case ESTADO_ERROR:
            return 1;
    }
    return 0;
}
/*aceptor */

/*auxiliares no necesarias pero hacen el codigo mas legible en español*/
int esLetra(char l)
{
    return islower(l) && isupper(l);
}
int esNumero(char l)
{
    return isdigit(l);
}
int esEspacio(char l)
{
    return isspace(l);
}
int esVacio(char l)
{
	return l == "";
};
/*auxiliares no necesarias pero hacen el codigo mas legible en español*/




