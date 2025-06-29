#include <iostream>
using namespace std;

int main(){
    int n=7;
    int nums[7]={1,2,3,4,5,6,7}; //{5,6,7,1,2,3,4}
    int k=3;

    int temp[n];
    for(int i = 0; i < k; i++){
        temp[i] = nums[n-k+i];
    }
    for(int i = 0; i < n-k; i++){
        temp[k+i] = nums[i];
    }
    
    for (int j = 0; j < n; j++)
    {
        cout<<temp[j]<<" ";
    }
    return 0;
}