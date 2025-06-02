import pytest
from customer import Customer, Rental, Movie

def test_sample():
    customer = Customer("Bob")
    customer.add_rental(Rental(Movie("Jaws", Movie.REGULAR), 2))
    customer.add_rental(Rental(Movie("Golden Eye", Movie.REGULAR), 3))
    customer.add_rental(Rental(Movie("Short New", Movie.NEW_RELEASE), 1))
    customer.add_rental(Rental(Movie("Long New", Movie.NEW_RELEASE), 2))
    customer.add_rental(Rental(Movie("Bambi", Movie.CHILDREN), 3))
    customer.add_rental(Rental(Movie("Toy Story", Movie.CHILDREN), 4))

    expected = (
        "Rental Record for Bob\n"
        "\tJaws\t"       "2.0\n"
        "\tGolden Eye\t" "3.5\n"
        "\tShort New\t"  "3.0\n"
        "\tLong New\t"   "6.0\n"
        "\tBambi\t"      "1.5\n"
        "\tToy Story\t"  "3.0\n"
        "Amount owed is 19.0\n"
        "You earned 7 frequent renter points"
    )

    assert customer.statement() == expected
