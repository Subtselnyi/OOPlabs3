#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include "Abonement.h"
#include "order.h"
using std::vector;

class Client
{
    public:
        char FIO[20];
        bool medicalCard;
        vector <order> abonement;

    public:
        Client();
        Client(char[20],order ordered);
        Client(char name[20], order ordered, bool check);
        virtual ~Client();

        void addAbonement(order ordered);
        void getFIO();
        void showAbonement();
        void attand(int);



};

#endif // CLIENT_H
