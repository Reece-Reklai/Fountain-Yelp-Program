/*************************************************************************
 *
 * Project III: Start here.
 *
 * File Name:       main.cpp
 * Name(s):         ?
 * Course:          CPTR 142
 * Date:            ?
 *
 */
#include "Campus.h"
#include "ErrorCheck.h"
#include "Fountain.h"
#include "Review.h"
#include "User.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {
  bool isRunning = true;
  int choice, rating;
  string username, password, id, header, content;
  Campus wwup;
  cout << "Welcome to WWUP!" << endl << "________________" << endl;
  while (isRunning) {
    cout << "1) Log In\n2) Sign Up\n3) Display All Fountains\n4) View A "
            "Fountain\n5) Write A Review\n6) View Profile\n7) Log Out\n8) Quit "
            "Program\n"
         << endl;
    cin >> choice;
    try {
      errorCheck(choice, 1, 8);
    } catch (exception &e) {
      cerr << e.what() << endl << "Try Again" << endl;
      continue;
    }
    switch (choice) {
    case 1:
      wwup.logout();
      cout << "Enter Your Username: ";
      cin >> username;
      cout << "Enter Your Password: ";
      cin >> password;
      try {
        wwup.login(username, password);
        cout << "Successfully Logged In" << endl;
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      break;
    case 2:
      wwup.logout();
      cout << "Enter a Username: ";
      cin >> username;
      cout << "Enter a Password: ";
      cin >> password;
      try {
        wwup.signUp(username, password);
        wwup.login(username, password);
        cout << "Created Account Successfully" << endl;
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      break;
    case 3:
      wwup.displayFountains();
      break;
    case 4:
      cout << "Enter a Fountain ID: ";
      cin >> id;
      try {
        wwup.printFountain(id);
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      break;
    case 5:
      cout << "Choose a Fountain to Review(by ID): ";
      cin >> id;
      cout << "Rate The Fountain Out of 5: ";
      cin >> rating;
      try {
        errorCheck(rating, 0, 5);
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      cout << "Write a Header to Your Review: ";
      cin >> header;
      cout << "Write The Body of Your Review: ";
      cin >> content;
      try {
        wwup.writeReview(id, rating, header, content);
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      break;
    case 6:
      try {
        wwup.printSignedUser();
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      break;
    case 7:
      wwup.logout();
      break;
    case 8:
      return 1;
      break;
    }
  }
}