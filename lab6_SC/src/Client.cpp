#include "Client.h"

Client::Client()
{

}

Client::Client(char name[20], order ordered, bool check)
{
    strcpy(FIO,name);

    if (ordered.getBassey())
    {
        ordered.setBassey(check);
    }
    abonement.push_back(ordered);
}

Client::Client(char name[20], order ordered)
{
    strcpy(FIO,name);

    if (ordered.getBassey())
    {
        bool check = ordered.swimming_pool();
        ordered.setBassey(check);
    }
    abonement.push_back(ordered);
    cout<<"created new Client and abonement"<<endl;
}
Client::~Client()
{
    //dtor
}

void Client::getFIO()
{
    cout<<FIO<<endl;
}

void Client::addAbonement(order ordered)
{
    abonement.push_back(ordered);
    cout<<"added new abonement"<<endl;
}

void Client::showAbonement()
{
    switch (abonement[abonement.size()-1].type){
        case (1):{
            cout<<"Your type is UNLIMITED"<<endl;
            if(abonement[abonement.size()-1].bassey.need)
                cout<<"You can attand bassey"<<endl;
            break;
        }
    default:
   if(abonement[abonement.size()-1].gym.need){
            cout<<"You can attend GYM"<<endl;
            cout<<"You have "<<abonement[abonement.size()-1].gym.attand<<"attands"<<endl;
   }
   if(abonement[abonement.size()-1].fitness.need){
    cout<<"You can attend Fitness"<<endl;
     cout<<"You have "<<abonement[abonement.size()-1].fitness.attand<<"attands"<<endl;
   }
   if(abonement[abonement.size()-1].sauna.need){
   cout<<"You can attend sauna"<<endl;
    cout<<"You have "<<abonement[abonement.size()-1].sauna.attand<<"attands"<<endl;
   }
   if(abonement[abonement.size()-1].massage.need){
   cout<<"You can attend massage"<<endl;
    cout<<"You have "<<abonement[abonement.size()-1].massage.attand<<"attands"<<endl;
   }
   if(abonement[abonement.size()-1].bassey.need){
   cout<<"You can attend bassey"<<endl;
    cout<<"You have "<<abonement[abonement.size()-1].bassey.attand<<"attands"<<endl;
   }
    }
}

void Client::attand(int s)
{
    if (abonement[abonement.size()-1].type==1)
    {
        cout<<"you are unlimited client"<<endl;
    }
    else
    switch (s){
        case (1):{
            if (abonement[abonement.size()-1].gym.attand)
                abonement[abonement.size()-1].gym.attand--;
            else
                cout<<"no more attands"<<endl;
                break;
        }
        case (2):{
            if (abonement[abonement.size()-1].fitness.attand)
                abonement[abonement.size()-1].fitness.attand--;
                else
                cout<<"no more attands"<<endl;
                 break;
        }
        case (3):{
            if (abonement[abonement.size()-1].massage.attand)
                abonement[abonement.size()-1].massage.attand--;
                else
                cout<<"no more attands"<<endl;
                 break;
        }
        case (4):{
            if (abonement[abonement.size()-1].sauna.attand)
                abonement[abonement.size()-1].sauna.attand--;
                else
                cout<<"no more attands"<<endl;
                 break;
        }
        case (5):{
            if (abonement[abonement.size()-1].bassey.attand)
                abonement[abonement.size()-1].bassey.attand--;
                else
                cout<<"no more attands"<<endl;
                 break;
        }
    }
    cout<<"atanded succesfuly"<<endl;
}
