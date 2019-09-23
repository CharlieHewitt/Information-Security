#include <iostream>
#include <sstream>
#include <string>

#include "mtable.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error number of command args != 2 but = " << argc << std::endl;
        return -1;
    }
    std::cout << argv[1] << std::endl;
    int n = std::stoi(argv[1]);
    sstream ss;

    printHeader(n, &ss);
    printHeaderEnd(n, &ss);
    printRows(n, &ss);

    std::string s = ss.str();
    std::cout << s << std::endl;

    return 0;
}

void printHeader(int n, sstream *ss)
{
    *ss << "* |";

    for (int i = 1; i < n; i++)
    {
        *ss << " " << i;
    }

    *ss << "\n";
}

void printHeaderEnd(int n, sstream *ss)
{
    *ss << "--|";

    for (int i = 0; i < n; i++)
    {
        *ss << "--";
    }
    *ss << "\n";
}

void printRow(int i, int n, sstream *ss)
{
    *ss << i << " |";
    for (int j = 1; j < n; j++)
    {
        *ss << " " << (i * j % n);
    }

    *ss << "\n";
}

void printRows(int n, sstream *ss)
{
    for (int i = 1; i < n; i++)
    {
        printRow(i, n, ss);
    }
}
