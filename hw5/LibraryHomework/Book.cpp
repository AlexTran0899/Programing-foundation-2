//
// Created by Alex Tran on 4/5/23.
//

#include "Book.h"

Book::Book() {
    this->year = 0;
    this->title = "";
    this->authorFirstName = "";
    this->authorLastName = "";
    this->genre = "";
    this->rating = 0.0;
}

Book::Book(int year, const string &title, const string &authorFirstName, const string &authorLastName,
           const string &genre, float rating) {
    this->year = year;
    this->title = title;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->genre = genre;
    this->rating = rating;
}

Book::Book(const Book & copy) {
    this->year = copy.year;
    this->title = copy.title;
    this->authorFirstName = copy.authorFirstName;
    this->authorLastName = copy.authorLastName;
    this->genre = copy.genre;
    this->rating = copy.rating;
}

Book::~Book() {

}

int Book::getYear() const {
    return year;
}
string Book::getTitle() const {
    return title;
}

string Book::getAuthorFirstName() const {
    return authorFirstName;
}

string Book::getAuthorLastName() const {
    return authorLastName;
}

string Book::getGenre() const {
    return genre;
}

float Book::getRating() const {
    return rating;
}

void Book::setYear(int year) {
    Book::year = year;
}

void Book::setTitle(const string title) {
    Book::title = title;
}

void Book::setAuthorFirstName(const string authorFirstName) {
    Book::authorFirstName = authorFirstName;
}

void Book::setAuthorLastName(const string authorLastName) {
    Book::authorLastName = authorLastName;
}

void Book::setGenre(const string genre) {
    Book::genre = genre;
}

void Book::setRating(float rating) {
    Book::rating = rating;
}

void Book::print() const {
    cout << year << endl;
    cout << title << endl;
    cout << authorFirstName << endl;
    cout << authorLastName << endl;
    cout << genre << endl;
    cout << rating << endl;
}
