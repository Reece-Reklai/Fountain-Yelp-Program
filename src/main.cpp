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
  int choice, rating, cred;
  int credLevel = 0;
  string username, password, id, header, content, location, name;
  Campus wwup;
  cout << "Welcome to WWUP!" << endl << "________________" << endl;
  while (isRunning) {
    cout << "1) Log In\n2) Sign Up\n3) Display All Fountains\n4) View A "
            "Fountain\n5) Write A Review\n6) View Profile\n7) Log Out\n8) "
            "Admin Tools\n9) Quit "
            "Program\n"
         << endl
         << "Choice: ";
    cin >> choice;
    try {
      errorCheck(choice, 1, 9);
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
      cin.ignore();
      getline(cin, header);
      cout << "Write The Body of Your Review: ";
      getline(cin, content);
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
      credLevel = 0;
      break;
    case 8:
      try {
        credLevel = wwup.checkCred();
      } catch (exception &e) {
        cerr << e.what() << endl;
        continue;
      }
      if (credLevel > 1) {
        bool adminTools = true;
        while (adminTools) {
          cout << "welcome to Admin Tools" << endl
               << "1) Add Fountain\n2) Set Privileges\n3) Quit Admin Tools\n"
               << endl
               << "Choice: ";
          cin >> choice;
          try {
            errorCheck(choice, 1, 3);
          } catch (exception &e) {
            cerr << e.what() << endl;
            continue;
          }
          switch (choice) {
          case 1:
            if (credLevel < 2) {
              cerr << "You Are Not Authorized" << endl;
              continue;
            }
            cout << "Enter the fountain location: ";
            cin.ignore();
            getline(cin, location);
            cout << "Enter the fountain name: ";
            getline(cin, name);
            try {
              wwup.addFountain(location, name);
              cout << "Fountain Successfully Added" << endl;
            } catch (exception &e) {
              cerr << e.what() << endl;
              continue;
            }
            break;
          case 2:
            if (credLevel < 3) {
              cerr << "You Are Not Authorized" << endl;
              continue;
            }
            cout << "Enter the ID of the user you would like to change: ";
            cin >> id;
            cout << "Enter the desired credential level(1-3): ";
            cin >> cred;
            try {
              errorCheck(cred, 1, 3);
            } catch (exception &e) {
              cerr << e.what() << endl;
              continue;
            }
            try {
              wwup.changeCred(id, cred);
              wwup.reInitializeUsers();
            } catch (exception &e) {
              cerr << e.what() << endl;
              continue;
            }
            break;
          case 3:
            adminTools = false;
            break;
          }
        }
      } else {
        cerr << "You Are Not Authorized" << endl;
        continue;
      }
      break;
    case 9:
      return 1;
      break;
    }
  }
}