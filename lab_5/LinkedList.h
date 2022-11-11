#include <iostream>
//#include "Node.h"

class Node;

class LinkedList{

public:

    Node* head;

    LinkedList();

    LinkedList(Node* node);

    void PushFront(Node* node);

    void PushBack(Node* Node);

    void DeleteNodes(int value);

    std::string ToString();

};