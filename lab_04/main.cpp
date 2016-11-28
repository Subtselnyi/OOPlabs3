#include <iostream>
#include "Multi_Set.h"
#include "UException.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {

	printf("OOP lab work #4\nVariant - 20, Level - B\nTask: Write Multi_Set of charecters\nWriter: Alexander Subtselnyi\n\n");
	printf("Menu:\n1. Start program\n2. Exit\n\nMake your choice ");
	bool cando=false;
	do{
    try{
	int t;
	scanf("%d", &t);
	switch (t) {
	case 1: {

		char str[20];
		bool ready=false;
		int len;
		do{
        cout<<"Enter set 1 through ','"<<endl;
		cin>>str;
		len = strlen(str);
        try{
            bool flag=true,
            prevflag=true;
            for (int i=1;i<len;i+=2){
                if (str[i]==',') flag=!flag;
                if (prevflag==flag) throw UException("substring in your Multi_Set");
                prevflag=flag;
            }
            ready=false;
        }
        catch (UException &e){
            e.show();
            ready=true;
        }
		}while (ready);
        Multi_Set A(str,len);
		str[0]='/0';

		cin>>str;
		do{
        cout<<"Enter set 2 through ','"<<endl;
		cin>>str;
		len = strlen(str);
        try{
            bool flag=true,
            prevflag=true;
            for (int i=1;i<len;i+=2){
                if (str[i]==',') flag=!flag;
                if (prevflag==flag) throw UException("substring in your Multi_Set");
                prevflag=flag;
            }
            ready=false;
        }
        catch (UException &e){
            e.show();
            ready=true;
        }
		}while (ready);
		Multi_Set B(str,len);
		str[0]='/0';


		printf("\nSet A: "); A.outputSet();
		printf("\nSet B: "); B.outputSet();

		printf("\n\nUnion of A and B: "); (A + B).outputSet();
		printf("\nSubtraction of A and B: "); (A - B).outputSet();
		printf("\nSubtraction of B and A: "); (B - A).outputSet();
		printf("\nIntersection of A * B: "); (A * B).outputSet();

		printf("\n\nUnion of A and B: "); (A += B).outputSet();
		printf("\nSet A: "); A.outputSet();
		printf("\nSubtraction of A and B: "); (A -= B).outputSet();
		printf("\nSet A: "); A.outputSet();
		printf("\nIntersection of A * B: "); (A *= B).outputSet();
		printf("\nSet A: "); A.outputSet();

        if (!A.checkout()){
            cout<<"Enter set A again, because its empty"<<endl;
            cin>>str;
            len = strlen(str);
            A.push(str,len);
        }


		cout<<"Print symbol to add to A"<<endl;
		char c;
		cin>>c;
 		Multi_Set errorarray ;
 		int error;
		do
        {
        errorarray=A << c;
        error=errorarray.getter();
		if (error){
		cout<<"Adding symbol "<<c<<" to A"<<endl;
        A.outputSet();
        } else
        cin>>c;} while (!error);

        cout<<"Print symbol to delete from A"<<endl;
		cin>>c;
		int l=A.getter();
		A >> c;
		int lnew=A.getter();
		if (l!=lnew)
		cout<<"Deleting symbol "<<c<<" from A"<<endl;
        A.outputSet();

		printf("\n");
        cout<<"OK";
	}
	case 2: return 0;
	default: throw Exception ("Incorrect input");
	}
    }
    catch(UException& e){
        e.show();
        cando=true;
    }
	}while (cando);

	return 0;
}

//Ââåäåííÿ ñòðîêè

