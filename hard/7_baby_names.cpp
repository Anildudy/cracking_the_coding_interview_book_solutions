#include<bits/stdc++.h>
using namespace std;

unordered_set<string>visited;

void dfs(map<string,vector<string>>& edges, string start, map<string,int>& freq, int& sm){
    if(visited.find(start)!=visited.end())
        return;
    
    visited.insert(start);
    sm += freq[start];
    for(auto item: edges[start]){
        if(visited.find(item)==visited.end())
            dfs(edges,item,freq,sm);
    }
    return;
}

void connect_edges(vector<pair<string,string>>& syn, map<string,vector<string>>& edges){
    for(auto item: syn){
        edges[item.first].push_back(item.second);
        edges[item.second].push_back(item.first);
    }
    return ;
}

int main(){
    map<string,int>freq = {{"John",10}, {"Jon",3}, {"Davis",2},{"Kari",3}, {"Johnny",11},{"Carlton",8},{"Carleton",2},{"Jonathan",9},{"Carrie",5}};
    vector<pair<string,string>>syn = {{"Jonathan","John"}, {"Jon","Johnny"},{"Johnny","John"},{"Kari","Carrie"},{"Carleton","Carlton"}};  
    map<string,vector<string>>edges;
    map<string,int>res;
    connect_edges(syn,edges);
    
    
    for(auto& item: freq){
        int sm = 0;
        if(visited.find(item.first)==visited.end()){
            dfs(edges,item.first,freq,sm);
            res[item.first] = sm;
        }
    }
    
    // for(auto&item: edges){
    //     cout<<item.first<<" ";
    //     for(auto& i: item.second)
    //         cout<<i<<",";
    //     cout<<"\n";
    // }

    for(auto& item: res){
        cout<<item.first<<" "<<item.second<<"\n";
    }

    return 0;
}
