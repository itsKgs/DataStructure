#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int primeFactorSUM(int n){
    int pfS = 0;
    if(prime(n)){
        for(int i = 2; i <= n; i++){
            if(n%i == 0){
                pfS = pfS + i;
            }
        }
    }
    else{
        for(int i = 2; i <= sqrt(n) + 1; i++){
            if(n%i == 0){
                pfS = pfS + i;
            }
        }
    }
    return pfS;
}


int main(){
    
    int n = 15;
    int pfS = primeFactorSUM(n);
    while(pfS != n){
        n = pfS;
        pfS = primeFactorSUM(n);
    }
    cout<<n<<endl;

    return 0;
}