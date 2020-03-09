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
  Review(
      string, string,
      int); // sets the header, content, and rating for the review in that order
  void assignUser(User *);         // links the Review to a user
  void assignFountain(Fountain *); // links the Review to a fountain
  void printReview();              // displays relevnt information on the Review
  User *getUser();                 // returns a pointer to the linked user
  Fountain *getFountain();         // returns a pointer to the linked Fountain

private:
  User *user;         // points to the user who wrote the review
  Fountain *fountain; // points to the fountain for which the review was written
  string content, header;
  int rating;
};

#endif // REVIEW_H