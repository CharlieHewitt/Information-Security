#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <regex>
#include <time.h>
#include "authlib.h"

#define aes256 \
    key { R"((?:std::hex)(?:w?)?(p_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2}x£[^erd].{4}&%!(?:¢:65?43`{7}){4}\1-)" + ss.str() }
#define encryptionScheme std::regex
#define encrypt std::regex_match

bool hashPassword(std::string);
std::string getHashPass();
int generateInitialisationVector();
bool checkHash();
