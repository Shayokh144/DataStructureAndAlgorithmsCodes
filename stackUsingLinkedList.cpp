#include<iostream>

using namespace std;

int stackSize=0;
int maxLimit = 100;
typedef struct nodeStruct
{
    int info;
    struct nodeStruct *next;
} Node;


Node* createNode(int n)
{
    Node* node = new Node;
    node->info = n;
    node -> next = NULL;
    return node;

}



Node* sPush(Node* customStack,int value)
{
    Node* newNode;
    Node* temp;


    if(stackSize<maxLimit)
    {

        temp = customStack;
        newNode = createNode(value);
        if(customStack)
        {
            newNode->next = temp;

        }

        stackSize+=1;
        return newNode;

    }
    else
    {
        cout<<"stack full...\n";
        return customStack;
    }




}

Node* sPop(Node* customStack)
{
    if(customStack)
    {
        customStack = customStack->next;
        stackSize--;
    }
    else
    {
        cout<<"stack already empty...\n";
    }
    return customStack;

}


void printStack(Node* customStack)
{
    cout<<"Stack element: ";
    Node* Stack = customStack;

    while (Stack)
    {

        cout<<Stack->info<<" ";
        Stack = Stack->next;

    }
    cout<<"\n";
}

int main()
{
    Node* customStack =NULL;
    customStack = sPush(customStack,10);
    customStack = sPush(customStack,20);
    customStack = sPush(customStack,30);
    customStack = sPush(customStack,190);
    printStack(customStack);

    customStack = sPop(customStack);
    printStack(customStack);
    customStack = sPop(customStack);
    cout<<"stack size = "<<stackSize<<"\n";

    return 0;
}
