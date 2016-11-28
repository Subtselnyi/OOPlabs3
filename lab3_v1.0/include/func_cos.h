#pragma once
#ifndef FUNC_COS_H
#define FUNC_COS_H

#include "func.h"


class func_cos : public func
{
    public:
        func_cos(double);
        virtual ~func_cos();
        double funct();
        double funct_der();
    protected:
    private:
};

#endif // FUNC_COS_H
