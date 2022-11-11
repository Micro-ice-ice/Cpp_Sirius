#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include <cstdint>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {

    LinkedList mylist = LinkedList();

    if (argc != 2) {
        std::cerr << "Wrong input arguments" << std::endl;
        return -1;
    }

    std::string filename = argv[1];
    std::ifstream f(filename);
	std::string current_line;

    int last;

    while (getline(f, current_line)) {

        try{         
            last = std::stoi(current_line);
            mylist.PushBack(new Node(last));
        }

        catch(...){

            std::cerr << "Wrong file format" << std::endl;
            return -1;
        }
    }

    std::cout << "Start list:\n";
    std::cout << mylist.ToString();

    mylist.DeleteNodes(last);

    std::cout << "After delete:\n";
    std::cout << mylist.ToString();


  
}
