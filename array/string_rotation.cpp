#include<bits/stdc++.h>
using namespace std;

bool is_substring(string s1, string s2){
    if(s1.find(s2) != string::npos)
        return true;
    return false;
}

bool is_rotation(string s1, string s2){
    int l = s1.length();
    if(l==s2.length() && l>0){
        string s = s1+s1;
        return is_substring(s,s2);
    }
    return false;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<is_rotation(s1,s2)<<"\n";
    return 0;
}