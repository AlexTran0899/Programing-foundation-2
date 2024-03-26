//
// Created by Alex Tran on 2/7/23.
//

#include "RestaurantNode.h"
int RestaurantNode::currentID = 0;

RestaurantNode::RestaurantNode() {
    this->name = "";
    this->rating = 0.0;
    this->mealName = "";
    this->mealType = "";
    this->price = 0.0;
    this->next = NULL;
}

RestaurantNode::RestaurantNode(const string name, const float rating, const string mealName, const string mealType,
                               const float price) {
    this->ID     = currentID++;
    this->name = name;
    this->rating = rating;
    this->mealName = mealName;
    this->mealType = mealType;
    this->price = price;
    this->next = NULL;
}

RestaurantNode::RestaurantNode(const RestaurantNode & copy) {
    this->ID     = copy.ID;
    this->name = copy.name;
    this->rating = copy.rating;
    this->mealName = copy.mealName;
    this->mealType = copy.mealType;
    this->price = copy.price;
    this->next = NULL;
}

bool RestaurantNode::operator == (RestaurantNode & node) const
{
    return ( name == node.getName() &&
         rating == node.getRating() &&
         mealName == node.getMealName() &&
         mealType == node.getMealType() &&
         price == node.getPrice());
}
bool RestaurantNode::operator != (RestaurantNode & node) const
{
    return !( name == node.getName() &&
             rating == node.getRating() &&
             mealName == node.getMealName() &&
             mealType == node.getMealType());
}


RestaurantNode::~RestaurantNode(){

}

void RestaurantNode::setName(const string & name) {
    this->name = name;
}
void RestaurantNode::setRating(const float & rating) {
    this->rating = rating;
}

void RestaurantNode::setMealName(const string & mealName) {
    this->mealName = mealName;
}

void RestaurantNode::setMealType(const string & mealType) {
    this->mealType = mealType;
}

void RestaurantNode::setPrice(const float & price) {
    this->price = price;
}

string RestaurantNode::getName() const {
    return name;
}

float RestaurantNode::getRating() const {
    return rating;
}

string RestaurantNode::getMealName() const {
    return mealName;
}

string RestaurantNode::getMealType() const {
    return mealType;
}

float RestaurantNode::getPrice() const {
    return price;
}

int RestaurantNode::getID() const{
    return this->ID;
}

void RestaurantNode::print() const {
    cout << fixed << setprecision(2);
    cout << setw(5) << left <<  this->ID;
    cout << setw(25) << this->name ;
    cout << setw(15) << this->rating;
    cout << setw(25) << this->mealName;
    cout << setw(15) << this->mealType;
    cout << setw(15) << this->price << endl;
}
