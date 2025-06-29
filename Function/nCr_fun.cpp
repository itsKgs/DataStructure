#include <iostream>
using namespace std;

int fact(int n){
    int factorial = 1;
    for(int i = 2; i <= n; i++){
        factorial = factorial*i;
    }
    return factorial;
}

int main(){
    int n, r;
    cout<<"Value of number n = ";
    cin>>n;
    cout<<"value of number r = ";
    cin>>r;

    float nCr = fact(n)/(fact(n-r)*fact(r));
    cout<<nCr<<endl;

    return 0;
}