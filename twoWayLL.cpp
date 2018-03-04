#include<iostream>

using namespace std;
typedef struct nodeStruct
{
    int info;
    nodeStruct *next;
    nodeStruct * previous;
} Node;

Node* createNode(int n)
{
    Node* node = new Node;
    node->info = n;
    node->previous = NULL;
    node -> next = NULL;
    return node;

}



Node *createList(int a[], int numOfElements)
{
    int i;
    Node * temp, *newNode;
    Node *start = createNode(a[0]);
    Node *first = start;
    temp = start;
    for ( i = 1; i < numOfElements; i++)
    {

        newNode = createNode(a[i]);
        temp->next = newNode;
        newNode->previous = temp;
        temp = temp->next;
    }
    return first;
}

void insertLast(Node *list, int num)
{
    while (list->next)
        list = list->next;
    Node* newNode = createNode(num);
    list->next = newNode;
    newNode->previous = list;

}


Node * insertFirst(Node *list, int num)
{
    Node *temp, *newNode;
    temp = list;

    newNode = createNode(num);
    newNode->next = temp;
    temp->previous = newNode;
    return newNode;


}


Node* insertKthPosition(Node* list, int position, int value)
{
    Node* temp = new Node;
    Node* previous = new Node;
    Node* current = new Node;
    Node* newNode = new Node;
    newNode = createNode(value);
    int idx = 1;
    temp = list;

    while(temp->next)
    {
        previous  = temp;
        if(idx == position-1)
        {

            temp = temp->next;
            newNode->next = temp;
            newNode->previous = previous;
            temp->previous = newNode;
            previous->next = newNode;
            break;
        }
        temp = temp->next;
        idx++;
    }

    return list;
}

Node* deleteLast(Node* list)
{
    Node* temp = list;
    while(list->next->next)
    {
        list = list->next;
    }
    list->next = NULL;
    return temp;
}

Node* deleteFirst(Node* list)
{
    if(list->next)
    {
        list = list->next;
        list->previous = NULL;
    }

    else
        list = NULL;
    return list;
}

Node* deleteKthPosition(Node* list, int position)
{
    Node* temp = new Node;
    Node* previous = new Node;


    int idx = 1;
    temp = list;

    while(temp->next)
    {
        previous  = temp;

        if(idx == position-1)
        {


            temp = temp->next;

            previous->next = temp->next;
            temp->next->previous = previous;

            break;
        }
        temp = temp->next;
        idx++;
    }

    return list;
}




void printList(Node * list)
{
    cout<<" forward travarse list element: ";
    Node* temp = list;
    while (list->next)
    {
        cout<<list->info<<" ";
        list = list->next;
    }
    cout<<list->info<<"\n";
    cout<<" backward travarse list element: ";


    while (list)
    {
        cout<<list->info<<" ";
        list = list->previous;
    }
    cout<<"\n";
}

int main()
{    int i,a[100];
    int numOfElement;
    cout<<"num of element\n";
    cin >> numOfElement;

    cout<<"enter elements:\n";
    for (i = 0; i < numOfElement; i++)
    {
        cin >> a[i];
    }

    Node* list;
    list = createList(a, numOfElement);
    printList(list);
    insertLast(list, 10);
    printList(list);
    list = insertFirst(list,30);
    printList(list);
    list = insertKthPosition(list, 3, 99);
    printList(list);
    list = deleteLast(list);
    printList(list);
    list = deleteFirst(list);
    printList(list);
    list = deleteKthPosition(list, 2);
    printList(list);

    return 0;
}
/*
4
1 2 3 4
*/
