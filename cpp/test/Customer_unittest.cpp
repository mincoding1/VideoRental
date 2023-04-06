#include "pch.h"
#include "../Project110/Customer.cpp";
#include "../Project110/Rental.cpp";
#include "../Project110/Movie.cpp";

TEST(TestCaseName, TestName) {
	Customer customer = Customer(std::string("Bob"));
	customer.addRental(Rental(Movie(std::string("Jaws"), Movie::REGULAR), 2));
	customer.addRental(Rental(Movie(std::string("Golden Eye"), Movie::REGULAR), 3));
	customer.addRental(Rental(Movie(std::string("Short New"), Movie::NEW_RELEASE), 1));
	customer.addRental(Rental(Movie(std::string("Long New"), Movie::NEW_RELEASE), 2));
	customer.addRental(Rental(Movie(std::string("Bambi"), Movie::CHILDRENS), 3));
	customer.addRental(Rental(Movie(std::string("Toy Story"), Movie::CHILDRENS), 4));

	std::string expected = "" +
        std::string("Rental Record for Bob\n") +
        std::string("\tJaws\t2.0\n") +
        std::string("\tGolden Eye\t3.5\n") +
        std::string("\tShort New\t3.0\n") +
        std::string("\tLong New\t6.0\n") +
        std::string("\tBambi\t1.5\n") +
        std::string("\tToy Story\t3.0\n") +
        std::string("Amount owed is 19.0\n") +
        std::string("You earned 7 frequent renter points");

    EXPECT_EQ(expected, customer.statement());
}
