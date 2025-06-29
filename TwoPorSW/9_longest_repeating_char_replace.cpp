#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s = "ABAB";
    int k = 2;
    int n = s.size();

    int maxL = 0;
    for(int i = 0; i < n; i++){
        vector<int> hash(26, 0);
        int maxFreq = 0;
        for(int j = i; j < n; j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            int changes = (j - i + 1) - maxFreq;
            if(changes <= k){
                maxL = max(maxL, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    cout<<maxL<<endl;

    return 0;
}