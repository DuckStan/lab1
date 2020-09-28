#include <iostream>
#include "headers_1.h"

using namespace Lab1;

int main()
{
    Line *arr = nullptr;
    int m;
    int index;

    arr=input(m);
    if(!arr){
        std::cout << "incorrect data" << std::endl;
        return 1;
    }
    std::cout << "Input the number of line you want to edit:" << std::endl;
    std::cin >> index;

    output("Sourced matrix", arr, m);

    process((index-1), arr, is_even);
    arr=sort(arr, m);

    output("Final matrix", arr, m);

    erase(arr, m);
    return 0;
}
