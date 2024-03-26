//
// Created by Alex Tran on 3/7/23.
//

#include "queue.h"

Queue::Queue() {
    count = 0;
}


Queue::Queue(const Queue& copy){
    count = copy.count;
    for(int i = 0; i < (signed)copy.data.size(); i++){
        this->data[i] = copy.data[i];
    }
}
Queue::~Queue(){

}

void Queue::insert(const int number){
    this->data.push_back(number);
    this->count++;
}

int Queue::remove(){
    if(isEmpty()) return -1;
    this->count--;
    int temp = this->data[0];
    this->data.erase(this->data.begin());
    return temp;
}

bool Queue::isFull(){
    try {
        this->data.push_back(42);
        return false;
    } catch (std::bad_alloc const &) {
        cout << "out of memory" << endl;
        return true;
    }
}

bool Queue::isEmpty() const{
    return (this->count == 0);
}

int Queue::getCount() const{
    return this->count;
}

void Queue::print() const{
    cout << "Numbers: ";
    for(int i = 0; i < (signed)this->data.size(); i++){
        cout << this->data[i] << " ";
    }
    cout << endl;
}