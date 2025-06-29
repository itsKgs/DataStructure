#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string DecToBin (int n){
    string res = "";
    while(n != 0){
        if (n%2 == 1){
            res += '1';
        }
        else{
            res += '0';
        }
        n = n/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n = 13;
    cout<<DecToBin(n);
    return 0;
}