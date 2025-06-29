#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int element){
    int s=0;
    int e=n;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid]>element){
            e = mid-1;
        }
        else{
            s = mid+1;
        }    
    }
    return -1;
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
    int element;
    cout<<"Enter the element to search ";
    cin>>element;

    cout<<binarySearch(arr, n, element);

    return 0;
}