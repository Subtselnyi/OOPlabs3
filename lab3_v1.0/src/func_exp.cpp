#include "func_exp.h"

func_exp::func_exp(double y)
{
    x=y;
}

func_exp::~func_exp()
{
    //dtor
}

double func_exp::funct() //������� ���������������
{
    return exp(x);
}

double func_exp::funct_der()//������� ��������������� ��������
{
    return 2*exp(x);
}
