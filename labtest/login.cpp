#include "authlib.h"
#include "login.h"

int main()
{
	std::string username, password;
	bool auth = false;
	do
	{
		// user input
		std::cout << "Please enter your username: " << std::endl;
		std::cin >> username;
		std::cout << "Please enter your password: " << std::endl;
		std::cin >> password;

		// check if valid and output result
		auth = (hashPassword(password) == getStoredPassword(username));
		auth ? authenticated(username) : rejected(username);

	} while (!auth);
}

// hashes password using openssl & SHA256 -> source: ..................................
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

// retrieves stored password (hash) from pwdb.txt
std::string getStoredPassword(std::string username)
{
	std::string storedPassword, line;

	// check if username is at start of a line in pwdb.txt
	std::ifstream infile("pwdb.txt");
	while (!infile.eof() && getline(infile, line))
	{
		if (line.find(username, 0) == 0)
		{
			storedPassword = line.substr(username.length() + 1, (line.length() - username.length() + 1));
		}
	}
	infile.close();
	return storedPassword;
}
