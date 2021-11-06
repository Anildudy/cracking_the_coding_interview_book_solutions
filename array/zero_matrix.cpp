#include<bits/stdc++.h>
using namespace std;

void nullify_row(vector<vector<int>>& matrix, int row){
    for(int j=1; j<matrix[0].size(); j++){
        matrix[row][j]=0;
    }
}

void nullify_column(vector<vector<int>>& matrix, int column){
    for(int i=1; i<matrix.size(); i++){
        matrix[i][column] = 0;
    }
}

void set_zero(vector<vector<int>>& matrix){
    bool row_has_zero = false;
    bool column_has_zero = false;

    for(int i=0; i<matrix.size(); i++){
        if(matrix[i][0]==0){
            row_has_zero = true;
            break;
        }
    }

    for(int i=0; i<matrix[0].size(); i++){
        if(matrix[0][i]==0){
            column_has_zero = true;
            break;
        }
    }

    for(int i=1; i<matrix.size(); i++){
        for(int j=1; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<matrix.size(); i++){
        if(matrix[i][0]==0)
            nullify_row(matrix,i);
    }
    
    for(int j=1; j<matrix[0].size(); j++){
        if(matrix[0][j]==0)
            nullify_column(matrix, j);
    }

    if(row_has_zero){
        nullify_column(matrix,0);
    }

    if(column_has_zero){
        nullify_row(matrix, 0);
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,0}};
    set_zero(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}