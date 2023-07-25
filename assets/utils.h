#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

#ifndef _Linux
	#define clean system("clear");
#elif _WIN32
	#define clean system("cls");
#elif _WIN64
	#define clean system("cls");
#endif

void pause() { 
    cout << "\nPress a key to continue..."; 
    cin.get(); 
}


#endif // utils