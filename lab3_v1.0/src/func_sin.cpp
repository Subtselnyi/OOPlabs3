#include "func_sin.h"

func_sin::func_sin(double x)
{
    func::x=x;
}

func_sin::~func_sin()
{
    //dtor
}

double func_sin::funct() //������� ������������ �������
{
    return asinh(x);
}


double func_sin::funct_der() //������� ������� ������������ �������
{
    return acosh(x);
}
