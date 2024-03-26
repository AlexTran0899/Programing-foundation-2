//
// Created by Alex Tran on 4/29/23.
//

#ifndef HW7_BOOK_H
#define HW7_BOOK_H

#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    int year;
    string title;
    string lastName;
    string firstName;
    string genre;
    float rating;
public:
    Book();
    Book(int year, string title, string lastName, string firstName, string genre, float rating);
    Book(const Book & copy);
    ~Book();

    // getter
    int getYear() const;
    string getTitle() const;
    string getLastName() const;
    string getFirstName() const;
    string getGenre() const;
    float getRating() const;

    // setter
    void setYear(int year);
    void setTitle(string title);
    void setLastName(string lastName);
    void setFirstName(string firstName);
    void setGenre(string genre);
    void setRating(float rating);

    // util
    void print() const;

    // operator
    bool operator < (Book & b) const;
    bool operator > (Book & b) const;
    bool operator == (Book & b) const;

};

#endif //HW7_BOOK_H
