// Created by Alex Tran
// Today date: Apr, 5, 2023
#include "Book.h"
#include <fstream>

// function prototype
void readFile(vector<Book> & library);
void writeFile(vector<Book> &library, string type);
void insertion_sort(vector<Book> & library);
void selection_sort(vector<Book> & library);
vector<Book> merge_sort(vector<Book> & library);
void quick_sort(vector<Book> & library, int low, int high);
Book stringToBookParser(const string & str);

int main(){
    vector<Book> library;
    readFile(library);

    clock_t start = clock();
    insertion_sort(library);
    clock_t end = clock();
    double runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for insertion_sort algorithm: " << runtime << " seconds" << endl;
    writeFile(library, "insertion_sort");

    start = clock();
    selection_sort(library);
    end = clock();
    runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for selection_sort algorithm: " << runtime << " seconds" << endl;
    writeFile(library, "selection_sort");

    start = clock();
    library = merge_sort(library);
    end = clock();
    runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for merge_sort algorithm: " << runtime << " seconds" << endl;
    writeFile(library, "merge_sort");

    start = clock();
    quick_sort(library, 0, library.size() - 1);
    end = clock();
    runtime = (end - start) / double(CLOCKS_PER_SEC);
    cout << "Run time for quick_sort algorithm: " << runtime << " seconds" << endl;
    writeFile(library, "quick_sort");

    return 0;
}

void swap(Book & first, Book & second) {
    Book temp = first;
    first = second;
    second = temp;
}

// sort by authorLastName
void insertion_sort(vector<Book> &library){
    for(int i = 0; i < library.size(); i++) {
        int currIDX = i;
        while(currIDX > 0 && library[currIDX].getAuthorLastName() < library[currIDX - 1].getAuthorLastName()){
            swap(library[currIDX], library[currIDX - 1]);
            currIDX -= 1;
        }
    }
}

// sort by authorFirstName
void selection_sort(vector<Book> &library){
    for(int i = 0; i < library.size(); i++){
        int minIDX = i;
        for(int j = i; j < library.size(); j++){
            if(library[j].getAuthorFirstName() < library[minIDX].getAuthorFirstName()){
                minIDX = j;
            }
        }
        swap(library[minIDX],library[i]);
    }
}

vector<Book> merge(vector<Book> & a, vector<Book> & b) {
    vector<Book> c;
    int aIdx = 0;
    int bIdx = 0;
    while(aIdx < a.size() && bIdx < b.size()){
        if(a[aIdx].getYear() > b[bIdx].getYear()) {
            c.push_back(b[bIdx++]);
        } else {
            c.push_back(a[aIdx++]);
        }
    }
    while(aIdx < a.size()){
        c.push_back(a[aIdx++]);
    }
    while(bIdx < b.size()){
        c.push_back(b[bIdx++]);
    }
    return c;
}

// sort by year
vector<Book> merge_sort(vector<Book> & library){
    if (library.size() == 1){
        return library;
    }
    int mid = library.size() / 2;
    vector<Book> left(library.begin(), library.begin() + mid);
    vector<Book> right(library.begin() + mid, library.end());
    return merge(left, right);
}

int partition(vector<Book> & arr, int low , int high) {
    float pivot = arr[high].getRating();
    int pointer = low - 1;
    for(int i = low; i < high; i++) {
        if(arr[i].getRating() <= pivot) {
            pointer += 1;
            swap(arr[pointer], arr[i]);
        }
    }
    swap(arr[pointer + 1], arr[high]);
    return pointer + 1;
}

// sort by rating
void quick_sort(vector<Book> &library, int low, int high){
    if(low < high) {
        int pi = partition(library, low, high);
        quick_sort(library, low, pi - 1);
        quick_sort(library, pi + 1, high);
    }
}

void readFile(vector<Book> &library){
    ifstream din ("books.csv");
    string data;
    if (din.is_open())
    {
        while (getline(din,data) )
        {
            Book curr = stringToBookParser(data);
            library.push_back(curr);
        }
        din.close();
    } else {
        cout << "failed";
    }
}

Book stringToBookParser(const string & str) {
    string data[6];
    int currIndex = 0;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ','){
            currIndex += 1;
        } else {
            data[currIndex] += str[i];
        }
    }
    return Book(stoi(data[0]),data[1],data[2],
                data[3],data[4],stof(data[5]));
}

void writeFile(vector<Book> &library, string type) {
    ofstream dout ("/Users/alextran/CLionProjects/LibraryHomework/" + type + ".csv");
    if(dout.is_open()){
        for(int i = 0; i < library.size(); i++) {
            dout << library[i].getYear() << ",";
            dout << library[i].getTitle() << ",";
            dout << library[i].getAuthorFirstName() << ",";
            dout << library[i].getAuthorLastName() << ",";
            dout << library[i].getRating() << endl;
        }
    }
}
