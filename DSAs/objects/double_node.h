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
			os << this_node->value << endl;
			return os;
		}

};

template<class T>
DoubleNode<T>::DoubleNode() {
    next = NULL;
    previous = NULL;
}

template<class T>
DoubleNode<T>::DoubleNode(T v, DoubleNode<T> *n, DoubleNode<T> *p) {
    value = v;
    next = n;
    previous = p;
}

template<class T>
void DoubleNode<T>::set_value(T v) {
    value = v;
}

template<class T>
T DoubleNode<T>::get_value() {
    return value;
}

template<class T>
void DoubleNode<T>::set_next(DoubleNode<T>* n) {
    next = n;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::get_next() {
    return next;
}

template<class T>
void DoubleNode<T>::set_previous(DoubleNode<T>* p) {
    previous = p;
}

template<class T>
DoubleNode<T>* DoubleNode<T>::get_previous() {
    return previous;
}

#endif