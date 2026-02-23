#include "movies.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Movies::addMovie(string name, double rating) {
	movieList[name] = rating;
} 
void Movies::printAllMovies() {
	for ( auto&[name,rating] : movieList ) {
		std::cout << name << ", " << rating << std::endl;
	}
}
priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> Movies::createPriorityQueue(string prefix) {
	int length = prefix.length();
        priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> pq;
        for ( auto&[name,rating] : movieList ) {
                if (name.substr(0,length).compare(prefix)==0 ) {
                    pair<string,double> myPair = {name,rating};
                    pq.push(myPair);
                }
        }
	return pq;
}
void Movies::printPrefixMovies(string prefix) {
	priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> pq = createPriorityQueue(prefix);
	if ( pq.empty() ) {
                cout<< "No movies found with prefix " << prefix << endl;
        }
	while ( !pq.empty() ) {
		cout << (pq.top()).first << ", " << (pq.top()).second << endl;
		pq.pop();
	}
}


void Movies::printHighestRating( string prefix ) {
	string highestRatedMovie = "";
	double highestRating = 0.0;
	int length = prefix.length();
	for ( auto&[name,rating] : movieList ) {
		if ( name.substr(0,length).compare(prefix)==0 ) {
			if ( rating < highestRating ) { continue; }
			if ( rating == highestRating ) {
				if ( name > highestRatedMovie ) {
					highestRating = rating;
					highestRatedMovie = name;
				}

			}
			if( rating > highestRating ) {
				highestRating = rating;
				highestRatedMovie = name;
			}
		    }
		}
	if ( highestRatedMovie == "" ) {
		cout << "No movies found with prefix " << prefix << endl;
	}
	else {
				
	cout << "Best movie with prefix " << prefix << " is " << highestRatedMovie << " with rating " << highestRating << endl;
	}
}

