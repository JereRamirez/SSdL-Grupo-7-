#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
/*funciones*/

int scanner(FILE *automata); //funcion principal Automata Finito Deterministico
int debo_parar(int estado);
int esLetra(char l);
int esNumero(char l);
int esEspacio(char l);
int obtener_columna (char caracter);
int esVacio(char l);
/*funciones*/
#endif // SCANNER_H_INCLUDED

