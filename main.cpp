#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"

int main() {
    Limpiar;
    cout << "\n === Tipos de Datos Primitivos === \n" << endl;
    cout << "Tipo de Dato" << setw (20) << "Bits" << setw (25) << "Valor Minimo" << setw (25) << "Valor Maximo\n" << endl;
    cout << "Caracter con signo" << setw (14) << sizeof(char)*8 << setw (25) << CHAR_MIN << setw (25) << CHAR_MAX << endl;
    cout << "Caracter sin signo" << setw (14) << sizeof(unsigned char)*8 << setw (25) << 0 << setw (25) << UCHAR_MAX << endl;
    cout << "Entero corto con signo" << setw (10) << sizeof(short)*8 << setw (25) << SHRT_MIN << setw (25) << SHRT_MAX << endl;
    cout << "Entero corto sin signo" << setw (10) << sizeof(unsigned short)*8 << setw (25) << 0 << setw (25) << USHRT_MAX << endl;
    cout << "Entero largo con signo" << setw (10) << sizeof(long)*8 << setw (25) << LONG_MIN << setw (25) << LONG_MAX << endl;
    cout << "Entero largo sin signo" << setw (10) << sizeof(unsigned long)*8 << setw (25) << 0 << setw (25) << ULONG_MAX << endl;
    cout << "Real de precision simple" << setw (8) << sizeof(float)*8 << setw (25) << FLT_MIN << setw (25) << FLT_MAX << endl;
    cout << "Real de precision doble" << setw (9) << sizeof(double)*8 << setw (25) << DBL_MIN << setw (25) << DBL_MAX << endl;
    cout << "\n";
    pause();

    return 0;
}