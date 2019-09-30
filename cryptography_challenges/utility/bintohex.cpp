#include "bintohex.h"

int main(int argc, char **argv)
{
    sstream ss;

    if (argc != 2)
    {
        std::cout << "Error wrong number of arguments" << std::endl;
        return -1;
    }

    binToHex(argv[1], &ss);

    std::cout << ss.str() << std::endl;
}

void binToHex(string bin, sstream *ss)
{
    size_t length = bin.length();

    std::cout << length << std::endl;

    for (int i = 0; i < (length / 4); i++)
    {
        string segment = bin.substr(4 * i, 4);
        binSegmentToHex(segment, ss);
    }
}

void binSegmentToHex(string binSegment, sstream *ss)
{
    if (binSegment == "0000")
    {
        *ss << '0';
    }
    else if (binSegment == "0001")
    {
        *ss << '1';
    }
    else if (binSegment == "0010")
    {
        *ss << '2';
    }
    else if (binSegment == "0011")
    {
        *ss << '3';
    }
    else if (binSegment == "0100")
    {
        *ss << '4';
    }
    else if (binSegment == "0101")
    {
        *ss << '5';
    }
    else if (binSegment == "0110")
    {
        *ss << '6';
    }
    else if (binSegment == "0111")
    {
        *ss << '7';
    }
    else if (binSegment == "1000")
    {
        *ss << '8';
    }
    else if (binSegment == "1001")
    {
        *ss << '9';
    }
    else if (binSegment == "1010")
    {
        *ss << 'a';
    }
    else if (binSegment == "1011")
    {
        *ss << 'b';
    }
    else if (binSegment == "1100")
    {
        *ss << 'c';
    }
    else if (binSegment == "1101")
    {
        *ss << 'd';
    }
    else if (binSegment == "1110")
    {
        *ss << 'e';
    }
    else if (binSegment == "1111")
    {
        *ss << 'f';
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
}