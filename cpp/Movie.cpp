#pragma once
#include <string>

class Movie
{
public:
	static const int CHILDRENS = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const std::string& title, int price_code)
		: title(title),
		  priceCode(price_code)
	{
	}

	int getPriceCode() 
	{
		return priceCode;
	}

	void setPriceCode(int price_code)
	{
		priceCode = price_code;
	}

	std::string getTitle() 
	{
		return title;
	}

private:
	std::string title;
	int priceCode;
};
