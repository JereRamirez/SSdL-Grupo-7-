/*
    TP0 - 2018
    Grupo: 07
    Integrantes:
    - Aruquipa Mamani, Jhoselyn Sandra - 160.867-8
    - Demian
    - Jeremias
    - Shevchuk Calo, Miguel Omar - 152.603-0

*/

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    int constanteEntera = 0;
    int identificadores = 0;
    int errores = 0;
    char lexema;
    int resultado = 0;
    FILE *archivo;

    archivo = fopen("automata.dat","r");

    resultado = scanner(archivo);

    fclose(archivo);
    return 0;
}
