#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout<<"Enter the value a ";
    cin>>a;
    cout<<"Enter the value b ";
    cin>>b;
    for (int num = a; num <= b; num++){
        int j;
        for ( j = 2; j < num ; j++){
            if (num%j==0){
                break;
            }   
        }
        if (num==j){
            cout<<num<<endl;
        }      
    }
    return 0;
}