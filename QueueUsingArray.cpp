#include<iostream>
using namespace std;

int mxLength = 999;
int Queue[1000];
int Stack[1000];
int Qtop,Qbottom;

void initialize()
{

    Qtop = Qbottom = 0;


}

int Q_empty()
{
    if(Qtop ==Qbottom)
    {
        return 1;
    }
    else
        return 0;
}


void Q_push(int item)
{
    if (Qbottom<mxLength)
    {
        Queue[Qbottom]= item;
        Qbottom +=1;
    }
}


void Q_pop()
{
    if (!Q_empty())
    {
        Qtop+=1;
    }
}


void Q_print()
{
    //cout<<"top="<<Qtop<<"  bottom="<<Qbottom<<"\n";
    if(!Q_empty())
    {
     for (int i=Qtop;i<Qbottom;i++)
    {
        cout<<Queue[i]<<"  ";
    }
    cout<<"\n";

    }
    else
    {
        cout<<"empty";
    }
}

int main()
{
    initialize();
    Q_push(100);
    Q_push(200);
    Q_print();
    Q_pop();
    Q_print();
    Q_pop();
    Q_print();


    return 0;
}
