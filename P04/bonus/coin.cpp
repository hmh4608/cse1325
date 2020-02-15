#include <iostream>
#include <string>
#include "coin.h"
#include "logger.h"

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
Coin::Coin(Coin_size size, Year year) : _size{size}, _year{year}, _notes{nullptr} { LOG("Coin::Coin"); }
Coin::Coin() : Coin{Coin_size::PENNY, 1792} {}
Coin::Coin(const Coin& rhs) : _size{rhs._size}, _year{rhs._year}, _notes{new std::string{*(rhs._notes)}} { LOG("Coin::Coin copy constructor"); }
Coin::~Coin() { LOG("Coin::~Coin"); delete _notes; } //destructor

//methods
/*
*adds notes to the coin
*/
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
	LOG("Coin::operator=");
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
		ost << *(coin._notes);
	}
	
	return ost;
}
std::istream& operator>>(std::istream& ist, Coin& coin)
{
	std::string coin_sz, newln, notes;

	//>> skips whitespace
	ist >> coin._year >> coin_sz >> newln >> notes;

	//convert to all lowercase letters if needed
	for(int i = 0; i<coin_sz.length(); ++i)
	{
		if(coin_sz[i] >= 'A' && coin_sz[i] <= 'Z')
			coin_sz[i] += 32;
	}

	//change size of coin based on string input
	if(coin_sz == "penny")
		coin._size = Coin_size::PENNY;
	else if(coin_sz == "nickel")
		coin._size = Coin_size::NICKEL;
	else if(coin_sz == "dime")
		coin._size = Coin_size::DIME;
	else if(coin_sz == "quarter")
		coin._size = Coin_size::QUARTER;
	else
		throw std::runtime_error{"Not a coin"};

	if(notes != "" || notes != "\n")
	{
		coin.addnote(notes);
	}

	return ist;
}
