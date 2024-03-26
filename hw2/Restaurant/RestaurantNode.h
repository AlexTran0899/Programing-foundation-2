//
// Created by Alex Tran on 2/7/23.
//

#ifndef RESTAURANTLIST_RESTAURANTNODE_H
#define RESTAURANTLIST_RESTAURANTNODE_H

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
class RestaurantNode {
public:
    RestaurantNode * next;
    RestaurantNode();
    RestaurantNode(const string name, const float rating, const string mealName, const string mealType, const float price);
    RestaurantNode(const RestaurantNode & copy);
    ~RestaurantNode();

    //setter
    void setName(const string & name);
    void setRating(const float & rating);
    void setMealName(const string & mealName);
    void setMealType(const string & mealType);
    void setPrice(const float & price);

    //getter
    string getName() const;
    float getRating() const;
    string getMealName() const;
    string getMealType() const;
    float getPrice() const;
    int getID() const;

    // util
    bool operator == (RestaurantNode & nodes) const;
    bool operator != (RestaurantNode & nodes) const;
    void print() const;

private:
    static int currentID;
    int ID;
    string name;
    float rating;
    string mealName;
    string mealType;
    float price;
};


#endif //RESTAURANTLIST_RESTAURANTNODE_H
