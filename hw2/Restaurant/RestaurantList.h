//
// Created by Alex Tran on 2/7/23.
//

#ifndef RESTAURANTLIST_RESTAURANTLIST_H
#define RESTAURANTLIST_RESTAURANTLIST_H
#include "RestaurantNode.h"

class RestaurantList {

public:
    RestaurantList();
    RestaurantList(const RestaurantList & copy);
    ~RestaurantList();

    //methods
    bool addMeal(RestaurantNode & meal);
    float highestPrice();
    bool changePrice();
    void printHeader() const;
    void print();
    bool checkIfItemAlreadyExits(RestaurantNode & node) const;

private:
    RestaurantNode * head;
};


#endif //RESTAURANTLIST_RESTAURANTLIST_H
