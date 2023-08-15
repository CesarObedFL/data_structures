#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"

#include "algorithms/data_types.h"
#include "algorithms/chronometer.h"
#include "algorithms/number_to_binary.h"

#include "DSAs/lists/array_list.h"
#include "DSAs/stacks/array_stack.h"
#include "DSAs/stacks/linked_stack.h"
#include "DSAs/queues/array_queue.h"

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
    cout << "8: " << transform_number_to_binary(8) << endl;
    cout << "1425: " << transform_number_to_binary(1425) << endl;
    cout << "432158: " << transform_number_to_binary(432158) << endl;
    cout << "13423414: " << transform_number_to_binary(13423414) << endl;
    */

    do {
        clean;
        cout << "working..." << endl;
    } while ( question("do you want to continue?") );




    pause();
    return 0;
}