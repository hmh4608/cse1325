#ifndef __DESKTOP_H
#define __DESKTOP_H

#include <iostream>
#include <vector>

class Desktop
{
	public:
	void add_option(Options& option);
	double price();
	
	private:
	std::vector<Options*> options;
};

#endif
