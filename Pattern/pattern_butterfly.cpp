#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n "<<endl;
    cin>>n;

    for (int i = 1; i <= n; i++){
        for ( int j = 1; j <= 2*n; j++){
            if (j <= 2*n-i && j>i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }     
        cout<<endl;
    }

    for (int i = n+1; i <= 2*n; i++){
        for ( int j = 1; j <= 2*n; j++){
            if (j <= 2*n+1-i || j >= i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }     
        cout<<endl;
    }  
    return 0;
}