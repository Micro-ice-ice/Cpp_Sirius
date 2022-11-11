#include <iostream>
#include "Polynom.h"
#include <assert.h>
#include "Calculator.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    cout << "Please enter your expression:" << endl;
    string expression;
    getline(cin, expression);


    Calculator calc = Calculator(expression); 

    try{
        
        cout << calc.GetResult();

    }
    catch(...){

        cout << "Wrong expression";

    }
  

}
