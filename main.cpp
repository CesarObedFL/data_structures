#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"
#include "algoritms/data_types.h"
#include "algoritms/chronometer.h"
#include "EDAs/lists/array_list.h"

int main() {
    clean;
    print_data_types();

    //chronometer();

    ArrayList<int> list_of_integers;
    list_of_integers.perform_insertion(10);
    list_of_integers.perform_insertion(9);
    cout << "\nActual Position:" << list_of_integers.get_actual_position() << endl;
    list_of_integers.perform_insertion(8);
    list_of_integers.perform_insertion(7);
    list_of_integers.print_list();
    pause();

    return 0;
}