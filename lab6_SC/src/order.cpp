#include "Order.h"
order::order()
{

}
order::order(const int &type)
{
    if (type==1){
        gym.need=true;

        fitness.need=true;
        massage.need=true;
        sauna.need=true;
        bassey.need=true;
        fitness.attand=massage.attand=sauna.attand=bassey.attand=gym.attand=unlimit;
        totalPrice = basic.unlimited;
    }
    else{
    char str[number];
    bool elements[number];
    int capacity=0;

    cout<<"which services do you need?[Enter through ',']"<<endl;
    cout<<"1.GYM"<<endl<<"2.Fitness"<<endl<<"3.Massage"<<endl<<"4.Sauna"<<endl<<"5.Bassey"<<endl;
    bool ready=true;
    do{
    str[0]='/0';
    scanf("%s",str);
    int len = strlen(str);
    try{
        bool flag=true,
        prevflag=true;
        for (int i=1;i<len;i+=2){
            if (str[i]!=',') flag=false;
            if (!flag) throw UException("substring in your Multi_Set");
            if ((int)str[i-1]<33||int(str[i-1])>127||(int)str[0]<33||(int)str[0]>127) throw UException("not a symbol of ASCII");
            prevflag=flag;
        }
        ready=false;
        }
        catch (UException &e){
            e.show();
            ready=true;
            str[0]='/0';
        }
    }while(ready);

	for (int i = 0; i <= 5; i++) elements[i] = false;
    int i=0;
    char * pch = strtok (str,",");
    int n = atoi(pch);
    elements[n]=true;
    while (pch != NULL)
    {
        pch = strtok (NULL, ",");
        n = atoi(pch);
        elements[n]=true;
    }

    gym.need=elements[1];
    fitness.need=elements[2];
    massage.need=elements[3];
    sauna.need=elements[4];
    bassey.need=elements[5];

    }

    this->type=type;

    if (type==3){
        if (gym.need) {
                totalPrice+=basic.gym;
                gym.attand=1;
        }
        if (fitness.need)
        {totalPrice+=basic.fitness;
        fitness.attand=1;
        }
        if (massage.need){
            totalPrice+=basic.masssage;
            massage.attand=1;
        }
        if (sauna.need) {
                totalPrice+=basic.sauna;
                sauna.attand=1;
        }
        if (bassey.need){
                totalPrice+=basic.bassey;
                bassey.attand=1;
        }
    }
    if (type==2){
        if (gym.need) {
                totalPrice+=8*basic.gym;
                gym.attand=8;
        }
        if (fitness.need)
        {
            totalPrice+=8*basic.fitness;
            fitness.attand=8;
        }
        if (massage.need){
            totalPrice+=8*basic.masssage;
            massage.attand=8;
        }
        if (sauna.need) {
                totalPrice+=8*basic.sauna;
                sauna.attand=8;
        }
        if (bassey.need){
                totalPrice+=8*basic.bassey;
                bassey.attand=8;
        }
    }

   cout<<endl<<"Succesfully created order"<<endl<<"Total price is: "<<totalPrice<<endl;;
}

order::order(const int &type,bool n1, bool n2, bool n3, bool n4, bool n5)
{
    if (type==1){
        gym.need=true;

        fitness.need=true;
        massage.need=true;
        sauna.need=true;
        bassey.need=true;
        fitness.attand=massage.attand=sauna.attand=bassey.attand=gym.attand=unlimit;
        totalPrice = basic.unlimited;
    }
    else{


    gym.need=n1;
    fitness.need=n2;
    massage.need=n3;
    sauna.need=n4;
    bassey.need=n5;

    }

    this->type=type;

    if (type==3){
        if (gym.need) {
                totalPrice+=basic.gym;
                gym.attand=1;
        }
        if (fitness.need)
        {totalPrice+=basic.fitness;
        fitness.attand=1;
        }
        if (massage.need){
            totalPrice+=basic.masssage;
            massage.attand=1;
        }
        if (sauna.need) {
                totalPrice+=basic.sauna;
                sauna.attand=1;
        }
        if (bassey.need){
                totalPrice+=basic.bassey;
                bassey.attand=1;
        }
    }
    if (type==2){
        if (gym.need) {
                totalPrice+=8*basic.gym;
                gym.attand=8;
        }
        if (fitness.need)
        {
            totalPrice+=8*basic.fitness;
            fitness.attand=8;
        }
        if (massage.need){
            totalPrice+=8*basic.masssage;
            massage.attand=8;
        }
        if (sauna.need) {
                totalPrice+=8*basic.sauna;
                sauna.attand=8;
        }
        if (bassey.need){
                totalPrice+=8*basic.bassey;
                bassey.attand=8;
        }
    }

}

order::~order()
{
    //dtor
}



bool order::swimming_pool()
{
    char answer;
    cout<<"You've chosen a bassey! You need to pass the medical inspection"<<endl<<endl;
    cout<<"Do you have gerpes?[Y/n]"<<endl;
    cin>>answer;
    if (answer=='y'||answer=='Y')
        return false;
    srand (time(NULL));
    int AIDS= rand() % 100 + 1;
    if (AIDS<5){
            cout<<"We have found problems with our health! NO BASSEY"<<endl;
        return false;
    }
    return true;
}

bool order::getBassey()
{
    return bassey.need;
}
void order::setBassey(bool checked)
{
    bassey.need=checked;
}

