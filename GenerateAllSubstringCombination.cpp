//
//  main.cpp
//  GenerateAllSubtringCombination
//
//  Created by Asif on 14/12/21.
//

#include<iostream>
#include<string>
using namespace std;
int main() {
    
    string s = "abcde";
    cout << "generate all substing from : "<<s<<"\n";
    int len = s.size();
    string ts = "";
    for (int l = 1; l <= len; l++) /*keeps track of length from 1 to n */{
        for (int i = 0; i < len && i+l <= len; i++)/*creates starting point*/{
            for (int j = i; j <  i+l && j < len; j++)/*from starting point go upto given length */{
                cout << s[j];
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
 OUTPUT:
 generate all substing from : abcde
 a
 b
 c
 d
 e
 ab
 bc
 cd
 de
 abc
 bcd
 cde
 abcd
 bcde
 abcde
 */
