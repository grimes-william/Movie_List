#ifndef _MOVIES_HPP_
#define _MOVIES_HPP_
#include "Movie.hpp"
#include <vector>

class Movies
{
private:
    // Our movie list
    vector<Movie> movies;
public:
    Movies();
    ~Movies();
    
    // Prototypes for bool expressions defined in .cpp file
    bool add_movie(string name, string rating, int watched);
    bool increment_watched(string name);
    bool change_movie_info(string name, string rating, int watched);
       
    void display() const;

};

#endif // _MOVIES_HPP_
