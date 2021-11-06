#include<bits/stdc++.h>
using namespace std;

void add_parens(vector<string>& res, string s, int n, int m){
    if(n==0 && m==0)
        res.push_back(s);

    if(m>0){
        add_parens(res,s+")",n,m-1);
    }
    if(n>0){
        add_parens(res,s+"(",n-1,m+1);
    }
    return;
}

vector<string> generate_parenthesis(int n){
    vector<string> res;
    add_parens(res,"",n,0);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string>v = generate_parenthesis(n);

    for(auto item: v)
        cout<<item<<" ";
    cout<<"\n";

    return 0;
}