#include <map>
#include <string>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Movies {
private:
map<string,double> movieList;
public:
struct Rank {
   bool operator() (pair<string,double> a, pair<string,double> b) {
        if (a.second == b.second ) {
		string string1 = a.first;
		string string2 = b.first;
		size_t length = min ( string1.size(), string2.size() );
		for ( size_t i = 0 ; i < length; i ++) {
			if ( string1[i] != string2[i] ) {
				if ( string1[i]==' ') return true;
				if ( string2[i]==' ') return false;
				return string1[i] < string2[i];
			}
		}
		return string1.size() < string2.size();
	}
        else { return a.second < b.second ;}
}
};
Movies() {
}
priority_queue<pair<string,double>, vector<pair<string,double>>,Rank> createPriorityQueue(string prefix);

void addMovie(string name, double rating);

void printAllMovies();

bool printPrefixMovies(string prefix);

void printHighestRating(string prefix);
};




