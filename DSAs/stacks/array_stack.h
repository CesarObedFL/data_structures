#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "../../assets/utils.h"

#define MAX_SIZE 25

template <class T>
class ArrayStack {
	private:
		T stack[MAX_SIZE];
        int top;

	public:
        ArrayStack(); /* constructor */
        ~ArrayStack(); /* destructor */

        // get item and position functions
        T get_top();
        
        // action functions
        bool is_empty();
        bool is_full();
        void push(T);
        T pop();
        void clear();
        void show();

};

template <class T>
ArrayStack<T>::ArrayStack() { 
    this->top = 0;
}

template <class T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <class T>
T ArrayStack<T>::get_top() {
    if ( !is_empty() ) {
        return this->stack[this->top];
    } else {
        return NULL;
    }
}

template <class T>
bool ArrayStack<T>::is_empty() {
    return this->stack[this->top] == 0;
}

template <class T>
bool ArrayStack<T>::is_full() {
    return this->top == MAX_SIZE;
}

template <class T>
void ArrayStack<T>::push(T new_item) {
    if ( !is_full() ) {
        this->stack[this->top] = new_item;
        this->top++;
    }
}

template <class T>
T ArrayStack<T>::pop() {
    if ( !is_empty() ) {
        T item = this->stack[this->top];
        this->stack[this->top] = 0;
        this->top--;
        return item;
    } else {
        return 0;
    }
}



template <class T>
void ArrayStack<T>::clear() {
    if ( !is_empty() ) {
        for (int i = 0; i < MAX_SIZE; i++ ) {
            this->stack[i] = 0;
        }
        this->top = 0;
    }
}

template <class T>
void ArrayStack<T>::show() {
    if( is_empty() ) {
        cout << "The stack is empty...";

    } else {
        for (int i = 0; i < this->top; i++){
            cout << i+1 << ".- " << this->stack[i] << endl;
        }
    }
}

#endif