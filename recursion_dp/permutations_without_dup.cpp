#include<bits/stdc++.h>
using namespace std;

vector<string> p;

void find_permutations(string s, int idx, string tmp){
    if(idx == s.length()){
        p.push_back(tmp);
        return;
    }

    for(int i=idx; i<s.length(); i++){
        swap(s[i],s[idx]);
        //cout<<s<<" ";
        string st = tmp+s[idx];
        find_permutations(s,idx+1,st);
        swap(s[i],s[idx]);
    }
}

int main(){
    string s;
    cin>>s;
    find_permutations(s,0,"");
    
    for(auto item : p){
        cout<<item<<" ";
    }
    cout<<"\n"<<p.size()<<"\n";
    return 0;
}