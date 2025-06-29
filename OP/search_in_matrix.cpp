#include <iostream>
using namespace std;

int main(){
    int n,m,target;
    cin>>n>>m>>target;

    int matrix[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }

    int row = 0, column = m-1;
    bool found = false;
    while (row<n && column>=0){
        if (matrix[row][column]==target){
            found = true;
            break;
        }
        if (matrix[row][column] < target){
            row++;
        }
        else{
            column--;
        }
    }

    if (true){
        cout<<"row = "<<row<<endl;
        cout<<"column = "<<column;
    }
    else{
        cout<<"Not found";
    }
    return 0;
}