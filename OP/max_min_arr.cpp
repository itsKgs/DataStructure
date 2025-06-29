#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length ";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i<<"th value ";
        cin>>arr[i];
    }  

    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for (int i = 0; i < n; i++){
       //if(arr[i]>maxNo){
       //    maxNo = arr[i];
       maxNo = max(maxNo,arr[i]);
        //if (arr[i]<minNo){
        //    minNo = arr[i];   
        minNo = min(minNo,arr[i]);
    }
    cout<<maxNo<<endl;
    cout<<minNo<<endl;
    return 0;
}
