#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int nums[10] = {1,2,3,1,1,0,1,0,2,3};
    int k = 3;
    int len = 0;
    for(int i = 0; i < 10; i++){
        int sum = 0;
        for(int j = i; j < 10; j++){
            sum = sum + nums[j];
            if(sum == k){
                len = std::max(len, j-i+1);
            }
            else if(sum > k){
                break;
            }
        }
    }
    cout<<len<<endl;

    return 0;
}   