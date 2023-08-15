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
    cout << "\nPress a key to continue..." << endl << endl; 
    cin.get(); 
}


bool question(string pregunta) {
    char option;
    bool isValidChar = false;
    do {
        cout << endl << pregunta << "  (y/n) : ";
        cin >> option;

        if (option == 'y' || option == 'Y' || option == 'n' || option == 'N')
                isValidChar = true;
        else
                cout << endl << "Invalid Option..." << endl;

    }  while (!isValidChar);
    return (option == 'y' || option == 'Y') ? true : false;
}

#endif // utils