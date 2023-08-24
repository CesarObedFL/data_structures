/*     LISTA SIMPLEMENTE LIGADA     */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/node.h"

template<class T>
class LinkedList {
    private:
        Node<T> *start_node;

    public:
        LinkedList();           // construct
        LinkedList(Node<T>*);   // construct
        ~LinkedList();          // destruct

        // getters methods
        Node<T>* first_node();
		Node<T>* last_node();
		Node<T>* next_node(Node<T>*);
		Node<T>* previous_node(Node<T>*);
        Node<T>* recover(unsigned int);
        int locate(Node<T>*);

        // functions & methods
        bool is_empty();
        int size();
        void insert_front(Node<T>*);
        void insert_back(Node<T>*);
        void insert_position(Node<T>*, int);
		void delete_front();
        void delete_back();
        void delete_position(int);
        void clear();
        void show();

};

template<class T>
LinkedList<T>::LinkedList() {
    start_node = NULL;
}

template<class T>
LinkedList<T>::LinkedList(Node<T> *s) {
    start_node = s;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
Node<T>* LinkedList<T>::first_node() {
    return start_node;
}

template<class T>
Node<T>* LinkedList<T>::last_node() {
    Node<T> *auxiliary_node = first_node();
    while( auxiliary_node->get_next() ) {
        auxiliary_node = auxiliary_node->get_next();
    }
    return auxiliary_node;
}

template<class T>
Node<T>* LinkedList<T>::next_node(Node<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == last_node() ) {
        return NULL;

    } else {
        Node<T> *auxiliary_node = first_node();
        while (auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_next();
    }
}

template<class T>
Node<T>* LinkedList<T>::previous_node(Node<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == first_node() ) {
        return NULL;

    } else {
        Node<T> *auxiliary_node = first_node();
        while ( auxiliary_node->get_next() != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node;
    }
}

template<class T>
Node<T>* LinkedList<T>::recover(unsigned int position) {
    if ( is_empty() ) {
        return NULL;
    
    } else {
        Node<T> *auxiliary_node = first_node();
        unsigned int position_counter = 1;
        while (position_counter != position) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        return auxiliary_node;
    }
}

template<class T>
int LinkedList<T>::locate(Node<T> *node) {
    if ( is_empty() ) {
        return 0;
    
    } else {
        Node<T> *auxiliary_node = first_node();
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
        Node<T> *auxiliary_node = first_node();
        int size = 1;
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
            size++;
        }
        return size;
    }
}

template<class T>
void LinkedList<T>::insert_front(Node<T> *new_node) {
    if ( is_empty() ) {
        start_node = new_node;

    } else {
        new_node->set_next(first_node());
        start_node = new_node;
    }
}

template<class T>
void LinkedList<T>::insert_back(Node<T> *new_node) {
    if ( is_empty() ) {
        start_node = new_node;

    } else {
        Node<T> *auxiliary_node = first_node();
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
        }
        auxiliary_node->set_next(new_node);
    }
}

template<class T>
void LinkedList<T>::insert_position(Node<T> *new_node, int position) {
    if ( is_empty() ) {
        start_node = new_node;

    } else if ( position < 0 && position > size() ) {
        insert_back(new_node);

    } else {
        Node<T> *auxiliary_node = first_node();
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
        Node<T> *auxiliary_node = first_node();
        start_node = first_node()->get_next();
        delete(auxiliary_node);
    }
}

template<class T>
void LinkedList<T>::delete_back() {
    if ( !is_empty() ) {
        Node<T> *auxiliary_node = first_node();
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
            Node<T> *auxiliary_node = first_node();
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
        Node<T> *auxiliary_node = first_node();
        Node<T> *node_to_delete;
        while ( auxiliary_node ) {
            node_to_delete = auxiliary_node;
            auxiliary_node = auxiliary_node->get_next();
            delete(node_to_delete);
        }
        start_node = NULL;
    }
}

template<class T>
void LinkedList<T>::show() {
    if ( is_empty() ) {
        cout << "The list is empty...";

    } else {
        cout << endl;
        Node<T> *auxiliary_node = first_node();
        int index = 1;
        while( auxiliary_node ) {
            cout << index << ".- " << auxiliary_node << endl;
            auxiliary_node = auxiliary_node->get_next();
            index++;
        }
    }
}



#endif