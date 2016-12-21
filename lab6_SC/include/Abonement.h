#ifndef ABONEMENT_H
#define ABONEMENT_H
#include "service_struct.h"
#include "service_pack.h"
#include <iostream>
using namespace std;

class Abonement
{
  private:
        service_struct gym,fitness,massage,sauna,bassey;
        int price;
        int type;

    public:
        Abonement(int type,service_pack pack,bool medCard) ;
        ~Abonement();
};

#endif // ABONEMENT_H
