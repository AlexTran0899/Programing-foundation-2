#include "Tree.h"
#include <fstream>

void readFile(Tree & tree);
Book decoder(string data);
void printMenu();
void insertBook(Tree & tree);

int main() {
    string input;
    int selected;
    Tree tree;
    string title;
    readFile(tree);
    do {
        printMenu();
        getline(cin, input);
        selected = stoi(input);
        cout << endl;
        switch(selected) {
            case 1:
                readFile(tree);
                cout << "file loaded" << endl;
                break;
            case 2:
                cout << "Please enter book title: ";
                getline(cin,title);
                if(tree.getBookByTitle(title).getTitle() != "") {
                    tree.getBookByTitle(title).print();
                } else {
                    cout << "Book not found" << endl;
                }
                break;
            case 3:
                insertBook(tree);
                break;
            case 4:
                cout << "Please enter book title: ";
                getline(cin,title);
                cout << endl;
                tree.deleteBook(title);
                break;
            case 5:
                tree.print();
                break;
            case 0:
                cout << "exiting program..." << endl;
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
    } while(selected != 0);


    return 0;
}

void printMenu() {
    cout << "1: Load data into tree" << endl;
    cout << "2: Search for a book by title" << endl;
    cout << "3: Insert a book" << endl;
    cout << "4: Delete a book" << endl;
    cout << "5: print all the book" << endl;
    cout << "0: exit program" << endl;
    cout << "Please select: ";
}

void readFile(Tree & tree) {
    ifstream din("books.csv");
    string data;

    if(din.is_open()){
        while(din.good()){
            getline(din, data);
            tree.insertBook(decoder(data));
        }
        din.close();
    }
}

Book decoder(string data) {
    string arr[6] = {};
    string curr = "";
    int idx = 0;

    for(int i = 0; i < signed(data.size() + 1); i++) {
        if(data[i] == ',' || i == signed(data.size())) {
            arr[idx] = curr;
            curr = "";
            idx++;
        } else {
            curr += data[i];
        }
    }
    return Book(stoi(arr[0]) , arr[1], arr[2], arr[3], arr[4], stof(arr[5]));
}

void insertBook(Tree & tree) {
    string year, title, lastName,firstName, genre, rating;

    cout << "Please enter book release year: ";
    getline(cin, year);
    cout << endl;

    cout << "Please enter book title: ";
    getline(cin, title);
    cout << endl;

    cout << "Please enter author last name: ";
    getline(cin, lastName);
    cout << endl;

    cout << "Please enter author first name: ";
    getline(cin, firstName);
    cout << endl;

    cout << "Please enter book genre: ";
    getline(cin, genre);
    cout << endl;

    cout << "Please enter book rating: ";
    getline(cin, rating);
    cout << endl;

    tree.insertBook(Book(stoi(year),title, lastName, firstName, genre, stof(rating)));

    cout << "book inserted" << endl;
}
