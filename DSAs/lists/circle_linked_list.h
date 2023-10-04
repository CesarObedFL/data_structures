#ifndef CIRCLE_LINKED_LIST_H
#define CIRCLE_LINKED_LIST_H

#include "../../assets/utils.h"
#include "../objects/double_node.h"

template<class T>
class CircleLinkedList {
    private:
        DoubleNode<T> *start_node;
        DoubleNode<T> *end_node;

    public:
        CircleLinkedList();           // construct
        CircleLinkedList(DoubleNode<T>*);   // construct
        ~CircleLinkedList();          // destruct

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
CircleLinkedList<T>::CircleLinkedList() {
    this->start_node = NULL;
    this->end_node = NULL;
}

template<class T>
CircleLinkedList<T>::CircleLinkedList(DoubleNode<T> *node) {
    this->start_node = node;
    this->end_node = node;
}

template<class T>
CircleLinkedList<T>::~CircleLinkedList() {
    clear();
}

template<class T>
DoubleNode<T>* CircleLinkedList<T>::first_node() {
    return this->start_node;
}

template<class T>
DoubleNode<T>* CircleLinkedList<T>::last_node() {
    return this->end_node;
}

template<class T>
DoubleNode<T>* CircleLinkedList<T>::next_node(DoubleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == last_node() ) {
        return first_node();

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        while (auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_next();
    }
}

template<class T>
DoubleNode<T>* CircleLinkedList<T>::previous_node(DoubleNode<T> *actual_node) {
    if ( is_empty() ) {
        return NULL;

    } else if ( actual_node == first_node() ) {
        return last_node();

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        while ( auxiliary_node != actual_node) {
            auxiliary_node = auxiliary_node->get_next();
        }
        return auxiliary_node->get_previous();
    }
}

template<class T>
DoubleNode<T>* CircleLinkedList<T>::recover(unsigned int position) {
    if ( is_empty() ) {
        return NULL;
    
    } else {
        if ( position > 0 && position < size() ) {
            DoubleNode<T> *auxiliary_node = first_node();
            unsigned int position_counter = 1;
            while (position_counter != position) {
                auxiliary_node = auxiliary_node->get_next();
                position_counter++;
            }
            return auxiliary_node;
        } else {
            return NULL;
        }
    }
}

template<class T>
int CircleLinkedList<T>::locate(DoubleNode<T> *node) {
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
bool CircleLinkedList<T>::is_empty() {
    return first_node() == NULL;
}

template<class T>
int CircleLinkedList<T>::size() {
    if ( is_empty() ) {
        return 0;

    } else {
        DoubleNode<T> *auxiliary_node = first_node();
        int size = 1;
        while ( auxiliary_node != last_node() ) {
            auxiliary_node = auxiliary_node->get_next();
            size++;
        }
        return size;
    }
}

template<class T>
void CircleLinkedList<T>::insert_front(DoubleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;
        this->end_node = new_node;

    } else {
        new_node->set_next(first_node());
        this->start_node = new_node;
    }
}

template<class T>
void CircleLinkedList<T>::insert_back(DoubleNode<T> *new_node) {
    if ( is_empty() ) {
        this->start_node = new_node;
        this->end_node = new_node;

    } else {
        new_node->set_previous( last_node() );
        new_node->set_next( first_node() );
        this->end_node->set_next(new_node);
        this->end_node = new_node;
    }
}

template<class T>
void CircleLinkedList<T>::insert_position(DoubleNode<T> *new_node, int position) {
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
void CircleLinkedList<T>::delete_front() {
    if ( !is_empty() ) {
        DoubleNode<T> *auxiliary_node = first_node();
        if ( this->start_node == this->end_node ) {
            this->start_node = NULL;
            this->end_node = NULL;

        } else {
            this->start_node = first_node()->get_next();
            last_node()->set_next(this->start_node);
        }
        
        delete(auxiliary_node);
    }
}

template<class T>
void CircleLinkedList<T>::delete_back() {
    if ( !is_empty() ) {
        DoubleNode<T> *auxiliary_node = last_node();
        this->end_node->get_previous()->set_next(first_node());
        this->end_node = this->end_node->get_previous();
        delete(auxiliary_node);
    }
}

template<class T>
void CircleLinkedList<T>::delete_position(int position) {
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
void CircleLinkedList<T>::clear() {
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
void CircleLinkedList<T>::show() {
    if ( is_empty() ) {
        cout << "The list is empty...";

    } else {
        cout << endl;
        DoubleNode<T> *auxiliary_node = first_node();
        int index = 1;
        while( auxiliary_node != last_node() ) {
            cout << index << ".- " << auxiliary_node << endl;
            auxiliary_node = auxiliary_node->get_next();
            index++;
        }
    }
}



#endif