#include "movie.cpp";

class Rental {
public:
	Rental(const Movie &movie, int days_rented) : movie{ movie }, daysRented{ days_rented } {	}

	int getDaysRented() const {
		return daysRented;
	}

 	Movie getMovie() {
		return movie;
	}

private:
	Movie movie;
	int daysRented;
};
