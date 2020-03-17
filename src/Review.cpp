#include "Review.h"
#include "Fountain.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

Review::Review(string header, string content, int rating) {
  this->header = header;
  this->content = content;
  this->rating = rating;
}
void Review::assignUser(User *user) { this->user = user; }
void Review::assignFountain(Fountain *fountain) { this->fountain = fountain; }
User *Review::getUser() { return user; }
Fountain *Review::getFountain() { return fountain; }
void Review::printReview() {
  cout << user->getName() << " - Rating: " << rating << "/5" << endl
       << header << endl
       << content << endl;
}
int Review::getRating() { return rating; }
string Review::getHeader() { return header; }
string Review::getContent() { return content; }