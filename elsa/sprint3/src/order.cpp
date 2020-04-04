#include <iostream>
#include <string>
#include <vector>
#include "order.h"

//implementation of Order

//constructor and destructor
Order::Order(Customer& customer) : _customer{&customer} {}
//load
Order::Order(std::istream& ist)
{
	//load in customer data	
	_customer = new Customer{ist};

	//load in product data
	int numProd = 0;
	ist >> numProd;
	ist.ignore(32767, '\n');
	
	for(int i=0; i<numProd; ++i)
	{
		_products.push_back(new Desktop{ist});
	}
	
}
Order::~Order() {}

//methods
//save
void Order::save(std::ostream& ost)
{
	//save customer data
	_customer->save(ost);

	ost << _products.size() << std::endl; //save number of products in product vector

	//save data of products
	for(auto p : _products)
	{
		p->save(ost);
	}
}
//adds a desktop to the order
void Order::add_product(Desktop& desktop)
{
	_products.push_back(&desktop);
}
//sums the Desktop product prices from _products vector
double Order::price()
{
	double sum = 0;
	for(auto& d : _products)
	{
		sum += d->price();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order)
{
	ost << "Order of Customer " << *(order._customer) << "\n";
	
	for(auto& d : order._products)
	{
		ost << "     " << *d << "\n";
	}

	return ost;
}
