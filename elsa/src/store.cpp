#include <vector>
#include <string>
#include <iostream>
#include "store.h"

//implementation of Store

//constructors
Store::Store() {}
Store::Store(std::istream& ist)
{
	//input buffer
	std::string s;

	//checking correct elsa file and version
	std::getline(ist, s);
	if(s != ELSA_COOKIE)
		throw std::runtime_error{"Not an ELSA file"};
	std::getline(ist, s);
	if(s != ELSA_FILE_VERSION)
		throw std::runtime_error{"Unsupported ELSA file version"};

	//loading in customers	
	//stream number of customers
	int numCust = 0;
	ist >> numCust;
	ist.ignore(32767, '\n'); //ignore any text left in the input to leave stream poitner at start of next line

	//iterate over all customers and restore customer data using ist as parameter
	for(int i=0; i<numCust; ++i)
	{		
		customers.push_back(Customer{ist});
	}

	//loading options
	int numOpt = 0;
	ist >> numOpt;
	ist.ignore(32767, '\n');
	for(int i=0; i<numOpt; ++i)
	{
		//check what kind of option it is
		std::getline(ist, s);
		if(s == "ram")
		{
			std::getline(ist, s); //since every option is marked with other whether it's ram or not			
			options.push_back(new Ram{ist});
		}	
		else
		{
			options.push_back(new Options{ist});
		}
	}

	//loading desktops
	int numDesk = 0;
	ist >> numDesk;
	ist.ignore(32767, '\n');
	for(int i=0 ;i<numDesk; ++i)
	{
		desktops.push_back(Desktop{ist});
	}
	//loading orders
	int numOrd = 0;
	ist >> numOrd;
	ist.ignore(32767, '\n');
	for(int i=0; i<numOrd; ++i)
	{
		orders.push_back(Order{ist});
	}
}

//save
void Store::save(std::ostream& ost)
{
	ost << ELSA_COOKIE << "\n";
	ost << ELSA_FILE_VERSION << "\n";
	
	//saving customers		
	//stream out number of customers
	ost << customers.size() << std::endl;
	//iterate over all customers and save each customer's data
	for(auto& c : customers)
	{
		c.save(ost);
	}
	if(!ost) throw std::runtime_error{"Error writing customers to file"};

	//saving options
	ost << options.size() << std::endl;
	for(auto& o : options)
	{
		o->save(ost);
	}
	if(!ost) throw std::runtime_error{"Error writing options to file"};

	//saving desktops
	ost << desktops.size() << std::endl;
	for(auto& d : desktops)
	{
		d.save(ost);
	}		
	if(!ost) throw std::runtime_error{"Error writing desktops to file"};

	//saving orders
	ost << orders.size() << std::endl;
	for(auto& o : orders)
	{
		o.save(ost);
	}
	if(!ost) throw std::runtime_error{"Error writing orders to file"};
}

//customer
//push customer to customers vector
void Store::add_customer(Customer& customer)
{
	customers.push_back(customer);
}
//return size() method of the vector
int Store::num_customers()
{
	return customers.size();
}
//returns a reference to the object in the vector at the index provided as a parameter
Customer& Store::customer(int index)
{
	return customers.at(index);
}

//options
void Store::add_option(Options& option)
{	
	options.push_back(new Options{option});
}
int Store::num_options()
{
	return options.size();
}
Options& Store::option(int index)
{
	return *(options.at(index));
}

//desktop
//pushes new object into vector and returns its index
int Store::new_desktop()
{
	desktops.push_back(Desktop{});
	return num_desktops()-1;
}
//given index of the option to add to the desktop at the provided index
void Store::add_option(int option, int desktop)
{
	(this->desktop(desktop)).add_option(this->option(option));
}
int Store::num_desktops()
{
	return desktops.size();
}
Desktop& Store::desktop(int index)
{
	return desktops.at(index);
}

//orders
int Store::new_order(int customer)
{
	orders.push_back(Order{this->customer(customer)});
	return num_orders()-1;
}
void Store::add_desktop(int desktop, int order)
{
	(this->order(order)).add_product(this->desktop(desktop));
}
int Store::num_orders()
{
	return orders.size();
}
Order& Store::order(int index)
{
	return orders.at(index);
}
