#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int row, int col) {
    if(row == 0 && col == 0){
        return 1;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    int l = uniquePaths(row-1, col);
    int r = uniquePaths(row, col-1);
    return l + r;
}

int main(){
    int m = 3, n = 3;

    cout<<uniquePaths(m - 1, n - 1)<<endl;

    return 0;
}