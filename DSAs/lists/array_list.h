#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "../../assets/utils.h"


template <class T>
class ArrayList {
	private:
		T* array_list;
		int max_size;
		int first_position;
		int	last_position; 

	public:
		ArrayList();  // constructor
		ArrayList(int);
		~ArrayList(); // destructor

        // status list
        bool is_empty(); 
		bool is_full();
		int get_size();
		int get_max_size();
		
        // get item and position functions
        T get_item(int);
		T get_first_item();
		T get_last_item();
		T get_next_item(int);
		T get_previous_item(int);

        // actions functions
		void insert_item(T);
		void insert_item_by_position(int, T);
		void perform_insertion(T);
		void edit_item(int);
        void remove_item(int);
		
		void print_list();
		
};

template <class T>
ArrayList<T>::ArrayList(){
	this->max_size = 25;
	this->array_list = new T[this->max_size];
	this->first_position = 0;
	this->last_position = -1;
}

template <class T>
ArrayList<T>::ArrayList(int max_size){
	this->max_size = max_size;
	this->array_list = new T[this->max_size];
	this->first_position = 0;
	this->last_position = -1;
}

template <class T>
ArrayList<T>::~ArrayList(){
	delete[] this->array_list;
}

template <class T>
bool ArrayList<T>::is_empty(){
	if( this->last_position == -1 ){
		return true;
	} else {
		return false;
	}
}

template <class T>
bool ArrayList<T>::is_full(){
	if( this->last_position == get_max_size()-1 ){
		return true;
	} else {
		return false;
	}
}

template <class T>
int ArrayList<T>::get_size(){
	if( is_empty() ) {
		return 0;
	} else {
		return this->last_position + 1;
	}
}

template <class T>
int ArrayList<T>::get_max_size(){
	return this->max_size;
}

template <class T>
T ArrayList<T>::get_item(int position){
	if ( position >= this->first_position && position <= get_size() ) {
		return this->array_list[position-1];
	} else {
		return get_last_item();
	}
}

template <class T>
T ArrayList<T>::get_first_item(){
	if ( is_empty() ){
		return 0;
	} else {
		return this->array_list[this->first_position];
	}
}

template <class T>
T ArrayList<T>::get_last_item(){
	if ( is_empty() ){
		return 0;
	} else {
		return this->array_list[get_size()-1];
	}
}

template <class T>
T ArrayList<T>::get_next_item(int position){
	if ( position >= this->first_position && position < get_size() ) {
		return this->array_list[position];
	} else {
		cout << "invalid position";
		return 0;
	}
}

template <class T>
T ArrayList<T>::get_previous_item(int position){
	if ( position > this->first_position && position <= get_size() ) {
		return this->array_list[position-2];
	} else {
		cout << "invalid position";
		return 0;
	}
}

template <class T>
void ArrayList<T>::perform_insertion(T new_item){
	char option;
	bool is_option_valid = false;
	int chosen_position;
	do
    {
		cout << endl << "Do you want to chose the position where insert the item? y/n" << endl;
        cin >> option;
		
		switch(option){
			case 'n':
				insert_item(new_item);
				is_option_valid = true;
			break;

			case 'y':
				cout << endl << "Insert the number of the position: ";
				cin >> chosen_position;
				insert_item_by_position(chosen_position, new_item);
				is_option_valid = true;
			break;
			
			default:
				cout << endl << "Invalid option..." << endl;
			break;
		}
    } while(is_option_valid != true);
	
}

template <class T>
void ArrayList<T>::insert_item(T new_item){
	if ( is_empty() || !is_full() ) {
		this->array_list[++this->last_position] = new_item;
	} else {
		cout << endl << "The list is full..." << endl;
	}
}

template <class T>
void ArrayList<T>::insert_item_by_position(int position, T new_item){
	if ( !is_full() ) {
		if(position > this->first_position && position <= get_size()){
			position--;
			for (int k = get_size(); k > position; k--) {
				this->array_list[k] = this->array_list[k-1];
            }
			this->array_list[position] = new_item;
			this->last_position++;
		} else {
		    cout << endl << "Invalid position..." << endl;
		}
	} else {
		cout << endl << "The List is full..." << endl;
	}
}

template <class T>
void ArrayList<T>::edit_item(int position){
	if ( is_empty() ){
		cout << endl << "Empty list..." << endl;
	} else {
		if (position >= this->first_position && position <= get_size()){
			cout << "Editing item at position " << position 
				 << "  value: " << this->array_list[position] << endl; // << operator overload
            cout << "Enter the new values:";
			cin >> this->array_list[position]; // >> operator overload
		} else {
			cout << endl << "Invalid position..." << endl;
		}
	}
}

template <class T>
void ArrayList<T>::remove_item(int position){
	if ( is_empty() ) {
		cout << endl << "Empty List..." << endl;
	} else if (position > this->first_position-1 && position < get_size()+1) {
		cout << endl << "Removig item at position: " << position << endl;
		for (int k = position; k <= get_size(); k++) {
			this->array_list[k-1] = this->array_list[k];
		}
		position--;
		this->last_position--;
	} else {
		cout << endl << "Invalid position...";
	}
}


template <class T>
void ArrayList<T>::print_list(){
	if ( is_empty() ){
		cout << endl << "Empty list" << endl;

	} else {
		cout << endl << endl << "\t...Listing..." << endl << endl;
		int i = 0;
		while (i < get_size()){
			cout << (i+1) << ".- " << this->array_list[i] << endl;
		    i++;
		}
		if (get_size() == get_max_size()){
			cout << endl << "The list is full!" << endl;
		}
	}
}



#endif
