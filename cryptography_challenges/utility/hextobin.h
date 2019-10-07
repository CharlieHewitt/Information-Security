#include <sstream>
#include <string>
#include <iostream>

typedef std::string string;
typedef std::stringstream sstream;

void hexToBin(string hex, sstream *ss);
void hexDigitToBin(char hexDigit, sstream *ss);