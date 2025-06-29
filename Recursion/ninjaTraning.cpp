#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int maxPoint( int day, int task, int last, vector<vector<int>>& points){
    if(day == 0){
        int maxi = 0;
        for(int i = 0; i < task; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for(int i = 0; i < task; i++){
        if(i != last){
            int point = points[day][i] + maxPoint(day - 1, task, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;

}

int main(){
    int day = 3, task = 3;
    vector<vector<int>> points = {{18,11,19},{4,13,7},{1,8,13}};
    cout<<maxPoint(day-1, task, task, points)<<endl;

    return 0;
}