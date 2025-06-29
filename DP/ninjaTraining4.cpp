#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
//Space Optimization
using namespace std;

int main(){
    int day = 3, task = 3;
    vector<vector<int>> points = {{18,11,19},{4,13,7},{1,8,13}};
    vector<int> prev(task + 1, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int i = 1; i < day; i++){
        vector<int> temp(task + 1, 0);
        for(int last = 0; last < task + 1; last++){
            temp[last] = 0;
            
            for(int j = 0; j < task; j++){
                if(j != last){
                    temp[last] = max(temp[last], points[i][j] + prev[j]);   
                }
            }
        }
        prev = temp;
    }
    
    cout<<prev[task]<<endl;

    return 0;
}