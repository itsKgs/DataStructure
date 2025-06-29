#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of charector array = ";
    cin>>n;

    char arr[n+1];
    cout<<"Enter array = ";
    cin>>arr;

    bool ans = true;
    for (int i = 0; i < n; i++){
        if (arr[i] != arr[n-1-i]){
            ans = false;
        }
    }
    
    if (ans){
        cout<<"Given word is palindrom";
    }
    else{
        cout<<"Given word is not palindrom";
    }
    
    return 0;
}