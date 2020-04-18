#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "desktop.h"

//implementation of Desktop

//loading constructor
Desktop::Desktop() {}
Desktop::Desktop(std::istream& ist)
{
	int numOpt = 0;
	ist >> numOpt;
	ist.ignore(32767, '\n');

	//iterate over each option
	for(int i=0; i<numOpt; ++i)
	{
		options.push_back(new Options{ist});
	}
}

//methods
//save
void Desktop::save(std::ostream& ost)
{
	ost << options.size() << std::endl;
	for(auto o : options)
	{
		o->save(ost);
	}
}

//adds Option ref to vector options
void Desktop::add_option(Options& option)
{
	options.push_back(&option);
}
//returns sum of option costs
double Desktop::price() const
{
	double sum = 0;	
	for(auto& o : options)
	{
		sum += o->cost();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
	ost << "Desktop ($" << desktop.price() << std::fixed << std::setprecision(2) << ") includes\n";
	for(auto& o : desktop.options)
	{
		ost << "     " << *o << "\n";
	}	
	return ost;
}
