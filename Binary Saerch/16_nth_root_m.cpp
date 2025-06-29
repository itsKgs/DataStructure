#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n = 3;
    int m = 9;
    for(int i = 1; i <= m; i++){
        if(pow(i, n) == m){
            cout<<i<<endl;
            break;
        }
        else if(pow(i, n) > m){
            break;
        }
    }
    cout<<"-1"<<endl;

    return 0;
}