#include <iostream>
using namespace std;

int main(){
    int arr[] = {100, 200, 300, 400};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for(int i = 0; i < k; i++){
        sum = sum + arr[i];
    }
    
    int left = 0;
    int right = k - 1;
    int maxSum = sum;
    while(right < n - 1){
        sum = sum - arr[left];
        left++;
        right++;
        sum = sum + arr[right];
        maxSum = max(maxSum, sum);
    }
    cout<<maxSum<<endl;
    return 0;
}