#include <iostream>
#include "RestaurantList.h"

void printMenu();
RestaurantNode userInputNewMeal();

int main() {
    RestaurantList list;
    RestaurantNode meal1("Khana Indian Grill", 4.7, "Chicken Tika Masala", "Indian", 13.55);
    RestaurantNode meal2("Khana Indian Grill", 4.7, "Chole", "Indian", 12.00);
    RestaurantNode meal3("Khana Indian Grill", 4.7, "Super Indian", "Indian", 26.00);

    list.addMeal(meal1);
    list.addMeal(meal2);
    list.addMeal(meal3);
    list.addMeal(meal2);
    list.addMeal(meal3);
    list.addMeal(meal3);
    list.addMeal(meal1);

    char input;
    do{
        printMenu();
        cin >> input;
        switch(input){
            case '1':
                list.print();
                break;
            case '2':{
                RestaurantNode newMeal = userInputNewMeal();
                list.addMeal(newMeal);
                break;
            }
            case '3':
                list.changePrice();
                break;
            case '4':
                cout << "highest price: " << list.highestPrice() << endl;
                break;
            case '0':
                cout << "goodbye..." << endl;
                break;
            default:
                cout << "invalid entry" << endl;
        }
    }while(input != '0');

    return 0;
}

void printMenu(){
    cout << endl;
    cout << "Please select one of the following: " << endl;
    cout << "1: Print all item." << endl;
    cout << "2: Add item." << endl;
    cout << "3: change an item price." << endl;
    cout << "4: Print highest price." << endl;
    cout << "0: Exit the program." << endl;
}

RestaurantNode userInputNewMeal(){
    string name;
    float rating;
    string mealName;
    string mealType;
    float price;
    string temp;

    cout << "Please enter restaurant name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Restaurant rating: ";
    getline(cin, temp);
    rating = stof(temp);

    cout << "Meal name: ";
    getline(cin, mealName);

    cout << "Meal type: ";
    getline(cin, mealType);

    cout << "Meal price: ";
    getline(cin, temp);
    price = stof(temp);

    RestaurantNode newItem(name, rating, mealName, mealType, price);
    return newItem;
}
