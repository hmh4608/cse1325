#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <vector>
#include "customer.h"
#include "desktop.h"

class Order
{
	public:
	Order(Customer& customer);
	~Order();
	void add_product(Desktop& desktop);
	double price();
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);

	private:
	Customer& _customer;
	std::vector<Desktop*> _products;
};

#endif
