#include "Campus.h"
#include "Fountain.h"
#include "Review.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
  Campus wwup;
  wwup.printUList();
  cout << endl;
  wwup.printFList();
  cout << endl;
  wwup.printRlist();
  cout << "pick a fountain Id: ";
  string id;
  cin >> id;
  wwup.displayFountain(id);
}