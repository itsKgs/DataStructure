#include <iostream>
using namespace std;
void factorial(int i, int fact){
    if(i==0){
        cout<<fact<<endl;
        return;
    }
    factorial(i-1, i*fact);
}

int main(){
    int n;
    cin>>n;
    factorial(n, 1);

    return 0;
}