//
// Created by Alex Tran on 2/7/23.
//

#include "RestaurantList.h"
RestaurantList::RestaurantList() {
    this->head = nullptr;
}

RestaurantList::RestaurantList(const RestaurantList & copy) {

}

RestaurantList::~RestaurantList() {

}

bool RestaurantList::addMeal(RestaurantNode & meal) {
    RestaurantNode * temp = new RestaurantNode(meal);
    RestaurantNode * curr = head;

    if(checkIfItemAlreadyExits(meal)){
        return false;
    }

    if(!curr || curr->getPrice() > temp->getPrice()){
        temp->next = head;
        return head = temp;
    }

    while(curr->next != NULL && curr->next->getPrice() < temp->getPrice()) {
        curr = curr->next;
   }

    temp->next = curr->next;
    curr->next = temp;

    return true;
}

float RestaurantList::highestPrice() {
    float maxPrice = 0.0;
    RestaurantNode * curr = head;

    while(curr){
        maxPrice = max(maxPrice, curr->getPrice());
        curr = curr->next;
    }
    return maxPrice;
}

bool RestaurantList::changePrice() {
    RestaurantNode * curr = head;
    RestaurantNode * prev = nullptr;

    int ID = 0;
    int newPrice = 0;

    cout << "Please enter item ID: ";
    cin >> ID;
    cout << "Please enter item new price: ";
    cin >> newPrice;

    while(curr != nullptr){
        if(curr->getID() == ID){
            curr->setPrice(newPrice);
            // remove the curr node
            if(!prev){
                this->head = curr->next;
            }else{
                prev->next = curr->next;
            }
            // insert it back to the list to be sorted.
            addMeal(*curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
}

void RestaurantList::printHeader() const {
    cout << setw(5) << left << "ID";
    cout << setw(25) << "Name";
    cout << setw(15) << "Rating";
    cout << setw(25) << "Item";
    cout << setw(15) << "Type";
    cout << setw(15) << "Price" << endl;
}

void RestaurantList::print() {
    RestaurantNode * curr = head;
    printHeader();

    while(curr != nullptr){
        curr->print();
        curr = curr->next;
    }
}

bool RestaurantList::checkIfItemAlreadyExits(RestaurantNode & node) const{
    RestaurantNode * curr = head;
    while(curr){
        if(*curr == node){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

