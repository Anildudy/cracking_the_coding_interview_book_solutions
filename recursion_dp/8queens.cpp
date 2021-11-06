#include<bits/stdc++.h>
using namespace std;

int board[8][8];
int ct = 0;

bool is_possible(int n, int row, int col){
    for(int i=row-1; i>=0; i--){
        if(board[i][col]==1)
            return false;
    }

    for(int i=row-1,j=col-1; i>=0,j>=0; i--,j--){
        if(board[i][j]==1)
            return false;
    }

    for(int i=row-1,j=col+1; i>=0,j<n; i--,j++){
        if(board[i][j]==1)
            return false;
    }

    return true;
}

void place_queen(int n, int row){
    if(row==n){
        ct++;
        return;
    }
    for(int j=0; j<n; j++){
        if(is_possible(n,row,j)){
            board[row][j]=1;
            place_queen(n,row+1);
            board[row][j]=0;
        }
    }

    return;   
}

int main(){
    memset(board,0,8*8*sizeof(int));

    place_queen(8,0);

    cout<<ct<<"\n";

    return 0;
}