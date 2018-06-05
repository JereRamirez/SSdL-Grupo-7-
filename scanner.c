#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

char scanner(FILE *automata){
while((lexema = fgetc(archivo)) != EOF){
        printf("%c", lexema);
    }
}

