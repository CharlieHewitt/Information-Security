#include <iostream>
#include <string>

void authenticated(std::string u); 
void rejected(std::string u);
bool promptUser();
std::string hashPassword(std::string);
std::string getHashPass(std::string);
bool compareHashedPasses(std::string, std::string);