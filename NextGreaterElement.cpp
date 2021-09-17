//
//  main.cpp
//  NextGreateElement
//
//  Created by Asif on 18/9/21.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> getNextGreaterElement(vector<int>input, int size){
    stack<int> stkOfIndx;
    vector<int>nextGreater(size);
    if(size== 0){
        return nextGreater;
    }
    stkOfIndx.push(0);
    int topIndx;
    for(int i=1;i<input.size();i++){
        topIndx =stkOfIndx.top();
        if(input[i] <= input[topIndx]){
            stkOfIndx.push(i);
        }
        else{
            while(!stkOfIndx.empty()){
                topIndx = stkOfIndx.top();
                if(input[topIndx] < input[i]){
                    nextGreater[topIndx] = input[i];
                    stkOfIndx.pop();
                }
                else{
                    stkOfIndx.push(i);
                    break;
                }
            }
        }
    }
    while(!stkOfIndx.empty()){
        topIndx = stkOfIndx.top();
        stkOfIndx.pop();
        nextGreater[topIndx] = -1;
    }
    return nextGreater;
}

void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    int n;
    cin>>n;
    int a;
    vector<int>input;
    for(int i=0;i<n;i++){
        cin>>a;
        input.push_back(a);
    }
    vector<int>nextGreater = getNextGreaterElement(input, n);
    printVector(nextGreater);
    return 0;
}
