#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>&kp, int n, vector<string>& all_words, string s){
    if(n<=0){
        all_words.push_back(s);
        return;
    }
    int t = n%10;
    for(int i=0; i<kp[t].size(); i++){
        string tmp = s;
        tmp = kp[t][i] + tmp;
        solve(kp,n/10,all_words,tmp);
    }
    return;
}

int main(){
    vector<vector<char>>kp = {
        {' '},{' '},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},
        {'w','x','y','z'}
    };
    int n;
    cin>>n;
    vector<string>all_words;
    solve(kp,n,all_words,"");
    for(string s: all_words)
        cout<<s<<" ";

    return 0;
}