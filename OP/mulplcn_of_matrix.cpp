#include <iostream>
using namespace std;

int main(){
    int n1 = 3, n2 = 4 , n3 = 3;

    int A[n1][n2] = {{2,4,1,2},{8,4,3,6},{1,7,9,5}};
    int B[n2][n1] = {{1,2,3},{4,5,6},{7,8,9},{4,5,6}};

    int matrix[n1][n3];
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++){
            matrix[i][j] = 0;
        } 
    }
    
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++){
            for (int k = 0; k < n2; k++){
                matrix[i][j] = matrix[i][j] + (A[i][k])*(B[k][j]);
            }
        } 
    }
    
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n3; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}