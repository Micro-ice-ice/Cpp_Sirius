#include <iostream>
#include "Polynom.h"
#include "Quat.h"
#include <assert.h>

using namespace std;

void Test1(){

    cout << "Test 1 is running!\n";

    int arr1[] = {1, 1, 1};

    Polynom<int> p1 = Polynom(arr1, 3);

    double arr2[] = {2.5, 3.5, 4.5};

    Polynom<double> p2 = Polynom(arr2, 3);

    auto p3 = p1 * p2;

    cout << p3;

    assert(p3.Coefficients[0] == 2.5);
    assert(p3.Coefficients[1] == 6.0);
    assert(p3.Coefficients[2] == 10.5);
    assert(p3.Coefficients[3] == 8.0);
    assert(p3.Coefficients[4] == 4.5);

    cout << "Test 1 done!\n"; 


}

void Test2(){

    cout << "Test 2 is running!\n";

    double arr1[] = {1.0, 1.0, 1.0};

    Polynom<double> p1 = Polynom(arr1, 3);

    Complex<int> cmplx1 = Complex(1, 1);
    Complex<int> cmplx2 = Complex(2, 1);
    Complex<int> cmplx3 = Complex(3, 1);

    Complex<int> arr2[] = {cmplx1, cmplx2, cmplx3};

    Polynom<Complex<int>> p2 = Polynom(arr2, 3);

    auto p3 = p1 * p2;

    cout << p3;

    assert(p3.Coefficients[0].A == 1.0);
    assert(p3.Coefficients[0].B == 1.0);
    assert(p3.Coefficients[1].A == 3.0);
    assert(p3.Coefficients[1].B == 2.0);
    assert(p3.Coefficients[2].A == 6.0);
    assert(p3.Coefficients[2].B == 3.0);
    assert(p3.Coefficients[3].A == 5.0);
    assert(p3.Coefficients[3].B == 2.0);
    assert(p3.Coefficients[4].A == 3.0);
    assert(p3.Coefficients[4].B == 1.0);

    cout << "Test 2 done!\n";


}

void Test3(){

    cout << "Test 3 is running!\n";

    Complex<double> cmplx1d = Complex(1.0, 1.0);
    Complex<double> cmplx2d = Complex(1.0, 1.0);
    Complex<double> cmplx3d = Complex(1.0, 1.0);

    Complex<double> arr1[] = {cmplx1d, cmplx2d, cmplx3d};

    Polynom<Complex<double>> p1 = Polynom(arr1, 3);

    Complex<int> cmplx1 = Complex(1, 1);
    Complex<int> cmplx2 = Complex(2, 1);
    Complex<int> cmplx3 = Complex(3, 1);

    Complex<int> arr2[] = {cmplx1, cmplx2, cmplx3};

    Polynom<Complex<int>> p2 = Polynom(arr2, 3);

    auto p3 = p1 * p2;

    cout << p3;

    assert(p3.Coefficients[0].A == 0.0);
    assert(p3.Coefficients[0].B == 2.0);
    assert(p3.Coefficients[1].A == 1.0);
    assert(p3.Coefficients[1].B == 5.0);
    assert(p3.Coefficients[2].A == 3.0);
    assert(p3.Coefficients[2].B == 9.0);
    assert(p3.Coefficients[3].A == 3.0);
    assert(p3.Coefficients[3].B == 7.0);
    assert(p3.Coefficients[4].A == 2.0);
    assert(p3.Coefficients[4].B == 4.0);

    cout << "Test 3 done!\n";


}

void Test4(){

    cout << "Test 4 is running!\n";

    double arr1[] = {1.0, 1.0, 1.0};

    Polynom<double> p1 = Polynom(arr1, 3);

    Quat<int> q1 = Quat(1, 1, 1, 1);
    Quat<int> q2 = Quat(1, 1, 1, 1);
    Quat<int> q3 = Quat(1, 1, 1, 1);

    Quat<int> arr2[] = {q1, q2, q3};
    
    Polynom<Quat<int>> p2 = Polynom(arr2, 3);

    auto p3 = p1 * p2;

    cout << p3;

    assert(p3.Coefficients[0].A == 1.0);
    assert(p3.Coefficients[0].B == 1.0);
    assert(p3.Coefficients[0].C == 1.0);
    assert(p3.Coefficients[0].D == 1.0);
    
    assert(p3.Coefficients[1].A == 2.0);
    assert(p3.Coefficients[1].B == 2.0);
    assert(p3.Coefficients[1].C == 2.0);
    assert(p3.Coefficients[1].D == 2.0);

    assert(p3.Coefficients[2].A == 3.0);
    assert(p3.Coefficients[2].B == 3.0);
    assert(p3.Coefficients[2].C == 3.0);
    assert(p3.Coefficients[2].D == 3.0);
    
    assert(p3.Coefficients[3].A == 2.0);
    assert(p3.Coefficients[3].B == 2.0);
    assert(p3.Coefficients[3].C == 2.0);
    assert(p3.Coefficients[3].D == 2.0);

    assert(p3.Coefficients[4].A == 1.0);
    assert(p3.Coefficients[4].B == 1.0);
    assert(p3.Coefficients[4].C == 1.0);
    assert(p3.Coefficients[4].D == 1.0);

    

    cout << "Test 4 done!\n";

}

void Test5(){

    cout << "Test 5 is running!\n";

    Quat<int> q1 = Quat(1, 1, 1, 1);
    Quat<int> q2 = Quat(1, 1, 1, 1);
    Quat<int> q3 = Quat(1, 1, 1, 1);

    Quat<int> arr1[] = {q1, q2, q3};
    
    Polynom<Quat<int>> p1 = Polynom(arr1, 3);

    Quat<double> q1d = Quat(2.0, 2.0, 2.0, 2.0);
    Quat<double> q2d = Quat(2.0, 2.0, 2.0, 2.0);
    Quat<double> q3d = Quat(2.0, 2.0, 2.0, 2.0);

    Quat<double> arr2[] = {q1d, q2d, q3d};
    
    Polynom<Quat<double>> p2 = Polynom(arr2, 3);

    auto p3 = p1 * p2;

    cout << p3;

    assert(p3.Coefficients[0].A == -4.0);
    assert(p3.Coefficients[0].B == 4.0);
    assert(p3.Coefficients[0].C == 4.0);
    assert(p3.Coefficients[0].D == 4.0);
    
    assert(p3.Coefficients[1].A == -8.0);
    assert(p3.Coefficients[1].B == 8.0);
    assert(p3.Coefficients[1].C == 8.0);
    assert(p3.Coefficients[1].D == 8.0);

    assert(p3.Coefficients[2].A == -12.0);
    assert(p3.Coefficients[2].B == 12.0);
    assert(p3.Coefficients[2].C == 12.0);
    assert(p3.Coefficients[2].D == 12.0);
    
    assert(p3.Coefficients[3].A == -8.0);
    assert(p3.Coefficients[3].B == 8.0);
    assert(p3.Coefficients[3].C == 8.0);
    assert(p3.Coefficients[3].D == 8.0);

    assert(p3.Coefficients[4].A == -4.0);
    assert(p3.Coefficients[4].B == 4.0);
    assert(p3.Coefficients[4].C == 4.0);
    assert(p3.Coefficients[4].D == 4.0);

    

    cout << "Test 5 done!\n";

}



int main(int, char**) {

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

}
