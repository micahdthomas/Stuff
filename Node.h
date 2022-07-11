/********************************************
 * This is the node header. It houses all node
 * declarations.
 *
 * Micah Thomas
 * 7/3/2022
 *********************************************/

#ifndef HW4_NODE_H
#define HW4_NODE_H

struct Node {

public:
    //Constructors
    Node();
    Node (const int anItem);
    Node (const int anItem, Node* nextNodePtr, Node* previousPtr);
    //Getters
    int getItem() const;
    Node* getNext() const;
    Node* getPrevious() const;
    //Setters
    void setItem (int anItem);
    void setNext (Node* nextNodePtr);
    void setPrevious (Node* previousNodePtr);
private:
    Node* next;  //Pointer to the next node
    Node* previous; //Pointer to the previous node
    int item;        //An int data item

};


#endif //HW4_NODE_H
