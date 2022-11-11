#include "Calculator.h"
#include <regex>
#include <string>

Calculator::Calculator(string expression){

    regex rex{ "(?:der)|(?:\\*)|(?:\\+)|(?:\\[(?:(?:-?[0-9]+(?:\\.[0-9]+)? )*(?:-?[0-9]+(?:\\.[0-9]+)?))\\])|(?:int)" }; 
    std::sregex_iterator beg{ expression.cbegin(), expression.cend(), rex }; 
    std::sregex_iterator end{};  

    //i - текущий токен
    for (auto i = beg; i != end; ++i)
    {   
        //условие полинома
        if (i->str()[0] == '['){

            Polynom<double> p = TokenToPolynom(i->str());
            Polynoms.push(p);

        } //другой токен
        else{

            Operators.push(i->str());
        }
    }
}

Polynom<double> Calculator::TokenToPolynom(string token){

    regex rex{ "-?[0-9]+(?:\\.[0-9]+)?" }; 
    std::sregex_iterator beg{ token.cbegin(), token.cend(), rex }; 
    std::sregex_iterator end{};  
    int count = 0;

    for (auto i = beg; i != end; ++i)
    {   
        count++;        
    }

    double arr[count];
    
    int j = 0;
    for (auto i = beg; i != end; ++i)
    {   
        arr[j] = std::stod(i->str());   
        j++;          
    }

    Polynom<double> p = Polynom(arr, count);

    return p;

}

Polynom<double> Calculator::GetResult(){

    bool ok = true;
        while (!Operators.empty())
        {
            if(Operators.top() == "+"){

                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p2 = Polynoms.top();
                Polynoms.pop();
                
                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p1 = Polynoms.top();
                Polynoms.pop();

                Polynoms.push(p1 + p2);

            }

            if(Operators.top() == "-"){

                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p2 = Polynoms.top();
                Polynoms.pop();

                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p1 = Polynoms.top();
                Polynoms.pop();

                Polynoms.push(p1 - p2);

            }

            if(Operators.top() == "*"){
                
                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p2 = Polynoms.top();
                Polynoms.pop();

                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p1 = Polynoms.top();
                Polynoms.pop();

                Polynoms.push(p1 * p2);

            }   

            if(Operators.top() == "int"){
                
                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p2 = Polynoms.top();
                Polynoms.pop();

                Polynoms.push(p2.Integral());

            }

            if(Operators.top() == "der"){

                if (Polynoms.empty()){
                    ok = false;
                    break;;
                }
                Polynom<double> p2 = Polynoms.top();
                Polynoms.pop();

                Polynoms.push(p2.Der());

            }

            Operators.pop();
        }

        if (Polynoms.empty()){

            ok = false;
        }

        if (ok){
            return Polynoms.top();
        }
        std::cerr << "Wrong expression \n";
     
    
  
    

}
