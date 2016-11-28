#include "func_cos.h"

func_cos::func_cos(double x)
{
    func::x=x;
}

func_cos::~func_cos()
{
    //dtor
}
double func_cos::funct() //функція гіперболічного косинусу
{
    return acosh(x);
}


double func_cos::funct_der() // похідна функція гіперболічного косинусу
{
    return asinh(x);
}
