#include <iostream>
#include "authlib.h"
#include <openssl/sha.h>
#include "login.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

//main funtion from where the progam runs
int main()
{
	bool auth = promptUser();
	if (auth)
		authenticated("user");
	else
		rejected("user");
}

//prompts user for their username and password stores as string variables, then compareHashedPassestests if the password entered by theuser matches
//the hashed password for the username in the file
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


//this function hashes the password that the user has entered using SHA256
std::string hashPassword(std::string password)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];		//creates char variable of hash
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, password.c_str(), password.size());
	SHA256_Final(hash, &sha256);

	//writes the hashed password into the string stream
	std::stringstream ss;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}
	//returns finalised hash
	return ss.str();
}


//this funtion will get the password and username that the user has entered
std::string getHashPass(std::string username)
{
	std::ifstream infile("pwdb.txt"); //get the password file in the file stream
	int offset;// offset of the of the username and password in file line
	std::string hashWord; //variable to store hashed password from file
	username.append(":");//delimiter for line
	std::string line; //variable sting for the current line being red from file

	while (!infile.eof())
	{
		getline(infile, line); ////get the line from file
		if ((offset = line.find(username, 0)) != std::string::npos) //check if usrname matches and then fine the colon
		{
			hashWord = line.substr(username.length(), 64); //extreact the hashed password from file
		}
	}

	infile.close(); //close file
	return hashWord;// return password form file
}

// this is a function to compare the hashed password from the database to the hashed password that the user has enter
bool compareHashedPasses(std::string userPass, std::string storedPass)
{
	if (userPass == storedPass)
	{
		return true; // return true if password match
	}
	else
	{
		return false;
	}
}
