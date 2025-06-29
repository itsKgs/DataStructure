#include <iostream>
using namespace std;

void SieveOfEratosthenes(int n){
    int prime[n+1] = {0};

    for (int i = 2; i*i < n; i++){
        if (prime[i] == 0){
            for (int j = i*i; j <= n; j+=i){
            prime[j] = 1;
            } 
        }
    }
    
    for (int i = 2; i <= n; i++){
        if (prime[i] == 0){
            cout<<i<<" ";
        }
        
    }
}

int main(){
    int n;
    cin>>n;

    SieveOfEratosthenes(n);

    return 0;
}