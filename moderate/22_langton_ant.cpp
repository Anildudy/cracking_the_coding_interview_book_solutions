#include<bits/stdc++.h>
using namespace std;


// Not exactly correct, better to implement using map that way it will be extensible
void moves(vector<vector<char>>&v, int k, int i, int j){
    if(k==0)
        return;
    if(v[i][j]=='W'){
        v[i][j] = 'B';
        moves(v,k-1,i+1,j);
    }
    else{
        v[i][j]='W';
        moves(v,k-1,i,j+1);
    }
    return;
}

int main(){
    int k; 
    cin>>k;
    vector<vector<char>>v(k,vector<char>(k,'W'));
    for(int i=0; i<k; i+=2){
        for(int j=1; j<k; j+=2)
            v[i][j] = 'B';
        if(i+1<k){
        for(int j=0; j<k; j+=2)
            v[i+1][j] = 'B';
        }
    }
    moves(v,k,0,0);
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}