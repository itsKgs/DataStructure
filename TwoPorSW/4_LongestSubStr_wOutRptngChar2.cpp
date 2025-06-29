#include <iostream>
#include <limits>
#include <vector>
using namespace std;
// TC : O(N)
// SC : O(256)
int main(){
    string s = "a";
    int n = s.size();

    int maxL = 0;
    int left = 0;
    int right = 0;
    vector<int> hash(256, -1);

    while(right < n){ // O(N)
        if(hash[s[right]] != -1){
            if(hash[s[right]] >= left){
                left = hash[s[right]] + 1;
            }
        }
        maxL = max(maxL, right - left + 1);
        hash[s[right]] = right;
        right++;
    }

    cout<<maxL<<endl;

    return 0;
}