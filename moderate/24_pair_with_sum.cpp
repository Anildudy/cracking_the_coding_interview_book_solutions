#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    map<int,int>mp;
    vector<pair<int,int>>res;
    for(int i=0; i<n; i++){
        if(mp[v[i]]>0){
            res.push_back(make_pair(v[i],k-v[i]));
            mp[v[i]]--;
        }
        else{
            mp[k-v[i]]++;
        }
    }
    for(auto item: res){
        cout<<item.first<<" "<<item.second<<"\n";
    }

    return 0;

}