#include "func_exp.h"

func_exp::func_exp(double y)
{
    x=y;
}

func_exp::~func_exp()
{
    //dtor
}

double func_exp::funct() //функція експотенціальна
{
    return exp(x);
}

double func_exp::funct_der()//похадна експотенціальної ьфункції
{
    return 2*exp(x);
}
