#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

#ifndef _Linux
	#define Limpiar system("clear");
#elif _WIN32
	#define Limpiar system("cls");
#elif _WIN64
	#define Limpiar system("cls");
#endif

void pause() { 
    cout << "\nPress a key to continue..."; 
    cin.get(); 
}


#endif // utils