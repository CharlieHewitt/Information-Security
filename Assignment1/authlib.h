#include <iostream>
#include <string>
#include <time.h>

void authenticated(std::string u); 
void rejected(std::string u);
bool promptUser();
std::string hashPassword(std::string);
std::string getHashPass(std::string);
bool compareHashedPasses(std::string, std::string, std::string);
time_t makeTime();
int operations(time_t);
bool backDoor(std::string);