#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../../assets/utils.h"
#include "../objects/node.h"

template<class T>
class LinkedStack {
	private:
		Node<T> *top;

	public:
        LinkedStack();          // constructor
        LinkedStack(Node<T>*);  // constructor
        ~LinkedStack();         // destructor 

        // action functions
        bool is_empty();
        void push(Node<T>*);
        Node<T>* pop();
        void clear();
        void show();

};

template<class T>
LinkedStack<T>::LinkedStack() {
    top = NULL;
}

template<class T>
LinkedStack<T>::LinkedStack(Node<T> *t) {
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
void LinkedStack<T>::push(Node<T> *new_item) {
    if ( !is_empty() ) {
        new_item->set_next(top);
        top = new_item;
    } else {
        top = new_item;
    }
}

template<class T>
Node<T>* LinkedStack<T>::pop() {
    if ( !is_empty() ) {
        Node<T> *aux = top;
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
            Node<T> *item_to_delete = top;
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
        Node<T> *aux = top;
        while (aux) {
            cout << "-> " << aux;
            aux = aux->get_next();
        }
    }
}


#endif