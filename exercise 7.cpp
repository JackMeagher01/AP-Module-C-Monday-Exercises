//
// Public Link - https://repl.it/@Meagher01/Zero-Positive-and-Negative-Type-Counter#main.cpp
// Invite Link - https://repl.it/join/mxywrerh-meagher01
//
#include <iostream>
#include <string>
using namespace std;

bool isValidInput(string input) {
  bool valid;
  if (input.find_first_not_of("-0123456789qQ")) {
    valid = true;
  }
  for (int i=0; i < input.length(); i++) {
    int count = 0;
    if (input[i] == '-') {
      count ++;
    }
    if (input[i] == '-' && i !=0 ) {
      valid = false;
    } else if (count == input.length()) {
      valid = false;
    }
  }
  if (valid) {
    return true;
  }
  cout << "Invalid value, please try again:" << endl;
  return false;
}

string getInput() {
  string input;
  do {
    cin >> input;
  } while (!isValidInput(input));
  return input;
}

void displayResults(int validCount, int zeroCount, int negativeCount, int positiveCount) {
  cout << "Total number of values entered: " << validCount << endl;
  cout << "\nZeros: \t" << zeroCount;
  cout << "\nPositives: \t" << positiveCount;
  cout << "\nNegativess: \t" << negativeCount << endl;
}

int main() {
  string input;
  int validCount = 0;
  int zeroCount = 0;
  int negativeCount = 0;
  int positiveCount = 0;
  bool quit;
  cout << "Please enter a valid numeric, or “Q” to finish: " << endl;
  do {
    input = getInput();
    quit = input[0] == 'q'|| input[0] == 'Q';
    if (!quit) {
      validCount++;
    }
    if (!quit && stoi(input) > 0) {
      positiveCount++;
    } else if (!quit && stoi(input) < 0) {
      negativeCount++;
    } else if (!quit && stoi(input) == 0) {
      zeroCount++;
    }
  } while (!quit);
  displayResults(validCount, zeroCount, negativeCount, positiveCount);
}
