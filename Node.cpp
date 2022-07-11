/********************************************
 * This is the node class. It houses all node
 * definitions.
 *
 * Micah Thomas
 * 7/3/2022
 *********************************************/

#include "Node.h"

Node::Node()//basic node
{
    this->item = 0;
    this->next = nullptr;
}
/*********************************************/
Node::Node(int anItem)//semi-basic node
{
    this->item = anItem;
    this->next = nullptr;
    this->previous = nullptr;
}
/*********************************************/

Node::Node(int anItem, Node* nextPtr, Node* previousPtr)//can create a node with all the stuff defined
{
    this->item = anItem;
    this->next = nextPtr;
    this->previous = previousPtr;

}
/*********************************************/

int Node::getItem() const//Returns in value
{
    return item;
}
/*********************************************/

Node* Node::getNext() const//returns pointer from node to next
{
    return next;
}
/*********************************************/

Node* Node::getPrevious() const//returns pointer from node to previous
{
    return previous;
}
/*********************************************/

void Node::setItem(const int anItem)//setter for item
{
    this->item = anItem;

}
/*********************************************/

void Node::setNext(Node* nextPtr)//setter for next pointer
{
    this->next = nextPtr;

}
/*********************************************/

void Node::setPrevious(Node* previousPtr)//setter for previous pointer
{
    this->previous = previousPtr;

}
/*********************************************/
