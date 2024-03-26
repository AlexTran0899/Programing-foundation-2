//
// Created by Alex Tran on 4/19/23.
//

#ifndef HW6_STUDENTLIST_H
#define HW6_STUDENTLIST_H
#include "Student.h"

class StudentList {
public:
    StudentList();
//    StudentList(const StudentList & copy);
    ~StudentList();
    void insert(Student s);
    bool deleteStudent(Student s);
    bool updateProfile(string fullName, Student newProfile);
    Student search(string fullName);
    bool isEmpty() const;
    void printList() const;

private:
    Student * head;
};


#endif //HW6_STUDENTLIST_H
