#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList(){

    head = nullptr;
}

LinkedList::LinkedList(Node* node){

    head = node;
}

void LinkedList::PushFront(Node* node){

    node->next = head;
    head = node;
}

void LinkedList::PushBack(Node* node){

    if (head == nullptr){

        head = node;
        return;
    }

    Node* p = head;

    while (p->next != nullptr)
    {
        p = p->next;
    }

    p->next = node;
}

void LinkedList::DeleteNodes(int value){

    if (head == nullptr){
        
        return;
    }

    Node* p = head;
   
    while (p->X == value)
    {
        head = p->next;
        delete p;
        p = head;

        if (head == nullptr){

            return;
        }
    }
    
    Node* prev = head;

    while (p != nullptr)
    {
        if (p->X == value)
        {
            prev->next = p->next;
            delete p;
            p = prev->next;
            
        }
        else
        {
            prev = p;
            p = p->next;
            
        }

      
    }
    
}

std::string LinkedList::ToString(){

    if (head == nullptr){

        return "List is empty\n";
    }

    std::string result = "";

    Node* p = head;

    while (p->next != nullptr)
    {
        result += p->ToString() + " ";
        p = p->next;
    }

    result += p->ToString() + "\n";
    
    return result;
    
}

