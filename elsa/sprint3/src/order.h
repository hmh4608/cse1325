#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <vector>
#include "customer.h"
#include "desktop.h"

class Order
{
	public:
	//constructors and destructor
	Order(Customer& customer);
	Order(std::istream& ist);
	~Order();

	void add_product(Desktop& desktop);
	double price();
	save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);

	private:
	Customer& _customer;
	std::vector<Desktop*> _products;
};

#endif
