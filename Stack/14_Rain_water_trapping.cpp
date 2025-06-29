#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = height.size();
    vector<int> maxL(n);
    maxL[0] = height[0];

    for(int i = 1; i < n; i++){
        maxL[i] = max(maxL[i-1], height[i]);
    }

    vector<int> maxR(n);
    maxR[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--){
        maxR[i] = max(maxR[i+1], height[i]);
    }

    vector<int> water(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        water[i] = min(maxL[i], maxR[i]) - height[i];
        sum = sum + water[i];
    }

    cout<<sum<<endl;

    return 0;
}