#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//TC:(N-1) + (N-2) + (N-3) + . . . .  + 1 == N*(N-1)/2 = O(N^2) :-> best, avg, worst 
//SC : O(1)

int main(){
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++){//O(N)
        int min = i;
        for(int j = i + 1; j < n; j++){//O(N)
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[i]; //O(N)     
        arr[i] = arr[min];//O(N)
        arr[min] = temp;//O(N)
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}