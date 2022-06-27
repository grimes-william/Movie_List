#include "Movies.hpp"

// Default constructor
Movies::Movies()    {}

// Default destructor
Movies::~Movies()   {}

// Is the movie in the list?  If so, return false, if not, add it and return true
bool Movies::add_movie(string name, string rating, int watched) {
    for (const Movie &movie : movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
}

// Is the movie in the list?  If so, incremement the watch by 1 and return true, if not, return false
bool Movies::increment_watched(string name) {
    for (Movie &movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}


bool Movies::change_movie_info(string name, string rating, int watched) {
    for (Movie &movie : movies) {
        if (movie.get_name() == name) {
            movie.set_name(name);
            movie.set_rating(rating);
            movie.set_watched(watched);
            return true;
        }
    }
    return false;
}

// Display error message if list empty, output movies if list is NOT empty
void Movies::display() const {
    if (movies.size() == 0) {
        cout << "\nThere are no movies to display. " << endl;
    } else {
        cout << "\n==============================" << endl;
        for (const Movie &movie : movies) {
            movie.display();
        }
        cout << "\n==============================" << endl;
    }
}