#include <string>
#include <iostream>
using namespace std;

int main()
{
	//declare string var
	string name;
	
	//ask user for input	
	cout << "Please enter your name (including spaces): ";
	/*cin reads whitespace-separated word
	getline consumes \n */
		
	getline(cin, name);
	
	cout << "Hello, " << name << endl;

	return 0;
}
