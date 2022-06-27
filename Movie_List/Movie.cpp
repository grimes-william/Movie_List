#include "Movie.hpp"

// Constructor 3-args
Movie::Movie(string name, string rating, int watched) 
    :   name(name), rating(rating), watched(watched)   {}

// Copy constructor
Movie::Movie(const Movie &source)
    :   Movie{source.name, source.rating, source.watched}   {}

// Default destructor
Movie::~Movie() {}

void Movie::display() const {
    cout << "\nMovie Name: " << name << endl;
    cout << "Movie Rating: " << rating << endl;
    cout << "Times Watched: " << watched << endl;
}