//
// Created by Alex Tran on 4/19/23.
//

#ifndef HW6_STUDENT_H
#define HW6_STUDENT_H
#include <iostream>
using namespace  std;

class Student {
public:
    Student();
    Student(string fullName, string country, string city, char gender, float gpa, Student * next);
    Student(const Student & copy);
    ~Student();

    //getter
    string getFullName() const;
    string getCountry() const;
    string getCity() const;
    char getGender() const;
    float getGpa() const;
    void setGpa(float gpa);
    Student * getNext() const;

    //setter
    void setFullName(const string fullName);
    void setCountry(const string country);
    void setCity(const string city);
    void setGender(char gender);
    void setNext(Student * next);

    // print
    void print() const;
    bool operator == (Student & s) const;
    bool operator != (Student & s) const;

private:
    string fullName;
    string country;
    string city;
    char gender;
    float gpa;
    Student * next;
};


#endif //HW6_STUDENT_H
