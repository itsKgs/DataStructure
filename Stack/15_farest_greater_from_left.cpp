#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {6,2,4,3,2,2,5};
    int n = arr.size();
    vector<int> v(n);

    int farest_greater = arr[0];
    v[0] = farest_greater;

    for(int i = 1; i < n; i++){
        if(arr[i] <= v[i-1]){
            farest_greater = v[i-1];
        }
        else{
            farest_greater = arr[i];
        }
        v[i] = farest_greater;
    }

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}