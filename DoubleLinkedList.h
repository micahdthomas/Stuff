/********************************************
 * This is the Double Linked List header. It
 * houses all Double Linked List declarations.
 *
 * Micah Thomas
 * 7/3/2022
 *********************************************/

#ifndef HW4_DOUBLELINKEDLIST_H
#define HW4_DOUBLELINKEDLIST_H

#include "Node.h"
using namespace std;


class DoubleLinkedList
{
public:
    DoubleLinkedList();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(int anEntry);
    bool addNodeOrdered(int anEntry);
    bool remove(int anEntry);
    void clear();
    bool find(int anEntry) const;
    int getIndexTo(const int target) const;
    void printList();
private:
    int itemCount;
    Node* getPointerTo(int target) const;
    Node* headPtr;

};

#endif //HW4_NODE_H
