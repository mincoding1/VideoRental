#pragma once
#include <string>

using std::string;

class Movie {
public:
	static const int CHILDREN = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const string& title, int price_code) : title{ title }, priceCode{ price_code } {}

	int getPriceCode() {
		return priceCode;
	}

	void setPriceCode(int price_code)
	{
		priceCode = price_code;
	}

	string getTitle() const {
		return title;
	}

private:
	string title;
	int priceCode;
};
