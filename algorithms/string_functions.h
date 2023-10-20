#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string.h>

void print_string_functions() {
    cout << "\n === Funciones de Cadenas === \n" << endl;
    cout << "strcpy(cad_1, cad_2)     " << setw(5) << " = " << "Sustituye el contenido de cad_1 por el de cad_2" << endl;
    cout << "strncpy(cad_1, cad_2, n) " << setw(5) << " = " << "Copia n carácteres de cad_2 en cad_1" << endl;
    cout << "strcat(cad_1, cad_2)     " << setw(5) << " = " << "Agrega cad_2 al final de cad_1" << endl;
    cout << "strncat(cad_1, cad_2, n) " << setw(5) << " = " << "Agrega como máximo n carácteres de cad_2 a cad_1" << endl;
    cout << "int strcmp(cad_1, cad_2) " << setw(5) << " = " << "Compara cad_1 con cad_2; 0 si son iguales, > 0 si cad_1 es mayor, < 0 si cad_1 es menor" << endl;
    cout << "                         " << setw(5) << "   " << "La comparación es lexicográfica (alfabética) de A a Z, letras minúsculas > letras mayúsculas" << endl;
    cout << "int strcmpi(cad_1, cad_2)" << setw(5) << " = " << "Compara cad_1 con cad_2, considerando minúsculas y mayúsculas iguales" << endl;
    cout << "strncmp(cad_1, cad_2, n) " << setw(5) << " = " << "Compara n caracteres de cad_1 con cad_2, regresa los mismos valores que strcmp" << endl;
    cout << "strlen(cadena)           " << setw(5) << " = " << "Determina la longitud de la cadena" << endl;
    cout << "strlwr(cadena)           " << setw(5) << " = " << "Convierte la cadena en minúsculas" << endl;
    cout << "strupr(cadena)           " << setw(5) << " = " << "Convierte la cadena a mayúsculas" << endl;
    cout << "strrev(cadena)           " << setw(5) << " = " << "Invierte la cadena" << endl;
    cout << "strset(cadena, caracter) " << setw(5) << " = " << "Rellena toda la cadena con el caracter específicado" << endl;
    cout << endl;
}

#endif // STRING_FUNCTIONS_H