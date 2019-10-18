#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <openssl/sha.h>

// functions
std::string hashPassword(std::string password);
std::string getStoredPassword(std::string username)