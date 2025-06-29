#include <iostream>
#include <vector>
using namespace std;
int findMax(int ind, vector<int>& ans, vector<int>& val, vector<int>& wt, int capacity, int sum){

    if(sum <= capacity){
        sum = wt[ind] + findMax(ind + 1, ans, val, wt, capacity, sum);
    }

    sum = findMax(ind + 1, ans, val, wt, capacity, sum);

    return 

}

int main(){
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int capacity = 4;

    int n = val.size();
    vector<int> ans;
    int sum = 0

    findMax(0, ans, val, wt, capacity, sum);

    return 0;
}