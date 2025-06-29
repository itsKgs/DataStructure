#include <iostream>
#include <limits>
#include <vector>
using namespace std;
// TC : O(N) + O(N) == O(2N)
// SC : O(1)
int main(){
    int arr[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    int maxL = 0;
    int right = 0;
    int left = 0;
    int zeros = 0;
    while(right < n){ // O(N)
        if(arr[right] == 0){
            zeros++;
        }

        if(zeros > k){
            if(arr[left] == 0){
                zeros--;
            }
            left++;
        }

        if(zeros <= k){
            maxL = max(maxL, right - left + 1);
        }
        right++;
    }
    cout<<maxL<<endl;

    return 0;
}