#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"
#include "algoritms/data_types.h"
#include "algoritms/chronometer.h"
#include "EDAs/lists/array_list.h"
#include "EDAs/stacks/array_stack.h"

int main() {
    clean;
    print_data_types();

    //chronometer();

    /*
    ArrayList<int> list_of_integers;
    list_of_integers.perform_insertion(10);
    list_of_integers.perform_insertion(9);
    list_of_integers.perform_insertion(8);
    list_of_integers.perform_insertion(7);
    list_of_integers.print_list();
    */

    ArrayStack<int> stack_of_integers;
    stack_of_integers.show();
    stack_of_integers.push(1);
    stack_of_integers.push(2);
    stack_of_integers.push(3);
    stack_of_integers.show();
    stack_of_integers.pop();
    stack_of_integers.show();
    stack_of_integers.clear();
    stack_of_integers.show();
    pause();

    return 0;
}