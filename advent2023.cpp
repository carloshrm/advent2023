#include <iostream>
#include "Day13.h"
#include <chrono>

int main()
{
    Day13 solution{ };
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << solution.partOne() << " || " << solution.partTwo();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\n\n " << time.count() << "ƒÊs" << std::endl;
}