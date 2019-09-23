#include <iostream>
#include <cmath>
#include "dlog.h"
#include "unordered_map"
#include <utility>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Argument count != 4 but = " << argc << std::endl;
        return -1;
    }

    int g = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);
    int a = std::stoi(argv[3]);

    // g^x mod n = a => log g (a) mod n
    // g to the what mod n = a

    std::cout << dlog(g, n, a) << std::endl;
    //std::cout << babystep(g, n, a) << std::endl;
}

// brute force
int dlog(int g, int n, int a)
{
    for (int i = 1; i < 100000; i++)
    {
        // calculate g^i
        int power = pow(g, i);
        if (power % n == a)
        {
            return i;
        }
    }

    // not found
    return -1;
}

//
int babystep(int g, int n, int a)
{
    // m = sqrt n
    int m = std::ceil(std::sqrt(n));

    // initialise map
    std::unordered_map<int, int> map{};

    // 0 <= j < m
    for (int j = 0; j < m; j++)
    {
        int power = pow(g, j);
        map.emplace(j, power);
    }

    // a^-m
    int factor = pow(a, -m);

    //variable to store updated a
    int y = a;

    // 0 <= i < m
    for (int i = 0; i < m; i++)
    {
        auto it = map.find(y);
        if (it != map.end())
        {
            auto value = it->second;
            return (i * m + value);
        }
        else
        {
            y = y * factor % n;
        }
    }

    return -1;
}