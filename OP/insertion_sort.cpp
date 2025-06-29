#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of array";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element ";
        cin>>arr[i];
    }
    
    cout<<"array = ";
    for (int i = 0; i < n; i++){
       cout<<arr[i]<<" "; 
    }
    cout<<endl;

    for (int i = 1; i < n; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>arr[j+1] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    cout<<"Sorted array = ";
    for (int i = 0; i < n; i++){
       cout<<arr[i]<<" "; 
    }

    return 0;
}