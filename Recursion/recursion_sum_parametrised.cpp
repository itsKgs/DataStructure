#include <iostream>
using namespace std;

void SUM(int i, int sum){
    if(i<0){
        cout<<sum<<endl;
        return;
    }
    SUM(i-1, sum + i );
}

int main(){
    int n;
    cin>>n;
    SUM(n, 0);

    return 0;
}