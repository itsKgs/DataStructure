#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int BinToDec(string x){
    reverse(x.begin(), x.end());
    int sum = 0;
    for (int i=0; i < x.size(); i++){
        if (x[i] == '1'){
            sum = sum + pow(2, i);
        }
        else{
            sum = sum;
        }
    }
    return sum;
}

int main(){
    string x = "1101";
    cout<<BinToDec(x);
    return 0;
}