#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number ";
    cin>>num;
    int i;
    for ( i = 2; i < num; i++){
        if (num%i==0){
            cout<<"Not Prime"<<endl;
            break;
        }
    }
    if (num==i || num==1){
        cout<<"Prime Number";
    }

    return 0;
}