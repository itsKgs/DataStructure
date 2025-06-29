#include <iostream>
#include <vector>
using namespace std;
//TC : O(K + K)
//SC : O(1)

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1}; 
    int k = 3;
    int n = cardPoints.size();

    int sum = 0;
    for(int i = 0; i < k; i++){
        sum = sum + cardPoints[i];
    }

    int left = k - 1;
    int right = n;
    int maxSum = sum;

    while(left >= 0){
        sum = sum - cardPoints[left];
        left--;
        right--;
        sum = sum + cardPoints[right];
        maxSum = max(maxSum, sum);
    }
    cout<<maxSum<<endl;

    return 0;
}