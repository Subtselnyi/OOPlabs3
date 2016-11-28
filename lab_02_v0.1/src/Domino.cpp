#include "domino.h"

domino::domino() //конструтор, рандомне генерування
{
    n=10;
    srand( time(NULL) );
    mass=new edge[n];
    for (int i=0;i<n; i++){
        mass[i].a = rand()%7;
        mass[i].b = rand()%7;
        mass[i].mark=true;
    }
}

domino::~domino() //деструтор
{
    delete [] mass;

}

void domino::output() //виведення доміно
{
    cout<<"number of domino's ="<<n<<endl;
    for (int i=0; i<n;i++){
        cout<<"DOMINOSHKA "<<i+1<<" EDGE a="<<mass[i].a<<" EDGE b="<<mass[i].b<<endl;
    }
}

void domino::input()//можливість ввести свої занчення
{
    char c;
    cout<<"do you want to leave ctor values?[y/n]"<<endl;
    cin>>c;
    if (c=='y'||c=='Y')
        return;
    else {
        cout<<"enter number of domino's"<<endl;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cout<<"Enter edge a for "<<i+1<<endl;
            cin>>mass[i].a;
            cout<<"Enter edge b for "<<i+1<<endl;
            cin>>mass[i].b;
        }
    }
}
