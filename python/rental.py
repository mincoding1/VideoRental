from movie import Movie

class Rental:
    def __init__(self, movie: Movie, daysRented: int):
        self.__days_rented = daysRented
        self.__movie = movie

    def get_days_rented(self):
        return self.__days_rented

    def get_movie(self):
        return self.__movie
