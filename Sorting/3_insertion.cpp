#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//TC:(N-1) + (N-2) + (N-3) + . . . .  + 1 == N*(N-1)/2 = O(N^2) :-> avg, worst , in best : O(N)
//SC : O(1)

int main(){
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n; i++){//O(N)
        for(int j = i; j > 0; j--){//O(N)
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}