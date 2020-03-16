#include "Fountain.h"
#include <iostream>
using namespace std;

Fountain::Fountain(string id, string location, string name) {
  this->id = id;
  this->location = location;
  this->name = name;
}
void Fountain::printFountain() {
  cout << "ID: " << id << endl
       << "Location: " << location << endl
       << "Name: " << name << endl;
}
void Fountain::addReview(Review *review) { revList.push_back(review); }
string Fountain::getName() { return name; }
string Fountain::getId() { return id; }
string Fountain::getLocation() { return location; }
void Fountain::printReviews() {
  for (auto i : revList) {
    i->printReview();
    cout << "____________________" << endl;
  }
}
double Fountain::computeRating() {
  double totalStars = 0;
  double actualRating;
  for (auto i : revList) {
    totalStars += i->getRating();
  }
  actualRating = totalStars / revList.size();
  return actualRating;
}