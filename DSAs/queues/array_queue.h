#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "../../assets/utils.h"

#define MAX_SIZE 25

template <class T>
class ArrayQueue {
	private:
		T queue[MAX_SIZE];
        int last;

	public:
        ArrayQueue(); /* constructor */
        ~ArrayQueue(); /* destructor */

        // get item and position functions
        T get_front();
        
        // action functions
        bool is_empty();
        bool is_full();
        void enqueue(T);
        T dequeue();
        void clear();
        void show();

};

template <class T>
ArrayQueue<T>::ArrayQueue() { 
    this->last = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <class T>
T ArrayQueue<T>::get_front() {
    if ( !is_empty() ) {
        return this->queue[0];
    } else {
        return NULL;
    }
}

template <class T>
bool ArrayQueue<T>::is_empty() {
    return this->last == 0;
}

template <class T>
bool ArrayQueue<T>::is_full() {
    return this->last == MAX_SIZE;
}

template <class T>
void ArrayQueue<T>::enqueue(T new_item) {
    if ( !is_full() ) {
        this->queue[this->last] = new_item;
        this->last++;
    }
}

template <class T>
T ArrayQueue<T>::dequeue() {
    if ( !is_empty() ) {
        T item = this->queue[0];
        for (int i = 0; i < last; i++) {
            this->queue[i] = this->queue[i+1];
        }
        this->queue[this->last] = 0;
        this->last--;
        return item;
    } else {
        return 0;
    }
}



template <class T>
void ArrayQueue<T>::clear() {
    if ( !is_empty() ) {
        for (int i = 0; i < MAX_SIZE; i++ ) {
            this->queue[i] = 0;
        }
        this->last = 0;
    }
}

template <class T>
void ArrayQueue<T>::show() {
    if( is_empty() ) {
        cout << "The queue is empty...";

    } else {
        for (int i = 0; i < this->last; i++){
            cout << i+1 << ".- " << this->queue[i] << endl;
        }
    }
}

#endif