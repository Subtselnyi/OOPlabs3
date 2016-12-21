#include "SC.h"

SC::SC()
{
     cout << "Welcome to our Sport Complex!" << endl;
    collection = new Collection<Client, order>[100];
}

SC::~SC()
{
    //dtor
}

void SC::addClient(Client cl)
{
    clients.push_back(cl);
    counted++;
    bool check = cl.medicalCard;
    collection[clients.size()] = Collection<Client, order>(

                                                                    {cl.FIO,cl.abonement[cl.abonement.size()-1],check},

                                                                    {cl.abonement[cl.abonement.size()-1].type,cl.abonement[cl.abonement.size()-1].gym.need,
                                                                    cl.abonement[cl.abonement.size()-1].fitness.need,cl.abonement[cl.abonement.size()-1].massage.need,
                                                                    cl.abonement[cl.abonement.size()-1].sauna.need,cl.abonement[cl.abonement.size()-1].bassey.need}

                                                                 );
}

void SC::addOrder(Client cl,order rd)
{
    orders.push_back(rd);
    bool check = cl.medicalCard;
    collection[clients.size()] = Collection<Client, order>(

                                                                    {cl.FIO,cl.abonement[cl.abonement.size()-1],check},

                                                                    {rd.type,cl.abonement[cl.abonement.size()-1].gym.need,
                                                                    cl.abonement[cl.abonement.size()-1].fitness.need,cl.abonement[cl.abonement.size()-1].massage.need,
                                                                    cl.abonement[cl.abonement.size()-1].sauna.need,cl.abonement[cl.abonement.size()-1].bassey.need}

                                                                    );
    counted++;
}

void SC::showOrders()
{
    int gyma=0,fita=0,masa=0,saua=0,basa=0;
    int unlimited=0;
    for (int i=0;i<counted;i++)
    {

        if (collection[i].gym.attand!=unlimit)
            gyma+=collection[i].gym.attand;
        else
            unlimited++;
        if (collection[i].fitness.attand!=unlimit)
            fita+=collection[i].fitness.attand;
        if (collection[i].massage.attand!=unlimit)
            masa+=collection[i].massage.attand;
        if (collection[i].sauna.attand!=unlimit)
            saua+=collection[i].sauna.attand;
        if (collection[i].bassey.attand!=unlimit)
            basa+=collection[i].bassey.attand;

    }
    cout<<"Totaly was bought "<<gyma<<" GYM attands"<<endl;
    cout<<"Totaly was bought "<<fita<<" Fitness attands"<<endl;
    cout<<"Totaly was bought "<<masa<<" Massage attands"<<endl;
    cout<<"Totaly was bought "<<saua<<" Sauna attands"<<endl;
    cout<<"Totaly was bought "<<basa<<" Bassey attands"<<endl;
    cout<<"Totaly was bought "<<unlimited<<"Unlimited abonements"<<endl;
}

void SC::showClients()
{

    for (int i=0;i<clients.size();i++)
    {
        int gyma=0,fita=0,masa=0,saua=0,basa=0;
        int unlimited=0;
        cout<<i+1<<"client: "; clients[i].getFIO(); cout<<endl;
        for (int j=0;j<clients[i].abonement.size();j++)
        {
             if ( clients[i].abonement[j].gym.attand!=unlimit)
            gyma+= clients[i].abonement[j].gym.attand;
        else
            unlimited++;
        if ( clients[i].abonement[j].fitness.attand!=unlimit)
            fita+= clients[i].abonement[j].fitness.attand;
        if ( clients[i].abonement[j].massage.attand!=unlimit)
            masa+= clients[i].abonement[j].massage.attand;
        if ( clients[i].abonement[j].sauna.attand!=unlimit)
            saua+= clients[i].abonement[j].sauna.attand;
        if ( clients[i].abonement[j].bassey.attand!=unlimit)
            basa+= clients[i].abonement[j].bassey.attand;

        }
         cout<<"This client  bought "<<gyma<<" GYM attands, ";
        cout<<fita<<" Fitness attands, ";
        cout<<masa<<" Massage attands, ";
        cout<<saua<<" Sauna attands, ";
        cout<<basa<<" Bassey attands, "<<endl;
        cout<<unlimited<<"Unlimited abonements"<<endl;
    }
}

void SC::showTempClients()
{

    for (int i=0;i<clients.size();i++)
    {
        int gyma=0,fita=0,masa=0,saua=0,basa=0;
        int unlimited=0;
        cout<<i+1<<"client: "; clients[i].getFIO(); cout<<endl;
        int j=clients[i].abonement.size()-1;

             if ( clients[i].abonement[j].gym.attand==unlimit)
            unlimited++;

        else{
            gyma+= clients[i].abonement[j].gym.attand;

            fita+= clients[i].abonement[j].fitness.attand;

            masa+= clients[i].abonement[j].massage.attand;

            saua+= clients[i].abonement[j].sauna.attand;

            basa+= clients[i].abonement[j].bassey.attand;
        }
        if (!unlimited){
         cout<<"This client  has "<<gyma<<" GYM attands, ";
        cout<<fita<<" Fitness attands, ";
        cout<<masa<<" Massage attands, ";
        cout<<saua<<" Sauna attands, ";
        cout<<basa<<" Bassey attands, "<<endl;
        }
        else
        cout<<"This client  has Unlimited abonement"<<endl;
    }
}
