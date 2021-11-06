#include<bits/stdc++.h>
using namespace std;

vector<string> p;

void find_permutations(map<char,int>&mp,string tmp, int remaining){
    if(remaining == 0){
        p.push_back(tmp);
        return;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        int count = it->second;
        //cout<<it->second<<" ";
        if(count>0){
            it->second = count-1;
            string st = tmp + it->first;
            find_permutations(mp,st,remaining-1);
            it->second = count;
        }
    }
}

int main(){
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }

    find_permutations(mp,"",s.length());
    
    for(auto item : p){
        cout<<item<<" ";
    }
    cout<<"\n"<<p.size()<<"\n";
    return 0;
}