#include <iostream>
using namespace std;

int main(){
    int n = 8;

    int ans = 1;
    for(int i = 0; i <= n; i++){
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}