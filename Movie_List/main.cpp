#include <iostream>
#include <string>
#include "Movies.hpp"

using namespace std;

// Increment test and output, Movies.cpp
void increment_watched(Movies &movies, string name) {
    if (movies.increment_watched(name)) {
        cout << "\nOne additional view has been added to " << name << "!" << endl;
    } else {
        cout << "\n" << name << " is not found" << endl;
    }
}

// Add Movie test and output, Movies.cpp
void add_movie(Movies &movies, string name, string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        cout << "\n" << name << " has been added!" << endl;
    } else {
        cout << "\n" << name << " is already in the list!" << endl;
    }
}

// Change movie test and output, Movies.cpp
void change_movie_info(Movies &movies, string name, string rating, int watched) {
    if (movies.change_movie_info(name, rating, watched)) {
        cout << "\n" << name << " information updated!" << endl;
    } else {
        cout << "\n" << name << " is not on the list!" << endl;
    }
}

// Main menu
void display_menu() {
    cout << "\n===============================" << endl;
    cout << "1 - Display your movies" << endl;
    cout << "2 - Add a movie" << endl;
    cout << "3 - Change movie information" << endl;
    cout << "4 - Add a watch to a movie" << endl;
    cout << "5 - Quit" << endl;
    cout << "===============================" << endl;
    cout << "Selection: ";
}

// Rating specific menu
void display_ratings() {
    cout << "\n===============================" << endl;
    cout << "1 - G" << endl;
    cout << "2 - PG" << endl;
    cout << "3 - PG-13" << endl;
    cout << "4 - R" << endl;
    cout << "5 - NC-17" << endl;
    cout << "6 - Enter custom rating" << endl;
    cout << "===============================" << endl;
    cout << "Selection: ";
}

// Prompts user to select rating...gives examples
string choose_rating() {
    string rating;
    int selection;
    bool valid_choice = false;
    
    cout << "\nPlease choose a rating for the following options: " << endl;
    
    while (!valid_choice) {
        display_ratings();
        cin >> selection;
        
        switch(selection) {
            case 1:
                rating = "G";
                valid_choice = true;
                return rating;
                
            case 2:
                rating = "PG";
                valid_choice = true;
                return rating;
                
            case 3:
                rating = "PG-13";
                valid_choice = true;
                return rating;
                
            case 4:
                rating = "R";
                valid_choice = true;
                return rating;
                
            case 5:
                rating = "NC-17";
                valid_choice = true;
                return rating;
                
            case 6:
                cout << "Please enter the rating: ";
                cin >> rating;
                valid_choice = true;
                return rating;
            
            default:
                cout << "\nPlease enter a valid response:" << endl;
        }
    }
    
}

int main() {
    
    Movies my_movies;  // My list of movies!
    bool quit = false;
    int selection {0};
    
    cout << "Welcome!  Use the following menu to determine how you'd like to proceed:\n" << endl;
    
    while (!quit) {
        string name;
        string rating;
        int watched;
        
        display_menu();
        cin >> selection;
        
        switch(selection) {
            case 1:
                my_movies.display();
                break;
                
            case 2:
                cout << "\nMovie name: ";
                cin >> name;
                
                rating = choose_rating();
                
                cout << "\nTimes watched: ";
                cin >> watched;
                
                add_movie(my_movies, name, rating, watched);
                break;
            
            case 3:
                cout << "\nEnter the updated information:" << endl;
                
                cout << "\nMovie name: ";
                cin >> name;
                
                rating = choose_rating();
                
                cout << "\nTimes watched: ";
                cin >> watched;
                
                change_movie_info(my_movies, name, rating, watched);
                break;
                
            case 4:
                cout << "\nWhat movie would you like to add a watch to? ";
                cin >> name;
                
                increment_watched(my_movies, name);
                break;
                
            case 5:
                cout << "\nThanks for using this movie app!" << endl;
                quit = true;
                break;
                
            default:
                cout << "\nInvalid selection, please select an available option" << endl;
            
        }
    }
    
    return 0;
}