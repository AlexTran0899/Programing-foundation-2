//
// Created by Alex Tran on 4/29/23.
//

#include "Book.h"


Book::Book() {
    this->year = 0000;
    this->title = "";
    this->lastName = "";
    this->firstName= "";
    this->genre = "";
    this->rating = 0.0;
}

Book::Book(int year, string title, string lastName, string firstName, string genre, float rating) {
    this->year = year;
    this->title = title;
    this->lastName = lastName;
    this->firstName= firstName;
    this->genre = genre;
    this->rating = rating;
}

Book::Book(const Book & copy) {
    this->year = copy.year;
    this->title = copy.title;
    this->lastName = copy.lastName;
    this->firstName= copy.firstName;
    this->genre = copy.genre;
    this->rating = copy.rating;
}

Book::~Book() {
    // destructor
}

int Book::getYear() const {
    return year;
}

void Book::setYear(int year) {
    Book::year = year;
}


string Book::getTitle() const {
    return title;
}

void Book::setTitle(string title) {
    Book::title = title;
}

string Book::getLastName() const {
    return lastName;
}

void Book::setLastName(string lastName) {
    Book::lastName = lastName;
}

string Book::getFirstName() const {
    return firstName;
}

void Book::setFirstName(string firstName) {
    Book::firstName = firstName;
}

string Book::getGenre() const {
    return genre;
}

void Book::setGenre(string genre) {
    Book::genre = genre;
}

float Book::getRating() const {
    return rating;
}

void Book::setRating(float rating) {
    Book::rating = rating;
}

void Book::print() const {
    cout << this->year << ", ";
    cout << this->title << ", ";
    cout << this->lastName << ", ";
    cout << this->firstName << ", ";
    cout << this->genre << ", ";
    cout << this->rating << endl;
}

bool Book::operator < (Book & b) const {
    return year < b.year;
}
bool Book::operator > (Book & b) const {
    return year > b.year;
}
bool Book::operator == (Book & b) const {
    return year == b.year;
}


