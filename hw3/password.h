//
// Created by Alex Tran on 2/24/23.
//

#ifndef HW3_PASSWORD_H
#define HW3_PASSWORD_H
#include <iostream>
using namespace std;


class Password {
public:
    // constructor and destructor
    Password(const string &plaintext, int rank, const string &hash);
    Password(const Password & copy);
    ~Password();

    // getter
    const string &getPlaintext() const;
    int getRank() const;
    const string &getHash() const;

    // setter
    void setPlaintext(const string &plaintext);
    void setRank(int rank);
    void setHash(const string &hash);

    // print
    void print() const;

public:
    string plaintext;
    int rank;
    string hash;
};


#endif //HW3_PASSWORD_H
