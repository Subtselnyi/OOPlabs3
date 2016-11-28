#ifndef DOMMATCH_H
#define DOMMATCH_H

#include <domino.h>


class dommatch : public domino //наследование
{
    public:
        bool reality(); //перевірка на реальність
        void findsolution(); //знаходження маршруту
        bool findsol(int);
        int first;
        void outputsolution();
        dommatch(); //конструктор
        virtual ~dommatch(); //деструктор
    protected:
    private:
        int start[6]; //допоміжний масив
        int   //перше доміно
        last; //останнє доміно
};

#endif // DOMMATCH_H
