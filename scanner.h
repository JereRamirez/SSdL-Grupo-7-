#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
/*funciones*/
enum token{T_LETRA, T_NUMERO,T_ESPACIOS,T_EOF,T_ERROR};
char scanner(FILE *automata); //funcion principal Automata Finito Deterministico
int debo_parar(int estado);
int esLetra(char l);
int esNumero(char l);
int esEspacio(char l);
int obtener_columna (char caracter);
/*funciones*/
#endif // SCANNER_H_INCLUDED

