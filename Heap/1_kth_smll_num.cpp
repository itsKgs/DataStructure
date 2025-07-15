#include <iostream>
#include<vector>
#include<queue>
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

    priority_queue<int> maxH;
    for (int i = 0; i < arr.size(); i++){
        maxH.push(arr[i]);
        if(maxH.size() > k){
            maxH.pop();
        }
    }
    cout<<maxH.top()<<endl;

    return 0;
}