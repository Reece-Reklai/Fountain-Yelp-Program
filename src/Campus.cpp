#include "Campus.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
Campus::Campus() {
  isLogged = false;
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
    fountainByName.emplace(name, Flist.at(index));
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
    cout << i->getName() << " : " << i->getId() << " : " << i->computeRating()
         << endl;
  }
}

void Campus::printFountain(string id) {
  cout << "--------------------" << endl
       << fountainById.at(id)->getName() << " : "
       << fountainById.at(id)->getId() << " : "
       << fountainById.at(id)->computeRating() << endl
       << "____________________" << endl;
  fountainById.at(id)->printReviews();
}

void Campus::login(string username, string password) {
  if (userByName.count(username)) {
    if (userByName.at(username)->getPasscode() == password) {
      signedUser = userByName.at(username);
      isLogged = true;
    } else {
      throw runtime_error("Incorrect Password!");
    }
  } else {
    throw runtime_error("Could not find the user");
  }
}

void Campus::logout() {
  signedUser = NULL;
  isLogged = false;
}

void Campus::signUp(string username, string password) {
  if (userByName.count(username)) {
    throw runtime_error("A User By This Name Already Exists");
  } else {
    string newId = createId();
    while (userById.count(newId)) {
      newId = createId();
    }
    Ulist.push_back(new User(newId, username, password, 1));
    userById.emplace(newId, Ulist.back());
    userByName.emplace(username, Ulist.back());
    PutInFile("Users.txt", formatString(Ulist.back()));
  }
}

string Campus::formatString(User *out) {
  return to_string(out->getCred()) + '|' + out->getId() + '|' + out->getName() +
         '|' + out->getPasscode();
}

string Campus::formatString(Fountain *out) {
  return out->getId() + "|" + out->getLocation() + "|" + out->getName();
}

string Campus::formatString(Review *out) {
  return out->getUser()->getId() + "|" + out->getFountain()->getId() + "|" +
         to_string(out->getRating()) + "|" + out->getHeader() + "|" +
         out->getContent();
}

string Campus::createId() {
  srand(time(NULL));
  int newId1 = rand() % 10;
  string newId;
  for (int i = 1; i <= 4; i++) {
    newId1 += ((rand() % 10) * pow(10, i));
  }
  newId = to_string(newId1);
  return newId;
}

void Campus::PutInFile(string File_Name, string content) {
  ofstream Outfile;
  Outfile.open(File_Name, ios_base::app);
  Outfile << '\n' << content;
  return;
}

void Campus::printSignedUser() {
  if (isLogged) {
    cout << "Name: " << signedUser->getName() << endl
         << "Password: " << signedUser->getPasscode() << endl
         << "ID: " << signedUser->getId() << endl
         << "Cred Level: " << signedUser->getCred() << endl;
  } else {
    cout << "no way" << endl;
  }
}

void Campus::writeReview(string fountain, int rating, string header,
                         string content) {
  Rlist.push_back(new Review(header, content, rating));
  Rlist.back()->assignFountain(fountainById.at(fountain));
  Rlist.back()->assignUser(signedUser);
  fountainById.at(fountain)->addReview(Rlist.back());
  signedUser->addReview(Rlist.back());
  PutInFile("Review.txt", formatString(Rlist.back()));
}
void Campus::addFountain(string location, string name) {
  string newId = createId();
  while (fountainById.count(newId)) {
    newId = createId();
  }
  Flist.push_back(new Fountain(newId, location, name));
  fountainById.emplace(newId, Flist.back());
  fountainByName.emplace(name, Flist.back());
  PutInFile("Fountains.txt", formatString(Flist.back()));
}