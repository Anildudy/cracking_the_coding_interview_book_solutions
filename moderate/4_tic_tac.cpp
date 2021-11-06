#include<bits/stdc++.h>
using namespace std;

bool is_won(vector<vector<int>>& board){
    int size = board.size();
    if(board.size() != board[0].size())
        return false;
    
    // check rows
    for(int i=0; i<size; i++){
        int first = board[i][0];
        if(first ==0)
            continue;
        for(int j=1; j<size; j++){
            if(board[i][j]!=first)
                break;
            else if(j== size-1)
                return true;
        }
    }

    // check columns
    for(int i=0; i<size; i++){
        int first = board[0][i];
        if(first ==0)
            continue;
        for(int j=1; j<size; j++){
            if(board[j][i]!=first)
                break;
            else if(j==size-1)
                return true;
        }
    }

    // check diagonals
    int first = board[0][0];
    if(first!=0){
        for(int i=1; i<size; i++){
            if(board[i][i]!=first)
                break;
            else if(i==size-1)
                return true;
        }
    }

    first = board[0][size-1];
    if(first!=0){
        for(int i=1; i<size; i++){
            if(board[i][size-1-i]!=first)
                break;
            else if(i==size-1)
                return true;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> v = {{1,2,1}, {2,1,2},{1,0,1}};
    cout<<is_won(v)<<"\n";
}