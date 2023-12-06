#include <iostream>
#include "Day6.h"
#include <chrono>

int main()
{
    Day6 solution{ };
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << solution.partOne() << "||" << solution.partTwo();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\n run time: " << time.count() << "ms" << std::endl;
}