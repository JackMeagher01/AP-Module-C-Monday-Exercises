// 
// Public Link - https://repl.it/@Meagher01/Karvonen-Heart-Rate-Calculator#main.cpp
// Invite Link - https://repl.it/join/ahwsehgq-meagher01
//
#include <iostream>
using namespace std;

int getAge() {
  int age;
  cout << "Please enter your age: ";
  cin >> age;
  return age;
}

int getRestingHeartRate() {
  int pulse;
  cout << "Please enter your resting pulse: ";
  cin >> pulse;
  return pulse;
}

bool isValidInput() {
  if (cin.fail()) {
    cout << "Please enter a valid age.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  return true;
}

void displayInputs(int age, int pulse) {
  cout << "Resting Pulse: " << pulse << "\tAge: " << age << endl;
  cout << "\nIntensity\tRate\n--------------------"<< endl;
}

int calculateHeartRate(int age, int pulse, float intensity) {
  return (((220-age) - pulse) * intensity) + pulse;
}

int * getTargetHeartRates(int age, int pulse) {
  static int heartRates[12];
  int size = sizeof(heartRates) / sizeof(*heartRates);
  for (int i = 0; i < size; i++) {
    float intensity = 0.4 + (0.05 * i);
    heartRates[i] = calculateHeartRate(age, pulse, intensity);
  }
  return heartRates;
}

void displayTargetRates(int * pTargetHeartRates) {
  int *targetHeartRates = pTargetHeartRates;
  int size = sizeof(*pTargetHeartRates) + sizeof(pTargetHeartRates);
  for (int i = 0; i < 12; i++) {
    cout << (0.4 + (0.05 * i)) * 100 << "\t\t\t" << targetHeartRates[i] << endl;
  }
}

int main() {
  int age;
  do {
    age = getAge();
  } while (!isValidInput());

  int pulse;
  do {
    pulse = getRestingHeartRate();
  } while (!isValidInput());

  displayInputs(age, pulse);
  displayTargetRates(getTargetHeartRates(age, pulse));

}
