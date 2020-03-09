#ifndef FOUNTAIN_H
#define FOUNTAIN_H
#include <vector>
#include "Review.h"
#include <map>
#include <string>
using namespace std;
class Fountain {
public:
Fountain(string ,string,string);
void printFountain();
void addReview(Review*);
string getName();
string getId();

private:
vector<Review*> revList;//holds a list of pointers to all of a fountain's reviews
string id,location,name;
};
#endif // FOUNTAIN_H