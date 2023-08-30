#ifndef SIMPLE_NODE_H
#define SIMPLE_NODE_H

template<class T>
class SimpleNode {
	private:
	    T value;
		SimpleNode *next;

	public:

        // constructors and destructors
		SimpleNode();
		SimpleNode(T v, SimpleNode<T> *n);

        // getters and setters
		void set_value(T v);
		T get_value();
		void set_next(SimpleNode<T>* n);
		SimpleNode<T>* get_next();

		// istream operator overload (>>)
		friend std::istream& operator>>(std::istream& is, SimpleNode<T>* node) {
			is >> node->value;
			return is;
		}

		// ostream operator overload (<<)
		friend std::ostream& operator<<(std::ostream& os, const SimpleNode<T>* node) {
			if ( node ) {
				os << node->value << endl;
			} else {
				os << "NULL" << endl;
			}
			return os;
		}

};

template<class T>
SimpleNode<T>::SimpleNode() {
    next = NULL;
}

template<class T>
SimpleNode<T>::SimpleNode(T v, SimpleNode<T> *n) {
    value = v;
    next = n;
}

template<class T>
void SimpleNode<T>::set_value(T v) {
    value = v;
}

template<class T>
T SimpleNode<T>::get_value() {
    return value;
}

template<class T>
void SimpleNode<T>::set_next(SimpleNode<T>* n) {
    next = n;
}

template<class T>
SimpleNode<T>* SimpleNode<T>::get_next() {
    return next;
}

#endif