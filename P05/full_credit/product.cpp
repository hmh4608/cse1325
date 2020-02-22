#include <iostream>
#include <string>
#include <iomanip>
#include "product.h"

//implementations of Product

//constructor and destructor
Product::Product(std::string name, double cost) : _name{name}, _cost{cost}, _quantity{0} { if(_cost < 0) throw std::runtime_error("Cost is Negative"); }
Product::~Product() {}

//method(s)

/*
*set method assigns quantity parameter to _quantity attribute
*/
void Product::set_quantity(int quantity)
{	
	_quantity = quantity;
}
/*
*getter method for quantity
*/
int Product::get_quantity() const
{
	return _quantity;
}
/*
*validates attributes
*/
void Product::validate() const
{
	if(_name == "") throw std::runtime_error("Not a product, empty string");
	if(_cost < 0) throw std::runtime_error("Cost is a negative number");
	if(_quantity < 0) throw std::runtime_error("Quantity is negative");
}

//since price is pure virtual there is no implementation for it in class Product, will be overridden in derived classes Taxed and Taxfree

//operator<< overlaod
std::ostream& operator<<(std::ostream& ost, const Product& product)
{	
	product.validate();	
	if(product._quantity == 0)
	{
		//setprecision + fixed sets number of digits after decimal point		
		ost << product._name + " ($" << std::setprecision(2) << std::fixed << product._cost << ")";
	}
	else if(product._quantity > 0)
	{
		ost << product._name + " (" << product._quantity << " @ " << std::setprecision(2) << std::fixed << product._cost << ")";
	}
	return ost;
}
