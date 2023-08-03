#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <iostream>

#include "../assets/utils.h"

#ifndef _Linux

    bool getKeyState(char key) {
        return false;
    }

#elif _WIN32
	#include <windows.h> // to use GetAsyncKeyState() function
    bool getKeyState(char key) {
        return GetAsyncKeyState(key);
    }
#elif _WIN64
	#include <windows.h> // to use GetAsyncKeyState() function
    bool getKeyState(char key) {
        return GetAsyncKeyState(key);
    }
#endif




using namespace std;

#define milisegundos 60 //Ajuste de los milisegundos deacuerdo a velocidad de PC
#define horas 10

void chronometer(){

	int hh, mm, ss, ms;

	for( hh = 0; hh < horas; hh++ ) {
		if (getKeyState('5')) {
            break;
        }
		for( mm = 0; mm < 59; mm++ ) {
			if (getKeyState('5')) {
                break;
            }
			for( ss = 0; ss < 59; ss++ ) {
				if (getKeyState('5')) {
                    break;
                }
				for ( ms = 0; ms < milisegundos; ms++ ) {
                    if (getKeyState('5')) {
                        break;
                    }
                    clean;
                    cout << "Chronometering...\n\n";
                    cout << "\t" << hh << ":" << mm << ":" << ss << ":" << ms << "\n";
                    cout << "\n3.- Stop  " 
                        << "\n4.- Restart" 
                        << "\n5.- Out  ";
                    if (getKeyState('3')) {
                        pause();
                    } else if (getKeyState('4')) {
                        hh = 0; 
                        mm = 0; 
                        ss = 0; 
                        ms = 0;
                    } else if (getKeyState('5')) {
                        break;
                    }
				} // /. miliesconds loop
			} // /. seconds loop
		} // /. minutes loop
	} // /. hours loop

}

#endif