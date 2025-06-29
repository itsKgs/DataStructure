#include <iostream>
using namespace std;

int fact(int n){
    int factorial = 1;
    for(int i = 2; i <= n; i++){
        factorial = factorial*i;
    }
    return factorial;
}

int nCr(int n, int r){
    int nCr = fact(n)/(fact(n-r)*fact(r));
    return nCr;
}

int main(){
    int n;
    cout<<"Enter a number n"<<endl;
    cin>>n;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (j < i || j==i){
                cout<<nCr(i,j)<<" ";
            }    
        }   
        cout<<endl;
    }
    return 0;
}