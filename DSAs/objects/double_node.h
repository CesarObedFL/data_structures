#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template<class T>
class DoubleNode {
	private:
	    T value;
		DoubleNode *next;
        DoubleNode *previous;

	public:

        // constructors and destructors
		DoubleNode();
		DoubleNode(T, DoubleNode<T>*, DoubleNode<T>*);

        // getters and setters
		void set_value(T);
		T get_value();
		void set_next(DoubleNode<T>*);
		DoubleNode<T>* get_next();
        void set_previous(DoubleNode<T>*);
        DoubleNode<T>* get_previous();

		// istream operator overload (>>)
		friend std::istream& operator>>(std::istream& is, DoubleNode<T>* this_node) {
			is >> this_node->value;
			return is;
		}

		// ostream operator overload (<<)
		friend std::ostream& operator<<(std::ostream& os, const DoubleNode<T>* this_node) {
			if ( this_node ) {
				os << this_node->value << endl;
			} else {
				os << "NULL" << endl;
			}
			return os;
		}

};

template<class T>
DoubleNode<T>::DoubleNode() {
    this->next = NULL;
    this->previous = NULL;
}

template<class T>
DoubleNode<T>::DoubleNode(T value, DoubleNode<T> *next, DoubleNode<T> *previous) {
    this->value = value;
    this->next = next;
    this->previous = previous;
}

template<class T>
void DoubleNode<T>::set_value(T value) {
    this->value = value;
}

template<class T>
T DoubleNode<T>::get_value() {
    return this->value;
}

template<class T>
void DoubleNode<T>::set_next(DoubleNode<T>* next) {
    this->next = next;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::get_next() {
    return this->next;
}

template<class T>
void DoubleNode<T>::set_previous(DoubleNode<T>* previous) {
    this->previous = previous;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::get_previous() {
    return this->previous;
}

#endif