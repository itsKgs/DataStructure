#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> leftIndex(vector<int>& heights){
    int n = heights.size();
    vector<int> left;
    stack<pair<int,int>> s;
    int psudo_index = -1;

    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            left.push_back(psudo_index);
        }
        else if(s.size() > 0 && s.top().first < heights[i]){
            left.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= heights[i]){
            while (s.size() > 0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size() == 0){
                left.push_back(psudo_index);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
    }
    return left;
}

vector<int> rightIndex(vector<int>& heights){
    int n = heights.size();
    vector<int> right;
    stack<pair<int,int>> s;
    int psudo_index = n;

    for(int i = n - 1; i >= 0; i--){
        if(s.size() == 0){
            right.push_back(psudo_index);
        }
        else if(s.size() > 0 && s.top().first < heights[i]){
            right.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= heights[i]){
            while (s.size() > 0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size() == 0){
                right.push_back(psudo_index);
            }
            else{
                right.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
    }

    reverse(right.begin(), right.end());
    return right;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int n = heights.size();
    vector<int> right = rightIndex(heights);
    vector<int> left = leftIndex(heights);
    vector<int> width(n);

    int area = 0;
    for(int i = 0; i < n; i++){
        width[i] = right[i] - left[i] -1;
        area = max(area, width[i]*heights[i]);
    }
    cout<<area<<endl;

    return 0;
}