#ifndef CAMPUS_H
#define CAMPUS_H
#include "Fountain.h"
#include "User.h"
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Campus {
public:
  Campus();          // most of the program's initialization happens within this
                     // constructor
  void printUList(); // prints relevent data from the objects in Ulist(Testing
                     // Purposes)
  void printFList(); // prints relevent data from the objects in Flist(Testing
                     // Purposes)
  void printRlist(); // prints relevent data from the objects in Rlist(Testing
                     // Purposes)
  void displayFountains();    // Displays a list of all fountain names alongside
                              // their ID numbers
  void printFountain(string); // Prints a fountain's reviews given its ID number

  void login(string, string);
  void logout();
  void signUp(string, string);


private:
  vector<Fountain *> Flist;
  vector<User *> Ulist;
  vector<Review *> Rlist;
  map<string, User *> userById;
  map<string, User *> userByName;
  map<string, Fountain *> fountainById;
  User *signedUser;
};

#endif