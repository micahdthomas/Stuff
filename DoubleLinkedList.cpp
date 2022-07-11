/********************************************
 * This is the Double Linked List class. It
 * houses all definitions.
 *
 * Micah Thomas
 * 7/3/2022
 *********************************************/

#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

DoubleLinkedList::DoubleLinkedList()//creates a new list with headPtr starting at null.
{
    headPtr = nullptr;
    itemCount = 0;
}
/*********************************************/

bool DoubleLinkedList::isEmpty() const//checks to see if it's empty.
{
    if (itemCount == 0)
        return true;
    else
        return false;
}
/*********************************************/

int DoubleLinkedList::getCurrentSize() const//returns size of the list.
{
    return itemCount;
}
/*********************************************/

bool DoubleLinkedList::add(const int newEntry)//basic add function
{
    Node* newNode = new Node(newEntry);
    newNode->setNext(nullptr);
    newNode->setPrevious(nullptr);
    this->headPtr = newNode;
    this->itemCount++;

    return true;
}
/*********************************************/

bool DoubleLinkedList::addNodeOrdered(int newEntry) //adds sorted into list by value
{
    bool moveOn = false;
    Node *tempPointer = this->headPtr;
    Node *tempPrevious = nullptr;
    if (this->headPtr == nullptr) {
        this->headPtr = new Node(newEntry);
        this->itemCount++;
        return true;
    }
    if (newEntry <= this->headPtr->getItem()) {
        Node *newNode = new Node(newEntry);
        newNode->setNext(this->headPtr);
        this->headPtr = newNode;
        newNode->getNext()->setPrevious(newNode);
        this->itemCount++;
        return true;
    }
    do {
        tempPrevious = tempPointer;
        tempPointer = tempPointer->getNext();
        if (tempPointer == nullptr) {
            Node *newNode = new Node(newEntry);
            newNode->setNext(nullptr);
            newNode->setPrevious(tempPrevious);
            tempPrevious->setNext(newNode);
            this->itemCount++;
            return true;
        } else if (newEntry <= tempPointer->getItem()) {
            Node *newNode = new Node(newEntry);
            newNode->setNext(tempPointer);
            newNode->setPrevious(tempPrevious);
            tempPrevious->setNext(newNode);
            tempPointer->setPrevious(newNode);
            this->itemCount++;
            return true;

        }
    } while (moveOn == false);
}
/*********************************************/

bool DoubleLinkedList::remove(int anEntry)//removes target from list
{
    if (isEmpty() == true || find(anEntry) == false)//is it empty? Is it even in the list?
        return false;//breaks if empty or not on list
    Node* tempPointer1 = this->headPtr;//starting location for finder
    Node* tempPointer2 = nullptr;//starting location for previous

    if (find(anEntry)) {
        while (tempPointer1->getItem() != anEntry) {
            tempPointer2 = tempPointer1;
            tempPointer1 = tempPointer1->getNext();
        }
        tempPointer2->setNext(tempPointer1->getNext());
        tempPointer1->setNext(nullptr);
        tempPointer1->setPrevious(nullptr);

        itemCount--;
    }
    return true;
}
/*********************************************/

void DoubleLinkedList::clear()//clears the whole list.
{
    do
    {
        Node* tempPtr1 = headPtr;
        headPtr = headPtr->getNext();
        tempPtr1->setPrevious(nullptr);
        tempPtr1->setNext(nullptr);
    } while (headPtr != nullptr);//how it knows where to stop
    this->itemCount =0;
}
/*********************************************/

bool DoubleLinkedList::find(int anEntry) const //Is it available?
{
    return (getPointerTo(anEntry) != nullptr);

}
/*********************************************/

Node* DoubleLinkedList::getPointerTo(const int target) const//returns a pointer
{
    Node* targetPtr = headPtr;
    while (targetPtr != nullptr) {
        if (targetPtr->getItem() == target) {
            return targetPtr;
        }
        else {
            targetPtr = targetPtr->getNext();
        }
    }
    return targetPtr;
}
/*********************************************/

int DoubleLinkedList::getIndexTo(const int target) const//returns index number for an object via printing
{
    Node *targetPtr = this->headPtr;
    if (find(target)==false)
        cout << "\nNumber " << target << " is not on the list";
    for (int i = 0; i <= this->itemCount; i++) {
        while (targetPtr != nullptr) {
            if (targetPtr->getItem() == target) {
                cout << "\nNumber " << target << " is at position " << i;
                return 0;
            } else {
                targetPtr = targetPtr->getNext();
                i++;
            }

        }
    }
}
/*********************************************/

void DoubleLinkedList::printList() //prints the list in order
{
    cout << "Your list is: ";
    if (this->headPtr == nullptr) {
        cout << " empty.\n";
    }
    Node *tempPtr1 = this->headPtr;
    do {
        int tempNum = tempPtr1->getItem();
        cout << " " << tempNum;
        tempPtr1 = tempPtr1->getNext();
        } while (tempPtr1 != nullptr);
        cout << ".\n";
    }
/*********************************************/

