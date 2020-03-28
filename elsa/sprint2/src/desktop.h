#ifndef __DESKTOP_H
#define __DESKTOP_H

#include <iostream>
#include <vector>
#include "options.h"

class Desktop
{
	public:
	void add_option(Options& option);
	double price() const;
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
	
	private:
	std::vector<Options*> options;
};

#endif
