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
Coin::Coin(Coin_size size, Year year) : _size{size}, _year{year}, _notes{nullptr} {}
Coin::Coin() : Coin{Coin_size::PENNY, 1792} {}
Coin::Coin(const Coin& rhs) : _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}} {}
Coin::~Coin() { delete _notes; } //destructor

//methods
void Coin::add_note(std::string s)
{
	//checks if notes are blank/nullptr
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
	if(this != &rhs)
	{
		_size = rhs._size;
		_year = rhs._year;
		_notes = new std::string{*(rhs._notes)};
	}

	return *this;
}
std::ostream& operator<<(std::ostream& ost, const Coin& coin)
{
	//checking it is a type of coin or not and whether it is a legitimate coin made after 1792
	if(coin._size != Coin_size::PENNY && coin._size != Coin_size::NICKEL && coin._size != Coin_size::DIME && coin._size != Coin_size::QUARTER || coin._year < 1792)
	{
		throw std::runtime_error{"Not a coin"};
	}
	else
	{
		ost << std::to_string(coin._year) + " " + to_string(coin._size) + "\n";
	}

	if(coin._notes)
	{
		ost << *(coin._notes) << std::endl;
	}
	
	return ost;
}
