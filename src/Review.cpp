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
void Review::printReview() {
  cout << "Username: " << user->getName() << endl
       << "Fountain: " << fountain->getName() << endl
       << "Header: " << header << endl
       << "Content: " << content << endl
       << "Rating: " << rating << endl;
       cout<<"_________________________"<<endl;
}