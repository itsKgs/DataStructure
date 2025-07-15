#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
    int k, n;
    
    cout<<"Enter ith Num : ";
    cin>>k;

    cout<<"Enter array size : ";
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cout<<"Enter "<<i<<"th elemnt : ";
        cin>>arr[i];
    }
    cout<<endl;

    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < arr.size(); i++){
        minH.push(arr[i]);
        if(minH.size() > k){
            minH.pop();
        }
    }

    while(minH.size() > 0){
        cout<<minH.top()<<" ";
        minH.pop();
    }
    cout<<endl;


    return 0;
}