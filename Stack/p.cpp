#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    vector<int> flowerbed = {1,0,0,0,0,1};
    int n = 2;
        int m = flowerbed.size();
        vector<int> ans(m, 0);

        int count = 0;
        for(int i = 0; i < m; i++){
            if(i == 0){
                if(flowerbed[i] == 0 && flowerbed[i + 1] == 0){
                    ans[i] = 1;
                    count++;
                }
                else{
                    ans[i] = flowerbed[i];
                }
            }
            else if(i == m-1){
                if(flowerbed[i] == 0 && ans[i - 1] == 0){
                    ans[i] = 1;
                    count++;
                }
                else{
                    ans[i] = flowerbed[i];
                }
            }
            else{
                if(flowerbed[i] == 0 && (flowerbed[i + 1] == flowerbed[i] && ans[i - 1] == flowerbed[i])){
                    ans.push_back(1);
                    count++;
                }
                else{
                    ans[i] = flowerbed[i];
                }
            }
        }
        cout<<count<<endl;
        for(int i = 0; i < m; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    return 0;
}