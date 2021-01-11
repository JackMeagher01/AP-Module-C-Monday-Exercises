//
// https://repl.it/@Meagher01/Low-and-Largest-Numbers#main.cpp
// https://repl.it/join/rmokkimq-meagher01
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

void displayResults(int validCount,int low , int high) {
  cout << "\nTotal number of values entered: " << validCount;
  cout << "\nLowest Value: \t" << low;
  cout << "\nLargest Value: \t" << high << endl;
}

int main() {
  string input;
  int validCount = 0;
  int validNumber;
  int low = 0;
  int high = 0;
  bool quit;
  cout << "Please enter a valid numeric, or “Q” to finish: " << endl;
  do {
    input = getInput();
    quit = input[0] == 'q'|| input[0] == 'Q';
    if (!quit) {
      validCount++;
      validNumber = stoi(input);
    } 
    if (!quit && (validNumber > high || validCount == 1)) {
      high = validNumber;
    } 
    if (!quit && (validNumber < low || validCount == 1)) {
      low = validNumber;
    }
  } while (!quit);
  displayResults(validCount, low, high);
  return 0;
}
