#include "Campus.h"
#include "Fountain.h"
#include "Review.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
  Campus wwup;
  bool yuh = true;
  cout << "Wellcome to the Walla Walla University Yelp for drinking "
          "fountains(WWUP)"
       << endl;
  while (yuh) {

    int choice;
    string stChoice, username, password;
    cout << "Here are your optinons" << endl
         << "----------------------" << endl
         << "1) Display All Fountains\n2) Select a Fountain\n3) Log in\n4) "
            "Sign up"
         << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      wwup.displayFountains();
      break;
    case 2:
      cout << "Enter The Desired Fountain's ID Number: ";
      cin >> stChoice;
      wwup.printFountain(stChoice);
      break;
    case 3:
      cin >> username;
      cin >> password;
      wwup.login(username, password);
      break;
    case 4:
      cin >> username;
      cin >> password;
      wwup.signUp(username, password);
      break;
    case 5:
      yuh = false;
      break;
    }
  }
}