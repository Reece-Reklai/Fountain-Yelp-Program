#ifndef USER_H
#define USER_H
#include "Review.h"
#include <string>
#include <vector>
using namespace std;
class User {
public:
  User();
  User(string, string, string,int);
  string getPasscode();
  string getId();
  string getName();
  int getCred();
  void setPasscode(string);
  void setId(string);
  void setName(string);
  void printUser();
  void addReview(Review *);
  void setCred(int);

private:
  vector<Review *> revList;
  string id;
  string passcode;
  string username;
  int credential;
};
#endif // USER_H