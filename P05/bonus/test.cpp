#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "product.h"
#include "taxed.h"
#include "taxfree.h"

//2nd main for regression testing

int main()
{
	int result = 0; //set to non-zero code if failed, shows how many tests failed at the end
	int test_vector = 1; //bitmask for calculating codes	

	//Taxed and Taxfree products for testing
	Taxed ICE_CREAM{"Ice Cream", 4.95};
	Taxfree COFFEE{"Coffee", 7.49};

	Taxed::set_tax_rate(0.0825); //sets tax rate	

	//TEST #1 - seeing if the attributes were properly constructed and operator<< works for Taxed item with quantity 0
	std::string expected = "Ice Cream ($4.95)";
	std::ostringstream actual; //for streaming into a string
	actual << ICE_CREAM;

	if(expected != actual.str())
	{
		std::cerr << "Not properly contructed Taxed item and streamed out" << std::endl;
		std::cerr << "	Expected: \"" << expected << '"' << std::endl;
		std::cerr << "	Actual: \"" << actual.str() << '"' << std::endl;
		result |= test_vector;
	}
	test_vector <<= 1; //bitwise shift

	//TEST #2 - seeing if price was correctly found with nonzero quantity set for Taxed item
	ICE_CREAM.set_quantity(2);
	double expected_price = 10.72;
	double actual_price = ICE_CREAM.price();
	//round off actual_price to 2 decimal points
	actual_price = (int)(actual_price * 100 + 0.5);
	actual_price = (double)(actual_price/100);

	if(expected_price != actual_price)
	{
		std::cerr << "Taxed price is incorrectly calculated" << std::endl;
		std::cerr << "	Expected: " << std::setprecision(2) << std::fixed <<  expected_price << std::endl;
		std::cerr << "	Actual: " << std::setprecision(2) << std::fixed << actual_price << std::endl;
		result |= test_vector;
	}
	test_vector <<= 1;

	//TEST #3 - seeing if the attributes were properly constructed and operator<< works for Taxfree item with quantity 0
	expected = "Coffee ($7.49)";
	actual.str(""); //resetting the string to be empty
	actual << COFFEE;

	if(expected != actual.str())
	{
		std::cerr << "Not properly constructed and streamed out Taxfree item" << std::endl;
		std::cerr << "	Expected: \"" << expected << '"' << std::endl;
		std::cerr << "	Actual: \"" << actual.str() << '"' << std::endl;
		result |= test_vector;
	}
	test_vector <<= 1;

	//TEST #4 - seeing if price was correctly found with nonzero quantity set for Taxfree item
	COFFEE.set_quantity(5);
	expected_price = 37.45;
	actual_price = COFFEE.price();
	
	if(expected_price != actual_price)
	{
		std::cerr << "Taxfree total price incorrectly calculated" << std::endl;
		std::cerr << "	Expected: " << std::setprecision(2) << std::fixed << expected_price << std::endl;
		std::cerr << "	Actual: " << std::setprecision(2) << std::fixed << actual_price << std::endl;
		result |= test_vector;
	}
	test_vector <<= 1;

	if(result) //print out which test failed
	{
		std::cerr << "FAIL: Code " << result << std::endl;
	}

	return result;
}
