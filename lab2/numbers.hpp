//
//  numbers.hpp
//  numbers
//
//  Created by Alex Tran on 2/3/23.
//

#ifndef numbers_hpp
#define numbers_hpp

//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------
#include <fstream>
#include <iostream>
using namespace std;

//----------------------------------------------
class Numbers
{
public:
    // Constructors
    Numbers();
    ~Numbers();

    // Methods
    void readFile(string filename);
    int getCount();
    int getValue(int index);
    int findMin();
    int findMax();
    int findMean();

private:
    static const int SIZE = 100;
    int Count;
    int Data[SIZE];
};



#endif /* numbers_hpp */
