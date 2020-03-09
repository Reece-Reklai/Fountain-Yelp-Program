#ifndef FOUNTAIN_H
#define FOUNTAIN_H
#include "Review.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
class Fountain {
public:
  Fountain(string, string, string); // constructor sets the id, location and
                                    // name
  void printFountain();     // Prints the fountain's id, location, and name
  void addReview(Review *); // Pushes back a pointer to a Review object into the
                            // revList vector
  string getName();    // returns the fountain's name
  string getId();      // returns the fountain's ID number
  void printReviews(); // Prints the content of the fountain's reviews

private:
  vector<Review *>
      revList; // holds a list of pointers to all of a fountain's reviews
  string id, location, name;
};
#endif // FOUNTAIN_H