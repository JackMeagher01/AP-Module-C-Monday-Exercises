//
// Public Link - https://repl.it/@Meagher01/Retirement-Calculator#main.cpp
// Invite Link - https://repl.it/join/ftglakgw-meagher01
//
#include <iostream>
#include <ctime>
using namespace std;

int getCurrentAge() {
  int age;
  cout << "Please enter your current age? ";
  cin >> age;
  return age;
}

int getRetirementAge() {
  int age;
  cout << "At what age would you like to retire? ";
  cin >> age;
  return age;
}

bool isValidInput(int age) {
  if (cin.fail()) {
    cout << "Please enter a valid age.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  } else if (age < 1) {
    cout << "Please enter a valid age.\n" << endl;
    return false;
  }
  return true;
}

int getYear() {
  time_t t = time(NULL);
	tm* timePtr = localtime(&t);
  return timePtr->tm_year + 1900;
}

int getYearsUntilRetirement(int currentAge, int retirementAge) {
  return retirementAge - currentAge;
}

void displayRetirementCalculation(int yearsUntilRetirement) {
  cout << "The current year is " << getYear() << ", you can retire ";
  if (yearsUntilRetirement < 1) {
    cout << "now." << endl;
  } else {
    cout << "in " << getYear() + yearsUntilRetirement << ", you have " << yearsUntilRetirement << " years remaining." << endl;
  }
}

int main() {
  int currentAge;
  do {
    currentAge = getCurrentAge();
  } while (!isValidInput(currentAge));

  int retirementAge;
  do {
    retirementAge = getRetirementAge();
  } while (!isValidInput(retirementAge));

  int yearsUntilRetirement = getYearsUntilRetirement(currentAge, retirementAge);
  displayRetirementCalculation(yearsUntilRetirement);
}
