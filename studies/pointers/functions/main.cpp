#include <iostream>
#include <vector>

// This code will add a function pointer to another function.
void ForEach(const std::vector<int> &values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = {1, 5, 4, 2, 3};
    //LAMBDAS
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

    std::cin.get();
}