#include <string>
using namespace std;
#ifndef USER_H
#define USER_H

class User {
public:
  User();
  User(string, string, string);
  string getPasscode();
  string getName();
  void setPasscode(string);
  void setName(string);

private:
  string name;
  string passcode;
  string username;
};
#endif // USER_H