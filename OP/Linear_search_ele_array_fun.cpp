#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int element){
    for (int i = 0; i < n; i++){
        if (arr[i]==element){
            return i;
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
    cout<<"Enter the to search ";
    cin>>element;
    
    cout<<LinearSearch(arr, n, element);
    return 0;
}