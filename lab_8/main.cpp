#include <iostream>
#include "Polynom.h"
#include "Quat.h"
#include <assert.h>
#include "Bernstein.h"

using namespace std;

void Test1(){

    cout << "Test 1\n";

    Polynom<int> arr[] = {bern_v<2, 0>, bern_v<2, 1>, bern_v<2, 2>};

    Polynom<int> p = arr[0] * 1 + arr[1] * 3 + arr[2] * 2;

    for  (int i = 0; i < 3; i++){

        cout << "bernstrein basis Polynom n = 2, k = " << i << endl;
        cout << arr[i];
    }

    assert(arr[0].Coefficients[0] == 1);
    assert(arr[0].Coefficients[1] == -2);
    assert(arr[0].Coefficients[2] == 1);
    assert(arr[1].Coefficients[0] == 0);
    assert(arr[1].Coefficients[1] == 2);
    assert(arr[1].Coefficients[2] == -2);
    assert(arr[2].Coefficients[0] == 0);
    assert(arr[2].Coefficients[1] == 0);
    assert(arr[2].Coefficients[2] == 1);

    cout << "Bernstein Polynom (Linear combination) k0 = 1 k1 = 3 k2 = 2" << endl;
    cout << p;    

    cout << "Test 1 completed\n"; 


}


int main(int, char**) {

    Test1();

}
