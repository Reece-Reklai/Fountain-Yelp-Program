#include "User.h"
#include <iostream>
#include <string>

User::User() {
    id = "";
    passcode = "";
    username = "";
}
User::User(string id, string username, string passcode) {
    this->id = id;
    this->username = username;
    this->passcode = passcode;
}
string User::getId() {
    return id;
}
string User::getPasscode() {
    return passcode;
}
string User::getName() {
    return username;
}
void User::setId(string id) {
    this->id = id;
}
void User::setPasscode(string passcode) {
    this->passcode = passcode;
}
void User::setName(string username) {
    this->username = username;
}
void User::printUser() {
    cout << "ID: " << id << endl
         << "Username: " << username << endl
         << "Passcode: " << passcode << endl;
}
void User::addReview(Review *review) {
    revList.push_back(review);
}