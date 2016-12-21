#include "Abonement.h"

Abonement::Abonement(int type,service_pack pack,bool medCard)
{
     gym.need=pack.gym;
            fitness.need=pack.fitness;
            massage.need=pack.massage;
            sauna.need=pack.sauna;
            if (medCard)
                bassey.need=pack.bassey;
            else
                bassey.need=false;
            this->type=type;
            cout<<endl<<"Succesfully created abonement"<<endl;
}

Abonement::~Abonement()
{
    //dtor
}
