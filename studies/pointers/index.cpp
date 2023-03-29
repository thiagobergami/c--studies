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

 Dereferencing a Pointer
 Access the data we're pointing to - dereferencing a pointer
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num{10};

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
    cout << "Dereferencing a Pointer" << endl;
    int score{100};
    int *score_ptr{&score};

    cout << "*score_ptr:  " << *score_ptr << endl; // 100
    cout << "Referencing 200 to the Pointer *score_ptr" << endl;
    *score_ptr = 200;

    cout << "*score_ptr:  " << *score_ptr << endl;
    cout << "score:  " << score << endl;
    score = 300;

    cout << "*score_ptr:  " << *score_ptr << endl;
    cout << "score:  " << score << endl;

    cout << "--------------------------------------" << endl;
    cout << "Dereferencing a vector Pointer" << endl;

    vector<string> stooges{"Larry", "Moe", "Curly"};
    vector<string> *vector_ptr{nullptr};

    vector_ptr = &stooges;

    cout << "First stooge: " <<(*vector_ptr).at(0) <<endl; //Larry

    cout <<"Stooges: ";
    for(string stooge: *vector_ptr)
        cout<<stooge<<" ";
    cout << endl;

    cout << "--------------------------------------" << endl;
    enum difficulty {NOVICE, EASY, NORMAL};

    difficulty myDif = EASY;

    cout << myDif << endl;

    return 0;
}