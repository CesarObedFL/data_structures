#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
	private:
	    T value;
		Node *next;

	public:

        // constructors and destructors
		Node();
		Node(T v, Node<T> *n);

        // getters and setters
		void set_value(T v);
		T get_value();
		void set_next(Node<T>* n);
		Node<T>* get_next();

};

template<class T>
Node<T>::Node() {
    value = NULL;
    next = NULL;
}

template<class T>
Node<T>::Node(T v, Node<T> *n) {
    value = v;
    next = n;
}

template<class T>
void Node<T>::set_value(T v) {
    value = v;
}

template<class T>
T Node<T>::get_value() {
    return value;
}

template<class T>
void Node<T>::set_next(Node<T>* n) {
    next = n;
}

template<class T>
Node<T>* Node<T>::get_next() {
    return next;
}

#endif