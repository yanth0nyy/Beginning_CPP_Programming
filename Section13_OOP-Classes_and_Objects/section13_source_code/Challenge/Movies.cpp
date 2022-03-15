/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // for (Movie movie : movies) {
    for (const Movie &movie : movies) {
        if (movie.get_name() == name)
            return false;
    }
    
    // >> If movie isn't found in the movies vector, code comes here

    // Create a movie object to push back into the movies vector
    Movie temporary {name, rating, watched};
    movies.push_back(temporary);
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
    for (Movie &movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    // >> If movie isn't found in movies vector, cannot increment 
    return false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
    if (movies.size() == 0) {
        std::cout <<  "Sorry, no movies to display" << std::endl;
    } else {
        std::cout << "\n===================================" << std::endl;
        for (const Movie &movie : movies)
            movie.display();
        std::cout << "\n===================================" << std::endl;
    }
}