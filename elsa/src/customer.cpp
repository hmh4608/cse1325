#include <iostream>
#include <string>
#include "customer.h"

//implementation of Customer

//constructors
Customer::Customer(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} {}
Customer::Customer(std::istream& ist)
{
	ist >> _name >> _phone >> _email;
}

//save method
void Customer::save(std::ostream& ost)
{
	ost << _name << std::endl;
	ost << _phone << std::endl;
	ost << _email << std::endl;
}

//operator<< overload
std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
	//validation
	if(customer._name == "") throw std::runtime_error("Not a name, empty string");
	if(customer._phone == "") throw std::runtime_error("Not a phone number, empty string");
	if(customer._email == "") throw std::runtime_error("Not an email, empty string");

	ost << customer._name + " / " + customer._phone + " / " + customer._email;

	return ost;
}
