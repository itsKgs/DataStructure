#include <iostream>
using namespace std;
// TC : O(N)
// SC : O(1)

int main(){
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    int maxL = 0;
    for(int i = 0; i < n; i++){
        int zeros = 0;
        for(int j = i; j < n; j++){
            if(arr[j] == 0){
                zeros++;
            }
            if(zeros <= k){
                maxL = max(maxL, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    cout<<maxL<<endl;

    return 0;
}