#ifndef USER_H
#define USER_H
#include "Review.h"
#include <string>
using namespace std;
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
#endif // USER_H