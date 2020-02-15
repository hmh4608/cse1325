#ifndef __COIN_H
#define __COIN_H

#include <iostream>
#include <string>

enum class Coin_size{ PENNY, NICKEL, DIME, QUARTER };

class Coin
{
	typedef int Year;	

	public:
	//constructors-destructor	
	Coin();
	Coin(Coin_size size, Year year);
	Coin(const Coin& rhs);
	~Coin();
	
	//methods
	void add_note(std::string s);
	
	//operator overload	
	Coin& operator=(const Coin& rhs);
	friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
	friend std::istream& operator>>(std::istream& ist, Coin& coin);

	private:
	Year _year;
	Coin_size _size;
	std::string* _notes;
};

#endif
