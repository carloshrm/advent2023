#include <iostream>
#include "Day11.h"
#include <chrono>

int main()
{
    Day11 solution{ };
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << solution.partOne() << " || " << solution.partTwo();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\n\n " << time.count() << "��s" << std::endl;
}