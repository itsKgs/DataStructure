#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n+1];
    arr[n]=-1;
    for (int i = 0; i < n; i++){
        cout<<"enter value of "<<i<<"th element ";
        cin>>arr[i];
    }

    cout<<"array = ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    if (n==1){
        cout<<1<<endl;;
        return 0;
    }

    int count=0;
    int mx = -1;
    for(int i = 0; i < n; i++){
        if (arr[i]>arr[i+1] && arr[i]>mx){
            count = count + 1;
            cout<<arr[i]<<endl;
        }
        mx = max(arr[i], mx);
        
    }
    cout<<count;
    return 0;
}