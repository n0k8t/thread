#include <iostream>
#include <thread>
#include "InfInt.h"


void factorial(int& num, InfInt& res)
{
    res = 1;
    for (int i = 1; i <= num; ++i)
    {
        res *= i;
    }
}

InfInt C(int n, int k)
{
    if (k == n || k == 0)
        return 1;
    InfInt nFact;
    InfInt kFact;
    InfInt difFact;
    int dif = n - k;
    std::thread first(factorial, std::ref(n), std::ref(nFact));
    std::thread second(factorial, std::ref(k), std::ref(kFact));
    std::thread third(factorial, std::ref(dif), std::ref(difFact));
    first.join();
    second.join();
    third.join();
    InfInt result = nFact / (kFact*difFact);
    return result;
}

int main()
{
    std::cout << "> "<< C(30, 5) << std::endl;
    return 0;
}