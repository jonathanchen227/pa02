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
		return a.first > b.first;
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




