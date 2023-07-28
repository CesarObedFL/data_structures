#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "../../assets/utils.h"

#define SIZE 25

template <class T>
class ArrayList {
	private:
		T array_list[SIZE];
		int first;
		int	last; 
		int actual_position;
	public:
		ArrayList(); /* constructor */

        // staus list
        bool is_empty(); 
		bool is_full();
		
        // get item and position functions
        T get_item(int);
		T get_first_item();
		T get_last_item();
		T get_next_item(int);
		T get_previous_item(int);
        int get_actual_position();

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
	first = 0;
	last = -1;
	actual_position = 0;
}

template <class T>
bool ArrayList<T>::is_empty(){
	if( first > last ){
		return true;
	} else {
		return false;
	}
}

template <class T>
bool ArrayList<T>::is_full(){
	if( last == SIZE-1 ){
		return true;
	} else {
		return false;
	}
}

template <class T>
T ArrayList<T>::get_item(int position){
	return array_list[position];
}

template <class T>
T ArrayList<T>::get_first_item(){
	if ( is_empty() ){
		return 0;
	} else {
		return array_list[first];
	}
}

template <class T>
T ArrayList<T>::get_last_item(){
	if ( is_empty() ){
		return 0;
	} else {
		return array_list[last+1];
	}
}

template <class T>
T ArrayList<T>::get_next_item(int position){
	if ( is_full() ){
		return 0;
	} else {
		return array_list[position+1];
	}
}

template <class T>
T ArrayList<T>::get_previous_item(int position){
	if ( is_empty() ){
		return 0;
	} else {
		return array_list[position-1];
	}
}

template <class T>
int ArrayList<T>::get_actual_position() {
    return actual_position;
}

template <class T>
void ArrayList<T>::perform_insertion(T new_item){
	char option;
	bool is_option_valid = false;
	int chosen_position;
	do
    {
		cout << "\n\n";
		cout << "Do you want to chose the position where insert the item? y/n" << endl;
        cin >> option;
		
		switch(option){
			case 'n':
				insert_item(new_item);
				is_option_valid = true;
			break;

			case 'y':
				cout << "\nInsert the number of the position: ";
				cin >> chosen_position;
				insert_item_by_position(chosen_position, new_item);
				is_option_valid = true;
			break;
			
			default:
				cout << "Invalid option...\n";
			break;
		}
    }while(is_option_valid != true);
	
}

template <class T>
void ArrayList<T>::insert_item(T new_item){
	if ( is_empty() || !is_full() ) {
		array_list[last] = new_item;	
		last++;
	} else {
		cout << "The list is full...";
	}
}

template <class T>
void ArrayList<T>::insert_item_by_position(int position, T new_item){
	if ( !is_full() ) {
		if(position >= first && position <= last){
			for (int k = last+1; k > position; k--) {
				array_list[k] = array_list[k-1];
            }
			array_list[position] = new_item;
			last++;
		} else {
		    cout << "\nInvalid position...\n";
		}
	} else {
		cout << "The List is full...";
	}
}

template <class T>
void ArrayList<T>::edit_item(int position){
	if ( is_empty() ){
		cout << "\nEmpty list...\n";
	} else {
		if (position >= first && position <= last){
			cout << "Editing item at position " << position << endl;
			cout << array_list[position]; // << operator overload
            cout << "Enter the new values:";
			cin >> array_list[position];
		} else {
			cout << "\nInvalid position...\n";
		}
	}
}

template <class T>
void ArrayList<T>::remove_item(int position){
	if ( is_empty() ) {
		cout << "\n\nEmpty List...";
	} else if (position > first-1 && position < last+1) {
			for (int k = position+1; k <= last; k++) {
				array_list[k-1] = array_list[k];
            }
			position--;
			last--;
	} else {
		cout << "\nInvalid position...";
	}
}


template <class T>
void ArrayList<T>::print_list(){
	if ( is_empty() ){
		cout << "\nEmpty list\n";

	} else {
		cout << "\t\t...Listing...\n\n";
		int i = 0;
		while (i < last+1){
			cout << (i+1) << ".- " << array_list[i] << "\n";
		    i++;
		}
		if (last == SIZE-1){
			cout << "\nThe list is full!!!";
		}
	}
}



#endif
