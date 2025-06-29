#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    int n = arr.size();
    vector<pair<int, int>> v(n);

    int farest_greater = arr[n-1];//arr[n-1];
    v[n-1] = {farest_greater, n-1};

    for(int i = n-2; i >= 0; i--){
        if(arr[i] <= v[i+1].first){
            farest_greater = v[i+1].first;
        }
        else{
            farest_greater = arr[i];//arr[i];
        }
        v[i] = {farest_greater, i};
    }

    for (int i = 0; i < v.size(); i++) {
        cout << "(" << v[i].first << ", " << v[i].second << ") ";
    }
    cout << endl;

    return 0;
}