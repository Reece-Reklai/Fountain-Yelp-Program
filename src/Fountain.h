#ifndef SRC_FOUNTAIN_H_
#define SRC_FOUNTAIN_H_

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
#endif // SRC_FOUNTAIN_H_