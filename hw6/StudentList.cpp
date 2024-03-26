//
// Created by Alex Tran on 4/19/23.
//

#include "StudentList.h"

StudentList::StudentList() {
    this->head = nullptr;
}
//
//StudentList::StudentList(const StudentList & copy) {
//    this->head = nullptr;
//    Student * curr = copy.head;
//    Student * temp = head;
//    while(curr != nullptr) {
//        Student temp = *curr;
//        temp = *new Student(*curr);
//        curr = curr->getNext();
//    }
//}

StudentList::~StudentList() {
    while(head != nullptr){
        Student * temp = head->getNext();
        delete head;
        head = temp;
    }
}

void StudentList::insert(Student s) {
    if(this->search(s.getFullName()).getFullName() != ""){
        return;
    }

    Student * curr = new Student(s);
    curr->setNext(head);
    this->head = curr;
}

bool StudentList::deleteStudent(Student s) {
    // if list is empty, return out
    if(head == nullptr) {
        return false;
    }
    // if the item is the first item in the list
    if(*head == s) {
        head = head->getNext();
        return true;
    }

    Student * curr = head;
    Student * prev = new Student;
    prev->setNext(head);
    while(curr != nullptr) {
        if(*curr == s){
            prev->setNext(curr->getNext());
            return true;
        } else {
            curr = curr->getNext();
            prev = prev->getNext();
        }
    }
    return false;
}


bool StudentList::updateProfile(string fullName, Student newProfile) {
    if(head == nullptr) {
        return false;
    }
    Student * curr = new Student;
    curr->setNext(head);
    while(curr != nullptr) {
        if(curr->getFullName() == fullName) {
            curr->setCity(newProfile.getCity());
            curr->setCountry(newProfile.getCountry());
            curr->setGender(newProfile.getGender());
            curr->setGpa(newProfile.getGpa());
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

Student StudentList::search(string fullName) {
    Student empty;
    if(head == nullptr) {
        return empty;
    }
    Student * curr = head;
    while(curr != nullptr) {
        if(curr->getFullName() == fullName) {
            return *curr;
        }
        curr = curr->getNext();
    }
    return empty;
}

void StudentList::printList() const {
    Student * temp = head;
    while(temp != nullptr) {
        temp->print();
        temp = temp->getNext();
    }
}

bool StudentList::isEmpty() const {
    if(this->head == nullptr){
        return true;
    } else {
        return false;
    }
}