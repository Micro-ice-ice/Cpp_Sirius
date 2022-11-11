#pragma once
#include <iostream>
#include "Complex.h"



template<typename T>
class Quat{

public:

    T A; //

    T B; //i

    T C; //j

    T D; //k

    Quat(){
        
        A = 0;
        
        B = 0;

        C = 0;

        D = 0;
    }

    Quat(T a, T b, T c, T d){

        A = a;

        B = b;

        C = c;

        D = d;
    }

    Quat(T a){

        A = a;
    }

    template <typename S>
    auto operator+(Quat<S> q){

        using X = decltype(A + q.A);

        return Quat<X>(A + q.A, B + q.B, C + q.C, D + q.D);
    }

    template <typename S>
    auto operator+(Complex<S> q){

        using X = decltype(A + q.A);

        return Quat<X>(A + q.A, B + q.B, C, D);
    }

    template <typename S>
    auto operator+(S s){

        using X = decltype(A + s);

        return Quat<X>(A + s, B, C, D);
    }

    template <typename S>
    auto operator*(Quat<S> q){

        using X = decltype(A + q.A);

        X a = A * q.A - B * q.B - C * q.C - D * q.D;

        X b = A * q.B + q.A * B + C * q.D - q.C * D;

        X c = A * q.C + q.A * C + D * q.B - q.D * B;

        X d = A * q.D + q.A * D + B * q.C - q.B * C;

        return Quat<X>(a, b, c, d);
    }

    template <typename S>
    auto operator*(S s){

        using X = decltype(A + s);

        return Quat<X>(A * s, B * s, C * s, D * s);
    }

    template <typename S>
    auto operator*(Complex<S> q){

        using X = decltype(A + q.A);

        X a = A * q.A - B * q.B;

        X b = A * q.B + q.A * B;

        X c = q.A * C + D * q.B;

        X d = q.A * D - q.B * C;

        return Quat<X>(a, b, c, d);
    }

    template <typename S>
    auto operator-(Quat<S> q){

        using X = decltype(A + q.A);

        return Quat<X>(A - q.A, B - q.B, C - q.C, D - q.D);
    }

    template <typename S>
    auto operator-(S s){

        using X = decltype(A + s);

        return Quat<X>(A - s, B, C, D);
    }

    template <typename S>
    auto operator-(Complex<S> q){

        using X = decltype(A + q.A);

        return Quat<X>(A - q.A, B - q.B, C, D);
    }


};

template<typename T>
std::ostream& operator<<(std::ostream& strm, const Quat<T> &q)
{
    strm << "(" << q.A << ", [" << q.B << ", " << q.C << ", " << q.D << "])";
    return strm;
}

template<typename T, typename S>
auto operator+(S const& s, Quat<T> &q){

    return q + s;

}

template<typename T, typename S>
auto operator-(S const& s, Quat<T> const& q){

    using X = decltype(s - q.A);
    Quat<X> result = Quat<X>(s);
    return result - q;

}

template<typename T, typename S>
auto operator*(S const& s, Quat<T> &q){

    return q * s;

}







