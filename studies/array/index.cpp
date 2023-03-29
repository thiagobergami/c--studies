/*

Arrays in C++ have fixed size.
Elements are all the same type in a array
Stored contiguously in memory

first element is at index 0
last element is at index size-1

examples:

int test_scores [5] {100,95,99,87,88};

int high_score_per_level [10] {3,5}  init to 3,5 and remaining to 0

const double days_in_year {365};
double hi_temperatures [days_in_year] {0}; //init an array with 365 elements equal 0;

int another_array [] {1,2,3,4,5}; //automatically calculated.

to access an element in array it's array_name [element_index]
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // char vowels[]{'a', 'e', 'i', 'o', 'u'};

    // cin >> vowels[5]; out of bounds

    /*     double hi_temps[]{99.1, 98.2, 97.3, 96.4, 95.5};
        cout << "The first high temperature is: " << hi_temps[0] << endl;

        hi_temps[0] = 100.0;

        cout << "\nThe first high temperature is now: " << hi_temps[0] << endl; // set the first element in hi_temps to 100.7

        cout << "Array adress: " << hi_temps << endl; */

    // to declare a multi-dimensional array
    // int movie_rating[3][4];

    /*
        Suppose we want to store test scores for my school

        We don't have no way of knowing how many students will register next year

        use a c++ vector, that's containin in the C++ STL

        vector is a array that can grow and shrink in size at execution time

    */
    // declare vector
    // vector <char> vowels; vector of chars
    // vector <int> test_scores (10); declare a vector of 10 elements;

    /*     vector<int> test_scores{100, 95, 99, 87, 88};

        cout << "\nFirst score at index 0: " << test_scores[0] << endl;
        cout << "Second score at index 1: " << test_scores[1] << endl;
        cout << "Out of bounds 5: " << test_scores[5] << endl;

        cout << "\nFirst score at index using at: " << test_scores.at(0) << endl;

        test_scores.push_back(87);
        cout << "\nAdd element usgin push_back: " << test_scores[5] << endl;
     */
    /*
     vector <char> vowels; //empty
     vector <char> vowels(5); //5 initialized to zero
      */
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    vector<int> test_scores{100, 98, 89};

    cout << "Test scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[1] << endl;

    cout << "\nEnter 3 test scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "\nUpdated test scores: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;

    cout << "\nEnter a test score to add to the vector: ";
    int score_to_add{0};
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << "\nEnter a more score to add to the vector: ";
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;

    // Example of a 2D-vector

    vector<vector<int>> movie_ratings
    {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    cout << "\nHere are the movie rating :" << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;
    cout << movie_ratings[0][4] << endl;

    return 0;
}