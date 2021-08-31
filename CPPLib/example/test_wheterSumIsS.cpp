#include "dynamic_programming.h"
#include <iostream>

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    bool ret = whetherSumIsS(arr, 5, 3);
    std::cout << "Result of 9: " << ret << std::endl;

    ret = whetherSumIsS(arr, 5, 100);
    std::cout << "Result of 100: " << ret << std::endl;

    std::cout << "----------------------" << std::endl;
    // Dynamic programming
    ret = dp_whetherSumIsS(arr, 5, 9);
    std::cout << "Result of 9: " << ret << std::endl;

    return 0;
}