#include <iostream>
#include "authlib.h"
#include <openssl/sha.h>
#include "login.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

int main()
{
	bool auth = promptUser();
	if (auth)
		authenticated("user");
	else
		rejected("user");
}

//prompts user for their username and password
bool promptUser()
{
	std::string userName;
	std::string password;
	std::cout << "Please enter your username: " << std::endl;
	std::cin >> userName;
	std::cin.clear();
	std::cout << "PLease enter your password: " << std::endl;
	std::cin >> password;

	std::string userPass = hashPassword(password);
	std::string storedPass = getHashPass(userName);

	if (compareHashedPasses(userPass, storedPass) == true)
	{
		std::cout << "they match bitch";
		return true;
	}
	else
	{
		std::cout << "a460c62eb16389cd9f623f";
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
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
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

	while (!infile.eof())
	{
		getline(infile, line);
		if ((offset = line.find(username, 0)) != std::string::npos)
		{
			hashWord = line.substr(username.length(), 64);
		}
	}

	infile.close();
	return hashWord;
}

bool compareHashedPasses(std::string userPass, std::string storedPass)
{
	if (userPass == storedPass)
	{
		return true;
	}
	else
	{
		return false;
	}
}
