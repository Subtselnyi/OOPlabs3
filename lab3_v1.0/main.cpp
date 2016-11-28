#include <iostream>
#include <stdio.h>
#include "func.h"
#include "func_exp.h"
#include "func_cos.h"
#include "func_sin.h"
using namespace std;

int main()
{
    printf("OOP lab work #3\nVariant - 20, Level - B\nBy: Alexander Subtselnyi\n\n");

	int t=1;
    while(t!=2){
    printf("Menu:\n1. Start program\n2. Exit\n ");
	scanf("%d", &t);
	switch (t) {
	case 1: {
	    cout<<"Enter the argument"<<endl;
	    double f;//������� ���������
	    cin>>f;
	    func* object[3]; //��������� ������ �����
	    object[0]=new func_exp(f);//���� ����� ��������������� �������
	    object[1]=new func_cos(f+1); //��������
	    object[2]=new func_sin(f+2); //������

		cout<<"Core functions"<<endl;
		for (int i = 0; i < 3; i++) printf("%d - %.3Lf\n", i + 1, object[i]->funct());//������ ������� �������
        cout<<"Derivated functions"<<endl;
		for (int i = 0; i < 3; i++) printf("%d - %.3Lf\n", i + 1, object[i]->funct_der());//������ ������ �����

		printf("Where:\n1 - exp\n2 - cosh\n3 - sinh\n\n");

		for (int i = 0; i < 3; i++) delete object[i];//��������� �����

		break;
	}

	case 2: return 0;

	}
    }
}
