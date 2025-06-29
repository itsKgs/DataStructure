#include <iostream>
#include <map>
using namespace std;
//TC : O(N) + O(N) == O(N)
//Sc : O(3)
int main(){
    int arr[] = {3,3,3,1,2,1,1,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxL = 0;
    int l = 0;
    int r = 0;
    map<int, int> mp;
    while(r < n){
        mp[arr[r]]++;
        if(mp.size() > 2){
            mp[arr[l]]--;
            if(mp[arr[l]] == 0){
                mp.erase(arr[l]);
            }
            l++;
        }
        if(mp.size() <= 2){
            maxL = max(maxL, r - l + 1);
        }
        r++;
    }
    cout<<maxL<<endl;

    return 0;
}