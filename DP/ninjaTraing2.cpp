#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
//Memorization
using namespace std;
int maxPoint( int day, int task, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0; i < task; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }

    int maxi = 0;
    for(int i = 0; i < task; i++){
        if(i != last){
            int point = points[day][i] + maxPoint(day - 1, task, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;

}

int main(){
    int day = 3, task = 3;
    vector<vector<int>> points = {{18,11,19},{4,13,7},{1,8,13}};

    vector<vector<int>> dp(day, vector<int>(task + 1, -1));
    cout<<maxPoint(day-1, task, task, points, dp)<<endl;

    return 0;
}