#ifndef NUMBER_TO_BINARY_H
#define NUMBER_TO_BINARY_H


#include "../assets/utils.h"


string transform_number_to_binary(unsigned int number) {
    unsigned long long counter = 1ULL << 63;
    string string_number;

    for (int i = 0; i < 64; ++i) {
        if (counter & number) 
            string_number += "1";
        else 
            string_number += "0";

        counter >>= 1;
    }

    return string_number;
}


#endif