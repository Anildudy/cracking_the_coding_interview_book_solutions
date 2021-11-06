#include<bits/stdc++.h>
using namespace std;

void ponds(vector<vector<int>>& mat, int i, int j, int &cnt){
    if(i>=mat.size() || j>=mat[0].size() || mat[i][j]!=0 || i<0 || j<0)
        return;
    //cout<<i<<" "<<j<<endl;
    // cout<<cnt<<endl;
    mat[i][j]=1;
    cnt = cnt+1;
    //cout<<*cnt<<" ";
    ponds(mat,i+1,j,cnt);
    ponds(mat,i,j+1,cnt);
    ponds(mat,i+1,j+1,cnt);
    ponds(mat,i-1,j,cnt);
    ponds(mat,i,j-1,cnt);
    ponds(mat,i-1,j-1,cnt);
    ponds(mat,i-1,j+1,cnt);
    ponds(mat,i+1,j-1,cnt);

    return;
}

int main(){
    vector<vector<int>> mat{{0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1}};
    vector<int>v;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j]==0){
                int cnt = 0;
                //cout<<i<<" "<<j<<endl;
                ponds(mat,i,j,cnt);
                v.push_back(cnt);
            }
        }
    }
    for(int it: v)
        cout<<it<<"\n";

    return 0;
}