//
// Public Link - https://repl.it/@Meagher01/Character-Type-Checker#main.cpp
// Invite Link - https://repl.it/join/pnwjgmnj-meagher01
//
#include <iostream>
#include <stdio.h>

using namespace std;

bool validInputTryAgain(string input) {
  if (cin.fail() || input.length() > 1) {
    cout << "Please enter a valid value.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  } 
  char validInput = toupper(input[0]);
  if (validInput == 'Y' || validInput == 'N') {
    return true;
  }
  
  cout << "Please enter a valid value.\n";
  return false;
}

bool validInput(string input) {
  if (cin.fail() || input.length() > 1) {
    cout << "Please enter a valid value.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  } 

  if (isalpha(input[0])) {
    cout << "Alphabetic character detected.";
    return true;
  } else if (isdigit(input[0])) {
    cout << "Numeric character detected.";
    return true;
  } else {
    cout << "Special character detected";
    return true;
  }
  
  cout << "Please enter a valid value.\n";
  return false;
}

bool tryAgain() {
  string input;
  do {
    cout << "\nTry again (Y/N)? ";
    cin >> input;;
  } while(!validInputTryAgain(input));
  char inputUpper = toupper(input[0]);
  switch (inputUpper) {
    case 'Y': return true;
    case 'N': 
      cout << "Thank you, good bye.";
      return false;
  }
  return false;
}

int main() {
  string input;
  bool again;
  do {
    do {
      cout << "Please enter a character? ";
      cin >> input;
    } while (!validInput(input));
    again = tryAgain();
  } while (again);
}
