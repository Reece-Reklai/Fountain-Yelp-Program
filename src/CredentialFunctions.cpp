
#include "CredentialFunctions.h"
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;
bool Login(map<string, string> Credential) {
    bool verdict = true;
    char tryAgain = 'Y';
    string username;
    string passcode;
    do {
        if (verdict == false) {
            cout << "Sorry, username does not exist" << endl;
            cout << "Do you want to try again? (Y)es or (N)o : ";
            cin >> tryAgain;
            while (tryAgain != 'Y' && tryAgain != 'y' && tryAgain != 'N' &&
                   tryAgain != 'n') {
                cout << "Please enter Y for yes or N for no : ";
                cin >> tryAgain;
            }
        }
        if (tryAgain == 'N' || tryAgain == 'n') {
            break;
        }
        cout << "What is your username? : ";
        cin >> username;
        for (auto map : Credential) {
            if (username == map.first) {
                verdict = true;
                break;
            } else {
                verdict = false;
            }
        }
    } while (verdict == false);
    if (verdict == true) {
        do {
            if (verdict == false) {
                cout << "Sorry, passcode does not exist" << endl;
                cout << "Do you want to try again? (Y)es or (N)o : ";
                cin >> tryAgain;
                while (tryAgain != 'Y' && tryAgain != 'y' && tryAgain != 'N' &&
                       tryAgain != 'n') {
                    cout << "Please enter Y for yes or N for no : ";
                    cin >> tryAgain;
                }
                if (tryAgain == 'N' || tryAgain == 'n') {
                    break;
                }
            }
            cout << "What is your passcode? : ";
            cin >> passcode;
            for (auto map : Credential) {
                if (passcode == map.second) {
                    verdict = true;
                    break;
                } else {
                    verdict = false;
                }
            }
        } while (verdict == false);
    }
    return verdict;
}
bool SignUp(map<string, string> Credential) {
    bool verdict = true;
    char tryAgain = 'Y';
    string username;
    string passcode;
    do {
        if (verdict == false) {
            cout << "Sorry, username is taken" << endl;
            cout << "Do you want to try again? (Y)es or (N)o : ";
            cin >> tryAgain;
            while (tryAgain != 'Y' && tryAgain != 'y' && tryAgain != 'N' &&
                   tryAgain != 'n') {
                cout << "Please enter Y for yes or N for no : ";
                cin >> tryAgain;
            }
        }
        if (tryAgain == 'N' || tryAgain == 'n') {
            break;
        }
        cout << "What is your desired username? : ";
        cin >> username;
        for (auto map : Credential) {
            if (username != map.first) {
                verdict = true;
            } else {
                verdict = false;
                break;
            }
        }
    } while (verdict == false);
    if (verdict == true) {
        cout << "What is your passcode? : ";
        cin >> passcode;
    }
    if (verdict == true) {
        Credential.emplace(username, passcode);
    }
    return verdict;
}