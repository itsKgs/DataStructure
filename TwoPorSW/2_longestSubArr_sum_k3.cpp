#include <iostream>
using namespace std;
//TC : O(N + N)
//SC : O(1)

int main(){
    int arr[] = {10, 5, 2, 7, 1, -10};
    int k = 15;
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxLength = 0;
    int left = 0;
    int right = 0; 
    int sum = 0;
    while(right < n){
        sum = sum + arr[right];
        if(sum > k){
            sum = sum - arr[left];
            left++;
        }
        if(sum <= k){
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }
    cout<<maxLength<<endl;

    return 0;
}