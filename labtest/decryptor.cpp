#include <iostream>
#include "authlib.h"
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>


int main(int argc, char **argv){

	if (argc != 2)
	{
		return -1;
	}

	std::string username = argv[1];
	int length = username.length();
	std::time_t currTime = std::time(nullptr);
	std::cout << "it is currently " << currTime << std::endl;
	currTime /= 60;
	currTime = currTime % 60;
	int timeTwo = (currTime % 360);
	int timeThree = currTime*currTime;
	currTime = ((currTime*timeTwo*60)+currTime/currTime+((currTime*currTime)%((3*currTime)/(currTime))))%(timeTwo*12344566*currTime)*33422462;
	timeTwo = timeThree+currTime;
	std::cout << (int)currTime << std::endl;

	std::cout << "std::hexp_a:et/rp_a:et/rp_a:et/rp_a:et/rAAC!&&^;.p_a:et/rp_a:et/rx£afedr&%!¢:643```````¢:643```````¢:643```````¢:643```````p_a:et/r-";

	for (int i = 0; i < length; i++)
	{
		std::cout << "_-_-_-__-_-:" << (int)currTime << "#€@";
	}

	std::cout << "a";

	std::cout.flush();
}