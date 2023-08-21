/*     LISTA SIMPLEMENTE LIGADA     */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/node.h"

template<class T>
class LinkedList {
    private:
        Node<T> *first;

    public:
        LinkedList();           // construct
        LinkedList(Node<T>*);   // construct
        ~LinkedList();          // destruct

        // getters methods
        Node<T>* first_item();
		Node<T>* last_item();
		Node<T>* next_item(Node<T>*);
		Node<T>* previous_item(Node<T>*);
        Node<T>* recover(unsigned int);
        int locate(Node<T>*);

        // functions & methods
        bool is_empty();
        int size();
        void insert_front();
        void insert_back();
        void insert_position();
		void delete_front();
        void delete_back();
        void delete_position();
		void edit();
		void show();
        void clear();

};

template<class T>
LinkedList<T>::LinkedList() {
    first = NULL;
}

template<class T>
LinkedList<T>::LinkedList(Node<T> *s) {
    first = s;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
Node<T>* LinkedList<T>::first_item() {
    return first;
}

template<class T>
Node<T>* LinkedList<T>::last_item() {
    Node<T> *aux = first;
    while( aux->get_next() ) {
        aux = aux->get_next();
    }
    return aux;
}

template<class T>
Node<T>* LinkedList<T>::next_item(Node<T> *actual_item) {
    if ( is_empty() ) {
        return NULL;

    } else {
        Node<T> *aux = first;
        while (aux != actual_item) {
            aux = aux->get_next();
        }
        return aux->get_next();
    }
}

template<class T>
Node<T>* LinkedList<T>::previous_item(Node<T> *actual_item) {
    if ( is_empty() ) {
        return NULL;

    } else {
        Node<T> *aux = first;
        while ( aux->get_next() != actual_item) {
            aux = aux->get_next();
        }
        return aux;
    }
}

template<class T>
Node<T>* LinkedList<T>::recover(unsigned int position) {
    if ( is_empty() ) {
        return NULL;
    
    } else {
        Node<T> *aux = first;
        unsigned int counter = 1;
        while (counter != position) {
            aux = aux->get_next();
            counter++;
        }
        return aux;
    }
}

template<class T>
int LinkedList<T>::locate(Node<T> *item) {
    if ( is_empty() ) {
        return 0;
    
    } else {
        Node<T> *aux = first;
        int position = 1;
        while (aux != item) {
            aux = aux->get_next();
            position++;
        }
        return position;
    }
}

template<class T>
bool LinkedList<T>::is_empty() {
    return start == NULL;
}

template<class T>
int LinkedList<T>::size() {
    if ( is_empty() ) {
        return 0;
    } else {
        Node<T> *aux = first;
        int size = 0;
        while ( aux->get_next() ) {
            aux = aux->get_next();
            size++;
        }
        delete(aux);
        return size;
    }
}

template<class T>
void LinkedList<T>::insert_front() {

}

template<class T>
void LinkedList<T>::insert_back() {

}

template<class T>
void LinkedList<T>::insert_position() {

}

template<class T>
void LinkedList<T>::delete_front() {

}

template<class T>
void LinkedList<T>::delete_back() {

}

template<class T>
void LinkedList<T>::delete_position() {

}

template<class T>
void LinkedList<T>::edit() {

}

template<class T>
void LinkedList<T>::show() {

}

template<class T>
void LinkedList<T>::clear() {

}




#endif