#include "ErrorCheck.h"
#include <iostream>
#include <string>
using namespace std;

void errorCheck(int input, int bottom, int top) {
  if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cin.clear();
    throw runtime_error("Invalid Input");
  }
  if (input < bottom || input > top) {
    throw runtime_error("Input Out of Specified Range");
  }
}