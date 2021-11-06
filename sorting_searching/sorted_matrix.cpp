#include<bits/stdc++.h>
using namespace std;

string find_element(vector<vector<int>>&matrix, int target){
    int i=0;
    int j=matrix[0].size()-1;
    //cout<<i<<" "<<j;

    while(i<matrix.size() &&  j>=0){
        if(matrix[i][j]==target)
            return "found";
        else if(matrix[i][j]>target){
            j--;
            continue;
        }
        else{
            i++;
            continue;
        }
    }
    return "Not found";
}

int main(){
    vector<vector<int>>matrix = {{1,2,3},{4,6,7},{5,8,3}};
    int target = 10;
    cout<<find_element(matrix, target)<<"\n";
}