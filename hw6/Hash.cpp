//
// Created by Alex Tran on 4/19/23.
//

#include "Hash.h"

Hash::Hash(){
    this->size = 10;
    this->count = 0;
    this->collision = 0;
    arr = new StudentList[this->size];
}

Hash::Hash(int size){
    this->size = size;
    this->count = 0;
    this->collision = 0;
    arr = new StudentList[size];
}

Hash::Hash(const Hash & h){
    this->size = h.size;
    this->count = h.count;
    this->collision = h.collision;
    arr = new StudentList[h.size];
    for(int i = 0; i < h.size; i++){
        arr[i] = h.arr[i];
    }
}

Hash::~Hash(){
//    cout << "in hash deconstructor" << endl;
    delete[] arr;
}
int Hash::getSize() const {
    return size;
}

const StudentList *Hash::getArr() const {
    return arr;
}

int Hash::getHashValue(string fullName) const {
    int counter = 0;
    for(int i = 0; size_t(i) < fullName.size(); i++) {
        counter += int(fullName[i]);
    }
    return counter % size;
}

bool Hash::hashInsert(Student s) {
    int index = this->getHashValue(s.getFullName());
    collision += arr[index].isEmpty() ? 0 : 1;
    count += 1;
    arr[index].insert(s);
    return true;
}

Student Hash::search(string fullName) const {
    int index = this->getHashValue(fullName);
    cout << "Search result: ";
    arr[index].search(fullName).print();
    return arr[index].search(fullName);
}

bool Hash::hashUpdate(string fullName, Student newProfile) {
    if(search(fullName).getFullName() == ""){
        return false;
    }
    const int idx = getHashValue(fullName);
    arr[idx].updateProfile(fullName, newProfile);
    return true;
}

void Hash::hashDelete(Student s) {
    int index = this->getHashValue(s.getFullName());
    if(arr[index].deleteStudent(s)) {
        count -= 1;
        collision -= arr[index].isEmpty() ? 0 : 1;
    }
}

void Hash::printStat() const {
    cout << "Collision: " << this->collision << endl;
    cout << "Count: " << this->count << endl;
    cout << "Size: " << this->size << endl;
}

void Hash::printHash() const {
    cout << "Collision: " << this->collision << endl;
    cout << "Count: " << this->count << endl;
    cout << "Size: " << this->size << endl;
    for(int i = 0; i < size; i++){
        arr[i].printList();
    }
}
