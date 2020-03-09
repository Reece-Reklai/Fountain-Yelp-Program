<<<<<<< HEAD
#include <string>
using namespace std;
#ifndef SRC_USER_H_
#define SRC_USER_H_

=======
#ifndef USER_H
#define USER_H
#include "Review.h"
#include <string>
using namespace std;
>>>>>>> origin
class User {
public:
  User();
  User(string, string, string);
  string getPasscode();
  string getId();
  string getName();
  void setPasscode(string);
  void setId(string);
  void setName(string);
  void printUser();
void addReview(Review*);
private:
  vector<Review *> revList;
  string id;
  string passcode;
  string username;
};
#endif // SRC_USER_H_