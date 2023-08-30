#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../../assets/utils.h"
#include "../objects/simple_node.h"

template<class T>
class LinkedStack {
	private:
		SimpleNode<T> *top;

	public:
        LinkedStack();          // constructor
        LinkedStack(SimpleNode<T>*);  // constructor
        ~LinkedStack();         // destructor 

        // action functions
        bool is_empty();
        void push(SimpleNode<T>*);
        SimpleNode<T>* pop();
        void clear();
        void show();

};

template<class T>
LinkedStack<T>::LinkedStack() {
    top = NULL;
}

template<class T>
LinkedStack<T>::LinkedStack(SimpleNode<T> *t) {
    top = t;
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template<class T>
bool LinkedStack<T>::is_empty() {
    return top == NULL;
}

template<class T>
void LinkedStack<T>::push(SimpleNode<T> *new_item) {
    if ( !is_empty() ) {
        new_item->set_next(top);
        top = new_item;
    } else {
        top = new_item;
    }
}

template<class T>
SimpleNode<T>* LinkedStack<T>::pop() {
    if ( !is_empty() ) {
        SimpleNode<T> *aux = top;
        top = top->get_next();
        return aux;
    } else {
        return NULL;
    }
}

template<class T>
void LinkedStack<T>::clear() {
    if ( !is_empty() ) {
        while (!is_empty()) {
            SimpleNode<T> *item_to_delete = top;
            top = top->get_next();
            delete (item_to_delete);
        }
    }
}

template<class T>
void LinkedStack<T>::show() {
    if( is_empty() ) {
        cout << "The stack is empty...";
    } else {
        SimpleNode<T> *aux = top;
        while (aux) {
            cout << "-> " << aux;
            aux = aux->get_next();
        }
    }
}


#endif