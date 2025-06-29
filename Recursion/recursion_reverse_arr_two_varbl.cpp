#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void revArr(int l, int r, int arr[]){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    revArr(l+1, r-1, arr);
}

int main(){
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element "; 
        cin>>arr[i];
    }
    cout<<"Given array is ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"The reverse array is ";
    revArr(0, n-1, arr);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}