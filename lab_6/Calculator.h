#include <iostream>
#include <stack>
#include "Polynom.h"

using namespace std;

class Calculator {

private:

    stack<string> Operators = stack<string>();

    stack<Polynom<double>> Polynoms = stack<Polynom<double>>();

    Polynom<double> TokenToPolynom(string token);


public:

    Calculator(string expression);

    Polynom<double> GetResult();   


};