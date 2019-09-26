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
    std::cout << babystep(g, n, a) << std::endl;
}

// brute force
int dlog(int g, int n, int a)
{
    for (int i = 0; i < 100000; i++)
    {
        // calculate g^i
        int power = powersqm(g, i, n);
        if (power % n == a)
        {
            return i;
        }
    }

    // not found
    return -1;
}

// fix this as its not working as intended
int babystep(int g, int n, int a)
{
    // m = sqrt n
    int m = std::ceil(std::sqrt(n));

    // initialise map
    std::unordered_map<int, int> map{};

    // 0 <= j < n SHOULD BE M?
    for (int j = 0; j < n; j++)
    {
        // sq to multiply to stop overflowing
        int power = powersqm(g, j, n);
        map.emplace(power % n, j);
        std::cout << "Added pair " << power % n << ", " << j << std::endl;
    }

    //  For loop is useless -> i always = 0? Is it just the value or is it a fluke?
    for (int i = 0; i < m; i++)
    {
        auto it = map.find(a);
        if (it != map.end())
        {
            auto key = it->first;
            auto value = it->second;
            std::cout << "Found pair " << key << ", " << value << std::endl;
            std::cout << value << " - " << m << " * " << i << std::endl;
            return (value - m * i);
        }
    }
    // Sasa : Might not work if neg, add n-1 (to get in mod range) (otherwise mod inverses ...)

    return -1;
}

int powersqm(int a, int b, int n)
{
    //convert h to binary
    int binaryPower[64];
    int index = -1;

    for (int i = 0; i < 64; i++)
    {
        binaryPower[i] = 0;
    }
    while (b > 0)
    {
        index++;

        if (b % 2 == 1)
        {
            binaryPower[index] = 1;
        }
        else
        {
            binaryPower[index] = 0;
        }

        b /= 2;
    }

    for (int i = 0; i < 64; i++)
    {
        // cout << binaryPower[i];
    }

    //cout << endl;

    int pow = a;
    int result = 1;

    int counter = 0;
    while (counter <= index)
    {

        if (binaryPower[counter] == 1)
        {
            result = (result * pow) % n;
        }

        pow = (pow * pow) % n;

        counter++;
    }

    return result;
}