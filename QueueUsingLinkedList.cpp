#include<iostream>
using namespace std;

typedef struct nodeStruct{
	int info;
	struct nodeStruct *next;
}Node;

Node* createNode(int n)// Node* is the data type..
{
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->info = n;
	node->next = NULL;
	return node;

}


Node* qPush(Node* queue, int value)
{
	if (queue == NULL)
	{
		queue = createNode(value);
	}
	else
	{
		Node* newNode = createNode(value);
		Node* temp = queue;
		while (temp->next)
			temp = temp-> next;
		temp->next = newNode;

	}
	return queue;
}

Node* qPop(Node* queue)
{
	if (queue)
	{
		queue = queue->next;
	}
	else
	{
		cout << "queue already empty\n";
	}
	return queue;
}

int qTop(Node* queue)
{
	if (queue)
		return queue->info;
	else
		return -1;

	
}


void qPrint(Node * queueN)
{
	while (queueN)
	{
		cout << queueN->info << " ";
		queueN = queueN->next;
	}
	cout << "\n";
}


int main()
{
	Node* queue=NULL;
	queue = qPush(queue, 10);
	queue = qPush(queue, 20);
	queue = qPush(queue, 30);
	qPrint(queue);
	queue = qPop(queue);
	qPrint(queue);
	cout << qTop(queue)<<"\n";
	return 0;
}