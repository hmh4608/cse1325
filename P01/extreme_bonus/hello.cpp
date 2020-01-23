#include <iostream>

int main()
{
	//extreme bonus

	/*from cppreference
	*currently not checking if the environment variable is found
	*getenv() returns the matched environment list variable and null if not found*/
	const char* userName = std::getenv("USERNAME");

	//outputs
	std::cout << "Hello, " << userName << std::endl;
	
	return 0;
}
