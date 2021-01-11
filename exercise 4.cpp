//
// Public Link - https://repl.it/@Meagher01/Odds-and-Evens#main.cpp
// Invite Link - https://repl.it/join/utkajmlz-meagher01
//
#include <iostream>
#include <math.h> 
using namespace std;

// If remainder is 0, number must be even.
bool isOddOrEven(int value) {
  return value % 2 == 0;
}

bool isWholeNumber(float value) {
  if (floor(value) == value) {
    return true;
  }
  cout << "Only an integer can be odd or even. Please enter a whole number.\n";
  return false;
}

int main() {
  float value;
  do {
    cout << "Please enter a value? ";
    cin >> value;
  } while (!isWholeNumber(value));  

  string oddOrEven;
  oddOrEven = isOddOrEven(value) ? "even" : "odd"; 

  cout << value << " is an " << oddOrEven << " number" << endl;

  return 0;
}
