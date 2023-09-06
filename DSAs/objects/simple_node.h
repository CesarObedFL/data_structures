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
		SimpleNode(T, SimpleNode<T>*);

        // getters and setters
		void set_value(T);
		T get_value();
		void set_next(SimpleNode<T>*);
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
    this->next = NULL;
}

template<class T>
SimpleNode<T>::SimpleNode(T value, SimpleNode<T> *next) {
    this->value = value;
    this->next = next;
}

template<class T>
void SimpleNode<T>::set_value(T value) {
    this->value = value;
}

template<class T>
T SimpleNode<T>::get_value() {
    return this->value;
}

template<class T>
void SimpleNode<T>::set_next(SimpleNode<T>* next) {
    this->next = next;
}

template<class T>
SimpleNode<T>* SimpleNode<T>::get_next() {
    return this->next;
}

#endif