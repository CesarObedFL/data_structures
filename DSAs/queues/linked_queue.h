#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "../../assets/utils.h"
#include "../objects/simple_node.h"

template <class T>
class LinkedQueue {
	private:
        SimpleNode<T> *first;

	public:
        LinkedQueue();          // constructor
        LinkedQueue(SimpleNode<T>*);  // constructor
        ~LinkedQueue();         // destructor
        
        // action functions
        bool is_empty();
        void enqueue(SimpleNode<T>*);
        SimpleNode<T>* dequeue();
        void clear();
        void show();

};

template <class T>
LinkedQueue<T>::LinkedQueue() { 
    first = 0;
}

template<class T>
LinkedQueue<T>::LinkedQueue(SimpleNode<T> *f) {
    first = f;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <class T>
bool LinkedQueue<T>::is_empty() {
    return first == NULL;
}

template <class T>
void LinkedQueue<T>::enqueue(SimpleNode<T> *new_item) {
    if ( is_empty() ) {
        first = new_item;
    } else {
        SimpleNode<T> *aux = first;
        while (aux->get_next()) {
            aux = aux->get_next();
        }
        aux->set_next(new_item);
    }
}

template <class T>
SimpleNode<T>* LinkedQueue<T>::dequeue() {
    if ( !is_empty() ) {
        Node<T>* item = first;
        first = first->get_next();
        return item;
    } else {
        return NULL;
    }
}

template <class T>
void LinkedQueue<T>::clear() {
    if ( !is_empty() ) {
        while( first ) {
            Node<T> *aux = first;
            first = first->get_next();
            delete (aux);
        }
    }
}

template <class T>
void LinkedQueue<T>::show() {
    if( is_empty() ) {
        cout << "The queue is empty...";

    } else {
        Node<T> *aux = first;
        int i = 1;
        while ( aux ) {
            cout << i << ".- " << aux << endl;
            aux = aux->get_next();
            i++;
        }
    }
}

#endif