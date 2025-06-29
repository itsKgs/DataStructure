#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cout<<"enter value of "<<i<<"th element ";
        cin>>arr[i];
    }


    cout<<"array = ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int longest_length=0;
    int initial_length=2;
    for (int i = 0; i < n; i++){
        if ((arr[i]-arr[i+1])==(arr[i+1]-arr[i+2])){
            initial_length = initial_length + 1;
        }
        else{
            if (longest_length>c){
                continue;
            }
            else{
                longest_length = initial_length;
            }
            initial_length = 2;
        }
    }
    cout<<longest_length;
    
    return 0;
}