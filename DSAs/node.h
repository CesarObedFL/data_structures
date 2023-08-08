#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
	private:
	    T value;
		Node *next;
		Node *previous;

	public:

        // constructors and destructors
		Node();
		Node(T v, Node<T> *n);

        // getters and setters
		void set_value(T v);
		T get_value();
		void set_next(Node<T>* n);
		Node<T>* get_next();

		// Sobrecarga del operador de entrada (>>)
		friend std::istream& operator>>(std::istream& is, Node& node) {
			is >> node.value;
			return is;
		}

		// Sobrecarga del operador de salida (<<)
		friend std::ostream& operator<<(std::ostream& os, const Node& node) {
			os << node.value << endl;
			return os;
		}

};

template<class T>
Node<T>::Node() {
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