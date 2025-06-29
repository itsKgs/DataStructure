#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> nums = {"111","011","001"};

    int n = nums.size();
    string ans = "";
    for(int i = 0; i < n; i++){
        if(nums[i][i] == '0'){  //Cantor Diagonalization;
            ans = ans + '1';
        }
        else{
            ans = ans + '0';
        }
    }
    cout<<ans<<endl;

    return 0;
}