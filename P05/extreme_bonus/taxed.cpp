#include <iostream>
#include <string>
#include "taxed.h"
#include "logger.h"

//implementation of the derived class Taxed that is a Product

double Taxed::_tax = 0;

//constructor and destructor
Taxed::Taxed(std::string name, double cost) : Product(name, cost) { LOG("Taxed(std::string name, double cost)"); }
Taxed::~Taxed() { LOG("~Taxed()"); }

//methods
/*
*static method that assigns parameter to _tax static attribute
*/
void Taxed::set_tax_rate(double sales_tax)
{
	_tax = sales_tax;
}
//finally implement pure virtual method from Product price()
/*
*returns double total prices as quantity * cost * (1 + tax)
*/
double Taxed::price() const
{
	validate();	
	return _quantity * _cost * (1 + _tax);
}
Product* Taxed::clone() const
{
	return new Taxed{_name, _cost};
}
