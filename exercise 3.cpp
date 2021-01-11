//
// Public Link - https://repl.it/@Meagher01/Area-of-a-rectangle-room#main.cpp
// Invite Link - https://repl.it/join/xbgajnhb-meagher01
//
#include <iostream>
using namespace std;

const double METRES_TO_FEET_SQUARED = 10.764;


bool isValidMeasurementType(string measurementType) {
  if (measurementType.size() != 1) {
    cout << "Please enter a valid option.\n\n";
    return false;
  }
  switch (measurementType[0]) {
    case 'F': return true;
    case 'M': return true;
  }
  cout << "Please enter a valid option.\n\n";
  return false;
}

bool isValidMeasurement(double measurement) {
  if (cin.fail()) {
    cout << "Please enter a valid measurement.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  return true;
}

string getMeasurementTypeString(char measurementType) {
  if (measurementType == 'F') {
    return "feet";
  } else if (measurementType == 'M') {
    return "metres";
  }
  return "";
}

double convertToMetres(double area) {
  return area / METRES_TO_FEET_SQUARED;
}

double convertToFeet(double area) {
  return area * METRES_TO_FEET_SQUARED;
}

double convertArea(double area, char measurementType) {
  switch (measurementType) {
    case 'F': return convertToMetres(area);
    case 'M': return convertToFeet(area);
  }
  return 0;
}

void displayAreas(double areaInFeet, double areaInMetres) {
  cout << areaInFeet << " square feet.\n" << areaInMetres << " square metres.\n";
}

int main() {
  string measurementTypeString;
  char measurementType;
  do {
    cout << "Press 'F' if you measured the room in feet.\nPress 'M' if you measured the room in metres.\n\nYour Choice: ";
    cin >> measurementTypeString; 
    measurementTypeString[0] = toupper(measurementTypeString[0]);
  } while (!isValidMeasurementType(measurementTypeString));
  measurementType = measurementTypeString[0];

  double length;
  do {
    cout << "What is the length of the room in " << getMeasurementTypeString(measurementType) << "? ";
    cin >> length;
  } while (!isValidMeasurement(length));

  double width;
  do {
    cout << "What is the width of the room in " << getMeasurementTypeString(measurementType) << "? ";
    cin >> width;
  } while (!isValidMeasurement(width));

  double area;
  area = length * width;

  double areaInFeet;
  double areaInMetres;
  switch (measurementType) {
    case 'F':
      areaInFeet = area;
      areaInMetres = convertArea(area, measurementType);
      break;
    case 'M':
      areaInFeet = convertArea(area, measurementType);
      areaInMetres = area;
      break;
  }
  
  displayAreas(areaInFeet, areaInMetres);
} 
