#include <iostream>
#include "generator.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Argument count != 3 but = " << argc << std::endl;
        return -1;
    }

    int g = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);

    generate(g, n);
}

// calculate g^1 -> g^n-1 mod n
void generate(int g, int n)
{
    int total = 1;

    for (int i = 0; i < n; i++)
    {
        total = (total * g) % n;
        std::cout << total << std::endl;
    }
}