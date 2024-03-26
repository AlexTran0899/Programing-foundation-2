//
// Created by Alex Tran on 3/7/23.
//

#include "stack.h"
Stack::Stack(){
    this->count = 0;
}

Stack::Stack(const Stack& copy){
    count = copy.count;
    for(int i = 0; i < (signed)copy.data.size(); i++){
        this->data[i] = copy.data[i];
    }
}
Stack::~Stack(){

}

void Stack::push(const int number){
    this->data.push_back(number);
    this->count++;
}

int Stack::pop(){
    if(isEmpty()) return -1;
    int temp = this->data[count];
    this->count--;
    this->data.pop_back();
    return temp;
}

int Stack::top() const{
    return this->data[count];
}

bool Stack::isFull(){
    try {
        this->data.push_back(42);
        return false;
    } catch (std::bad_alloc const &) {
        cout << "out of memory" << endl;
        return true;
    }
}

bool Stack::isEmpty() const{
    return (this->count == 0);
}

int Stack::getCount() const{
    return this->count;
}

void Stack::print() const{
    cout << "Numbers: ";
    for(int i = 0; i < (signed)this->data.size(); i++){
        cout << this->data[i] << " ";
    }
    cout << endl;
}
