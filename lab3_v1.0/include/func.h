#pragma once
#ifndef FUNC_H
#define FUNC_H
#include "Math.h"


class func
{
    protected:
        double x; //�������� ��� �������
    public:
        func();
        virtual ~func();
        virtual double funct()=0;//�����
        virtual double funct_der()=0; //������� �������
};

#endif // FUNC_H
