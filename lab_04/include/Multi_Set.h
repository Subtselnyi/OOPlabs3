#ifndef MULTI_SET_H
#define MULTI_SET_H
#pragma once
#include "UException.h"
#define countOfNegativeElemnts 128
#include <ctype.h>
#include <cstdio>
#define num 5
#define number 20
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class Multi_Set {
private:
	char elements[number]; // CharSet
	int capacity=0;
public:
	Multi_Set(void); // Default constructor
	Multi_Set(char*,int); // Constructor
	void outputSet(void) const; // Output all CharSet on screen
    bool checkout();
    void push(char*,int);
    int getter();
	// ---- OPERATIONS ----
	//Union
	 Multi_Set operator+ (Multi_Set &obj);
	Multi_Set operator+= (Multi_Set obj);

	//subtraction
	 Multi_Set operator- (Multi_Set obj) ;
	Multi_Set operator-= ( Multi_Set obj);

	//Intersection
	 Multi_Set operator* ( Multi_Set obj) ;
	Multi_Set operator*= (const Multi_Set obj);

	// Adding and removing
	Multi_Set& operator<< ( const char c);
	Multi_Set& operator>> ( const char c);
};
#endif // MULTI_SET_H
