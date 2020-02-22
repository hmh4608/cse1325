#include <iostream>
#include <string>
#include "taxed.h"

//implementation of the derived class Taxed that is a Product

//constructor and destructor
Taxed::Taxed(std::string name, double cost) : Product(name, cost) {}
Taxed::~Taxed() {}

//methods
/*
*static method that assigns parameter to _tax static attribute
*/
static void Taxed::set_tax_rate(double sales_tax)
{
	_tax = sales_tax;
}
//finally implement pure virtual method from Product price()
/*
*returns double total prices as quantity * cost * (1 + tax)
*/
double Taxed::price() const override
{
	validate();	
	return _quantity * _cost * (1 + _tax);
}
