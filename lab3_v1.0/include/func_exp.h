#pragma once
#ifndef FUNC_EXP_H
#define FUNC_EXP_H

#include "func.h"


class func_exp : public func
{
    public:
        func_exp(double);
        virtual ~func_exp();
        double funct();
        double funct_der();
};

#endif // FUNC_EXP_H
