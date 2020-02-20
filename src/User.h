#include <string>
using namespace std;
#ifndef USER_H
#define USER_H
class User {
public:
  User();
  string getPasscode();
  void setPasscode();

private:
  string name;
  string passcode;
};
#endif // USER_H