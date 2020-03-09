#include "Campus.h"
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
    string id, name, password;
    getline(fin, id, '|');
    getline(fin, name, '|');
    getline(fin, password, '\n');
    Ulist.push_back(new User(id, name, password));
    userById.emplace(id, Ulist.at(index));
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