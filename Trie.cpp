//
//  main.cpp
//  CppTest
//
//  Created by Abu Taher on 3/18/20.
//  Copyright © 2020 Abu Taher. All rights reserved.
//

#include<iostream>
using namespace std;

#define SIZE 26
typedef struct trieNode{
    int isLeaf;
    struct trieNode *child[SIZE];
}Node;


char reversedString[100];
Node* createNode()
{
    Node *newNode;
    newNode = (Node*) new Node;
    newNode->isLeaf = 0;
    for (int i = 0; i < SIZE; i++)
    {
        newNode->child[i] = NULL;
    }
    return newNode;
}

int getSizeOfString(char input[]){
    int index = 0;
    for (int i = 0; input[i]; i++){
        index += 1;
    }
    if (index > 0){
        index -= 1;
    }
    return index;
}

void doReverseString(char input[]){
    int stSize = getSizeOfString(input);
    //printf("size = %d\n",stSize);
    for (int i= stSize; i>=0;i--){
        reversedString[stSize - i] = input[i];
    }
    reversedString[stSize + 1] = '\0';
    //printf("reversed string: %s\n", reversedString);
}

void insertTrie(Node* root, char input[])
{
    Node *cur = root;
    for (int i = 0; input[i]; i++)
    {
        int index = input[i] - 'a';
        if (NULL == cur->child[index])
        {
            cur->child[index] = createNode();
        }
        cur = cur->child[index];
    }
    cur->isLeaf++;
}

int searchTrie(Node *root, char input[])
{
    Node *cur = root;
    for (int i = 0; input[i]; i++)
    {
        int index = input[i] - 'a';
        if (NULL == cur->child[index])
        {
            return 0;
        }
        cur = cur->child[index];
    }
    return 1;
}

void printPrefix(Node *root, char input[], int inpSize, int index, char output[]){
    if (root->isLeaf == 1)
    {
        output[index] = '\0';
        printf("%s\n", output);

    }
    for (int i = 0; i < SIZE; i++)
    {
        if (root->child[i] != NULL)
        {
            if(index < inpSize){
                if (i + 'a' == input[index]){
                    output[index] = i + 'a';
                    printPrefix(root->child[i], input, inpSize, index + 1, output);
                }
            }
            else{
                output[index] = i + 'a';
                printPrefix(root->child[i], input, inpSize, index + 1, output);
            }

        }
    }
}


int deleteTrie(Node* root, char input[])
{
    Node* cur = root;
    for (int i = 0; input[i]; i++)
    {
        int index = input[i] - 'a';
        if (NULL == cur->child[index])
        {
            return 0;
        }
        cur = cur->child[index];
    }
    if (cur->isLeaf){
        cur->isLeaf--;
        return 1;
    }
    else
        return 0;
}



void printTrie(Node* root, char output[], int index)
{
    if (root->isLeaf == 1)
    {
        output[index] = '\0';
        printf("%s\n", output);

    }

    for (int i = 0; i < SIZE; i++)
    {
        if (root->child[i] != NULL)
        {
            output[index] = i + 'a';
            printTrie(root->child[i], output, index + 1);
        }
    }
}

int main(){
    Node *root;
    root = createNode();
    insertTrie(root, "cccc");
    insertTrie(root, "kadsd");
    insertTrie(root, "kcabc");
    insertTrie(root, "kcdef");
    char output[100];

    cout<<"print trie:\n";
    printTrie(root, output, 0);
    cout<<"print end\n";
    cout<<"search xxxx\n";
    if (searchTrie(root, "xxxx"))
        cout << "found\n";
    else
        cout << "not found\n";

    cout<<"delete eds\n";
    if (deleteTrie(root, "eds"))
    {
        cout << "deleted\n";
    }
    else
        cout << "not del\n";
    cout<<"search eds\n";
    if (searchTrie(root, "eds"))
        cout << "found\n";
    else
        cout << "not found\n";

    printf("print :");
    printTrie(root, output, 0);

    /////////////////////////////////////////////////////////

    printf("\n\n\t START PREFIX SEARCH\n\n");

    char prefix[] = {'k', 'c'};
    printPrefix(root, prefix, 2,0, output);
    Node *current = root;

    doReverseString("z");
    doReverseString("efg");

}

