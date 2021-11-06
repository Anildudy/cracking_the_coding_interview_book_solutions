#include<bits/stdc++.h>
using namespace std;

int dp[5][5];

void printSolution(vector<vector<int>> &grid){
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[0].size(); j++)
      cout<<dp[i][j]<<" ";
    cout<<"\n";
  }
}

void find_path(vector<vector<int>>& grid,int i, int j){
  if(i==grid.size()-1 && j==grid[0].size()-1){
    dp[i][j] = 1;
    printSolution(grid);
    cout<<endl;
    dp[i][j] = 0;
    return;
  }
  // cout<<i<<" "<<j<<endl;

  if(i>= grid.size() || j>=grid[0].size() || grid[i][j] == 2 || dp[i][j] ==1)
    return;

  dp[i][j] = 1;
  find_path(grid,i+1,j);
  find_path(grid,i,j+1);
  dp[i][j] = 0;

}

bool get_path(vector<vector<int>> &grid, )


int main(){
  int r,c;
  cin>>r>>c;
  vector<vector<int>> grid(r, vector<int>(c,0));
  grid[1][1] = 2;
  find_path(grid,0,0);
}
