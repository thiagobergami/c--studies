/* 

Pointer giver power to alocating and dealocating memory 

Pointer is a variable whose values is an address

to declare:
variable_type *pointer_name;

int *int_prt {}; // a pointer to a integer

initializing pointer variables to point nowhere

    - Always initialize pointers
    - Uninitialized pointers contain garbage data and can 'point anywhere´
    - initializing to zero or nullprt(C++ 11) represents address zero
        - implies that the pointer is 'pointing nowhere'
 */

#include <iostream>

using namespace std;

int main(){
    int num {10};

    cout << "Value of num is: " << num << endl;
    cout << "Size of of num is: " << sizeof num << endl;
    cout << "Address of of num is: " << &num << endl;

    cout << "--------------------------------------" << endl;

    int *p;

    cout << "Value p: " << p << endl;
    cout << "Address p: " << &p << endl;
    cout << "sizeof p: " << sizeof p << endl;

    p = nullptr;

    cout << "Value p: " << p << endl;

    cout << "--------------------------------------" << endl;
    
    

}