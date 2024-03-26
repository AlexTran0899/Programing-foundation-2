#include "PinBall.h"

PinBall::PinBall(){
  this->name             = "";
  this->year             = 0;
  this->manufacturer     = "";
  this->averageFunRating = 0.0;
  this->themes           = {};
}

PinBall::PinBall(string name,
                int year,
                string manufacturer,
                float averageFunRating,
                vector<string> themes){
  this->name              = name;
  this->year              = year;
  this->manufacturer      = manufacturer;
  this->averageFunRating  = averageFunRating;
  this->themes            = themes;
}

PinBall::PinBall(const PinBall & copy){
    this->name             = copy.name;
    this->year             = copy.year;
    this->manufacturer     = copy.manufacturer;
    this->averageFunRating = copy.averageFunRating;
    this->themes           = copy.themes;
}
PinBall::~PinBall(){
  
}
// getter:
string PinBall::getName() const {
  return this->name;
}
int PinBall::getYear() const {
  return this->year;
}
string PinBall::getManufacturer() const {
  return this->manufacturer;
}
float PinBall::getAverageFunRating() const {
  return this->averageFunRating;
}
vector<string> PinBall::getTheme() const {
  return this->themes;
}
// setter:
void PinBall::setName(string name){
  this->name = name;
}
void PinBall::setYear(int year){
  this->year = year;
}
void PinBall::setManufacturer(string manufacturer){
  this->manufacturer = manufacturer;
}
void PinBall::setAverageFunRating(float avgFunRt){
  this->averageFunRating = avgFunRt;
}
void PinBall::setTheme(vector<string> themes){
  this->themes = themes;
}

// methods:
void PinBall::print() const {
  cout << "Name: " << this->name << endl;
  cout << "Year: " << this->year << endl;
  cout << "Manufacturer: " << this->manufacturer << endl;
  cout << "Average Fun Rating: " << this->averageFunRating << endl;
  cout << "Themes: ";
  for(int i = 0 ;i < this->themes.size() - 1;i++){
      cout << this->themes[i] << ", ";
  }
  cout << this->themes.back();
  cout << endl << endl;
}
