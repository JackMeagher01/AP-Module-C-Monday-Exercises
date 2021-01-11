//
// Public Link - https://repl.it/@Meagher01/Fahrenheit-Centigrade-Conversion#main.cpp
// Invite Link - https://repl.it/join/rzbehftk-meagher01
//
#include <iostream>
using namespace std;

const string validConversionTypes[][2] = {{"C","Centigrade"},{"F", "Fahrenheit"}, {"K","Kelvin"}};
const int numberOfConversionTypes = sizeof(validConversionTypes) / sizeof(validConversionTypes[0]);

double startTempMenu() {
  double temp;
  cout << "Please enter the starting temperature: ";
  cin >> temp;
  return temp;
}

string conversionFromMenu() {
  string conversionType;
  for (int i = 0; i < numberOfConversionTypes; i++) {
    cout << "Press '" << validConversionTypes[i][0] << "' to convert from " << validConversionTypes[i][1] << endl;
  }
  cout << "\nYour Choice: ";
  cin >> conversionType;
  return conversionType;
}

string conversionToMenu() {
  string conversionType;
  for (int i = 0; i < numberOfConversionTypes; i++) {
    cout << "Press '" << validConversionTypes[i][0] << "' to convert to " << validConversionTypes[i][1] << endl;
  }
  cout << "\nYour Choice: ";
  cin >> conversionType;
  return conversionType;
}

// Takes in the user's input temperature and checks if it is valid.
bool isValidTemperature() {
  if (cin.fail()) {
    cout << "Please enter a valid temperature.\n" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  return true;
}

// Takes in the user's conversionType and checks if the input was valid
bool isValidConversionType(string conversionType) {
  for (int i = 0; i < numberOfConversionTypes; i++) {
    if (conversionType.size() != 1) {
      break;
    }
    string validConversionType = validConversionTypes[i][0];
    if (conversionType == validConversionType) {
      return true;
    }    
  }
  cout << "Please enter a valid value.\n" << endl;
  return false;
}

double cToF(double temp) {
  return (temp * 9 / 5) + 32;
}

double cToK(double temp) {
  return temp + 273;
}

double fToC(double temp) {
  return (temp -32) * 5 / 9;
}

double fToK(double temp) {
  return cToK(fToC(temp));
}

double kToC(double temp) {
  return temp - 273;
}

double kToF(double temp) {
  return cToF(kToC(temp));
}

double doConversion(double temp, char conversionFromType, char conversionToType) {
  switch (conversionFromType) {
    case 'C': 
      switch (conversionToType) {
        case 'C': return temp;
        case 'F': return cToF(temp);
        case 'K': return cToK(temp);
      }
    case 'F':
      switch (conversionToType) {
        case 'C': return fToC(temp);
        case 'F': return temp;
        case 'K': return fToK(temp);
      }
    case 'K':
      switch (conversionToType) {
        case 'C': return kToC(temp);
        case 'F': return kToF(temp);
        case 'K': return temp;
      }
  }
  return 0;
}

string getTempMeasurementString(char tempMeasurement) {
  switch (tempMeasurement) {
    case 'C': return " degrees Celsius ";
    case 'F': return " degrees Fahrenheit ";
    case 'K': return " Kelvin ";
  }
  return "";
}

void displayConversion(double temp, double convertedTemp, string conversionFromType, string conversionToType) {
  cout << temp << getTempMeasurementString(conversionFromType[0]) << "is " << convertedTemp << getTempMeasurementString(conversionToType[0]);
}

int main() {
  double temp;
  do {
    temp = startTempMenu();
  } while(!isValidTemperature());  
  
  string conversionFromType;
  do {
    conversionFromType = conversionFromMenu();
    conversionFromType[0] = toupper(conversionFromType[0]);
  } while(!isValidConversionType(conversionFromType));
  
  string conversionToType;
  do {
    conversionToType = conversionToMenu();
    conversionToType[0] = toupper(conversionToType[0]);
  } while(!isValidConversionType(conversionToType));

  double convertedTemp;
  convertedTemp = doConversion(temp, conversionFromType[0], conversionToType[0]);

  displayConversion(temp, convertedTemp, conversionFromType, conversionToType);
}
