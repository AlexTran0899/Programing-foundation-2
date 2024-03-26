//
// Created by Alex Tran on 4/5/23.
//

#ifndef SORTING2_BOOK_H
#define SORTING2_BOOK_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Book {
public:
    Book();
    Book(int year, const string &title, const string &authorFirstName, const string &authorLastName,
         const string &genre, float rating);
    Book(const Book & book);
    ~Book();

    // getter
    int getYear() const;
    string getTitle() const;
    string getAuthorFirstName() const;
    string getAuthorLastName() const;
    string getGenre() const;
    float getRating() const;

    // setter
    void setYear(int year);
    void setTitle(const string title);
    void setAuthorFirstName(const string authorFirstName);
    void setAuthorLastName(const string authorLastName);
    void setGenre(const string genre);
    void setRating(float rating);

    // methods;
    void print() const;

private:
    int year;
    string title;
    string authorFirstName;
    string authorLastName;
    string genre;
    float rating;
};

#endif //SORTING2_BOOK_H
