#include <iostream>
using namespace std;

void SieveOfEratosthenes(int n){
    int prime[n+1] = {0};

    for (int i = 2; i <= n; i++){
        prime[i] = i;
    }
    
    for (int i = 2; i <= n; i++){
        if (prime[i] == i){
            for (int j = i*i; j <= n; j+=i){
                if (prime[j] == j){
                    prime[j] = i;
                }  
            }          
        }      
    }

    while (n != 1){
        cout<<prime[n]<<" ";
        n = n/prime[n];
    }  
}

int main(){
    int n;
    cin>>n;

    SieveOfEratosthenes(n);

    return 0;
}