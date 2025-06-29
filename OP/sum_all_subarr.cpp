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
        int sum = 0;
        for (int j = i; j < n; j++){
            sum = sum + arr[j];
            cout<<sum<<" ";
        }   
    }
    return 0;
}