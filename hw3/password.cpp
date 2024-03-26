//
// Created by Alex Tran on 2/24/23.
//

#include "password.h"

Password::Password(const string &plaintext, int rank, const string &hash) {
    this->plaintext = plaintext;
    this->rank = rank;
    this->hash = hash;
}

Password::Password(const Password & copy){
    this->plaintext = copy.plaintext;
    this->rank = copy.rank;
    this->hash = copy.hash;
}

Password::~Password(){

}

const string &Password::getPlaintext() const {
    return plaintext;
}

void Password::setPlaintext(const string &plaintext) {
    Password::plaintext = plaintext;
}

int Password::getRank() const {
    return rank;
}

void Password::setRank(int rank) {
    Password::rank = rank;
}

const string &Password::getHash() const {
    return hash;
}

void Password::setHash(const string & hash) {
    Password::hash = hash;
}

void Password::print() const {
    cout << plaintext << " ";
    cout << rank << " ";
    cout << hash << endl;
}