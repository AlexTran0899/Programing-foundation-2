//----------------------------------------------
// Purpose: Starter code for homework 3 - you should use this code
// to read in your files instead of starting from scratch!
//----------------------------------------------

#include "password.h"
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;


// PROVIDED
bool readFile(string filename, vector<Password> &list)
{
    string password;
    string rank;
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din, password, ','))
    {
        getline(din, rank, ',');
        getline(din, hash);
        Password temp (password,stoi(rank),hash);
        list.push_back(temp);
    }
    din.close();
    return 1;
}
// PROVIDED
bool readFile_given_hashes(string filename, vector<string> &list)
{
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din,hash)){
        list.push_back(hash);
    }
    return 1;
}


// ADD SEARCH FUNCTIONS HERE!!
void print_menu(){
    cout << endl;
    cout << "Please select one of the follow: " << endl;
    cout << "5: find all password in a range." << endl;
    cout << "4: print a password rank and hash value." << endl;
    cout << "3: find hash" << endl;
    cout << "2: compare binary search to linear search" << endl;
    cout << "1: iterative binary search for password" << endl;
    cout << "0: exit program." << endl;
}

int idx_locator_rec_password(vector<Password> & data, int low, int high, string target){
    int mid = low + ((high - low) / 2);
    if (low > high){
        cout << "password \"" << target << "\" not found." << endl;
        return -1;
    }

    if(data[mid].getPlaintext() == target){
        return mid;
    } else if(data[mid].getPlaintext() < target){
        return idx_locator_rec_password(data, mid + 1, high, target);
    } else {
        return idx_locator_rec_password(data, low, mid - 1, target);
    }
}

void search_range(vector<Password> & data){
    string word1;
    string word2;
    cout << "Please enter the starting password: ";
    cin >> word1;
    cout << endl;

    cout << "Please enter the ending password: ";
    cin >> word2;
    cout << endl;

    int start_idx = idx_locator_rec_password(data,0,data.size() - 1,word1 < word2 ? word1 : word2);
    int end_idx = idx_locator_rec_password(data,0,data.size() - 1,word1 < word2 ? word2 : word1);

    if(start_idx == -1 || end_idx == -1){
        cout << "cannot find the specified password range" << endl;
        return;
    }
    for(int i = start_idx; i <= end_idx; i++){
        data[i].print();
    }
}

void search_password(vector<Password> & data){
    string target;
    cout << "Please enter the password you would like to search for: ";
    cin >> target;
    cout << endl;

    int idx = idx_locator_rec_password(data,0, data.size() - 1, target);

    if(idx != -1){
        data[idx].print();
    }
}

int idx_locator_rec_hash(vector<Password> & data, int low, int high, int target){
    int mid = low + ((high - low) / 2);
    if (low > high){
        cout << "hash not found." << endl;
        return -1;
    }
    int hash_converted = stoi(data[mid].getHash(),0,16);

    if(hash_converted == target){
        return mid;
    } else if(hash_converted < target){
        return idx_locator_rec_hash(data, mid + 1, high, target);
    } else {
        return idx_locator_rec_hash(data, low, mid - 1, target);
    }
}

void search_hash(vector<Password> & data){
    string hash_to_search;
    cout << "Please enter the hash you wish to search: ";
    cin >> hash_to_search;
    cout << endl;

    int converted_hash_to_search = stoi(hash_to_search, 0 , 16);
    int idx = idx_locator_rec_hash(data,0,data.size() - 1, converted_hash_to_search);
    if(idx != -1){
        data[idx].print();
    }
}

void password_search_performance_compare(vector<Password> & data){
    string password_to_search;
    cout << "Please enter a password to search: ";
    cin >> password_to_search;
    cout << endl;

    clock_t binaryTime = clock();
    int idx = idx_locator_rec_password(data, 0, data.size() - 1, password_to_search);
    if(idx == -1) return;
    binaryTime = clock() - binaryTime;

    clock_t linearTime = clock();
    for(int i = 0; (unsigned)i < data.size() - 1; i++){
        if(data[i].getPlaintext() == password_to_search){
            break;
        }
    }
    linearTime = clock() - linearTime;

    if(binaryTime < linearTime){
        cout << "Binary search is " << linearTime / binaryTime << " times quicker than linear search" << endl;
    } else {
        cout << "Linear search is " << binaryTime / linearTime << " times quicker than binary search" << endl;
    }
}

void iterative_binary_search(vector<Password> & data){
    string target;
    cout << "Please enter the password you wish to use binary search iteratively: ";
    cin >> target;
    cout << endl;

    int low = 0;
    int high = data.size() - 1;

    while(low <= high){
        int mid = low + ((high - low) / 2);
        if(data[mid].getPlaintext() == target){
            cout << mid << endl;
            data[mid].print();
            return;
        }
        if(target > data[mid].getPlaintext()){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "unable to find password" << endl;
}

//----------------------------------------------
int main()
{
    //vector for hash, password sorted file
    vector<Password> hashes, passwords;
    //vector for hashes to search for
    vector<string> given_hashes;
    readFile("sorted_hash_indexed_list.txt",hashes);
    readFile("sorted_password_indexed_list.txt",passwords);
    readFile_given_hashes("hashes_to_search.txt",given_hashes);
    // ADD YOUR MENU, USER CHOICE, AND IMPLEMENT MENU OPTIONS HERE

    char input = '\0';
    do{
        print_menu();
        cin >> input;

        switch(input){
            case '5':
                search_range(passwords);
                break;
            case '4':
                search_password(passwords);
                break;
            case '3':
                search_hash(hashes);
                break;
            case '2':
                password_search_performance_compare(passwords);
                break;
            case '1':
                iterative_binary_search(passwords);
                break;
            case '0':
                cout << "Good bye" << endl;
                break;
            default:
                cout << "invalid input" << endl;
        }
    } while(input != '0');

    return 0;
}
