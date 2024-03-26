#include "PinBall.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void loadPinBall(string filename, PinBall arr[10]);
bool createNewMachine(PinBall arr[10]);
bool printAllMachine(PinBall arr[10]);
bool getMachineByYear(PinBall arr[10]);
void printMenu();
bool writeToFile(PinBall arr[10]);

string trimString(string data);
vector<string> arrSplit(string dataString);

int counter = 10;

int main() {
  PinBall arcade[10] = {};
  char input = '0';
  loadPinBall("pinball.txt", arcade);

  while(input != '4'){
    printMenu();
    cin >> input;
    system("clear");
    
    switch(input){
      case '1':
        createNewMachine(arcade);
        break;
      case '2':
        getMachineByYear(arcade);
        break;
      case '3':
        printAllMachine(arcade);
        break;
      case '4':
        cout << "saving files" << endl;
        writeToFile(arcade);
        break;
    }
  }
}

void loadPinBall(string filename, PinBall arr[10]) {
  ifstream din(filename);
  if (din.is_open()) {
    string dataString;
    string name;
    int year;
    string manufacturer;
    float averageFunRating;
    
    while (din.good()) {
      vector<string> themes;
      vector<string> dataArr;

      // single query to db
      getline(din, dataString);
      if (dataString.empty()) {
        continue;
      }
      
      // turn dataString into array of items.
      dataArr = arrSplit(dataString);

      // variable assignment
      name             = dataArr[0];
      year             = stoi(dataArr[1]);
      manufacturer     = dataArr[2];
      averageFunRating = stof(dataArr[3]);

      // push the remaing items from dataArr to themes
      for(int i = 4 ; i < dataArr.size();i++){
        themes.push_back(dataArr[i]);
      }
      
      PinBall newMachine = PinBall(name, year, manufacturer, averageFunRating,themes);
      newMachine.print();
      arr[10 - ::counter] = newMachine;
      ::counter--;
    }
  }
}

vector<string> arrSplit(string dataString){
  string currString = "";
  vector<string> dataArr = {};

  // o(n) space and time
  for (int i = 0; i <= dataString.length(); i++) {
    if(dataString[i] == ',' || dataString.length() == i){
      dataArr.push_back(currString);
      currString = "";
    } 
    else if (dataString[i] != ' '){
      currString += dataString[i];
    } 
    // detect the start of the next word and add a space to currString
    else if(dataString[i+1] != ' ' && dataString[i+1] != ',') {
      if(!currString.empty()) {
        currString += " ";
      }
    }
  }  
  return dataArr;
}

bool createNewMachine(PinBall arr[10]){
  if(counter < 1){
    return false;
  }
  
  string name;
  string manufacturer;
  int year = 0;
  float averageFunRating = 0.0;
  vector<string> themes;
  string input;

  cout << "please enter the name of this machine: ";
  cin.ignore(1);
  getline(cin,name);
  cout << endl;
  cout << "please enter the year this machine was produced: ";
  cin >> year;
  cout << endl;
  cout << "please enter the manufacturer of this machine: ";
  cin.ignore(1);
  getline(cin,manufacturer);
  cout << endl;
  cout << "please enter the average fun rating of this machine: ";
  cin  >> averageFunRating;
  cout << endl;
  cout << "please enter this machine theme(s): ";
  do{
      cin.ignore(1);
      getline(cin,input);
      cout << endl;
      themes.push_back(input);
      cout << "would you like to add another theme? (y) for yes and (n) for no: ";
      cin >> input;
      cout << endl;
      if(input == "y"){
          cout << "please enter another theme for this machine: ";
      }
  } while(input != "n");
  
  PinBall newMachine = PinBall(name,year,manufacturer,averageFunRating,themes);
  newMachine.print();
  arr[10 - ::counter] = newMachine;
  ::counter--;
  return true;
}

bool printAllMachine(PinBall arr[10]){
  if(::counter == 10){
    return false;
  }
  for(int i = 0; i < 10 - counter; i++){
    arr[i].print();
  }
  return true;
}

void printMenu(){
  cout << "1: create a new Pin ball machine" << endl;
  cout << "2: print all machine produced during specified year" << endl;
  cout << "3: print all Pin ball machine" << endl;
  cout << "4: save new machine(s) to a new text file and exit the program" << endl;
}

bool getMachineByYear(PinBall arr[10]){
  if(::counter == 10){
    return false;
  }
  int year = 0;
  cout << "please enter the year of interest: ";
  cin >> year;
  cout << endl;
  
  for(int i = 0; i < 10 - ::counter; i++){
    const PinBall currMachine = arr[i];
    if(currMachine.getYear() == year){
        cout << "Name: " << currMachine.getName() << endl;
        cout << "Manufacturer: " << currMachine.getManufacturer() << endl;
    }
  }
  cout << endl;
  return true;
}

bool writeToFile(PinBall arr[10]){
  if(counter == 10){
    return false;
  }
  ofstream dout;
  dout.open ("output.txt");
  if(dout.is_open()){
    for(int i = 0; i < 10 - ::counter; i++){
      // this making a deep copy of the object might not be as effecient
      PinBall currMachine = arr[i];
      vector<string> themes = currMachine.getTheme();
      dout << "Name: " << currMachine.getName() << endl;
      dout << "Year: " << currMachine.getYear() << endl;
      dout << "Manufacturer: " << currMachine.getManufacturer() << endl;
      dout << "Average Fun Rating: " << currMachine.getAverageFunRating() << endl;
      dout << "Themes: ";
      for(int i = 0 ;i < themes.size() - 1;i++){
          dout << themes[i] << ", ";
      }
      dout << themes.back();
      dout << endl << endl;
    }
    return true;
  } else {
    return false;
  }
}