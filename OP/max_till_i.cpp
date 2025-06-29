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
    
    int mx = arr[0];
    for (int i = 0; i < n; i++){
        mx = max(mx, arr[i]);
    }
    cout<<mx<<" "; 
    return 0;
}