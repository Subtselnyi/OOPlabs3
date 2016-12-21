#ifndef SERVICE_STRUCT_H_INCLUDED
#define SERVICE_STRUCT_H_INCLUDED
#define unlimit 1000

struct service_struct
{
    int price,
        time,
        attand=0;
    bool need=false;
    int totalPrice=0;
};


#endif // SERVICE_STRUCT_H_INCLUDED
