#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Review.h"
#include <map>
#include <string>
using namespace std;
class Fountain {
public:
private:
  string location;
  int x, y;
  map<string, Review> *RevMap;
};
#endif // FOUNTAIN_H