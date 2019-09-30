#include "xorbin.h"

int main(int argc, char **argv)
{
    sstream ss;

    if (argc != 3)
    {
        std::cout << "Error wrong number of arguments" << std::endl;
        return -1;
    }

    xorBin(argv[1], argv[2], &ss);

    std::cout << ss.str() << std::endl;
}

void xorBin(string binA, string binB, sstream *ss)
{
    // should be same length but eh will be
    size_t length = binA.length();

    for (int i = 0; i < length; i++)
    {
        xorBinDigit(binA.at(i), binB.at(i), ss);
    }
}

// XOR Truth table:
// A   B   Result
// 0   0   0
// 0   1   1
// 1   0   1
// 1   1   0

void xorBinDigit(char binDigitA, char binDigitB, sstream *ss)
{
    char result = (binDigitA == binDigitB) ? '0' : '1';
    *ss << result;
}