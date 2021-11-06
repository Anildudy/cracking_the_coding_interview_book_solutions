#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    reverse(matrix.begin(), matrix.end());
    for(int i=0; i<matrix.size(); i++){
        for(int j=i+1; j<matrix.size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return;
}

void ring_by_ring(vector<vector<int>>& matrix){
    int n = matrix.size();
    int a = 0;
    int b = n-1;
    while(a<b){
        for(int i=0; i<(b-a); i++){
            swap(matrix[a][a+i], matrix[a+i][b]);
            swap(matrix[a][a+i], matrix[b][b-i]);
            swap(matrix[a][a+i], matrix[b-i][a]);
        }
        a++;
        b--;
    }
    return;
}

int main(){
    vector<vector<int>>matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    //rotate(matrix);
    ring_by_ring(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}