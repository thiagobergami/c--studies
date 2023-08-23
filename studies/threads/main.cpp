#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread id: " << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        std::cout << "Working... \n";
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    // wait to the thread to be joined
    worker.join();

    std::cout << "Finished." << std::endl;
    std::cout << "Started thread id: " << std::this_thread::get_id() << std::endl;
    std::cin.get();
}