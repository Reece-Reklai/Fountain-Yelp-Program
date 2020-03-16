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
  int index = 1;
  for (auto i : revList) {
    cout << index << ") ";
    i->printReview();
    cout << "____________________" << endl;
    index++;
  }
}
double Fountain::computeRating() {
  double totalStars = 0;
  double actualRating;
  if (revList.size() == 0) {
    throw runtime_error("No Reviews Yet");
  }
  for (auto i : revList) {
    totalStars += i->getRating();
  }
  actualRating = totalStars / revList.size();
  return actualRating;
}