#ifndef _MOVIE_HPP_
#define _MOVIE_HPP_
#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
    string name;
    string rating;
    int watched;
    
public:
    // Constructor 3-args
    Movie(string name, string rating, int watched);
    
    //Copy constructor
    Movie(const Movie &source);
    
    // Default deconstructor
    ~Movie();
    
    // Set/Get movie name
    void set_name(string name) {
        this->name = name;
    }
    
    string get_name() const {
        return name;
    }
    
    // Set/Get movie rating
    void set_rating(string rating) {
        this->rating = rating;
    }
    
    string get_rating() const {
        return rating;
    }
    
    // Set/Get times watched
    void set_watched(int watched) {
        this->watched = watched;
    }
    
    int get_watched() const {
        return watched;
    }

    void increment_watched() {
        ++watched;
    }
    
    void display() const;

};

#endif // _MOVIE_HPP_
