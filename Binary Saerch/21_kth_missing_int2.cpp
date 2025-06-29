#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{2,3,4,7,11}; 
    int k = 5;
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<high + 1 + k<<endl;

    return 0;
}