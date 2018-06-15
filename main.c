/*
    TP0 - 2018
    Grupo: 07
    Integrantes:
    - Aruquipa Mamani, Jhoselyn Sandra - 160.867-8
    - Yamada, Demian - 152.711-3
    - Ramirez, Jeremias - 141.941-9
    - Shevchuk Calo, Miguel Omar - 152.603-0
*/

#include <stdio.h>
#include <stdlib.h>

enum token{T_LETRA, T_NUMERO,T_ESPACIOS,T_EOF,T_ERROR};

int main()
{
    /*variables*/
    FILE *archivo;
    char resultado = 6;
    int constEnt = 0;
    int identificadores = 0;
    int errores = 0;
    /*variables*/
    archivo = freopen("automata.dat", "r", stdin);
    //archivo = fopen("automata.dat", "r"); //abre el archivo

    if (archivo == NULL) //verifica que no este vacio
    {
        printf("No esta el archivo automata.dat");
        return -1;
    }
    //bucle donde se ejecuta el automata

    while (resultado != T_EOF)
    {
        resultado = scanner(archivo);
        switch(resultado)
        {
        case T_NUMERO:
            printf("constante entera\n");
            constEnt++;
            break;
        case T_LETRA:
            printf("identificador\n");
            identificadores++;
            break;
        case T_ERROR:
            printf("error\n");
            errores++;
            break;
        }
    }
    /*imprime totales*/
    printf("----------------------------------\n");
    printf("Totales:\n");
    printf("identificadores: %d \n", identificadores);
    printf("constante entera: %d \n", constEnt);
    printf("error: %d \n", errores);
    /*imprime totales*/
     fclose(archivo); //cierra el archivo
    return 0;
}
