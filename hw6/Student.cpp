//
// Created by Alex Tran on 4/19/23.
//

#include "Student.h"

Student::Student() {
    fullName = "";
    country = "";
    city = "";
    gender = '\0';
    gpa = 0.0;
    next = nullptr;
}

Student::Student(string fullName, string country,string city, char gender, float gpa, Student * next) {
    this->fullName = fullName;
    this->country = country;
    this->city = city;
    this->gender = gender;
    this->gpa = gpa;
    this->next = next;
}

Student::Student(const Student & copy) {
//    cout << "in the copy" << endl;
    this->fullName = copy.fullName;
    this->country = copy.country;
    this->city = copy.city;
    this->gender = copy.gender;
    this->gpa = copy.gpa;
    this->next = nullptr;
}
Student::~Student(){
//    cout << "in the destructor for student" << endl;
}

string Student::getFullName() const {
    return fullName;
}

void Student::setFullName(const string fullName) {
    Student::fullName = fullName;
}

string Student::getCountry() const {
    return country;
}

void Student::setCountry(const string country) {
    Student::country = country;
}

string Student::getCity() const {
    return city;
}

void Student::setCity(const string city) {
    Student::city = city;
}

char Student::getGender() const {
    return gender;
}

void Student::setGender(char gender) {
    Student::gender = gender;
}

float Student::getGpa() const {
    return gpa;
}

void Student::setGpa(float gpa) {
    Student::gpa = gpa;
}

Student *Student::getNext() const {
    return next;
}

void Student::setNext(Student * next) {
    Student::next = next;
}

bool Student::operator == (Student & s) const {
    return (fullName == s.getFullName() &&
            country == s.getCountry() &&
            city == s.getCity() &&
            gender == s.getGender() &&
            gpa == s.getGpa());
}
// DeMorgan's law https://www.youtube.com/watch?v=-LW2lGHv0GE
bool Student::operator != (Student & s) const {
    return (fullName != s.getFullName() ||
            country != s.getCountry() ||
            city != s.getCity() ||
            gender != s.getGender() ||
            gpa != s.getGpa());
}

void Student::print() const {
    cout << this->fullName << " ";
    cout << this->country << " ";
    cout << this->city << " ";
    cout << this->gender << " ";
    cout << this->gpa << " " << endl;
}