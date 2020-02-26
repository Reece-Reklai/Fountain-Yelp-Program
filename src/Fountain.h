#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Review.h"
#include <map>
#include <string>
using namespace std;
class Fountain {
public:
  string getLocation();

private:
  string location;
  map<string, Review> RevMap;
};
#endif // FOUNTAIN_H