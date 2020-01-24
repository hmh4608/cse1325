#include <iostream>

int main()
{
	//extreme bonus

	/*
	*currently not checking if the environment variable is found
	*getenv() returns the environment variable that matches the category/parameter passed with the environment list and null if not found
	*environment variable - dynamic "object"; helps programs where to find user settings and directories, etc
	*/
	const char* name = std::getenv("USERNAME");

	//outputs
	std::cout << "Hello, " << name << std::endl;
	
	return 0;
}
