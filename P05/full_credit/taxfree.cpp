#include <string>
#include "taxfree.h"

//class implementation of derived class Taxfree that is a Product

//constructor and destructor
Taxfree::Taxfree(std::string name, double cost) : Product(name, cost) {}
Taxfree::~Taxfree() {}

//methods
/*
*override Product::price()
*returns total prices as quantity * cost
*/
double Taxfree::price() const override
{
	validate();	
	_quantity * cost;
}
