#include<bits/stdc++.h>
using namespace std;

bool * visited;
bool exist = false;

void addEdge(vector<int> adj[], int x, int y){
  adj[x].push_back(y);
  //adj[y].push_back(x);
}

void search(vector<int> adj[], int s, int f){
  for(int i=0; i<adj[s].size(); i++){
    int w = adj[s][i];
    //cout<<w<<"\n";
    if(w == f){
      exist = true;
      break;
    }
    if(!visited[w]){
      visited[w] = true;
      search(adj, w, f);
    }
  }
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<int> adj[n];
  for(int i=0; i<m; i++){
    int x,y;
    cin>>x>>y;
    addEdge(adj,x,y);
  }

  visited = new bool[n];
  memset(visited, false, n);
  int a,b;
  cin>>a>>b;
  search(adj,a,b);
  cout<<exist<<"\n";
  for(int i=0; i<n; i++)
    cout<<visited[i]<<" ";
  // for(int i=0; i<n; i++){
  //   cout<<"Adj node of edge "<<i<<"are :";
  //   for(auto j: adj[i])
  //     cout<<j<<" ";
  //   cout<<"\n";
  // }
  return 0;
}
