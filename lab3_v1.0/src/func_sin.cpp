#include "func_sin.h"

func_sin::func_sin(double x)
{
    func::x=x;
}

func_sin::~func_sin()
{
    //dtor
}

double func_sin::funct() //фуекція гіперболічного синуссу
{
    return asinh(x);
}


double func_sin::funct_der() //похідна фуекція гіперболічного синуссу
{
    return acosh(x);
}
