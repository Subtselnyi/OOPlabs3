#include "dommatch.h"

dommatch::dommatch() //конструтор
{
     n=10;
    solution=new edge[n];
     for (int i=0;i<n; i++){
        solution[i].a=0;
        solution[i].b=0;
    }
    solutions=new edge[n];
     for (int i=0;i<n; i++){
        solutions[i].a=0;
        solutions[i].b=0;
    }
}

dommatch::~dommatch() //деструтор
{
    delete [] solution;
    delete [] solutions;
}

bool dommatch::reality() //перевірка на реальність
{
    int l=0;
    int massiv[6];
    int cc=0;
    for (int i=1;i<7;i++) //створення допоміжного масиву
        massiv[i]=0;
    for (int i=0;i<n;i++) //знаходження кількості непарних ребер
    {
        massiv[mass[i].a]++;
        massiv[mass[i].b]++;
    }
    for (int i=1;i<=6;i++) //перевірка на кількість непарних ребер
    {
        if (massiv[i]%2!=0){
            cc++;
            start[l++]=i;
        }
    }
    if (cc>2) return false; //повернути false якщо кількість нерарних ребер більше 2
    first=mass[0].a;

    for (int i=0;i<n;i++){ //задати перший елемент
        if ((mass[i].a==start[0])){
            first=mass[i].b;
            mass[i].mark=false;
            solution[num++]=mass[i];
            break;
        }
        if ((mass[i].b==start[0])){
            first=mass[i].a;
            mass[i].mark=false;
            solution[num++]=mass[i];
            break;
        }
    }

   /* for (int i=0;i<n;i++){//задати останні елемент
        if ((mass[i].a==start[1])&&(mass[i].a!=first)&&mass[i].mark){
            last=mass[i].b;
            mass[i].mark=false;
            solution[n-1]=mass[i];
            break;
        }
        if ((mass[i].b==start[1])&&(mass[i].b!=first)&&mass[i].mark){
            last=mass[i].a;
            mass[i].mark=false;
            solution[n-1]=mass[i];
            break;
        }
    }*/
    return true;

}

void dommatch::findsolution() //знайти маршрут
{
    for (int j=0;j<n;j++){
    for (int i=0;i<n;i++)
    {
        if (num==n) continue;
        if (mass[i].mark&&(mass[i].a==first))//якщо співпадають ребра
        {
            first=mass[i].b;//якщо співпадають ребра
            mass[i].mark=false;
            solution[num++]=mass[i]; //додати до маршуруту
        }
        if (mass[i].mark&&(mass[i].b==first))//якщо співпадають ребра
        {
            first=mass[i].a;
            mass[i].mark=false;
            solution[num++]=mass[i];//додати до маршруту
        }
    }
    }
    if (num!=n-1){cout<<"NO WAY"; return;}
    for (int i=0;i<n;i++) //вивести маршгрут
    {
        cout<<solution[i].a<<" "<<solution[i].b<<endl;
    }

}


bool dommatch::findsol(int ffirst)
{
    for (int i=0;i<n;i++)
    {
        if(num==n){
            for(int j=0;j<n;j++){
                solutions[j]=solution[j];

            }
        }
        if(num!=n)
        {
            if ((ffirst==mass[i].a||ffirst==mass[i].b)&&mass[i].mark)
            {
                mass[i].mark=false;
                solution[num]=mass[i];
                num++;
                if ((ffirst==mass[i].a))
                    findsol(mass[i].b);
                else if (mass[i].a!=0)
                    findsol(mass[i].a);
                num--;
                mass[i].mark=true;
            }
        }
    }

}

void dommatch::outputsolution()
{
    if (solutions[0].a==0)
        cout<<"NO WAY"<<endl;
    else
     for (int i=0;i<n;i++) //вивести маршгрут
    {
        cout<<solutions[i].a<<" "<<solutions[i].b<<endl;
    }
}
