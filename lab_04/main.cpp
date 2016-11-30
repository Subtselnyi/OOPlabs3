#include <iostream>
#include "Multi_Set.h"
#include "UException.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
//#include <regex>
/*
#include <signal.h>//-
#include <stdlib.h>//-- for signal
#include <unistd.h>//-

void signal_callback_handler(int signum) {
   printf("\nCaught signal %d\n",signum);
   if (signum == 2) {
        printf("(Ctrl+^C)\n");
   }
}*/

using namespace std;


int main() {
    //signal(SIGINT, signal_callback_handler);

	printf("OOP lab work #4\nVariant - 20, Level - B\nTask: Write Multi_Set of charecters\nWriter: Alexander Subtselnyi\n\n");
	printf("Menu:\n1. Start program\n2. Exit\n\nMake your choice ");
	bool cando=false;
	//regex integer("^[0-9x+*-/(). ]+$");
	do{
    try{
	char t[20];
	scanf("%s",&t);
	if (strlen(t)>1) throw UException ("to many arguments");
	char k=t[0];
	switch (k) {
	case '1': {

		char str[20],str1[20];
		bool ready=false;
		int len=0,len1=0;

		do{
        str[0]='/0';
        cout<<"Enter set 1 through ','"<<endl;
        /*do{
		scanf("%s",&str1);
		len1 = strlen(str1);
		len+=len1;
		strcpy(str,str1);
        }while(str1[len1]!='\0');*/
        scanf("%s",str);
		len = strlen(str);
        try{
            bool flag=true,
            prevflag=true;
            for (int i=1;i<len;i+=2){
                if (str[i]!=',') flag=false;
                if (!flag) throw UException("substring in your Multi_Set");
                if ((int)str[i-1]<33||int(str[i-1])>127||(int)str[0]<33||(int)str[0]>127) throw UException("not a symbol of ASCII");
                prevflag=flag;
            }
            ready=false;
            //if(!regex_match(str, integer)) throw UException("Wrong input format!!!");
        }
        catch (UException &e){
            e.show();
            ready=true;
            str[0]='/0';

        }
		}while (ready);

        Multi_Set A(str,len);

		str[0]='/0';

		do{
        str[0]='/0';
        cout<<"Enter set 2 through ','"<<endl;
		scanf("%s",&str);
		len = strlen(str);
        try{
            bool flag=true,
            prevflag=true;
            for (int i=1;i<len;i+=2){
                if (str[i]!=',') flag=false;
                if (!flag) throw UException("substring in your Multi_Set");
                if ((int)str[i-1]<33||int(str[i-1])>127||(int)str[0]<33||(int)str[0]>127) throw UException("not a symbol of ASCII");
                prevflag=flag;
            }
            ready=false;
        }
        catch (UException &e){
            e.show();
            ready=true;
            str[0]='/0';
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
	case '2': cando=false;break;return 0;
	default: throw UException ("Incorrect input");
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

