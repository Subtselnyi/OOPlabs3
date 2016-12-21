#ifndef SC_H
#define SC_H
#include "Client.h"
#include "order.h"
#include "Collection.h"
#include <vector>
#include "service_price.h"

class SC
{
    public:
        vector <Client> clients;
        vector <order> orders;
        Collection<Client, order>* collection; // templates - collection
        service_price basic;

    public:
        int counted=0;
        SC();
        virtual ~SC();
        void addClient(Client);
        void addOrder(Client,order);
        void showOrders();
        void showClients();
        void showTempClients();


};

#endif // SC_H
