#include "Node.h"

Node::Node(){

    X = 0;

    next = nullptr;
}

Node::Node(int x){

    X = x;

    next = nullptr;
}

std::string Node::ToString(){

    std::string result = "";
    result += std::to_string(X);
    return result;

}