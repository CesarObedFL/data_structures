#ifndef NUMBER_TO_BINARY_H
#define NUMBER_TO_BINARY_H


#include "../assets/utils.h"


string transform_number_to_binary(unsigned int number) {
    unsigned int counter = 128;
    string string_number;

    for (counter; counter > 0; counter >>=1) {
        if (counter & number) 
            string_number += "1";
        else 
            string_number += "0";
    }

    return string_number;
}


#endif