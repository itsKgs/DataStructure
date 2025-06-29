#include <iostream>
using namespace std;

int main(){
    string s = "abcabc";
    int n = s.size();
    int count = 0;
    int lastSeen[3] = {-1, -1, -1};
    for(int i = 0; i < n; i++){
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            count = count + 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    cout<<count<<endl;

    return 0;
}