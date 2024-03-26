#ifndef PINBALL_H
#define PINBALL_H

#include <iostream>
#include <vector>

using namespace std;

class PinBall {
public:
  PinBall();
  PinBall(const string name,
          const int year,
          const string manufacturer,
          const float averageFunRating,
          const vector<string> theme
);

  PinBall(const PinBall & copy);
  ~PinBall();
  // getter:
  string getName() const;
  int getYear() const;
  string getManufacturer() const;
  float getAverageFunRating() const;
  vector<string> getTheme() const;
  // setter:
  void setName(string name);
  void setYear(int year);
  void setManufacturer(string manufacturer);
  void setAverageFunRating(float avgFunRt);
  void setTheme(vector<string> themes);
  // methods:
  void print() const;

private:
  string name;
  int year;
  string manufacturer;
  float averageFunRating;
  vector<string> themes; 
};

#endif