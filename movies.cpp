#include "movies.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

void Movies::addMovie(string name, double rating) {
	movieList[name] = rating;
} 
void Movies::printAllMovies() {
	auto iterator = movieList.begin();
        while ( iterator != movieList.end() ) {
                    cout << iterator->first << ", " << iterator->second << endl;
                    iterator++;
        }
}
priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> Movies::createPriorityQueue(string prefix) {
        priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> pq;
        auto iterator = movieList.lower_bound(prefix);
	while ( iterator != movieList.end() && iterator->first.compare(0,prefix.length(),prefix) == 0 ) {
                    pair<string,double> myPair = {iterator->first,iterator->second};
                    pq.push(myPair);
	            iterator++;
        }
	return pq;
}
bool Movies::printPrefixMovies(string prefix) {
	priority_queue<pair<string,double>, vector<pair<string,double>>,Movies::Rank> pq = createPriorityQueue(prefix);
	if ( pq.empty() ) {
                cout<< "No movies found with prefix " << prefix << "\n";
		return false;
        }
	while ( !pq.empty() ) {
		cout << (pq.top()).first << ", " << (pq.top()).second << endl;
		
		pq.pop();
	
	}
	return true;
}


void Movies::printHighestRating( string prefix ) {
	string highestRatedMovie = "";
	double highestRating = -1;
	int length = prefix.length();
	auto iterator = movieList.lower_bound(prefix);
        while ( iterator != movieList.end() && iterator->first.compare(0,prefix.length(),prefix) == 0 ) {
                     if ( iterator->second < highestRating ) { 
				iterator++;
				continue;
			 }
                        if ( iterator->second == highestRating ) {
                                if ( iterator->first < highestRatedMovie ) {
                                        highestRating = iterator->second;
                                        highestRatedMovie = iterator->first;
                                }

                        }
                        if( iterator->second > highestRating || highestRating == -1 ) {
                                highestRating = iterator->second;
                                highestRatedMovie = iterator->first;
                        }
                    iterator++;
        }
	if ( highestRatedMovie == "" ) {
	}
	else {
				
	cout << "Best movie with prefix " << prefix << " is " << highestRatedMovie << " with rating " << highestRating << endl;
	}
}

