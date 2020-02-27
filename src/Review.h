#include <string>
#include <utility>
#include "Fountain.h"
#include "User.h"
using namespace std;
#ifndef SRC_REVIEW_H_
#define SRC_REVIEW_H_
class Review {
  public:
    Review();

  private:
    pair<Fountain, User> review = {Fountain(), User()};
    string content;
    int rating;
};

#endif  // SRC_REVIEW_H_