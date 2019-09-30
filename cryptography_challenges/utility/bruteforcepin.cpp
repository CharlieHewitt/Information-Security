#include <string>
#include <iostream>
#include <sstream>

void getPin(int);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error wrong number of arguments" << std::endl;
        return -1;
    }

    getPin(std::stoi(argv[1]));
}

void getPin(int number)
{
    std::stringstream ss;
    std::string str;
    ss << number;
    ss >> str;

    size_t length = str.length();

    std::string frontbit = "";

    while (length < 4)
    {
        frontbit += "0";
        length++;
    }

    std::cout << frontbit + str << std::endl;
}