// Winter'24
// Instructor: Diba Mirza
// Student name: 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);


int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies

    string line, movieName;
    double movieRating;
    Movies movieList;    
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            movieList.addMovie(movieName,movieRating);            
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
    }

    movieFile.close();

    if (argc == 2){
            movieList.printAllMovies();
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }
    for ( string a : prefixes ) {
        bool it = movieList.printPrefixMovies(a);        
	if ( it ) {
		cout << endl;
	}
    }
    for ( string a: prefixes) {
                movieList.printHighestRating(a);
    }
    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.

    return 0;
}

/* The time complexity for part 2a of the project is O(logN + MlogM). Because a map is a binary search tree, it will take at most logN iterations to find any node using lowerbound. Next, pushing each prefix value into the priority queue takes at most log(M) which is done M times. The time complexity for part 2b of this project is O(logN + M). logN is already explained while the code iterates through each prefix once for a total of M iterations, resulting in O(logN+M). The runtime for input_20_random.csv is 0.069 seconds, the runtime for input_100_random.csv is 0.046 seconds, the runtime for input_1000_random.csv is 0.049 seconds, and the runtime for input_76920_random.csv is 0.178 seconds. */
/* The space complexity for part 2a of the project is O(logM) because each value with the correct prefix must be added to the priority queue. Meanwhile, the space complexity for part 2b of the project is O(L) where L is the length of the string highestRatedMovie because the only things that are created for that function are the string, the double rating, and the iterator, the length of the string. */
/*I was aiming for a low time complexity. I think that I was successful in doing this because instead of using for ( auto& [name,rating] : moviesList ), I used an iterator search for the first occurence of a prefix and then iterated through the ordered map until the prefix was no longer there. */ 
bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}
