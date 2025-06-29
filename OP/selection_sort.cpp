#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of array ";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element ";
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }  
    }
    
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}