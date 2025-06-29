#include <iostream>
using namespace std;

void name(int n, int x){
    if(x>n){
        return;
    }
    cout<<"KUNWAR GAURAV SAHU"<<endl;

    name(n,x+1);
}

int main(){
    int n;
    int x=1;
    cin>>n;

    name(n,x);

    return 0;
}