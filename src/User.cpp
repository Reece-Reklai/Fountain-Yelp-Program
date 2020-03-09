#include "User.h"
#include <string>

User::User() {
  name = "";
  passcode = "";
}
User::User(string username, string name, string passcode) {
  this->name = name;
  this->passcode = passcode;
}

string User::getName() { return name; }

string User::getPasscode() { return passcode; }

void User::setName(string name) { this->name = name; }

void User::setPasscode(string passcode) { this->passcode = passcode; }