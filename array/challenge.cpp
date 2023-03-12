/*
- Declare 2 empty vectors of integers named vector1 and vector2;

- Add 10 and 20 to vector1 dynamucally using push_back
- Display elements using at() method and size() method

- Add 100 and 200 to vector2 dynamically using push_back
- Display elements using at() method and size() method

- Declare an empty 2D vector int called vector_2d;

- Add vector1 to vector_2d
- Add vector2 to vector_2d

- Display the elements in vector_2d using at() method
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vector_1;
    vector<int> vector_2;
    vector<vector<int>> vector_2d;

    vector_1.push_back(10);
    vector_1.push_back(20);

    cout << "Vector_1 elements: " << endl;
    cout << vector_1.at(0) << endl;
    cout << vector_1.at(1) << endl;
    cout << "Vector_1 size is: " << vector_1.size() << endl;

    vector_2.push_back(100);
    vector_2.push_back(200);

    cout << "Vector_2 elements: " << endl;
    cout << vector_2.at(0) << endl;
    cout << vector_2.at(1) << endl;
    cout << "Vector_2 size is: " << vector_2.size() << endl;

    vector_2d.push_back(vector_1);
    vector_2d.push_back(vector_2);

    cout << "Vector 2d elements: " << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << "Vector 2d size is: " << vector_2.size() << endl;
    return 0;
}