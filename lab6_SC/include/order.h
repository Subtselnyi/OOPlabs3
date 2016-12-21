#ifndef ORDER_H
#define ORDER_H
#include "service_struct.h"
#include "service_pack.h"
#include <stdlib.h>
#include <time.h>
#define number 20
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "UException.h"
#include "service_price.h"
using namespace std;

class order
{
    public:
        //static const in size = sizeof ... (Values);
        service_struct gym,fitness,massage,sauna,bassey;
        int totalPrice=0;
        int type;
        service_price basic;

    public:
        order();
        order(const int &type,bool n1, bool n2, bool n3, bool n4, bool n5);
        order(const int &type) ;
        ~order();
        bool swimming_pool();
        bool getBassey();
        void setBassey(bool);
};

#endif // ORDER_H
