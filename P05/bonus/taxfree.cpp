#include <string>
#include "taxfree.h"
#include "logger.h"

//class implementation of derived class Taxfree that is a Product

//constructor and destructor
Taxfree::Taxfree(std::string name, double cost) : Product(name, cost) { LOG("Taxfree(std::string name, double cost)"); }
Taxfree::~Taxfree() { LOG("~Taxfree()"); }

//methods
/*
*override Product::price()
*returns total prices as quantity * cost
*/
double Taxfree::price() const
{	
	return _quantity * _cost;
}
