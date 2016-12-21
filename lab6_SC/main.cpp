#include <iostream>
#include <cstdlib>
# include <algorithm>
#include <stdio.h>
#include "SC.h"
#include "Client.h"
#include "service_struct.h"
#include "service_pack.h"
#include "Order.h"
#include "Abonement.h"
#include "UException.h"
#include <string.h>



using namespace std;



int main()
{
    cout<<"Subtselnyi Oleksandr LAB:6B. Varian:20"<<endl;
    SC Complex;

    int i=0;
    bool finish=true;
    while (finish){
            char choise;
            cout<<"MENU"<<endl<<endl;
            cout<<"1. Create new client"<<endl;
            cout<<"2. Make new abonement for client"<<endl;
            cout<<"3. Take User and make attand"<<endl;
            cout<<"4. Take User and show attands"<<endl;
            cout<<"5. Show all used services"<<endl;
            cout<<"6. Show all clients"<<endl;
            cout<<"7. Show all clients(temporary)"<<endl;
            cout<<"e. EXIT"<<endl;

            cin>>choise;
            switch(choise){
                case ('1'):
                {
                    int type;
                    cout<<"what abonement do you need?"<<endl<<"1.Unlimit"<<endl<<"2.Month(8 attands)"<<endl<<"3.Once"<<endl;
                    cin>>type;

                    order ordered(type);

                    cout<<"Enter the name of Client"<<endl;
                    char name[20];
                    scanf("%s",name);
                    Client cl(name,ordered);
                    Complex.addClient(cl);
                    Complex.addOrder(cl,ordered);
                    break;
                }
                case ('2'):
                {
                    cout<<"Choose client"<<endl;
                    for (int i=0;i<Complex.clients.size();i++){
                        cout<<i+1; Complex.clients[i].getFIO();
                    }
                    int num;
                    cin>>num;
                    Complex.clients[num-1].showAbonement();
                    int type;
                    cout<<"what abonement do you need?"<<endl<<"1.Unlimit"<<endl<<"2.Month"<<endl<<"3.Once"<<endl;
                    cin>>type;
                    order ordered(type);
                    Complex.addOrder(Complex.clients[num-1],ordered);
                    Complex.clients[num-1].addAbonement(ordered);
                    break;
                }
                case ('3'):
                {
                    cout<<"Choose client"<<endl;
                    for (int i=0;i<Complex.clients.size();i++){
                        cout<<i+1; Complex.clients[i].getFIO();
                    }
                    int num;
                    cin>>num;Complex.clients[num-1].showAbonement();
                    cout<<"What does client attand?"<<endl;
                    cout<<"1.GYM"<<endl<<"2.Fitness"<<endl<<"3.Massage"<<endl<<"4.Sauna"<<endl<<"5.Bassey"<<endl;
                    int type;
                    cin>>type;
                    Complex.clients[num-1].attand(type);
                    break;
                }
                case ('4'):
                    {
                        cout<<"Choose client"<<endl;
                    for (int i=0;i<Complex.clients.size();i++){
                        cout<<i+1; Complex.clients[i].getFIO();
                    }
                    int num;
                    cin>>num;Complex.clients[num-1].showAbonement();
                    break;
                    }
                case ('5'):
                    {
                        Complex.showOrders();
                        break;
                    }
                case ('6'):
                    {
                        Complex.showClients();
                        break;
                    }
                case ('7'):
                    {
                        Complex.showTempClients();
                        break;
                    }
                case ('e'):
                {
                    cout<<"SportComplex is closing"<<endl;
                    finish=false;
                    break;
                }


                default:
                {
                    cout<<"wrong input"<<endl;
                }
            }
    }
}
