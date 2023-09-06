/*     LISTA SIMPLEMENTE LIGADA     */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/simple_node.h"

template<class T>
class LinkedList {
    private:
        SimpleNode<T> *start_node;

    public:
        LinkedList();           // construct
        LinkedList(SimpleNode<T>*);   // construct
        ~LinkedList();          // destruct

        // getters methods
        SimpleNode<T>* first_node();
		SimpleNode<T>* last_node();
		SimpleNode<T>* next_node(SimpleNode<T>*);
		SimpleNode<T>* previous_node(SimpleNode<T>*);
        SimpleNode<T>* recover(unsigned int);
        int locate(SimpleNode<T>*);

        // functions & methods
        bool is_empty();
        int size();
        void insert_front(SimpleNode<T>*);
        void insert_back(SimpleNode<T>*);
        void insert_position(SimpleNode<T>*, int);
		void delete_front();
        void delete_back();
        void delete_position(int);
        void clear();
        void show();

};

template<class T>
LinkedList<T>::LinkedList() {
    this->start_node = NULL;
}

template<class T>
LinkedList<T>::LinkedList(SimpleNode<T> *start) {
    this->start_node = start;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
SimpleNode<T>* LinkedList<T>::first_node() {
    return this->start_node;
}

template<class T>
SimpleNode<T>* LinkedList<T>::last_node() {
    SimpleNode<T> *auxiliary_node = first_node();
    while( auxiliary_node->get_next() ) {
        auxiliary_node = auxiliary_node->get_next();
    }
    return auxiliary_node;
}

template<class T>
SimpleNode<T>* LinkedList<T>::next_node(SimpleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == last_node() ) {
        return NULL;

    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        while (auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_next();
    }
}

template<class T>
SimpleNode<T>* LinkedList<T>::previous_node(SimpleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == first_node() ) {
        return NULL;

    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        while ( auxiliary_node->get_next() != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node;
    }
}

template<class T>
SimpleNode<T>* LinkedList<T>::recover(unsigned int position) {
    if ( is_empty() ) {
        return NULL;
    
    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        unsigned int position_counter = 1;
        while (position_counter != position) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        return auxiliary_node;
    }
}

template<class T>
int LinkedList<T>::locate(SimpleNode<T> *node) {
    if ( is_empty() ) {
        return 0;
    
    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        int position_counter = 1;
        while (auxiliary_node != node) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        return position_counter;
    }
}

template<class T>
bool LinkedList<T>::is_empty() {
    return first_node() == NULL;
}

template<class T>
int LinkedList<T>::size() {
    if ( is_empty() ) {
        return 0;

    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        int size = 1;
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
            size++;
        }
        return size;
    }
}

template<class T>
void LinkedList<T>::insert_front(SimpleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;

    } else {
        new_node->set_next(first_node());
        this->start_node = new_node;
    }
}

template<class T>
void LinkedList<T>::insert_back(SimpleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;

    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
        }
        auxiliary_node->set_next(new_node);
    }
}

template<class T>
void LinkedList<T>::insert_position(SimpleNode<T> *new_node, int position) {
    if ( is_empty() ) {
        this->start_node = new_node;

    } else if ( position < 0 && position > size() ) {
        insert_back(new_node);

    } else {
        SimpleNode<T> *auxiliary_node = first_node();
        int position_counter = 1;
        while ( position_counter < position ) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        previous_node(auxiliary_node)->set_next(new_node);
        new_node->set_next(auxiliary_node);
    }
}

template<class T>
void LinkedList<T>::delete_front() {
    if ( !is_empty() ) {
        SimpleNode<T> *auxiliary_node = first_node();
        this->start_node = first_node()->get_next();
        delete(auxiliary_node);
    }
}

template<class T>
void LinkedList<T>::delete_back() {
    if ( !is_empty() ) {
        SimpleNode<T> *auxiliary_node = first_node();
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
        }
        previous_node(auxiliary_node)->set_next(NULL);
        delete(auxiliary_node);
    }
}

template<class T>
void LinkedList<T>::delete_position(int position) {
    if ( !is_empty() && (position > 0 && position <= size()) ) {

        if (position == 1) {
            delete_front();

        } else if (position == size()) {
            delete_back();

        } else {
            SimpleNode<T> *auxiliary_node = first_node();
            int position_counter = 1;
            while (position_counter != position) {
                auxiliary_node = auxiliary_node->get_next();
                position_counter++;
            }
            previous_node(auxiliary_node)->set_next(next_node(auxiliary_node));
            delete(auxiliary_node);
        }
    }
}

template<class T>
void LinkedList<T>::clear() {
    if ( !is_empty() ) {
        SimpleNode<T> *auxiliary_node = first_node();
        SimpleNode<T> *node_to_delete;
        while ( auxiliary_node ) {
            node_to_delete = auxiliary_node;
            auxiliary_node = auxiliary_node->get_next();
            delete(node_to_delete);
        }
        this->start_node = NULL;
    }
}

template<class T>
void LinkedList<T>::show() {
    if ( is_empty() ) {
        cout << "The list is empty...";

    } else {
        cout << endl;
        SimpleNode<T> *auxiliary_node = first_node();
        int index = 1;
        while( auxiliary_node ) {
            cout << index << ".- " << auxiliary_node << endl;
            auxiliary_node = auxiliary_node->get_next();
            index++;
        }
    }
}



#endif