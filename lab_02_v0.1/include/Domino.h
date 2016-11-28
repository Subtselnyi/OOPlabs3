#ifndef DOMINO_H
#define DOMINO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

class domino
{
    public:
        int n; //кількість доміно
        int num=0; //лічильник
        void output(); //вивести
        void input(); //вести
        domino(); //конструктор
        virtual ~domino(); //деструктор
    protected:
        struct edge //доміношні ребра
        {
            int a,b;
            bool mark;
        };
        edge *mass; //масив з доміно
        edge *solution; //маршрут
        edge *solutions;
    private:

};

#endif // DOMINO_H
