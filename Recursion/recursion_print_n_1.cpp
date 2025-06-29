#include <iostream>
using namespace std;

void PRint(int n){

    if(n==0){
        return;
    }
    cout<<n<<" ";
    PRint(n-1);
}

int main(){
    int n;
    cin>>n;
    PRint(n);

    return 0;
}