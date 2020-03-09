#ifndef CAMPUS_H
#define CAMPUS_H
#include "Fountain.h"
#include "User.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class Campus {
public:
  Campus();
  void printUList();
  void printFList();
  void printRlist();

private:
  vector<Fountain *> Flist;
  vector<User *> Ulist;
  vector<Review*>Rlist;
  map<string, User *> userById;
  map<string, Fountain *> fountainById;
};

#endif