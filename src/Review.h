<<<<<<< HEAD
=======
class User;
class Fountain;
#include "Fountain.h"
#include "User.h"
>>>>>>> origin
#include <string>
#include <utility>
#include "Fountain.h"
#include "User.h"
using namespace std;
#ifndef SRC_REVIEW_H_
#define SRC_REVIEW_H_
class Review {
<<<<<<< HEAD
  public:
    Review();

  private:
    pair<Fountain, User> review = {Fountain(), User()};
    string content;
    int rating;
=======
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
>>>>>>> origin
};

#endif  // SRC_REVIEW_H_