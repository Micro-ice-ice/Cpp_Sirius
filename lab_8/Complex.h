#pragma once
#include <iostream>

template<typename T>
class Quat;

template<typename T>
class Complex{

public:

    T A; //

    T B; // 

    Complex(){
        
        A = 0;

        B = 0;
    }

    Complex(T a){

        A = a;

        B = 0;
    }

    Complex(T a, T b){

        A = a;

        B = b;
    }

    template<typename S>
    auto operator+(Complex<S> c){

        using X = decltype(A + c.A);

        return Complex<X>(A + c.A, B + c.B);
    }

    template <typename S>
    auto operator+(S s){

        using X = decltype(A + s);

        return Complex<X>(A + s, B);
    }

    template<typename S>
    auto operator*(Quat<S> q){

        using X = decltype(A + q.A);

        X a = A * q.A - B * q.B;

        X b = A * q.B + B * q.A;

        X c = A * q.C - q.D * B;

        X d = A * q.D + B * q.C;

        return Quat<X>(a, b, c, d);
    }


    template<typename S>
    auto operator*(Complex<S> c){

        using X = decltype(A + c.A);

        X a = A * c.A - B * c.B;

        X b = A * c.B + B * c.A;

        return Complex<X>(a, b);
    }

    template <typename S>
    auto operator*(S s){

        using X = decltype(A + s);

        return Complex<X>(A * s, B * s);
    }

    template<typename S>
    auto operator-(Complex<S> c){

        using X = decltype(A + c.A);

        return Complex<X>(A - c.A, B - c.B);
    }

    template <typename S>
    auto operator-(S s){

        using X = decltype(A + s);

        return Complex<X>(A - s, B);
    }



};

template<typename T>
std::ostream& operator<<(std::ostream& strm, const Complex<T> &c)
{
    strm << "(" << c.A << ", [" << c.B << "])";
    return strm;
}

template<typename T, typename S>
auto operator+(S const& s, Complex<T> const& c){

    return c + s;
}

template<typename T, typename S>
auto operator-(S const& s, Complex<T> const& c){

    using X = decltype(s + c.A);
    Complex<X> result = Complex<X>(c);
    return result - c;

}

template<typename T, typename S>
auto operator*(S const& s, Complex<T> const& c){

    return c * s;

}