#include <iostream>
using namespace std;

bool IsPowerOf2(int n){
    if ((n & (n-1)) == 0){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    cout<<IsPowerOf2(n);

    return 0;
}