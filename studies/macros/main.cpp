#include <iostream>
#include <string>

#define PR_DEBUG 1

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(X)
#endif

int main()
{
    LOG("Hello");
    std::cin.get();
}