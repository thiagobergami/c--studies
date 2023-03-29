#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> myVector = {1, 2, 3, 4, 5};

    // Using a for loop and iterator to print out each element of the vector
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}