#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
//Tabulation
using namespace std;

int main(){
    int day = 3, task = 3;
    vector<vector<int>> points = {{18,11,19},{4,13,7},{1,8,13}};
    vector<vector<int>> dp(day, vector<int>(task + 1, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int i = 1; i < day; i++){
        for(int last = 0; last < task + 1; last++){
            dp[i][last] = 0;
            
            for(int j = 0; j < task; j++){
                if(j != last){
                    int point = points[i][j] + dp[i-1][j];
                    dp[i][last] = max(dp[i][last], point);
                }
            }
        }
    }
    
    cout<<dp[day-1][task]<<endl;

    return 0;
}