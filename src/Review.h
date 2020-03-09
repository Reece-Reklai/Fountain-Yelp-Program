class User;
class Fountain;
#include "Fountain.h"
#include "User.h"
#include <string>
#include <utility>
using namespace std;
#ifndef REVIEW_H
#define REVIEW_H
class Review {
public:
  Review(string, string, int);
  void assignUser(User *);
  void assignFountain(Fountain *);
  void printReview();
  User* getUser();

private:
  User *user;
  Fountain *fountain;
  string content, header;
  int rating;
};

#endif // REVIEW_H