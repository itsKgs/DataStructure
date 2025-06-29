#include <iostream>
using namespace std;
bool Sorted(int arr[], int n){
    if (n==1){
        return true;
    }
    bool restArr = Sorted(arr+1, n-1);
    return arr[0] < arr[1] && restArr;
}

int main(){
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th element"<<endl;
        cin>>arr[i];
    }
    cout<<"array = ";
    for (int i = 0; i < n; i++){
       cout<<arr[i]<<" "; 
    }
    cout<<endl;

    cout<<Sorted(arr, n)<<endl;
    return 0;
}