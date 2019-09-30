#include "hextobin.h"

int main(int argc, char **argv)
{
    sstream ss;

    if (argc != 2)
    {
        std::cout << "Error wrong number of arguments" << std::endl;
        return -1;
    }

    hexToBin(argv[1], &ss);

    std::cout << ss.str() << std::endl;
}

void hexToBin(string hex, sstream *ss)
{
    size_t length = hex.length();

    for (int i = 0; i < length; i++)
    {
        hexDigitToBin(hex.at(i), ss);
    }
}
void hexDigitToBin(char hexDigit, sstream *ss)
{
    switch (hexDigit)
    {
    case '0':
        *ss << "0000";
        break;
    case '1':
        *ss << "0001";
        break;
    case '2':
        *ss << "0010";
        break;
    case '3':
        *ss << "0011";
        break;
    case '4':
        *ss << "0100";
        break;
    case '5':
        *ss << "0101";
        break;
    case '6':
        *ss << "0110";
        break;
    case '7':
        *ss << "0111";
        break;
    case '8':
        *ss << "1000";
        break;
    case '9':
        *ss << "1001";
        break;
    case 'a':
        *ss << "1010";
        break;
    case 'b':
        *ss << "1011";
        break;
    case 'c':
        *ss << "1100";
        break;
    case 'd':
        *ss << "1101";
        break;
    case 'e':
        *ss << "1110";
        break;
    case 'f':
        *ss << "1111";
        break;
    default:
        std::cout << "ERROR" << std::endl;
    }
}
