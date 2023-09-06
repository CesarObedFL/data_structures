#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/double_node.h"

template<class T>
class DoubleLinkedList {
    private:
        DoubleNode<T> *start_node;
        DoubleNode<T> *end_node;

    public:
        DoubleLinkedList();           // construct
        DoubleLinkedList(DoubleNode<T>*);   // construct
        ~DoubleLinkedList();          // destruct

        // getters methods
        DoubleNode<T>* first_node();
		DoubleNode<T>* last_node();
		DoubleNode<T>* next_node(DoubleNode<T>*);
		DoubleNode<T>* previous_node(DoubleNode<T>*);
        DoubleNode<T>* recover(unsigned int);
        int locate(DoubleNode<T>*);

        // functions & methods
        bool is_empty();
        int size();
        void insert_front(DoubleNode<T>*);
        void insert_back(DoubleNode<T>*);
        void insert_position(DoubleNode<T>*, int);
		void delete_front();
        void delete_back();
        void delete_position(int);
        void clear();
        void show();

};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->start_node = NULL;
    this->end_node = NULL;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleNode<T> *node) {
    this->start_node = node;
    this->end_node = node;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    clear();
}

template<class T>
DoubleNode<T>* DoubleLinkedList<T>::first_node() {
    return this->start_node;
}

template<class T>
DoubleNode<T>* DoubleLinkedList<T>::last_node() {
    return this->end_node;
}

template<class T>
DoubleNode<T>* DoubleLinkedList<T>::next_node(DoubleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == last_node() ) {
        return NULL;

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        while (auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_next();
    }
}

template<class T>
DoubleNode<T>* DoubleLinkedList<T>::previous_node(DoubleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == first_node() ) {
        return NULL;

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        while ( auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_previous();
    }
}

template<class T>
DoubleNode<T>* DoubleLinkedList<T>::recover(unsigned int position) {
    if ( is_empty() ) {
        return NULL;
    
    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        unsigned int position_counter = 1;
        while (position_counter != position) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        return auxiliary_node;
    }
}

template<class T>
int DoubleLinkedList<T>::locate(DoubleNode<T> *node) {
    if ( is_empty() ) {
        return 0;
    
    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        int position_counter = 1;
        while (auxiliary_node != node) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        return position_counter;
    }
}

template<class T>
bool DoubleLinkedList<T>::is_empty() {
    return first_node() == NULL;
}

template<class T>
int DoubleLinkedList<T>::size() {
    if ( is_empty() ) {
        return 0;

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        int size = 1;
        while ( auxiliary_node->get_next() ) {
            auxiliary_node = auxiliary_node->get_next();
            size++;
        }
        return size;
    }
}

template<class T>
void DoubleLinkedList<T>::insert_front(DoubleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;
        this->end_node = new_node;

    } else {
        new_node->set_next(first_node());
        this->start_node = new_node;
    }
}

template<class T>
void DoubleLinkedList<T>::insert_back(DoubleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;
        this->end_node = new_node;

    } else {
        new_node->set_previous(this->end_node);
        this->end_node->set_next(new_node);
        this->end_node = new_node;
    }
}

template<class T>
void DoubleLinkedList<T>::insert_position(DoubleNode<T> *new_node, int position) {
    if ( is_empty() ) {
        this->start_node = new_node;
        this->end_node = new_node;

    } else if ( position < 0 && position > size() ) {
        insert_back(new_node);

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        int position_counter = 1;
        while ( position_counter < position ) {
            auxiliary_node = auxiliary_node->get_next();
            position_counter++;
        }
        new_node->set_previous( auxiliary_node->get_previous() );
        new_node->set_next(auxiliary_node);
        auxiliary_node->get_previous()->set_next(new_node);
        
        
    }
}

template<class T>
void DoubleLinkedList<T>::delete_front() {
    if ( !is_empty() ) {
        DoubleNode<T> *auxiliary_node = first_node();
        if ( this->start_node == this->end_node ) {
            this->start_node = NULL;
            this->end_node = NULL;

        } else {
            this->start_node = first_node()->get_next();
        }
        
        delete(auxiliary_node);
    }
}

template<class T>
void DoubleLinkedList<T>::delete_back() {
    if ( !is_empty() ) {
        DoubleNode<T> *auxiliary_node = last_node();
        this->end_node->get_previous()->set_next(NULL);
        this->end_node = this->end_node->get_previous();
        delete(auxiliary_node);
    }
}

template<class T>
void DoubleLinkedList<T>::delete_position(int position) {
    if ( !is_empty() && (position > 0 && position <= size()) ) {

        if (position == 1) {
            delete_front();

        } else if (position == size()) {
            delete_back();

        } else {
            DoubleNode<T> *auxiliary_node = first_node();
            int position_counter = 1;
            while (position_counter != position) {
                auxiliary_node = auxiliary_node->get_next();
                position_counter++;
            }
            auxiliary_node->get_previous()->set_next( auxiliary_node->get_next() );
            delete(auxiliary_node);
        }
    }
}

template<class T>
void DoubleLinkedList<T>::clear() {
    if ( !is_empty() ) {
        DoubleNode<T> *auxiliary_node = first_node();
        DoubleNode<T> *node_to_delete;
        while ( auxiliary_node ) {
            node_to_delete = auxiliary_node;
            auxiliary_node = auxiliary_node->get_next();
            delete(node_to_delete);
        }
        this->start_node = NULL;
        this->end_node = NULL;
    }
}

template<class T>
void DoubleLinkedList<T>::show() {
    if ( is_empty() ) {
        cout << "The list is empty...";

    } else {
        cout << endl;
        DoubleNode<T> *auxiliary_node = first_node();
        int index = 1;
        while( auxiliary_node ) {
            cout << index << ".- " << auxiliary_node << endl;
            auxiliary_node = auxiliary_node->get_next();
            index++;
        }
    }
}



#endif