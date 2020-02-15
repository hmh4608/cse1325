#include <iostream>
#include <string>
#include "coin.h"

//function for enum class
std::string to_string(Coin_size size)
{
	switch(size)
	{
		case Coin_size::PENNY : return "penny";
		case Coin_size::NICKEL : return "nickel";
		case Coin_size::DIME : return "dime";
		case Coin_size::QUARTER : return "quarter";
	}
}

//constructors
Coin::Coin(Coin_size size, Year year) : _size{size}, _year{year}, _notes{new std::string{NULL}} {}
Coin::Coin() : Coin{Coin_size::PENNY, 1792} {}
Coin::Coin(const Coin& rhs) : Coin{rhs._size, rhs._year} {}
Coin::~Coin() { delete _notes; } //destructor

//methods
void Coin::add_note(std::string s)
{
	//checks if notes are blank
	if(!_notes)
	{	
		_notes = new std::string{s};
	}	
	else
	{
		*_notes += s;
	}
}

//operator overloading
//copy assignment operator
Coin& Coin::operator=(const Coin& rhs)
{
	return *this;
}
std::ostream& operator<<(std::ostream& ost, const Coin& coin)
{
	//year + space
	ost << std::to_string(coin._year) + " ";
	
	//checking it is a type of coin or not
	if(coin._size != Coin_size::PENNY && coin._size != Coin_size::NICKEL && coin._size != Coin_size::DIME && coin._size != Coin_size::QUARTER)
	{
		throw std::runtime_error{"Not a coin"};
	}
	else
	{
		ost << to_string(coin._size) + "\n";
	}

	if(coin._notes)
	{
		ost << *(coin._notes) << std::endl;
	}
	
	return ost;
}
