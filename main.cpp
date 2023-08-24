#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"

#include "algorithms/data_types.h"
#include "algorithms/chronometer.h"
#include "algorithms/number_to_binary.h"

#include "DSAs/lists/array_list.h"
#include "DSAs/lists/linked_list.h"
#include "DSAs/queues/array_queue.h"
#include "DSAs/queues/linked_queue.h"
#include "DSAs/stacks/array_stack.h"
#include "DSAs/stacks/linked_stack.h"


#include "DSAs/objects/node.h"

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

    LinkedList<int> list_of_integers;
    list_of_integers.show();
    list_of_integers.insert_front(new Node<int>(10, NULL));
    list_of_integers.insert_back(new Node<int>(9, NULL));
    list_of_integers.insert_front(new Node<int>(8, NULL));
    list_of_integers.insert_back(new Node<int>(7, NULL));
    list_of_integers.show();
    list_of_integers.insert_position(new Node<int>(6, NULL), 3);
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
    linked_queue_of_integers.enqueue(new Node<int>(1,NULL));
    linked_queue_of_integers.enqueue(new Node<int>(2,NULL));
    linked_queue_of_integers.enqueue(new Node<int>(3,NULL));
    linked_queue_of_integers.enqueue(new Node<int>(4,NULL));
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
    linked_stack_of_integers.push(new Node<int>(1,NULL));
    linked_stack_of_integers.push(new Node<int>(2,NULL));
    linked_stack_of_integers.push(new Node<int>(3,NULL));
    linked_stack_of_integers.push(new Node<int>(4,NULL));
    linked_stack_of_integers.show();
    linked_stack_of_integers.pop();
    linked_stack_of_integers.show();
    linked_stack_of_integers.pop();
    linked_stack_of_integers.show();
    linked_stack_of_integers.clear();
    linked_stack_of_integers.show();
    */

    /*
    Node<int>* second_integer_node = new Node<int>(20, NULL);
    Node<int>* first_integer_node = new Node<int>(10, second_integer_node);
    Node<int>* third_integer_node = new Node<int>();
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




    pause();
    return 0;
}