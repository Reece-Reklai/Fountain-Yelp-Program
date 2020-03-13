#include "Campus.h"
#include "PutInFile.h"
#include "StringCreate.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Campus::Campus() {
  int index;
  ifstream fin;
  fin.open("Users.txt");
  index = 0;
  while (!fin.eof()) {
    string id, name, password, credstr;
    getline(fin, credstr, '|');
    int credential = stoi(credstr);
    getline(fin, id, '|');
    getline(fin, name, '|');
    getline(fin, password, '\n');
    Ulist.push_back(new User(id, name, password, credential));
    userById.emplace(id, Ulist.at(index));
    userByName.emplace(name, Ulist.at(index));
    index++;
  }
  fin.close();
  fin.open("Fountains.txt");
  index = 0;
  while (!fin.eof()) {
    string id, location, name;
    getline(fin, id, '|');
    getline(fin, location, '|');
    getline(fin, name, '\n');
    Flist.push_back(new Fountain(id, location, name));
    fountainById.emplace(id, Flist.at(index));
    index++;
  }
  fin.close();
  fin.open("Review.txt");
  index = 0;
  while (!fin.eof()) {
    string userId, fountainId, header, content, protoRating, ratingId;
    int rating;
    getline(fin, userId, '|');
    getline(fin, fountainId, '|');
    getline(fin, protoRating, '|');
    getline(fin, header, '|');
    getline(fin, content, '\n');
    stringstream s(protoRating);
    s >> rating;
    Rlist.push_back(new Review(header, content, rating));
    if (userById.count(userId)) {
      Rlist.at(index)->assignUser(userById.at(userId));
      userById.at(userId)->addReview(Rlist.at(index));
    }
    if (fountainById.count(fountainId)) {
      Rlist.at(index)->assignFountain(fountainById.at(fountainId));
      fountainById.at(fountainId)->addReview(Rlist.at(index));
    }

    index++;
  }
  fin.close();
}
void Campus::printUList() {
  for (auto i : Ulist) {
    i->printUser();
  }
}
void Campus::printFList() {
  for (auto i : Flist) {
    i->printFountain();
  }
}
void Campus::printRlist() {
  for (auto i : Rlist) {
    i->printReview();
  }
}
void Campus::displayFountains() {
  cout << "Name: ID" << endl;
  for (auto i : Flist) {
    cout << i->getName() << ": " << i->getId() << endl;
  }
}
void Campus::printFountain(string id) {

  cout << "--------------------" << endl
       << fountainById.at(id)->getName() << ": " << fountainById.at(id)->getId()
       << endl
       << "____________________" << endl;
  fountainById.at(id)->printReviews();
}

void Campus::login(string username, string password) {
  if (userByName.count(username)) {
    if (userByName.at(username)->getPasscode() == password) {
      signedUser = userByName.at(username);
    } else {
      throw runtime_error("Incorrect Password!");
    }
  } else {
    throw runtime_error("Could not find the user");
  }
}

void Campus::logout() { signedUser = NULL; }

void Campus::signUp(string username, string password) {
  if (userByName.count(username)) {
    throw runtime_error("Exuse me, but it seems as though a user going by "
                        "this name already exists");
  } else {
    string newId = createId();
    while (userById.count(newId)) {
      newId = createId();
    }
    Ulist.push_back(new User(newId, username, password, 1));
    userById.emplace(newId, Ulist.back());
    userByName.emplace(username, Ulist.back());
    PutInFile("Users.txt", formatUserString(Ulist.back()));
  }
}