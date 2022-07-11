/********************************************
 * This is the main function. It runs all the code.
 *
 * Micah Thomas
 * 7/3/2022
 *********************************************/

#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{

    DoubleLinkedList list;
    list.add(1);
    list.addNodeOrdered(5);
    list.addNodeOrdered(9);
    list.addNodeOrdered(16);
    list.addNodeOrdered(25);
    list.addNodeOrdered(2);
    list.addNodeOrdered(7);
    list.addNodeOrdered(19);
    list.printList();
    list.addNodeOrdered(10);
    list.printList();
    cout << "Number of items in the list is: " << list.getCurrentSize();
    cout << "\nThe list is: ";
    if (list.isEmpty()==true)
        cout << "empty\n";
    else
        cout << "not empty\n";
    list.remove(9);
    list.printList();
    cout << "Number of items in the list is: " << list.getCurrentSize();
    list.getIndexTo(16);
    list.getIndexTo(9);
    list.clear();
    cout << "\nThe list is: ";
    if (list.isEmpty()==true)
        cout << "empty\n";
    else
        cout << "not empty\n";
    return 0;
}
