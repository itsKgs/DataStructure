#include <iostream>
using namespace std;
//TC : O(N^2)
//SC : O(1)

int main(){
    int arr[] = {2, 5, 1, 7, 10};
    int k = 14;
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxLength = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum = sum + arr[j];
            if(sum <= k){
                maxLength = max(maxLength, j - i + 1);
            }
            else if(sum > k){
                break;
            }
        }
    }
    cout<<maxLength<<endl;

    return 0;
}