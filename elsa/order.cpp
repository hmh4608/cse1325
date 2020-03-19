#include <iostream>
#include <string>
#include <vector>
#include "order.h"

//implementation of Order

//constructor and destructor
Order::Order(Customer& customer) : _customer{customer} {}
Order::~Order() {}

//methods
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
	ost << "[ Order of Customer " << order._customer << " ]\n";
	
	for(auto& d : order._products)
	{
		ost << d << "\n";
	}

	return ost;
}
