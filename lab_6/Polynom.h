#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Polynom{

public:

    vector <T> Coefficients;

    Polynom(T* arr, int size){

        for (int i = 0; i < size; i++){

            Coefficients.push_back(arr[i]);
        }
    }

    template<typename S>
    auto operator-(Polynom<S> p){

        int size1 = Coefficients.size();
        int size2 = p.Coefficients.size();
        int min_size = min(size1, size2);
        int max_size = max(size1, size2);

        using X = decltype(Coefficients[0] + p.Coefficients[0]);

        X arr[max_size] ;

        for (int i = 0; i < min_size; i++){

            arr[i] = Coefficients[i] - p.Coefficients[i];
        }

        if (size1 > size2)
        {
            for (int i = min_size; i < max_size; i++){

                arr[i] = Coefficients[i];
            
            }
        }
        else
        {
            for (int i = min_size; i < max_size; i++){

                arr[i] = -p.Coefficients[i];
            
            }
        }

        return Polynom<X>(arr, max_size);
    }

    template<typename S>
    auto operator+(Polynom<S> p){


        int size1 = p.Coefficients.size();
        int size2 = Coefficients.size();
        int min_size = min(size1, size2);
        int max_size = max(size1, size2);

        using X = decltype(Coefficients[0] + p.Coefficients[0]);

        X arr[max_size] ;

        for (int i = 0; i < min_size; i++){

            arr[i] = Coefficients[i] + p.Coefficients[i];
        }

        if (size1 > size2)
        {
            for (int i = min_size; i < max_size; i++){

                arr[i] = p.Coefficients[i];
            
            }
        }
        else
        {
            for (int i = min_size; i < max_size; i++){

                arr[i] = Coefficients[i];
            
            }
        }

        return Polynom<X>(arr, max_size);
    }

    template<typename S>
    auto operator*(Polynom<S> p){


        int size1 = p.Coefficients.size() - 1;
        int size2 = Coefficients.size() - 1;
        int max_size = (size1 + size2) + 1;

        using X = decltype(p.Coefficients[0] + Coefficients[0]);

        X arr[max_size];

        for (int i = 0; i <= size1; i++){

            for (int j = 0; j <= size2; j++)

            arr[i + j] = arr[i + j] + p.Coefficients[i] * Coefficients[j];
        }

        return Polynom<X>(arr, max_size);
    }


    string ToString(){

        string result = "Polynom\n";
        for (int i = 0; i < Coefficients.size(); i++){

            result += "X ^ ";
            result += to_string(i);
            result += " = ";
            result += to_string(Coefficients[i]);
            result += "\n";
        }

        return result;
    }


    auto Der(){

        int max_size = Coefficients.size() - 1;
        T arr[max_size];

        for (int i = 0; i < max_size; i++){

            arr[i] = Coefficients[i + 1] * (i + 1);
        }

        return Polynom<T>(arr, max_size);

    }

    auto Integral(){

        int max_size = Coefficients.size() + 1;

        using X = double;

        X arr[max_size];

        arr[0] = Coefficients[0] * 0.0;

        for (int i = 1; i < max_size; i++){

            arr[i] = Coefficients[i - 1] / (double)(i);

        }  

        return Polynom<X>(arr, max_size);        
    }
    

};

template<typename T>
std::ostream& operator<<(std::ostream& strm, const Polynom<T> &p)
{
    strm << "Polynom\n";
    for (int i = 0; i < p.Coefficients.size(); i++){

            strm << "X ^ ";
            strm << i;
            strm << " = ";
            strm << p.Coefficients[i];
            strm << "\n";
        }

    return strm;
}
