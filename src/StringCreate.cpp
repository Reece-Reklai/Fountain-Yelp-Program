#include "StringCreate.h"
#include "Fountain.h"
#include "User.h"
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
using namespace std;

string formatUserString(User *out) {
  return to_string(out->getCred()) + '|' + out->getId() + '|' + out->getName() +
         '|' + out->getPasscode();
}

string createId() {
  srand(time(NULL));
  int newId1 = rand() % 10;
  string newId;
  for (int i = 1; i <= 4; i++) {
    newId1 += ((rand() % 10) * pow(10, i));
  }
  newId = to_string(newId1);
  return newId;
}