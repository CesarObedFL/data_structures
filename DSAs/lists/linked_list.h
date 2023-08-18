/*     LISTA SIMPLEMENTE LIGADA     */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/node.h"

template<class T>
class LinkedList {
    private:
        Node<T> *start;

    public:
        LinkedList();           // construct
        LinkedList(Node<T>*);   // construct
        ~LinkedList();          // destruct

        // functions & methods
        

};

template<class T>
LinkedList<T>::LinkedList() {
    start = NULL;
}

template<class T>
LinkedList<T>::LinkedList(Node<T> *s) {
    start = s;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}





#endif