//
// Created by Alex Tran on 4/19/23.
//

#ifndef HW6_HASH_H
#define HW6_HASH_H
#include "StudentList.h"
#include <array>

class Hash {
public:
Hash();
Hash(int size);
Hash(const Hash & h);
~Hash();

// getter
int getSize() const;
const StudentList *getArr() const;
int getHashValue(string fullName) const;

// util
bool hashInsert(Student s);
void printHash() const;
void printStat() const;
Student search(string fullName) const;
void hashDelete(Student s);
bool hashUpdate(string fullName, Student newProfile);

private:
    int size;
    int count;
    int collision = 0;
    StudentList * arr;
};

#endif //HW6_HASH_H
