#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

#include "assets/utils.h"
#include "algoritms/data_types.h"
#include "algoritms/chronometer.h"
#include "EDAs/lists/array_list.h"
#include "EDAs/stacks/array_stack.h"
#include "EDAs/queues/array_queue.h"
#include "EDAs/node.h"

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
    third_integer_node->set_value(30);
    second_integer_node->set_next(third_integer_node);
    cout << first_integer_node->get_value() << endl;
    cout << first_integer_node->get_next()->get_value() << endl;
    cout << second_integer_node->get_value() << endl;
    cout << second_integer_node->get_next()->get_value() << endl;
    cout << third_integer_node->get_value() << endl;

    delete(first_integer_node);
    delete(second_integer_node);
    delete(third_integer_node);
    */


    pause();
    return 0;
}