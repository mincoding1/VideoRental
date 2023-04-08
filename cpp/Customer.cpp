#pragma once

#include <vector>
#include "Movie.cpp"
#include "Rental.cpp"

class Customer {

private:
    std::string name;
    std::vector<Rental> rentals;

    std::string to_string_with_short_precision(double tar)
    {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", tar);
        return std::string(buf);
    }

public:
    Customer(const std::string& name) : name(name) {}

    void addRental(Rental arg)
    {
        rentals.push_back(arg);
    }

    std::string getName() {
        return name;
    }

    std::string statement()
    {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        std::string result = "Rental Record for " + getName() + "\n";

        for (Rental each : rentals) {
            double thisAmount = 0;

            //determine amounts for rental
            switch (each.getMovie().getPriceCode())
            {
            case Movie::REGULAR:
                thisAmount += 2;
                if (each.getDaysRented() > 2)
                    thisAmount += (each.getDaysRented() - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += each.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (each.getDaysRented() > 3)
                    thisAmount += (each.getDaysRented() - 3) * 1.5;
                break;
            }

            // add frequent renter points
            frequentRenterPoints++;
            // add bonus for a two day new release rental
            if (each.getMovie().getPriceCode() == Movie::NEW_RELEASE && each.getDaysRented() > 1) {
                frequentRenterPoints++;
            }

            // show figures for this rental
            result += "\t" + each.getMovie().getTitle() + "\t" + to_string_with_short_precision(thisAmount) + "\n";
            totalAmount += thisAmount;
        }

        // add footer lines
        result += "Amount owed is " + to_string_with_short_precision(totalAmount) + "\n";
        result += "You earned " + std::to_string(frequentRenterPoints) + " frequent renter points";

        return result;
    }
};
