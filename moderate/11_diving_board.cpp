#include<bits/stdc++.h>
using namespace std;

// void find_lengths(vector<int>&v,set<int>&s, int k, int idx, int len, int sel){
//     if(sel==k){
//         s.insert(len);
//         return;
//     }
//     int need = k-sel;
//     for(int i=idx; i<=v.size()-need; i++){
//         len += v[i];
//         find_lengths(v,s,k,i+1,len,sel+1);
//         len -= v[i];
//     }
//     return;
// }

// int possible_lengths(vector<int>&v, int k){
//     set<int> s;
//     find_lengths(v,s,k,0,0,0);
//     return s.size();
// }

void get_all_lengths(set<int>&lengths, set<string>&visited, int k, int s, int l, int len){
    if(k==0){
        lengths.insert(len);
        return;
    }
    string key = to_string(len) + " " + to_string(k);
    if(visited.find(key)!=visited.end())
        return;
    get_all_lengths(lengths,visited,k-1,s,l,len+s);
    get_all_lengths(lengths,visited,k-1,s,l,len+l);
    visited.insert(key);
}

int possible_lengths(int k, int s, int l){
    set<int> lengths;
    set<string> visited;
    get_all_lengths(lengths,visited,k,s,l,0);
    return lengths.size();
}

int all_lengths(int k, int s, int l){
    set<int> lengths;
    for(int shorter = 0; shorter<=k; shorter++){
        int longer = k-shorter;
        int len = shorter*s + longer*l;
        lengths.insert(len);
    }
    return lengths.size();
}

int main(){
    int k = 3;
    int small=1,large=2;
    cout<<possible_lengths(k,small,large)<<"\n";
    cout<<all_lengths(k,small,large)<<"\n";
    
    return 0;
}