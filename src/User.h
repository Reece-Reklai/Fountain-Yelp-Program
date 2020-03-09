#include <string>
using namespace std;
#ifndef SRC_USER_H_
#define SRC_USER_H_

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
#endif // SRC_USER_H_