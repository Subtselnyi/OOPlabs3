#include "func_cos.h"

func_cos::func_cos(double x)
{
    func::x=x;
}

func_cos::~func_cos()
{
    //dtor
}
double func_cos::funct() //������� ������������ ��������
{
    return acosh(x);
}


double func_cos::funct_der() // ������� ������� ������������ ��������
{
    return asinh(x);
}
