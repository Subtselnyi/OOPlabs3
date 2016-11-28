#pragma once
#ifndef FUNC_H
#define FUNC_H
#include "Math.h"


class func
{
    protected:
        double x; //аргумент для функцій
    public:
        func();
        virtual ~func();
        virtual double funct()=0;//функія
        virtual double funct_der()=0; //похідна функції
};

#endif // FUNC_H
