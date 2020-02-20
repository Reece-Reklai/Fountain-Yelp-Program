#include "Fountain.h"
#include "User.h"
#include <string>
#include <utility>
using namespace std;
#ifndef REVIEW_H
#define REVIEW_H
enum stars { ONE, TWO, THREE, FOUR, FIVE };
class Review {
public:
  Review();

private:
  pair<Fountain, User> review = {Fountain(), User()};
  string content;
  stars rating;
};

#endif // REVIEW_H