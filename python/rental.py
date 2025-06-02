from movie import Movie

class Rental:
    def __init__(self, movie: Movie, days_rented: int):
        self._days_rented = days_rented
        self._movie = movie

    @property
    def days_rented(self) -> int:
        return self._days_rented

    @property
    def movie(self) -> Movie:
        return self._movie
