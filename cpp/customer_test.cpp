#include "gmock/gmock.h"
#include "customer.cpp"

TEST(TestCaseName, TestName) {
    Customer customer = Customer(string("Bob"));
    customer.addRental(Rental(Movie(string("Jaws"), Movie::REGULAR), 2));
    customer.addRental(Rental(Movie(string("Golden Eye"), Movie::REGULAR), 3));
    customer.addRental(Rental(Movie(string("Short New"), Movie::NEW_RELEASE), 1));
    customer.addRental(Rental(Movie(string("Long New"), Movie::NEW_RELEASE), 2));
    customer.addRental(Rental(Movie(string("Bambi"), Movie::CHILDRENS), 3));
    customer.addRental(Rental(Movie(string("Toy Story"), Movie::CHILDRENS), 4));

    string expected = "" +
        string("Rental Record for Bob\n") +
        string("\tJaws\t2.0\n") +
        string("\tGolden Eye\t3.5\n") +
        string("\tShort New\t3.0\n") +
        string("\tLong New\t6.0\n") +
        string("\tBambi\t1.5\n") +
        string("\tToy Story\t3.0\n") +
        string("Amount owed is 19.0\n") +
        string("You earned 7 frequent renter points");

    EXPECT_EQ(expected, customer.statement());
}
