#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"


#include "algorithms/chronometer.h"
#include "algorithms/data_types.h"
#include "algorithms/date_validator.h"
#include "algorithms/number_to_binary.h"

#include "DSAs/lists/array_list.h"
#include "DSAs/lists/double_linked_list.h"
#include "DSAs/lists/linked_list.h"

#include "DSAs/queues/array_queue.h"
#include "DSAs/queues/linked_queue.h"

#include "DSAs/stacks/array_stack.h"
#include "DSAs/stacks/linked_stack.h"

#include "DSAs/objects/double_node.h"
#include "DSAs/objects/simple_node.h"


int main() {
    clean;
    
    //print_data_types();

    //chronometer();

    /*
    ArrayList<int> list_of_integers;
    list_of_integers.perform_insertion(10);
    list_of_integers.perform_insertion(9);
    list_of_integers.perform_insertion(8);
    list_of_integers.perform_insertion(7);
    list_of_integers.print_list();
    */

    /*
    LinkedList<int> list_of_integers;
    list_of_integers.show();
    list_of_integers.insert_front(new SimpleNode<int>(10, NULL));
    list_of_integers.insert_back(new SimpleNode<int>(9, NULL));
    list_of_integers.insert_front(new SimpleNode<int>(8, NULL));
    list_of_integers.insert_back(new SimpleNode<int>(7, NULL));
    list_of_integers.show();
    list_of_integers.insert_position(new SimpleNode<int>(6, NULL), 3);
    list_of_integers.show();
    cout << "size: " << list_of_integers.size() << endl;
    cout << "first node: " << list_of_integers.first_node() << endl;
    cout << "second node: " << list_of_integers.next_node( list_of_integers.first_node() ) << endl;
    cout << "antepenultimate node: " << list_of_integers.previous_node( list_of_integers.last_node() ) << endl;
    cout << "last node: " << list_of_integers.last_node() << endl;
    cout << "recover: " << list_of_integers.recover(3) << endl;
    cout << "locate: " << list_of_integers.locate(list_of_integers.previous_node( list_of_integers.last_node() )) << endl;
    list_of_integers.delete_position(3);
    list_of_integers.show();
    list_of_integers.delete_front();
    list_of_integers.show();
    list_of_integers.delete_back();
    list_of_integers.show();
    list_of_integers.clear();
    list_of_integers.show();
    */

    /*
    DoubleLinkedList<int> list_of_integers;
    list_of_integers.show();
    list_of_integers.insert_front(new DoubleNode<int>(9, NULL, NULL));
    list_of_integers.insert_back(new DoubleNode<int>(7, NULL, NULL));
    list_of_integers.insert_front(new DoubleNode<int>(10, NULL, NULL));
    list_of_integers.insert_back(new DoubleNode<int>(6, NULL, NULL));
    list_of_integers.show();
    list_of_integers.insert_position(new DoubleNode<int>(8, NULL, NULL), 3);
    list_of_integers.insert_back(new DoubleNode<int>(5, NULL, NULL));
    list_of_integers.insert_back(new DoubleNode<int>(4, NULL, NULL));
    list_of_integers.show();
    cout << "size: " << list_of_integers.size() << endl;
    cout << "first node: " << list_of_integers.first_node() << endl;
    cout << "second node: " << list_of_integers.next_node( list_of_integers.first_node() ) << endl;
    cout << "antepenultimate node: " << list_of_integers.previous_node( list_of_integers.last_node() ) << endl;
    cout << "last node: " << list_of_integers.last_node() << endl;
    cout << "recover: " << list_of_integers.recover(3) << endl;
    cout << "locate: " << list_of_integers.locate(list_of_integers.previous_node( list_of_integers.last_node() )) << endl;
    list_of_integers.delete_position(3);
    list_of_integers.show();
    list_of_integers.delete_front();
    list_of_integers.show();
    list_of_integers.delete_back();
    list_of_integers.show();
    list_of_integers.clear();
    list_of_integers.show();
    */

    /*
    ArrayQueue<int> queue_of_integers;
    queue_of_integers.show();
    queue_of_integers.enqueue(1);
    queue_of_integers.enqueue(2);
    queue_of_integers.enqueue(3);
    queue_of_integers.show();
    queue_of_integers.dequeue();
    queue_of_integers.show();
    queue_of_integers.clear();
    queue_of_integers.show();
    */

    /*
    LinkedQueue<int> linked_queue_of_integers;
    linked_queue_of_integers.show();
    linked_queue_of_integers.enqueue(new SimpleNode<int>(1,NULL));
    linked_queue_of_integers.enqueue(new SimpleNode<int>(2,NULL));
    linked_queue_of_integers.enqueue(new SimpleNode<int>(3,NULL));
    linked_queue_of_integers.enqueue(new SimpleNode<int>(4,NULL));
    linked_queue_of_integers.show();
    linked_queue_of_integers.dequeue();
    linked_queue_of_integers.show();
    linked_queue_of_integers.dequeue();
    linked_queue_of_integers.show();
    linked_queue_of_integers.clear();
    linked_queue_of_integers.show();
    */

    /*
    ArrayStack<int> stack_of_integers;
    stack_of_integers.show();
    stack_of_integers.push(1);
    stack_of_integers.push(2);
    stack_of_integers.push(3);
    stack_of_integers.show();
    stack_of_integers.pop();
    stack_of_integers.show();
    stack_of_integers.clear();
    stack_of_integers.show();
    */

    /*
    LinkedStack<int> linked_stack_of_integers;
    linked_stack_of_integers.show();
    linked_stack_of_integers.push(new SimpleNode<int>(1,NULL));
    linked_stack_of_integers.push(new SimpleNode<int>(2,NULL));
    linked_stack_of_integers.push(new SimpleNode<int>(3,NULL));
    linked_stack_of_integers.push(new SimpleNode<int>(4,NULL));
    linked_stack_of_integers.show();
    linked_stack_of_integers.pop();
    linked_stack_of_integers.show();
    linked_stack_of_integers.pop();
    linked_stack_of_integers.show();
    linked_stack_of_integers.clear();
    linked_stack_of_integers.show();
    */

    /*
    SimpleNode<int>* second_integer_node = new SimpleNode<int>(20, NULL);
    SimpleNode<int>* first_integer_node = new SimpleNode<int>(10, second_integer_node);
    SimpleNode<int>* third_integer_node = new SimpleNode<int>();
    cout << "Enter the third node value: " ;
    cin >> third_integer_node;
    second_integer_node->set_next(third_integer_node);
    cout << first_integer_node << endl;
    cout << first_integer_node->get_next() << endl;
    cout << second_integer_node << endl;
    cout << second_integer_node->get_next() << endl;
    cout << third_integer_node << endl;

    delete(first_integer_node);
    delete(second_integer_node);
    delete(third_integer_node);
    */

    /*
    DoubleNode<int>* second_integer_node = new DoubleNode<int>(20, NULL, NULL);
    DoubleNode<int>* first_integer_node = new DoubleNode<int>(10, second_integer_node, NULL);
    DoubleNode<int>* third_integer_node = new DoubleNode<int>();
    cout << "Enter the third node value: " ;
    cin >> third_integer_node;
    cout << endl;
    second_integer_node->set_previous(first_integer_node);
    second_integer_node->set_next(third_integer_node);
    third_integer_node->set_previous(second_integer_node);
    cout << "first node value: " << first_integer_node << "previous node value: " << first_integer_node->get_previous() << "next node value: " << first_integer_node->get_next() << endl;
    cout << "second node value: " << second_integer_node << "previous node value: " << second_integer_node->get_previous() << "next node value: " << second_integer_node->get_next() << endl;
    cout << "third node value: " << third_integer_node << "previous node value: " << third_integer_node->get_previous() << "next node value: " << third_integer_node->get_next() << endl;

    delete(first_integer_node);
    delete(second_integer_node);
    delete(third_integer_node);
    */

    /*
    cout << "8: " << transform_number_to_binary(8) << endl;
    cout << "1425: " << transform_number_to_binary(1425) << endl;
    cout << "432158: " << transform_number_to_binary(432158) << endl;
    cout << "13423414: " << transform_number_to_binary(13423414) << endl;
    */

    /*
    do {
        clean;
        cout << "working..." << endl;
    } while ( question("do you want to continue?") );
    */
    
    Date* date_1 = new Date(2023, 9, 1, 1);
    Date* date_2 = new Date(2000, 1, 31, 2);
    Date* date_3 = new Date(1978, 6, 0, 1);
    Date* date_4 = new Date(2050, 12, 24, 2);
    Date* date_5 = new Date(2023, 13, 1);
    Date* date_6 = new Date(1890, 2, 29);
    Date* date_7 = new Date(2012, 2, 29, 2);
    Date* date_8 = new Date(1991, 12, 9);
    Date* date_9 = new Date(2023, 1, 33, 2);
    Date* date_10 = new Date(1, 1, 1, 2);
    cout << date_1 << " : " << date_1->date_validator() << endl;
    cout << date_2 << " : " << date_2->date_validator() << endl;
    cout << date_3 << " : " << date_3->date_validator() << endl;
    cout << date_4 << " : " << date_4->date_validator() << endl;
    cout << date_5 << " : " << date_5->date_validator() << endl;
    cout << date_6 << " : " << date_6->date_validator() << endl;
    cout << date_7 << " : " << date_7->date_validator() << endl;
    cout << date_8 << " : " << date_8->date_validator() << endl;
    cout << date_9 << " : " << date_9->date_validator() << endl;
    cout << date_10 << " : " << date_10->date_validator() << endl;

    //cin >> date_1; 
    //cout << date_1;




      //////////////////////////////////////////////////////////
     //////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
    pause();
    return 0;
}