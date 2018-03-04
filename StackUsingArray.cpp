#include<iostream>
#define SIZE 5
#define MAX 5000 
using namespace std;
 
 
int STACK[MAX],TOP;
 
//stack initialization
void initStack(){
    TOP=-1;
}
//check it is empty or not
int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}
 
//check stack is full or not
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else   
        return 0;
}
 
void push(int num){
    if(isFull()){
        cout<<"STACK is FULL."<<endl;
        return; 
    }
    ++TOP;
    STACK[TOP]=num;
    cout<<num<<" has been inserted."<<endl;
}
 
void display(){
    int i;
    if(isEmpty()){
        cout<<"STACK is EMPTY."<<endl;
        return;
    }
    for(i=TOP;i>=0;i--){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}
 
//pop - to remove item
void pop(){
    int temp;
    if(isEmpty()){
        cout<<"STACK is EMPTY."<<endl;
        return;
    }
     
    temp=STACK[TOP];
    TOP--;
    cout<<temp<<" has been deleted."<<endl;   
}

int main()
{
    initStack();// create a new STACK
    push(10);
    display();
    push(30);
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}


