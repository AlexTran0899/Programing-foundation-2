#include "Hash.h"
#include <fstream>



bool readfile(string fileDir, Hash & h);
Student stringToObj(string str);
void updateStudentInfo(Hash & h);
void printMenu();
void findStudentByFullname(const Hash & h);
Student createStudentFromUserInput();

int main() {
    Hash h(300);
    readfile("student-dataset.txt", h);
    char input;
    do {
        printMenu();
        cin >> input;
        switch(input){
            case '5':
                h.printHash();
                break;
            case '4':
                findStudentByFullname(h);
                break;
            case '3':
                h.hashInsert(createStudentFromUserInput());
                break;
            case '2':
                h.hashDelete(createStudentFromUserInput());
                break;
            case '1':
                updateStudentInfo(h);
                break;
            case '0':
                h.printStat();
                cout << "good bye..." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
    } while(input != '0');
    return 0;
}

void printMenu() {
    cout << "Please select one of the following: " << endl;
    cout << "5: print all student" << endl;
    cout << "4: find student by full name" << endl;
    cout << "3: create student" << endl;
    cout << "2: delete student" << endl;
    cout << "1: update student info" << endl;
    cout << "0: exit the program" << endl;
}

bool readfile(string fileDir, Hash & h){
    ifstream din(fileDir);
    string dataString;
    if ( din.is_open() ) {
        while(din.good()){
            getline(din, dataString);
            h.hashInsert(stringToObj(dataString));
        }
        din.close();
    }
    return true;
}

Student stringToObj(string str) {
    string arr[5];
    string curr;
    int currIdx = 0;
    for(int i = 0; size_t(i) <= str.size(); i++){
        if(str[i] == ',' || size_t(i) == str.size()){
            arr[currIdx] = curr;
            curr = "";
            currIdx += 1;
        } else {
            curr += str[i];
        }
    }
    return Student(arr[0], arr[1] ,arr[2], arr[3][0], stof(arr[4]), nullptr);
}

void updateStudentInfo(Hash & h) {
    Student temp = createStudentFromUserInput();
    h.hashUpdate(temp.getFullName(), temp);
}

Student createStudentFromUserInput(){
    string fullName;
    string country;
    string city;
    char gender;
    float gpa;
    cin.ignore();
    cout << "Please enter student name (case sensitive): ";
    getline(cin, fullName);
    cout << endl;

    cout << "country: ";
    getline(cin , country);
    cout << endl;

    cout << "city: ";
    getline(cin, city);
    cout << endl;

    cout << "gender: ";
    cin >> gender;
    cout << endl;

    cout << "gpa: ";
    cin >> gpa;
    cout << endl;

    Student temp(fullName, country, city, gender, gpa, nullptr);
    return temp;
}

void findStudentByFullname(const Hash & h) {
    string fullName;
    cin.ignore();
    cout << "Please enter student full name(case sensitive): ";
    getline(cin, fullName);
    cout << endl;
    h.search(fullName);
}






















