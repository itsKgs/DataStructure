#include <iostream>
using namespace std;
void revArr(int i, int n, int arr[]){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    revArr(i+1, n, arr);
}

int main(){
    int n;
    cout<<"Enter the size of array ";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element ";
        cin>>arr[i];
    }

    cout<<"The given array is ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    revArr(0, n, arr);

    cout<<"The reverse array is ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}