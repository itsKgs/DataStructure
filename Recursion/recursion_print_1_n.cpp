#include <iostream>
using namespace std;
void PRint(int n, int x){
    if (x>n){
        return;
    }
    cout<<x<<" ";

    PRint(n, x+1);
}

int main(){
    int n;
    cin>>n;
    PRint(n,1);

    return 0;
}