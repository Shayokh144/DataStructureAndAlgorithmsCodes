#include<iostream>

using namespace std;

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

Node *createList(int a[], int numOfElements)
{
    int i;
    Node * temp;
    Node *start = createNode(a[0]);
    Node *first = start;
    temp = start;
    for ( i = 1; i < numOfElements; i++)
    {


        temp->next = createNode(a[i]);
        temp = temp->next;
    }
    return first;
}

void insertLast(Node *list, int num)
{
    while (list->next)
        list = list->next;
    list->next = createNode(num);

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
            previous->next = newNode;
            break;
        }
        temp = temp->next;
        idx++;
    }

    return list;
}

Node * insertFirst(Node *list, int num)
{
    Node *temp, *newNode;
    temp = list;

    newNode = createNode(num);
    newNode->next = temp;
    return newNode;


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
        list = list->next;
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

            break;
        }
        temp = temp->next;
        idx++;
    }

    return list;
}


void printList(Node * list)
{
    cout<<"list element: ";
    while (list)
    {
        cout<<list->info<<" ";
        list = list->next;
    }
    cout<<"\n";
}


int main()
{
    Node *n, *m;

    int i,a[100];
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
    list = insertFirst(list,199);
    printList(list);
    insertLast(list, 440);
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
