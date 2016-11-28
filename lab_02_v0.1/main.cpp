#include <iostream>
#include "domino.h"
#include "dommatch.h"

using namespace std;

int main()
{
    cout << "Subtselnyi Oleksandr Volodymyrovych" << endl;
    cout << "V : 20" << endl;
    cout << "L : B" << endl << endl;
    char h;
    while (h!='s'){
    dommatch* jbj = new dommatch(); //створення обэкта
    jbj->output();//вивести згенеровані конструктором елементи
    jbj->input();//моєжливість ввести свої дані
    if (jbj->reality()){ //перевірка на реальність
        cout<<"maybe possible"<<endl;
        //jbj->findsolution();//знайти шлях
        jbj->findsol(jbj->first);
        jbj->outputsolution();
    }
    else cout<<"NO!"<<endl;

    delete jbj; //видалите обєкт
    cout<<"if you want to stop press s";
    cin>>h;
    }
}
