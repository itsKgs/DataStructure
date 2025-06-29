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
    int n;
    cout<<"Enter a number n"<<endl;
    cin>>n;

    int factorial = fact(n);
    cout<<factorial<<endl;

    return 0;
}