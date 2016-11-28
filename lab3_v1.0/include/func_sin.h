#pragma once
#ifndef FUNC_SIN_H
#define FUNC_SIN_H

#include "func.h"


class func_sin : public func
{
    public:
        func_sin(double);
        virtual ~func_sin();
        double funct();
        double funct_der();
    protected:
    private:
};

#endif // FUNC_SIN_H
