#include <iostream>
using namespace std;

int main(){
    int n = 8;

    int ans = 1;
    int low = 1;
    int high = n;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        if(mid * mid == n){
            ans = mid;
            break;
        }
        else if(mid * mid < n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}