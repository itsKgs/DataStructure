#include <iostream>
#include <vector>
using namespace std;
int findK(vector<int> arr, int k){
    int current = 1;
    int index = 0;
    int missingCount = 0;
    while(true){
        if(index < arr.size() && arr[index] == current){
            index++;
        }
        else{
            missingCount++;
            if(missingCount == k){
                return current;
            }
        }
        current++;
    }
    return -1;
}

int main(){
    vector<int> arr{2,3,4,7,11}; 
    int k = 5;

    int n = arr.size();

    //for(int i = 0; i < n; i++){
    //    if(arr[i] <= k){
    //        k++;
    //    }
    //    else{
    //        break;
    //    }
    //}
    //cout<<k<<endl;
    cout<<findK(arr, k)<<endl;

    return 0;
}